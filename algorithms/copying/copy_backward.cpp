#include "../tools.hpp"

int main(){
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    std::vector<int> v (vec.size());

    std::copy_backward(vec.begin(), vec.begin()+7, v.end());

    print("vector: ", vec);
    print("vector with copied 7 values using std::copy_backwards: ", v);

    std::copy_backward(vec.begin()+7, vec.begin()+10, v.begin()+3);
    print("vector with copied 7 values using std::copy_backwards on vector.begin()+3 : ", v);
}