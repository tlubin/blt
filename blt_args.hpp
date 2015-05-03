#ifndef _BLT_ARG_HPP
#define _BLT_ARG_HPP
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <string>

enum string_code { eint, euint, ellong, efloat, echar, estring };

namespace blt_args {
  void* get_arg(std::string const& arg_type);
}

#endif
