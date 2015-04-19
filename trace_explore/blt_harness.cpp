#include <queue>
#include <cstdio>
#include <cassert>
using namespace std;

struct Func {
    char* old_f; // function name (XXX?) in old code
    char* new_f; // function name in refactored code
    int rank;   // "priority" of function in queue
};

// comparison of functions within priority queue
class CompareFunc {
public:
    bool operator()(Func& f1, Func& f2) { 
        if (f1.rank < f2.rank)
            return true;
        else 
            return false;
    }
};

// global queue
priority_queue<Func, vector<Func>, CompareFunc> fqueue;

// looks at the consequences of running f
void search() {
    // TODO
    // - need some way to look at the internal state of the program 
    //      in both sequences after functions run
    // - determine how to use heuristics (examine memory writes/reads?)
    // - add chosen functions with some determined rank to queue to analyze
}

int main() {
    void* ret1 = NULL; //XXX void* for now, unsure about type of return val 
    void* ret2 = NULL;
    
    while (!fqueue.empty()) {
        Func f = fqueue.top();
        fqueue.pop();
        ret1 = f.old_f();
        ret2 = f.new_f(); //XXX doesn't compile (not a real function, store function names?)
        if (ret1 != ret2)
            // program continues after print
            // could find effects of g on nonorthogonal funcs?
            printf("Not equivalent: %s\n", f.ptr1); 
        }
        search();
    }
}
