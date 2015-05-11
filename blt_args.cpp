

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { 0, 6, 40, 0, -21, INT_MIN, 44, 10, INT_MAX, 0, INT_MIN, INT_MIN, 0, 2, 0, 4, -10, 40, INT_MAX, -22, INT_MIN, INT_MAX, -32, 0, 0, INT_MAX, 0, -35, -8, 0, 0, -21, 0, INT_MAX, -32, INT_MAX, 0, INT_MAX, -38, 0, 0, INT_MAX, 50, -32, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 6, INT_MAX, 49, 0, 26, INT_MAX, 0, 0, INT_MAX, INT_MIN, INT_MIN, -38, 37, 0, 24, INT_MAX, 18, 27, 0, 0, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 1, INT_MAX, INT_MAX, 10, 37, INT_MIN, 0, 30, -40, INT_MAX, 0, INT_MAX, -2, -40, INT_MIN, -50, 0, INT_MAX, 0, -41, INT_MAX, 30, INT_MAX, 29, INT_MIN, INT_MIN, 27, INT_MAX, INT_MIN, INT_MIN, 0, INT_MIN, -39, 31, 0, INT_MAX, INT_MIN, 0, -22, INT_MAX, INT_MIN, INT_MIN, 0, INT_MAX, 19, -46, 0, INT_MAX, 0, INT_MAX, 0, INT_MAX, -21, 0, INT_MAX, 0, INT_MAX, INT_MIN, INT_MIN, 5, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, -4, INT_MIN, -48, INT_MAX, -26, -7, INT_MAX, INT_MIN, 0, 0, 0, INT_MIN, INT_MIN, 0, INT_MAX, INT_MAX, 13, INT_MAX, INT_MIN, INT_MAX, 45, -7, 0, -38, INT_MIN, 16, INT_MIN, -33, 0, 34, INT_MAX, 7, 8, 0, INT_MAX, 0, 7, INT_MAX, INT_MIN, 0, -37, 0, 13, -24, 7, INT_MAX, -30, 0, -5, 23, INT_MIN, 0, INT_MIN, 48, 43, -37, -31, 0, INT_MIN, 10, 0, INT_MAX, INT_MAX, INT_MAX, -26, INT_MIN, 44, 40, -16, 0, INT_MIN, -42, INT_MAX, INT_MAX, INT_MIN, 36, INT_MAX, 1, -4, -18, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, 0, 0, -16, INT_MIN, 26, INT_MIN, -31, INT_MIN, 0, INT_MAX, INT_MIN, -50, -16, INT_MAX, 44, 32, 36, 0, -38, -26, 0, INT_MAX, -50, INT_MIN, INT_MAX, 10, 47, INT_MAX, INT_MIN, 1, 0, 0, 0, -38, -24, 0, 0, -28, INT_MAX, INT_MIN, INT_MAX, 16, -25, 0, 47, INT_MAX, 17, INT_MAX, 46, INT_MAX, 8, INT_MIN, 0, 0, -23, INT_MAX, INT_MAX, 25, 11, -21, INT_MIN, INT_MAX, INT_MIN, -43, INT_MAX, INT_MIN, INT_MIN, -29, INT_MIN, INT_MAX, -11, INT_MIN, INT_MAX, 35, INT_MIN, 46, INT_MIN, -19, -19, 29, INT_MIN, INT_MAX, INT_MIN, 0, 0, INT_MIN, -1, -14, INT_MIN, INT_MAX, 0, 9, 0, 11, -14, 41, INT_MIN, 39, -46, 18, INT_MAX, INT_MIN, INT_MIN, 0, 32, 34, INT_MIN, 2, 50, -37, INT_MAX, -20, 18, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN, 8, INT_MIN, -16, INT_MAX, INT_MIN, INT_MIN, INT_MAX, -2, INT_MAX, -30, INT_MIN, 37, 4, -32, 27, INT_MAX, 0, INT_MIN, INT_MIN, -44, -2, -6, 15, 38, INT_MIN, INT_MIN, -11, INT_MAX, -24, -49, -10, 41, INT_MAX, 0, INT_MIN, INT_MIN, INT_MAX, 0, -20, 0, 0, 0, INT_MIN, INT_MIN, 7, 50, 8, 45, 0, -26, 5, INT_MIN, INT_MIN, -29, -50, 23, 14, 0, INT_MIN, 24, -37, INT_MAX, INT_MIN, -34, INT_MAX, 0, 0, INT_MAX, -35, 0, INT_MIN, 0, 43, INT_MIN, 30, INT_MIN, -47, -14, 0, 0, 17, -18, INT_MIN, INT_MAX, -19, INT_MIN, 0, 0, INT_MIN, INT_MAX, 24, 0, INT_MIN, 0, -31, INT_MAX, INT_MAX, 0, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, -16, INT_MAX, INT_MIN, 0, INT_MIN, INT_MIN, 0, -37, INT_MAX, -40, -47, -20, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 15, 0, 0, -7, -7, 0, INT_MIN, INT_MAX, -9, -10, INT_MIN, 3, 26, INT_MAX, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 21, -31, INT_MAX, INT_MIN, INT_MAX, 23, INT_MAX, -46, INT_MAX, INT_MAX, -32, INT_MAX, 0, INT_MIN, 0, -19, 42, INT_MIN, INT_MIN, 0, -40, INT_MIN, 23, INT_MIN, INT_MAX, 0, INT_MIN, -8, 0, INT_MIN, -9, INT_MAX, INT_MAX, 48, 0, 0, 16, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 0, -40, 40, 0, INT_MIN, INT_MIN, 0, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, 31, INT_MIN, 12, 0, -37, 43, INT_MAX, -45, INT_MAX, INT_MAX, -36, -18, -36, INT_MAX, INT_MAX, INT_MAX, INT_MIN, -44, -15, INT_MAX, -11, INT_MAX, -44 };


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
