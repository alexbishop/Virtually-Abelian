#pragma once
#ifndef b2f9aa55_VirtuallyHeisenberg_hpp
#define b2f9aa55_VirtuallyHeisenberg_hpp

#include <array>

namespace group_visualisation {
namespace group_impl {

class virt_heisenberg {
public:
  virt_heisenberg();
  virt_heisenberg(int x, int y, int z, bool t);

  static auto default_generating_set() {
    return std::array<virt_heisenberg,3>{
      virt_heisenberg( 1,0,0,false),
      virt_heisenberg(-1,0,0,false),
      virt_heisenberg( 0,0,0,true),
    };
  }

  virt_heisenberg inverse() const;

  virt_heisenberg compose(const virt_heisenberg& other) const;

  int compare_to (const virt_heisenberg& rhs) const;

  bool operator < (const virt_heisenberg& rhs) const {
    return compare_to(rhs) < 0;
  }

  bool operator == (const virt_heisenberg& rhs) const {
    return compare_to(rhs) == 0;
  }

  int x() const;
  int y() const;
  int z() const;
  bool t() const;

private:
  bool _t;
  int _x, _y, _z;
};

}; // namespace group_impl {
}; // namespace group_visualisation {

#endif
