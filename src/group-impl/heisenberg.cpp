#include <tuple>

#include <vheis/group-impl/heisenberg.hpp>

namespace vheis {
namespace group_impl {

heisenberg::heisenberg() : heisenberg(0, 0, 0) {}

heisenberg::heisenberg(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}

heisenberg::heisenberg(SafeInt<int> x, SafeInt<int> y, SafeInt<int> z)
    : m_x(x), m_y(y), m_z(z) {}

heisenberg heisenberg::inverse() const {
  SafeInt<int> inv_x = -m_x;
  SafeInt<int> inv_y = -m_y;
  SafeInt<int> inv_z = m_x * m_y - m_z;

  return heisenberg(inv_x, inv_y, inv_z);
}

heisenberg heisenberg::operator*(const heisenberg& other) const {
  SafeInt<int> compose_x = x() + other.x();
  SafeInt<int> compose_y = y() + other.y();
  SafeInt<int> compose_z = z() + other.z() + x() * other.y();

  return heisenberg(compose_x, compose_y, compose_z);
}

int heisenberg::compare(const heisenberg& rhs) const {
  const auto t_lhs = std::make_tuple(x(), y(), z());
  const auto t_rhs = std::make_tuple(rhs.x(), rhs.y(), rhs.z());

  if (t_lhs < t_rhs) {
    return -1;
  }

  if (t_lhs > t_rhs) {
    return 1;
  }

  return 0;
}

SafeInt<int> heisenberg::x() const {
  return m_x;
}

SafeInt<int> heisenberg::y() const {
  return m_y;
}

SafeInt<int> heisenberg::z() const {
  return m_z;
}

};  // namespace group_impl
};  // namespace vheis
