#include <climits>
#include <cfloat>
#include <cstdio>
#include <cstdlib>
#include <string>

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
      break;
  }
}

/*
int main() {
  int seed = 383;
  srand(seed);
  printf("int: %d\n", *((int*)get_arg("int")));
  printf("int: %d\n", *((int*)get_arg("int")));
  printf("int: %d\n", *((int*)get_arg("int")));
  printf("uint: %u\n", *((unsigned*)get_arg("unsigned")));
  printf("uint: %u\n", *((unsigned*)get_arg("unsigned")));
  printf("uint: %u\n", *((unsigned*)get_arg("unsigned")));
  printf("llong: %lld\n", *(long long*)get_arg("long long"));
  printf("llong: %lld\n", *(long long*)get_arg("long long"));
  printf("llong: %lld\n", *(long long*)get_arg("long long"));
  printf("float: %f\n", *(float*)get_arg("float"));
  printf("float: %f\n", *(float*)get_arg("float"));
  printf("float: %f\n", *(float*)get_arg("float"));
  printf("char: %c\n", *(char*)get_arg("char"));
  printf("char: %c\n", *(char*)get_arg("char"));
  printf("char: %c\n", *(char*)get_arg("char"));
  printf("string: %s\n", *(char**)get_arg("char*"));
  printf("string: %s\n", *(char**)get_arg("char*"));
  printf("string: %s\n", *(char**)get_arg("char*"));
}
*/
