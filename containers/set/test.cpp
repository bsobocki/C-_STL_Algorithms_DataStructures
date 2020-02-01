#include <iostream>
#include <set>

using namespace std;

class A {
    int key;
    int val;

    public:
    A() = default;
    A(int k, int v) : key(k), val(v) {}

    int get_key() const { return key; }
    int get_val() const { return val; }
    void set_key(const int key) { this->key = key; }
    void set_val(const int val) { this->val = val; }
    string to_string() { return "{ key: " + std::to_string(key) + ", val: "; }
};

struct B  : public A {
    int b;
    B(int key,int val, int bb) : A(key,val), b(bb) {}
};

bool operator<(const A& lhs, const A& rhs)
{
      return lhs.get_key() < rhs.get_key();
}


set<A> bar;

int main()
{
    A testA;
    testA.set_key(0);
    
    B testB(0,1,2);
    testB.set_key(30);

    bar.insert(testA);
    bar.insert(testB);

    for(auto a : bar) { std::cout<<a.get_key()<<std::endl; }
}