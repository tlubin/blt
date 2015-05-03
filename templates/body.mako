% for header in headers:
#include "${header}"
% endfor
#include <klee/klee.h>
#include <cassert>
#include <cstdlib>

// HELPERS ////////////////////////////////////////////////////////////////////

#define NTRACES ${ntraces}

void failure() {
  assert(0);
}

// FUNCTION WRAPPERS /////////////////////////////////////////////////////////

${funcs_str}
// TRACE WRAPPERS ////////////////////////////////////////////////////////////

${traces_str}
// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, const char* argv[]) {
  srand(${seed});
  if (argc != 2)
    return 1;
  unsigned n = atoi(argv[1]);
  if (n >= NTRACES)
    return 1;

  switch(n) {
  % for i in range(ntraces):
    case ${i}: trace${i}(); break;
  % endfor
  }
}
