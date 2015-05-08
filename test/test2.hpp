struct hidden {
  unsigned foo;
};

class Test2 {
  public:
    Test2();
    void set(unsigned x);
    void inc();
    unsigned get();
};

namespace args {
  void* arg_inc(unsigned i);
  void* arg_get(unsigned i);
  void* arg_set(unsigned i);
}
