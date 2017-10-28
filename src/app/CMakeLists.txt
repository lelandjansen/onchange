project(app)

add_executable(onchange
  main.cc)
target_link_libraries(onchange
  gflags
  yaml-cpp)

