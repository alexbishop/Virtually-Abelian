#include <tuple>
#include <algorithm>

#include "group-impl/virt-heisenberg.hpp"

namespace group_visualisation {
namespace group_impl {

virt_heisenberg::virt_heisenberg(): virt_heisenberg(0,0,0,false) {}

virt_heisenberg::virt_heisenberg(int x, int y, int z, bool t): _x(x), _y(y), _z(z), _t(t) {}

virt_heisenberg virt_heisenberg::inverse() const {

  int inv_x = -x();
  int inv_y = -y();
  int inv_z = x()*y() - z();

  bool inv_t = t();
  if (inv_t) {
    std::swap(inv_x,inv_y);
    inv_z = -inv_z;
  }

  return {inv_x, inv_y, inv_z, inv_t};
}

virt_heisenberg virt_heisenberg::compose(const virt_heisenberg& other) const {

  int rhs_x = other.x();
  int rhs_y = other.y();
  int rhs_z = other.z();
  bool rhs_t = other.t();

  // commute t() to the end
  if (t()) {
    std::swap(rhs_x,rhs_y);
    rhs_z = -rhs_z;
  }

  int compose_x = x() + rhs_x;
  int compose_y = y() + rhs_y;
  int compose_z = z() + rhs_z + x()*rhs_y;
  bool compose_t = (t() != rhs_t); // logical exclusive or

  return {compose_x, compose_y, compose_z, compose_t};
}

int virt_heisenberg::compare_to (const virt_heisenberg& rhs) const {
  const auto t_lhs = std::make_tuple(x(),y(),z(),t());
  const auto t_rhs = std::make_tuple(rhs.x(),rhs.y(),rhs.z(),rhs.t());

  if (t_lhs < t_rhs) {
    return -1;
  }

  if (t_lhs > t_rhs) {
    return 1;
  }

  return 0;
}

int virt_heisenberg::x() const {
  return _x;
}

int virt_heisenberg::y() const {
  return _y;
}

int virt_heisenberg::z() const {
  return _z;
}

bool virt_heisenberg::t() const {
  return _t;
}

}; // namespace group_impl {
}; // namespace group_visualisation {
