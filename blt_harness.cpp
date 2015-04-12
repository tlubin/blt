#include <queue>
#include <cstdio>
#include <cassert>
using namespace std;

struct Func {
    void* ptr1; // func ptr to call in first interleaving (no g)
    void* ptr2; // func ptr to call in second interleaving (with g)
    int rank;   // "priority" of function in queue
    int is_g;   // marks whether is the orthogonal function
};

// comparison of functions within priority queue
class CompareFunc {
public:
    bool operator()(Func& f1, Func& f2)
    {
        if (f1.rank < f2.rank)
            return true;
        else 
            return false;
    }
};

// global queue
priority_queue<Func, vector<Func>, CompareFunc> queue;

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
    
    while (!queue.empty()) {
        f = queue.pop();
        ret2 = &f.ptr2();
        
        // only compare results when executing non-orthogonal func
        if (!f.is_g) {
            ret1 = &f.ptr1();
            if (ret1 != ret2)
                cout << str << &f.ptr1 << end1; // right now, program continues after print
                                                // could find effects of g on nonorthogonal funcs?
        }
        search();
    }
}
