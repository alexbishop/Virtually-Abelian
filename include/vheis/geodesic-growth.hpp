#pragma once

#include <map>
#include <utility>
#include <vector>

#include "SafeInt.hpp"

namespace group_visualisation {

template <class Group>
class geodesic_growth {
 public:
  template <class Vector>
  explicit geodesic_growth(Vector g_set);

  template <class Iterator>
  explicit geodesic_growth(Iterator begin, Iterator end);

  std::pair<SafeInt<int>, SafeInt<unsigned long long>> next();

 private:
  SafeInt<int> current_size;
  SafeInt<unsigned long long> running_total;
  std::vector<Group> g_set;
  std::map<Group, SafeInt<unsigned long long>> sphere_0;
  std::map<Group, SafeInt<unsigned long long>> sphere_1;
  std::map<Group, SafeInt<unsigned long long>> sphere_2;
};

};  // namespace group_visualisation

// Implementation

namespace group_visualisation {

template <class Group>
template <class Vector>
geodesic_growth<Group>::geodesic_growth(Vector g_set)
    : geodesic_growth(g_set.begin(), g_set.end()) {}

template <class Group>
template <class Iterator>
geodesic_growth<Group>::geodesic_growth(Iterator begin, Iterator end)
    : g_set(begin, end), running_total(0), current_size(-1) {}

template <class Group>
std::pair<SafeInt<int>, SafeInt<unsigned long long>>
geodesic_growth<Group>::next() {
  if (current_size < 0) {
    Group identity;
    sphere_0[identity] = 1ull;
    current_size = 0;
    running_total = 1ull;

    return std::make_pair(current_size, running_total);
  }

  sphere_2 = std::move(sphere_1);
  sphere_1 = std::move(sphere_0);
  sphere_0 = std::map<Group, SafeInt<unsigned long long>>();

  for (const auto& [element, count] : sphere_1) {
    for (auto& g : g_set) {
      const auto next_element = element * g;

      if (sphere_1.count(next_element) == 0 &&
          sphere_2.count(next_element) == 0) {
        sphere_0[next_element] += count;
        running_total += count;
      }
    }
  }

  ++current_size;

  return std::make_pair(current_size, running_total);
}

}  // namespace group_visualisation
