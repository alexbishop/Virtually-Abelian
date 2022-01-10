#pragma once

#include <array>

#include "SafeInt.hpp"

namespace vheis {
namespace group_impl {

class virt_heisenberg {
 public:
  virt_heisenberg();
  explicit virt_heisenberg(SafeInt<int> x,
                           SafeInt<int> y,
                           SafeInt<int> z,
                           bool t);
  explicit virt_heisenberg(int x, int y, int z, bool t);

  static auto default_generating_set() {
    return std::array<virt_heisenberg, 3>{
        virt_heisenberg(1, 0, 0, false),
        virt_heisenberg(-1, 0, 0, false),
        virt_heisenberg(0, 0, 0, true),
    };
  }

  virt_heisenberg inverse() const;

  int compare(const virt_heisenberg& rhs) const;

  virt_heisenberg operator*(const virt_heisenberg& rhs) const;
  virt_heisenberg& operator*=(const virt_heisenberg& rhs);

  bool operator<(const virt_heisenberg& rhs) const;
  bool operator>(const virt_heisenberg& rhs) const;
  bool operator<=(const virt_heisenberg& rhs) const;
  bool operator>=(const virt_heisenberg& rhs) const;
  bool operator==(const virt_heisenberg& rhs) const;
  bool operator!=(const virt_heisenberg& rhs) const;

  SafeInt<int> x() const;
  SafeInt<int> y() const;
  SafeInt<int> z() const;
  bool t() const;

 private:
  SafeInt<int> m_x, m_y, m_z;
  bool m_t;
};

};  // namespace group_impl
};  // namespace vheis
