# Geodesic Growth of a Virtually Heisenberg Group

Computes the geodesic growth function of a particular virtually Heisenberg group.

## Requirements

This small project is written in C++17 and required CMake to build.

## SafeInt

To ensure that the output of this program can be trusted, we make use of a modifier version of the [SafeInt](https://github.com/dcleblanc/SafeInt) library. You will find this under `lib/SafeInt`.

The following modifications have been made to `SafeInt.hpp`:
* All overloaded cast operations now have the modifier `explicit`. For example `explicit operator int() const`. This prevents an accidental cast from `SafeInt<int>` to `int`, for example.
* The `SafeInt` class now has a default copy assignment operator.
