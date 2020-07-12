#pragma once
#ifndef b2f9aa55_GeodesicGrowth_hpp
#define b2f9aa55_GeodesicGrowth_hpp

#include <map>
#include <vector>
#include <utility>

namespace group_visualisation {

template <class Group>
class geodesic_growth {
public:
  template <class Vector>
  explicit geodesic_growth(Vector g_set);

  template <class Iterator>
  explicit geodesic_growth(Iterator begin, Iterator end);

  std::pair<int,unsigned long long> next();

private:
  int current_size;
  unsigned long long running_total;
  std::vector<Group> g_set;
  std::map<Group,unsigned long long> sphere_0;
  std::map<Group,unsigned long long> sphere_1;
  std::map<Group,unsigned long long> sphere_2;
}; // class geodesic_growth {

}; // namespace group_visualisation {

#include "_impl/geodesic-growth.impl.hpp"
#endif
