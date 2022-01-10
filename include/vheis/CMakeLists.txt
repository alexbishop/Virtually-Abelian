add_subdirectory(group-impl)

target_sources(vheis
  PUBLIC
    "${CMAKE_CURRENT_LIST_DIR}/geodesic-growth.hpp"
)
