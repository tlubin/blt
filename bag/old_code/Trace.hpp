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
    Trace(unsigned,unsigned,unsigned);
    ~Trace();
    conc_node* trace1();
    conc_node* trace2();
    conc_node* random(unsigned, unsigned); // random conc-sym trace, uses random swarm for concrete
    void clean_mem(conc_node*);
  
  private:
    conc_node* create_conc_node(unsigned, struct funcs, unsigned);
    unsigned con_depth;
    unsigned sym_depth;
    unsigned num_funcs;
    funcs* sets;
    unsigned i_max;
};

#endif
