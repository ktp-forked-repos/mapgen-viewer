#include "mapgen/utils.hpp"
#include "rang.hpp"

namespace mg {
	double getDistance(Point p, Point p2) {
		double distancex = (p2->x - p->x);
		double distancey = (p2->y - p->y);

		return std::sqrt(distancex * distancex + distancey * distancey);
  }

  template <typename T>
  std::vector<T *> filterObjects(std::vector<T *> regions,
                                      filterFunc<T> filter, sortFunc<T> sort) {
    std::vector<T *> places;

    std::copy_if(regions.begin(), regions.end(), std::back_inserter(places),
                 filter);
    std::sort(places.begin(), places.end(), sort);
    return places;
  }
  void before(std::string method) {
    std::cout << "Before: " << rang::fg::red << method << rang::style::reset << std::endl << std::flush;

  };
  void after(std::string method) {
    std::cout << "After: " << rang::fg::green << method << rang::style::reset << std::endl << std::flush;
  };
  void info(std::string prefix, std::string value) {
    std::cout << rang::style::bold << rang::fg::black << "[info]\t" << rang::style::reset << prefix << " " << rang::fg::blue << value << rang::style::reset << std::endl << std::flush;
  };
  void info(std::string prefix, int value) {
    std::cout << rang::style::bold << rang::fg::black << "[info]\t" << rang::style::reset << prefix << " " << rang::fg::blue << value << rang::style::reset << std::endl << std::flush;
  };
  void info(std::string prefix, float value) {
    std::cout << rang::style::bold << rang::fg::black << "[info]\t" << rang::style::reset << prefix << " " << rang::fg::blue << value << rang::style::reset << std::endl << std::flush;
  };
};