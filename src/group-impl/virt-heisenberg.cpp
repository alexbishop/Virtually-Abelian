#include <algorithm>
#include <tuple>

#include <vheis/group-impl/virt-heisenberg.hpp>

namespace vheis {
namespace group_impl {

virt_heisenberg::virt_heisenberg() : virt_heisenberg(0, 0, 0, false) {}

virt_heisenberg::virt_heisenberg(SafeInt<int> x,
                                 SafeInt<int> y,
                                 SafeInt<int> z,
                                 bool t)
    : m_x(x), m_y(y), m_z(z), m_t(t) {}

virt_heisenberg::virt_heisenberg(int x, int y, int z, bool t)
    : m_x(x), m_y(y), m_z(z), m_t(t) {}

virt_heisenberg virt_heisenberg::inverse() const {
  SafeInt<int> inv_x = -m_x;
  SafeInt<int> inv_y = -m_y;
  SafeInt<int> inv_z = m_x * m_y - m_z;

  bool inv_t = m_t;
  if (inv_t) {
    std::swap(inv_x, inv_y);
    inv_z = -inv_z;
  }

  return virt_heisenberg(inv_x, inv_y, inv_z, inv_t);
}

virt_heisenberg virt_heisenberg::operator*(const virt_heisenberg& other) const {
  SafeInt<int> rhs_x = other.m_x;
  SafeInt<int> rhs_y = other.m_y;
  SafeInt<int> rhs_z = other.m_z;
  bool rhs_t = other.m_t;

  if (m_t) {
    std::swap(rhs_x, rhs_y);
    rhs_z = -rhs_z;
  }

  SafeInt<int> compose_x = m_x + rhs_x;
  SafeInt<int> compose_y = m_y + rhs_y;
  SafeInt<int> compose_z = m_z + rhs_z + m_x * rhs_y;
  bool compose_t = (m_t != rhs_t);  // logical exclusive or

  return virt_heisenberg(compose_x, compose_y, compose_z, compose_t);
}

virt_heisenberg& virt_heisenberg::operator*=(const virt_heisenberg& other) {
  *this = (*this * other);
  return *this;
}

int virt_heisenberg::compare(const virt_heisenberg& rhs) const {
  const auto t_lhs = std::make_tuple(m_x, m_y, m_z, m_t);
  const auto t_rhs = std::make_tuple(rhs.m_x, rhs.m_y, rhs.m_z, rhs.m_t);

  if (t_lhs < t_rhs) {
    return -1;
  }

  if (t_lhs > t_rhs) {
    return 1;
  }

  return 0;
}

SafeInt<int> virt_heisenberg::x() const {
  return m_x;
}

SafeInt<int> virt_heisenberg::y() const {
  return m_y;
}

SafeInt<int> virt_heisenberg::z() const {
  return m_z;
}

bool virt_heisenberg::t() const {
  return m_t;
}

bool virt_heisenberg::operator<(const virt_heisenberg& rhs) const {
  return compare(rhs) < 0;
}

bool virt_heisenberg::operator>(const virt_heisenberg& rhs) const {
  return compare(rhs) > 0;
}

bool virt_heisenberg::operator<=(const virt_heisenberg& rhs) const {
  return compare(rhs) <= 0;
}

bool virt_heisenberg::operator>=(const virt_heisenberg& rhs) const {
  return compare(rhs) >= 0;
}

bool virt_heisenberg::operator==(const virt_heisenberg& rhs) const {
  return compare(rhs) == 0;
}

bool virt_heisenberg::operator!=(const virt_heisenberg& rhs) const {
  return compare(rhs) != 0;
}

};  // namespace group_impl
};  // namespace vheis
