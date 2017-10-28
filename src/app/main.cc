#include "main.h"

#include <iostream>

#include "gflags/gflags.h"

DEFINE_bool(option, false, "some cli option");

namespace onchange {

}  // namespace onchange

auto main(const int argc, const char** argv) -> int {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  std::cout << (FLAG_option ? "true" : "false") << std::endl;
}

