#include "old_calc.h"
#include "new_calc.h"
#include "args.hpp"
#include <klee/klee.h>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <string>

// HELPERS ////////////////////////////////////////////////////////////////////

#define NTRACES 1

void failure() {
  assert(0);
}

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";  

char genRandom() { return alphanum[rand() % (sizeof(alphanum) - 1)]; }

enum string_code { eint, euint, ellong, efloat, echar, estring };

string_code hashit (std::string const& inString) {
    if (inString == "int" || inString == "long") return eint;
    if (inString == "unsigned") return euint;
    if (inString == "long long") return ellong;
    if (inString == "float") return efloat;
    if (inString == "char") return echar;
    if (inString == "char*") return estring;
}

void* get_arg(std::string const& arg_type) {
  void* ret;
  switch (hashit(arg_type)) {
    case eint: {
      int ints[4];
        ints[0] = INT_MIN + rand() /(RAND_MAX/(INT_MAX-INT_MIN));
        ints[1] = INT_MAX;
        ints[2] = INT_MIN;
        ints[3] = 0;
      int* ret = new int[1];
      ret[0] = ints[rand() / (RAND_MAX/4)];
      return (void*)ret;
    }
    case euint: {
      unsigned uints[3];
        uints[0] = rand() / (RAND_MAX/UINT_MAX + 1);
        uints[1] = UINT_MAX;
        uints[2] = 0;
      unsigned* ret = new unsigned[1];
      ret[0] = uints[rand() / (RAND_MAX/3)];
      return (void*) ret;
    }
    case ellong: {
      long long llongs[4];
        llongs[0] = LLONG_MIN + rand() /(RAND_MAX/(LLONG_MAX-LLONG_MIN));
        llongs[1] = LLONG_MAX;
        llongs[2] = LLONG_MIN;
        llongs[3] = 0;
      long long* ret = new long long[1];
      ret[0] = llongs[rand() / (RAND_MAX/4)];
      return (void*) ret;
    }
    case efloat: {
      float floats[3];
        floats[0] = FLT_MIN + rand() /(RAND_MAX/(FLT_MAX-FLT_MIN));
        floats[1] = FLT_MAX;
        floats[2] = FLT_MIN; floats[3] = 0;
      float* ret = new float[1];
      ret[0] = floats[rand() / (RAND_MAX/4)];
      return (void*) ret;
    }
    case echar: {
      char chars[4];
        chars[0] = CHAR_MIN + rand() /(RAND_MAX/(CHAR_MAX-CHAR_MIN));
        chars[1] = ' ';
        chars[2] = CHAR_MAX;
        chars[3] = CHAR_MIN;
      char* ret = new char[1];
      ret[0] = chars[rand() / (RAND_MAX/4)];
      return (void*) ret; 
    }
    case estring: {
      char* strings[3];
        strings[0] = NULL;
        strings[1] = (char*)"";
        unsigned r = rand() % CHAR_MAX;
        strings[2] = (char*) malloc(sizeof(char) * r);
        for(unsigned i = 0; i < r; ++i)
            strings[2][i] = genRandom();
        strings[2][r] = 0;
      char** ret = new char*[1];
      ret[0] = strings[rand() / (RAND_MAX/3)];
      return (void*) ret; 
    }
    default:
      printf("Error: Argument generator required\n");
      exit(1);
  }
}

// FUNCTION WRAPPERS /////////////////////////////////////////////////////////

void call_init_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->init_pressed();
  v2->init_pressed();
}

void call_zero_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->zero_pressed();
  v2->zero_pressed();
}

void call_one_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->one_pressed();
  v2->one_pressed();
}

void call_plus_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->plus_pressed();
  v2->plus_pressed();
}

void call_mult_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->mult_pressed();
  v2->mult_pressed();
}

void call_eval_pressed(old_calc* v1, new_calc* v2, bool is_sym) {
  
  v1->eval_pressed();
  v2->eval_pressed();
}


// TRACE WRAPPERS ////////////////////////////////////////////////////////////

void trace0() {
  old_calc* v1 = new old_calc();
  new_calc* v2 = new new_calc();

  for (int i = 0; i < 1; ++i) {
    unsigned n0;
    n0 = rand() % 1;
    switch (n0) {
      case 0:
        call_init_pressed(v1, v2, false);
        break;
    }
  }

  for (int i = 0; i < 200; ++i) {
    unsigned n1;
    n1 = rand() % 4;
    switch (n1) {
      case 0:
        call_zero_pressed(v1, v2, false);
        break;
      case 1:
        call_one_pressed(v1, v2, false);
        break;
      case 2:
        call_plus_pressed(v1, v2, false);
        break;
      case 3:
        call_mult_pressed(v1, v2, false);
        break;
    }
  }

  for (int i = 0; i < 2; ++i) {
    unsigned n2;
    klee_make_symbolic(&n2, sizeof(n2), "n2");
    klee_assume(n2 < 4);
    switch (n2) {
      case 0:
        call_zero_pressed(v1, v2, true);
        break;
      case 1:
        call_one_pressed(v1, v2, true);
        break;
      case 2:
        call_plus_pressed(v1, v2, true);
        break;
      case 3:
        call_mult_pressed(v1, v2, true);
        break;
    }
  }

  for (int i = 0; i < 1; ++i) {
    unsigned n3;
    n3 = rand() % 1;
    switch (n3) {
      case 0:
        call_eval_pressed(v1, v2, false);
        break;
    }
  }

}


// MAIN //////////////////////////////////////////////////////////////////////

int main(int argc, const char* argv[]) {
  if (argc != 2)
    return 1;
  unsigned n = atoi(argv[1]);
  if (n >= NTRACES)
    return 1;

  switch(n) {
    case 0: trace0(); break;
  }
}

