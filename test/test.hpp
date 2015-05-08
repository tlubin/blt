struct hidden {
  unsigned foo;
};

class Test {
  public:
    void set(struct hidden *h, unsigned x);
    void inc(struct hidden *h);
    unsigned get(struct hidden *h);
};

namespace args {
  void* arg_inc(unsigned i);
  void* arg_get(unsigned i);
  void* arg_set(unsigned i);
}
