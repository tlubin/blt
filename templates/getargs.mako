#include <cstdlib>
#include <climits>
#include <cfloat>
#include <string>
#include <sstream>
#include <iostream>

// GENERATORS ////////////////////////////////////////////////////////////////////

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
        ints[0] = 5; //INT_MIN + rand() % INT_MAX;
        ints[1] = INT_MAX;
        ints[2] = INT_MIN;
        ints[3] = 0;
      int* ret = new int[1];
      ret[0] = ints[rand() / (RAND_MAX/4)];
      return (void*)ret;
    }
    case euint: {
      unsigned uints[3];
        uints[0] = 4; //rand() % UINT_MAX;
        uints[1] = UINT_MAX;
        uints[2] = 0;
      unsigned* ret = new unsigned[1];
      ret[0] = uints[rand() / (RAND_MAX/3)];
      return (void*) ret;
    }
    case ellong: {
      long long llongs[4];
        llongs[0] = 5; //LLONG_MIN + rand() % LLONG_MAX;
        llongs[1] = LLONG_MAX;
        llongs[2] = LLONG_MIN;
        llongs[3] = 0;
      long long* ret = new long long[1];
      ret[0] = llongs[rand() / (RAND_MAX/4)];
      return (void*) ret;
    }
    case efloat: {
      float floats[3];
      // TODO: need to think about these functions...
      // changed to * instead of % to suppress error
        floats[0] = 0.5; //FLT_MIN + rand() * FLT_MAX;
        floats[1] = FLT_MAX;
        floats[2] = FLT_MIN; floats[3] = 0;
      float* ret = new float[1];
      ret[0] = floats[rand() / (RAND_MAX/4)];
      return (void*) ret;
    }
    case echar: {
      char chars[4];
        chars[0] = 42; //CHAR_MIN + rand() % CHAR_MAX;
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

% for f in funcs:
void call_${f['name']}(std::stringstream* ss) {
  (*ss) << "${f['name']}";
  % if len(f['args']) > 0:
  % for typ in f['args']:
  ${typ} arg${loop.index};
  % endfor
  % for typ in f['args']:
  % if 'arg_gen' in f.keys():	
  (*ss) << ",GEN";
  % else: 
  arg${loop.index} = *(${typ}*)(get_arg("${typ}"));
  (*ss) << "," << arg${loop.index};
  %endif
  % endfor
  % endif
  (*ss) << "\n";
}
% endfor

int main(int argc, const char* argv[]) {
    std::stringstream* ss = new std::stringstream();
    <%
      nodes = [x for x in trace if x['symbolic_trace'] == 'false' and x['symbolic_args'] == 'false']
    %>
    % for node in nodes:
    % for f in node['calls']:
    call_${f}(ss);  
    % endfor
    % endfor

    std::cout << (*ss).str();
}
