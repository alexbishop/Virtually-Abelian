#include <tuple>

#include "group-impl/heisenberg.hpp"

namespace group_visualisation {
namespace group_impl {

heisenberg::heisenberg(): heisenberg(0,0,0) {}

heisenberg::heisenberg(int x, int y, int z): _x(x), _y(y), _z(z) {}

heisenberg heisenberg::inverse() const {
  int inv_x = -x();
  int inv_y = -y();
  int inv_z = x()*y() - z();

  return {inv_x, inv_y, inv_z};
}

heisenberg heisenberg::compose(const heisenberg& other) const {
  int compose_x = x() + other.x();
  int compose_y = y() + other.y();
  int compose_z = z() + other.z() + x() * other.y();

  return {compose_x, compose_y, compose_z};
}

int heisenberg::compare_to (const heisenberg& rhs) const {
  const auto t_lhs = std::make_tuple(x(),y(),z());
  const auto t_rhs = std::make_tuple(rhs.x(),rhs.y(),rhs.z());

  if (t_lhs < t_rhs) {
    return -1;
  }

  if (t_lhs > t_rhs) {
    return 1;
  }

  return 0;
}

int heisenberg::x() const {
  return _x;
}

int heisenberg::y() const {
  return _y;
}

int heisenberg::z() const {
  return _z;
}

}; // namespace group_impl {
}; // namespace group_visualisation {
