#pragma once

#include <array>

#include "SafeInt.hpp"

namespace group_visualisation {
namespace group_impl {

class heisenberg {
 public:
  heisenberg();
  explicit heisenberg(int x, int y, int z);
  explicit heisenberg(SafeInt<int> x, SafeInt<int> y, SafeInt<int> z);

  static auto default_generating_set() {
    return std::array<heisenberg, 4>{heisenberg(1, 0, 0), heisenberg(-1, 0, 0),
                                     heisenberg(0, 1, 0), heisenberg(0, -1, 0)};
  }

  heisenberg inverse() const;

  heisenberg operator*(const heisenberg& other) const;

  int compare(const heisenberg& rhs) const;

  bool operator<(const heisenberg& rhs) const { return compare(rhs) < 0; }

  bool operator==(const heisenberg& rhs) const { return compare(rhs) == 0; }

  SafeInt<int> x() const;
  SafeInt<int> y() const;
  SafeInt<int> z() const;

 private:
  SafeInt<int> m_x, m_y, m_z;
};

};  // namespace group_impl
};  // namespace group_visualisation
