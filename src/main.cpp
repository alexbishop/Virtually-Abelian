#include <fstream>
#include <iostream>
#include <map>
#include <utility>

#include <vheis/geodesic-growth.hpp>
#include <vheis/group-impl/virt-heisenberg.hpp>

using namespace group_visualisation;

int main() {
  using group = group_impl::virt_heisenberg;

  auto g_set = group::default_generating_set();

  geodesic_growth<group> growth(g_set);

  std::ofstream output("data.csv");

  output << "Length,Cumulative Growth" << std::endl;
  for (int i = 0; i <= 1'000; ++i) {
    auto [size, value] = growth.next();
    output << static_cast<int>(size) << ","
           << static_cast<unsigned long long>(value) << std::endl;
  }
}
