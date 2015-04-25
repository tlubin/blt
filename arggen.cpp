#include <climits>
#include <cstdio>
#include <cstdlib>
#include <random>

srand(seed);

static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";  

char genRandom() { return alphanum[rand() % stringLength]; }

void* get_arg(char* arg_type) {
  ints = malloc(sizeof(int)*5);
  uints = malloc(sizeof(int)*3);
  llongs = malloc(sizeof(int)*5);
  chars = malloc(sizeof(int)*5);
  strings = malloc(sizeof(char*)*3);
  
  ints[0] = rand() % INT_MAX;
  ints[1] = INT_MIN + rand() % INT_MAX;
  ints[2] = INT_MAX;
  ints[3] = INT_MIN;
  ints[4] = 0;
 
  uints[0] = rand() % UINT_MAX;
  uints[1] = UINT_MAX;
  uints[2] = 0;
 
  llongs[0] = rand() % LLONG_MAX;
  llongs[1] = LLONG_MIN + rand() % LLONG_MAX;
  llongs[2] = LLONG_MAX;
  llongs[3] = LLONG_MIN;
  llongs[4] = 0;

  chars[0] = rand() % CHAR_MAX;
  chars[1] = CHAR_MIN + rand() % CHAR_MAX;
  chars[2] = ' ';
  chars[3] = CHAR_MAX;
  chars[4] = CHAR_MIN;

  strings[0] = NULL;
  strings[1] = "";
  r = rand() % INT_MAX;
  strings[2] = malloc(sizeof(char) * r);
  for(unsigned i = 0; i < r; ++i)
      strings[2][i] = genRandom();
  
  void* ret;
  switch (arg_type) {
    case "int":
    case "long":
      ret = (void*)&ints[rand() % 5];
      break;
    case "uint":
      ret = (void*)&uints[rand() % 3];
      break;
    case "llong":
      ret = (void*)&llongs[rand() % 5];
      break;
    case "char":
      ret = (void*)&chars[rand() % 5];
      break;
    case "char*":
      ret = (void*)&strings[rand() % 3];
      break;
    default:
      break;
  }
  free(ints);
  free(uints);
  free(llongs);
  free(chars);
  free(strings[2]);
  free(strings);
  return ret;
}
