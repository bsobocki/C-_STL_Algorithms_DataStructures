#include "../tools.hpp"

int main(){
    std::cout << " ---- copy_if ----" << std::endl;

    std::vector<int> v1 = {-42, 24, 24, -123, -155, 100, 1};
    std::vector<int> bigger_than_zero;

    std::copy_if(v1.begin(), v1.end(), std::back_inserter(bigger_than_zero), 
        [](const int & x) {
            return x>0;
        });

    print("vector: ", v1);
    print("numbers from vector bigger than 0: ", bigger_than_zero);
}