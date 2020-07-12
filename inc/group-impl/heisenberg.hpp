#pragma once
#ifndef b2f9aa55_Heisenberg_hpp
#define b2f9aa55_Heisenberg_hpp

#include <array>

namespace group_visualisation {
namespace group_impl {

class heisenberg {
public:
  heisenberg();
  heisenberg(int x, int y, int z);

  static auto default_generating_set() {
    return std::array<heisenberg,4>{
      heisenberg( 1, 0,0),
      heisenberg(-1, 0,0),
      heisenberg( 0, 1,0),
      heisenberg( 0,-1,0)
    };
  }

  heisenberg inverse() const;

  heisenberg compose(const heisenberg& other) const;

  int compare_to (const heisenberg& rhs) const;

  bool operator < (const heisenberg& rhs) const {
    return compare_to(rhs) < 0;
  }

  bool operator == (const heisenberg& rhs) const {
    return compare_to(rhs) == 0;
  }

  int x() const;
  int y() const;
  int z() const;

private:
  int _x, _y, _z;
};

}; // namespace group_impl {
}; // namespace group_visualisation {

#endif

