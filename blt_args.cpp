

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { INT_MIN, 11, 0, INT_MIN, -38, INT_MIN, INT_MAX, 8, -42, INT_MAX, -27, 0, INT_MIN, 49, 0, 46, -15, 46, 2, 27, 0, 0, INT_MAX, 0, INT_MIN, INT_MAX, INT_MIN, 18, 0, INT_MIN, 0, INT_MAX, INT_MAX, INT_MAX, 23, -22, -25, 0, 0, INT_MAX, -46, -22, INT_MIN, 27, INT_MAX, 0, INT_MIN, 0, 0, INT_MAX, -15, 45, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 34, 35, 35, INT_MIN, INT_MAX, -13, 49, -32, INT_MIN, INT_MIN, INT_MAX, 42, -18, 0, 10, 0, INT_MIN, INT_MAX, -20, INT_MAX, INT_MIN, 35, -17, INT_MIN, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, 0, -20, INT_MAX, 0, INT_MIN, -47, 33, INT_MAX, 46, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, -9, 0, 0, INT_MAX, 0, -15, 0, -48, 0, 0, -30, INT_MIN, INT_MAX, -47, 23, 34, -46, 0, -43, 41, INT_MAX, 50, INT_MAX, 12, 36, INT_MIN, 0, INT_MIN, 23, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MAX, -25, 8, 0, 0, -24, 0, -7, INT_MIN, 48, 0, INT_MAX, -17, 0, 0, INT_MAX, INT_MAX, -28, INT_MAX, 18, -2, 30, INT_MAX, 32, -33, -33, INT_MAX, 0, -4, -26, INT_MIN, INT_MIN, INT_MAX, 40, 41, INT_MAX, 48, -7, INT_MIN, INT_MIN, 5, INT_MIN, INT_MIN, 0, INT_MAX, 47, INT_MAX, 33, INT_MAX, -22, INT_MIN, 11, 16, INT_MAX, -30, INT_MAX, -38, 48, -5, -31, INT_MIN, -6, 18, INT_MAX, -32, 0, -19, INT_MAX, INT_MIN, INT_MAX, 11, -17, -27, 0, INT_MIN, INT_MIN, -26, INT_MAX, INT_MAX, INT_MAX, -17, 0, -34, 46, 39, 10, INT_MAX, INT_MIN, INT_MIN, INT_MAX, 0, INT_MIN, 0, -31, -21, INT_MIN, -26, INT_MIN, 14, INT_MIN, 16, INT_MIN, 28, 49, INT_MAX, INT_MAX, -12, 31, 19, 0, -32, 46, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MIN, -36, INT_MIN, 0, 0, -42, -2, INT_MIN, 35, INT_MAX, 0, INT_MAX, 0, 38, -2, -32, 14, -38, INT_MAX, 37, 18, 0, 0, INT_MAX, INT_MIN, 10, INT_MAX, INT_MIN, INT_MIN, INT_MIN, -12, INT_MIN, 41, INT_MAX, 2, INT_MIN, 0, INT_MIN, -22, 13, INT_MAX, 42, INT_MIN, INT_MAX, 0, INT_MIN, INT_MIN, 0, 0, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, 15, 23, 37, 0, 9, -33, INT_MIN, 15, INT_MAX, 0, 25, -3, 42, INT_MAX, 0, INT_MIN, INT_MIN, 0, 4, INT_MIN, 0, -30, 0, INT_MIN, INT_MAX, -26, 0, 15, INT_MAX, INT_MIN, 8, 18, 49, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -45, 34, -28, 0, INT_MIN, 0, INT_MIN, INT_MIN, 0, 47, -10, INT_MAX, 0, 10, INT_MIN, -15, 0, 48, INT_MIN, 0, INT_MIN, -2, 2, INT_MIN, 45, 42, INT_MIN, INT_MIN, 0, -18, -18, -3, 0, INT_MAX, 35, -7, 0, -6, 0, 49, 0, -37, -46, 0, -12, INT_MAX, 16, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -41, INT_MIN, -15, -8, INT_MIN, 34, -43, INT_MIN, 0 };


static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";  

static char genRandom() { return alphanum[rand() % (sizeof(alphanum) - 1)]; }

static string_code hashit (std::string const& inString) {
    if (inString == "int" || inString == "long") return eint;
    if (inString == "unsigned") return euint;
    if (inString == "long long") return ellong;
    if (inString == "float") return efloat;
    if (inString == "char") return echar;
    if (inString == "char*") return estring;
}

void* blt_args::get_arg(std::string const& arg_type) {
  switch (hashit(arg_type)) {
    case eint:
      return (void*) &ints[intCnt++];
    default:
      printf("Error: Argument generator required\n");
      exit(1);
  }
}

/*
void* blt_args::get_arg(std::string const& arg_type) {
  void* ret;
  switch (hashit(arg_type)) {
    case eint: {
      int ints[5];
        ints[0] = rand() % 50;
        ints[1] = -1*(rand() % 50);
        ints[2] = INT_MAX;
	// TL Note: For now so when -2147483648 is put in replay file
	// the compiler doesn't yell
        ints[3] = INT_MIN+1;
        ints[4] = 0;
      int* ret = new int[1];
      // TL for now
      ret[0] = ints[2];
      //      ret[0] = ints[rand() / (RAND_MAX/5)];

      return (void*)ret;
    }
    case euint: {
      unsigned uints[3];
        uints[0] = rand() % UINT_MAX;
        uints[1] = UINT_MAX;
        uints[2] = 0;
      unsigned* ret = new unsigned[1];
      ret[0] = uints[rand() / (RAND_MAX/3)];
      return (void*) ret;
    }
    case ellong: {
      long long llongs[5];
        llongs[0] = rand() % LLONG_MAX;
        llongs[1] = -1*(rand() % LLONG_MAX);
        llongs[2] = LLONG_MAX;
        llongs[3] = LLONG_MIN;
        llongs[4] = 0;
      long long* ret = new long long[1];
      ret[0] = llongs[rand() / (RAND_MAX/5)];
      return (void*) ret;
    }
    case efloat: {
      float floats[5];
        floats[0] = static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(FLT_MAX)));
        floats[1] = FLT_MIN + static_cast <float> (rand()) * FLT_MAX;
        floats[2] = FLT_MAX;
        floats[3] = FLT_MIN; 
        floats[4] = 0;
      float* ret = new float[1];
      ret[0] = floats[rand() / (RAND_MAX/5)];
      return (void*) ret;
    }
    case echar: {
      char chars[5];
        chars[0] = rand() % CHAR_MAX;
        chars[1] = -1*(rand() % CHAR_MAX);
        chars[2] = ' ';
        chars[3] = CHAR_MAX;
        chars[4] = CHAR_MIN;
      char* ret = new char[1];
      ret[0] = chars[rand() / (RAND_MAX/5)];
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
*/
