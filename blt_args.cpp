

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { -32, INT_MAX, INT_MAX, 0, 10, 2, INT_MAX, INT_MAX, INT_MAX, 1, -49, 41, 10, 0, -11, 0, 50, INT_MIN, INT_MIN, INT_MAX, 40, 15, INT_MIN, INT_MAX, -26, INT_MAX, INT_MAX, INT_MAX, -12, 4, -22, 41, -25, 27, INT_MAX, INT_MAX, INT_MAX, -44, 0, 42, 0, 0, 21, INT_MAX, 6, INT_MIN, 8, -43, 3, 0, INT_MIN, 21, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 46, INT_MIN, 19, 0, INT_MAX, INT_MIN, -17, INT_MAX, INT_MIN, 10, INT_MIN, INT_MIN, 0, 27, 0, 12, INT_MIN, INT_MAX, 0, INT_MIN, INT_MAX, 20, -29, 0, INT_MAX, INT_MAX, INT_MAX, 0, -29, 0, -33, 3, INT_MIN, INT_MIN, -21, -46, INT_MAX, 48, -4, 37, -16, INT_MIN, 38, INT_MIN, INT_MAX, INT_MAX, 38, -26, 38, INT_MIN, 0, 21, INT_MIN, 6, 0, -31, INT_MAX, 44, -39, 45, INT_MAX, INT_MAX, 6, INT_MIN, 17, INT_MIN, 41, 0, 2, 0, INT_MAX, -35, -41, INT_MAX, 0, INT_MAX, INT_MIN, 42, 0, 0, -11, INT_MAX, 3, 7, 24, 0, INT_MIN, INT_MAX, INT_MAX, -3, 0, INT_MIN, -48, INT_MAX, INT_MAX, 0, INT_MAX, 0, INT_MAX, 0, 11, 24, INT_MAX, -34, INT_MIN, 0, 1, 0, 50, -4, INT_MIN, INT_MIN, -47, INT_MAX, 35, 0, INT_MIN, 0, INT_MIN, INT_MAX, INT_MAX, -42, 36, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 18, INT_MAX, INT_MIN, -33, 13, INT_MAX, 0, -26, INT_MIN, -11, 0, INT_MIN, 0, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 39, INT_MIN, 48, INT_MAX, 3, INT_MIN, 32, -14, -40, INT_MAX, 16, 0, 28, INT_MAX, -11, INT_MAX, 41, INT_MAX, 0, INT_MIN, 14, 39, -48, INT_MIN, -47, 0, INT_MAX, INT_MAX, 11, 23, 0, INT_MAX, 0, INT_MAX, 17, INT_MAX, 27, -35, -24, 1, 26, INT_MIN, 0, INT_MIN, INT_MIN, INT_MAX, 0, 24, 7, -1, 5, INT_MIN, INT_MIN, INT_MIN, -3, 5, 0, 39, INT_MIN, 0, 7, -34, -50, -45, 2, INT_MIN, -33, -39, INT_MAX, -42, INT_MIN, INT_MIN, INT_MIN, 0, 0, -12, 31, -19, -42, INT_MIN, 0, -40, INT_MAX, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, 0, -28, 29, 0, 12, 0, INT_MIN, INT_MIN, 48, INT_MAX, -26, INT_MIN, 37, INT_MAX, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, -36, 42, 0, -27, 39, INT_MIN, -11, 0, 0, -23, 0, -26, 0, 21, INT_MIN, INT_MAX, INT_MAX, 21, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 33, -44, INT_MIN, INT_MIN, INT_MIN, -9, INT_MIN, -11, -38, -7, 31, -30, 14, INT_MIN, -3, INT_MAX, 15, 0, 35, 0, INT_MIN, 21, -8, 0, -34, 34, INT_MIN, 48, -39, INT_MIN, 0, 0, -35, -40, 0, -8, 0, INT_MIN, 0, INT_MIN, INT_MIN, 43, INT_MIN, 0, INT_MIN, INT_MAX, INT_MIN, 0, INT_MAX, 0, INT_MIN, INT_MAX, 0, 19, INT_MIN, -3, 0, -24, 0, INT_MAX, INT_MIN, -39, -13, INT_MAX, INT_MIN, INT_MAX, 3, 43, INT_MIN, 8, INT_MIN, INT_MIN, INT_MAX, 10, INT_MAX, 0, -4, 0, INT_MIN, -15, -36, INT_MAX, 0, 0, 40, INT_MIN, INT_MAX, 0, INT_MAX, 0, INT_MAX, -37, -24, INT_MIN, 22, -20, 0, 0, 0, -9, INT_MIN, INT_MAX, INT_MAX, -9, INT_MAX, 31, 27, INT_MAX, 16, -3, 46, 0, INT_MIN, -10, INT_MIN, -8, INT_MIN, -28, 2, INT_MAX, INT_MIN, 0, INT_MAX, 27, 5, 50, 0, INT_MIN, 36, 31, INT_MIN, -19, -41, INT_MAX, -21, -24, 25, INT_MIN, 29, INT_MIN, -35, 0, 47, INT_MAX, INT_MAX, 0, INT_MIN, INT_MAX, 0, 25, INT_MIN, 38, 46, 32, INT_MIN, INT_MAX, 0, -29, 38, 0, 0, -34, INT_MIN, -13, INT_MAX, INT_MIN, INT_MIN, INT_MIN, 0, -42, INT_MAX, 39, INT_MIN, INT_MIN, -7, 0, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, -23, INT_MAX, -14, INT_MIN, 0, 4, INT_MIN, 42, -32, -6, INT_MAX, INT_MAX, 34, 19, -12, 25, 11, 11, 7, 0, 30, INT_MAX, -20, 0, -9, INT_MIN, INT_MAX, 19, INT_MAX, INT_MIN, INT_MAX, 28, INT_MAX, 13, -6, -28, 0, INT_MAX, -13, 25, 23, INT_MIN, 0, -43, INT_MIN, INT_MIN, INT_MIN, 49, INT_MIN, 0, 0, INT_MIN, INT_MAX, 0, 49, INT_MIN, -46, 25, INT_MIN, INT_MIN, -29, 0, 0, -14, INT_MIN, -47, 0, 42, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 0, 0, 0, 25, -10, 11, INT_MIN, 3, INT_MAX, 0, INT_MIN, INT_MIN, INT_MIN, 0, INT_MAX, -21, INT_MIN, -12, 0, 0, 38, 0, INT_MIN, INT_MAX, INT_MAX, INT_MIN, INT_MAX, 7, -39, INT_MIN, INT_MAX, 0, INT_MIN, 0, -32, 49, INT_MAX, 48, -23, -36, INT_MIN, INT_MAX, INT_MIN, -39, 50, -13, 23, -26, INT_MIN, INT_MIN, 0, 0, INT_MIN, 10, INT_MAX, -31, 7, -44, 34, -33 };


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
