#include "../../tools.hpp"

int main(){
    int arr[10] = {0, 1 ,2 ,3 ,4 ,5 ,6 , 7, 8, 9};
    int * tab = new int [10];

    std::reverse_copy(arr, arr+10, tab);

    std::cout << " arr: "; show(arr, 10);
    std::cout << "values copied from arr by reverse_copy: "; show(tab, 10);

    return 0;
}