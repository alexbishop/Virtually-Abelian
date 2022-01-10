add_subdirectory(group-impl)

target_sources(virtually-heisenberg
  PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
)
