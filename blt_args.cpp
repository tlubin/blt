

#include "/home/tslilyai/blt/blt_args.hpp"
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <string>

unsigned intCnt = 0;
int ints [] = { 42, INT_MIN, INT_MIN, INT_MAX, INT_MAX, -47, 0, 0, 21, 38, INT_MAX, INT_MAX, -13, 0, INT_MIN, INT_MIN, INT_MIN, INT_MIN, -20, INT_MIN, INT_MIN, -1, 0, INT_MAX, -12, INT_MAX, 0, INT_MAX, -36, -22, 0, -47, 3, -43, 44, 45, 0, -15, INT_MAX, INT_MAX, 0, 18, INT_MIN, -42, INT_MIN, INT_MAX, INT_MIN, 37, INT_MAX, INT_MAX, -28, 0, 31, 27, INT_MAX, 0, INT_MIN, 31, INT_MIN, INT_MAX, -23, INT_MAX, INT_MAX, INT_MAX, 9, 0, 0, -21, INT_MAX, -40, -21, -33, 12, 0, 31, -29, INT_MAX, 0, 0, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 27, 0, 42, 0, INT_MAX, 20, INT_MAX, 0, INT_MIN, 0, INT_MAX, INT_MIN, -21, -47, -31, INT_MIN, INT_MIN, 14, 0, 14, -7, INT_MAX, INT_MIN, 10, INT_MIN, 0, INT_MAX, INT_MAX, 10, 0, INT_MAX, 0, INT_MAX, INT_MAX, -37, 0, INT_MAX, 12, 0, 23, -17, INT_MIN, INT_MAX, INT_MIN, -29, 13, -12, INT_MIN, 24, INT_MAX, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 20, 0, -48, INT_MIN, INT_MIN, -1, 44, 38, INT_MIN, -8, 0, INT_MIN, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MAX, INT_MIN, 38, -25, INT_MAX, INT_MIN, -30, 0, INT_MIN, 39, 0, INT_MIN, 44, -25, -6, INT_MIN, -46, 0, 0, 34, 0, INT_MIN, INT_MIN, 33, INT_MIN, -2, -29, 3, 0, INT_MAX, INT_MIN, 43, -50, -29, INT_MIN, 0, -15, -19, INT_MAX, 0, 50, -13, 0, INT_MIN, 13, 0, INT_MIN, INT_MIN, INT_MIN, -26, INT_MIN, 0, 0, INT_MIN, INT_MAX, 0, 50, INT_MIN, INT_MAX, INT_MIN, INT_MAX, 38, 16, INT_MIN, 0, 12, INT_MAX, INT_MIN, 0, -15, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, 11, 3, -47, INT_MAX, -5, 0, INT_MAX, 0, -23, 0, 3, -6, 15, 0, 0, -10, INT_MAX, INT_MAX, -48, INT_MAX, 0, 21, -20, -22, 25, -41, 0, INT_MIN, INT_MIN, INT_MAX, 28, 27, INT_MIN, 9, -20, INT_MIN, INT_MIN, 0, INT_MAX, INT_MIN, INT_MAX, -29, INT_MAX, 0, INT_MIN, INT_MAX, -31, 0, 0, INT_MIN, 10, INT_MIN, -25, 0, INT_MAX, 0, INT_MIN, -12, INT_MAX, INT_MIN, INT_MIN, -19, 0, 0, 0, -3, 28, INT_MAX, 0, INT_MIN, -40, 0, 3, INT_MIN, 17, INT_MIN, 37, -32, INT_MIN, 24, INT_MAX, 14, INT_MIN, INT_MIN, -39, 17, INT_MAX, INT_MIN, 0, 23, 48, INT_MIN, 28, 0, -17, 0, 26, 48, -24, INT_MIN, INT_MIN, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 9, 1, -17, INT_MAX, INT_MIN, INT_MIN, 48, 37, 17, INT_MAX, -42, INT_MAX, INT_MAX, INT_MAX, 24, INT_MIN, -30, INT_MIN, INT_MAX, -1, -27, 0, INT_MAX, 32, INT_MAX, 25, 0, 15, INT_MIN, INT_MIN, INT_MIN, INT_MAX, INT_MIN, 29, 0, 0, INT_MIN, 45, INT_MIN, 5, INT_MAX, -6, -48, 1, 0, 0, INT_MIN, 0, 0, INT_MIN, 50, INT_MAX, INT_MIN, INT_MAX, 35, INT_MAX, INT_MAX, 0, INT_MAX, 48, 0, INT_MIN, 0, 0, 18, -25, 0, INT_MIN, -49, -3, -28, 41, -31, INT_MIN, 0, 0, INT_MIN, INT_MAX, INT_MAX, -37, INT_MIN, INT_MIN, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, INT_MAX, INT_MIN, 31, INT_MAX, 0, 24, INT_MIN, INT_MAX, INT_MIN, 0, 35, -10, 4, INT_MIN, INT_MIN, -13, INT_MIN, 4, INT_MAX, 0, INT_MIN, 0, 0, INT_MAX, INT_MIN, 0, INT_MAX, INT_MIN, -23, 34, 36, 1, INT_MIN, -20, -5, INT_MAX, 0, INT_MAX, 43, 0, INT_MAX, -21, 0, -6, -15, INT_MAX, 0, 0, INT_MIN, INT_MAX, INT_MAX, INT_MAX, 0, 0, INT_MIN, -29, INT_MAX, INT_MIN, -37, 0, -26, 0, 0, INT_MIN, INT_MAX, INT_MIN, -22, INT_MIN, INT_MAX, 3, INT_MIN, 8, INT_MIN, 23, INT_MAX, -12, 23, INT_MIN, 0, -6, 0, INT_MAX, 0, INT_MAX, -39, 0, 15, INT_MAX, 35, -4, -49, INT_MAX, -14, 0, 9, -19, 12, -4, 8, 23, INT_MAX, INT_MIN, INT_MAX, 5, INT_MAX, -25, 0, INT_MAX, INT_MAX, 0, INT_MAX, INT_MIN, INT_MAX, INT_MIN, INT_MIN, INT_MIN, INT_MAX, 24, 7, INT_MIN, 0, INT_MIN, INT_MAX, -17, INT_MAX, 9, 50, INT_MIN, 41, 21, 0, -26, 0, 0, 0, 49, INT_MAX, 42, 42, -46, INT_MAX, 47, INT_MAX, -42, 29, INT_MIN, 0, -31, INT_MIN, 33, INT_MIN, 0, INT_MAX, 0, INT_MAX, -3, INT_MAX, 0, INT_MIN, 23, -39, INT_MIN, INT_MAX, INT_MIN, 0, INT_MIN, INT_MAX, 0, 0, INT_MAX };


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
