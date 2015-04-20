#ifndef _xTRACE_HPP_
#define _xTRACE_HPP_

struct funcs {
  int sz;   // number of functions in swarm
  int* fs;  // switch numbers of functions in swarm
};

struct conc_node {
  unsigned isSym;     // symbolic or concrete?
  struct funcs funcs; // subset of functions to run
  unsigned length;    // number of functions to call
  conc_node *next;    // next node
};

class Trace {
  public:
    Trace(int, int);
    ~Trace() {};
    conc_node* trace1();
    conc_node* trace2();
    void clean_mem(conc_node* trace);
  
  private:
    conc_node* create_conc_node(unsigned isSym, struct funcs funcs, unsigned length);
    int con_depth;
    int sym_depth;
};

#endif
