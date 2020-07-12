#include <map>
#include <utility>
#include <fstream>
#include <iostream>

#include "geodesic-growth.hpp"
#include "group-impl/virt-heisenberg.hpp"

using namespace group_visualisation;

int main () {

  using group = group_impl::virt_heisenberg;

  auto g_set = group::default_generating_set();

  geodesic_growth<group> growth(g_set);

  std::ofstream output("data.csv");

  for (int i = 0; i <= 1'000'000'000; ++i) {
    auto [size, value] = growth.next();
    output << size << "," << value << std::endl;
  }

}
