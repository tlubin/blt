#include "LilIntBag.hpp"
#include "DynamicIntBag.hpp"
#include "args.hpp"
#include <klee/klee.h>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <string>

// HELPERS ////////////////////////////////////////////////////////////////////

#define NTRACES 2

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

void call_member(LilIntBag* v1, DynamicIntBag* v2, bool is_sym) {
  int arg0;
  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0), "arg0");
  } else {
    arg0 = *(int*)args::member_arg(0);
  }
  
  bool r1 = v1->member(arg0);
  bool r2 = v2->member(arg0);
  if (r1 != r2)
    failure();
}

void call_insert(LilIntBag* v1, DynamicIntBag* v2, bool is_sym) {
  int arg0;
  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0), "arg0");
  } else {
    arg0 = *(int*)args::insert_arg(0);
  }
  
  v1->insert(arg0);
  v2->insert(arg0);
}

void call_remove(LilIntBag* v1, DynamicIntBag* v2, bool is_sym) {
  int arg0;
  if (is_sym) {
    klee_make_symbolic(&arg0, sizeof(arg0), "arg0");
  } else {
    arg0 = *(int*)args::remove_arg(0);
  }
  
  v1->remove(arg0);
  v2->remove(arg0);
}

void call_get_size(LilIntBag* v1, DynamicIntBag* v2, bool is_sym) {
  
  unsigned r1 = v1->get_size();
  unsigned r2 = v2->get_size();
  if (r1 != r2)
    failure();
}


// TRACE WRAPPERS ////////////////////////////////////////////////////////////

void trace0() {
  LilIntBag* v1 = new LilIntBag();
  DynamicIntBag* v2 = new DynamicIntBag();

  for (int i = 0; i < 20; ++i) {
    unsigned n0;
    n0 = rand() % 1;
    switch (n0) {
      case 0:
        call_insert(v1, v2, false);
        break;
    }
  }

  for (int i = 0; i < 2; ++i) {
    unsigned n1;
    klee_make_symbolic(&n1, sizeof(n1), "n1");
    klee_assume(n1 < 4);
    switch (n1) {
      case 0:
        call_member(v1, v2, true);
        break;
      case 1:
        call_get_size(v1, v2, true);
        break;
      case 2:
        call_insert(v1, v2, true);
        break;
      case 3:
        call_remove(v1, v2, true);
        break;
    }
  }

}

void trace1() {
  LilIntBag* v1 = new LilIntBag();
  DynamicIntBag* v2 = new DynamicIntBag();

  for (int i = 0; i < 20; ++i) {
    unsigned n0;
    n0 = rand() % 2;
    switch (n0) {
      case 0:
        call_insert(v1, v2, false);
        break;
      case 1:
        call_get_size(v1, v2, false);
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
    case 1: trace1(); break;
  }
}

