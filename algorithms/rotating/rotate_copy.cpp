#include "../tools.hpp"

int main(){
    int arr[10] = {0, 1 ,2 ,3 ,4 ,5 ,6 , 7, 8, 9};
    int * tab = new int [10];

    std::rotate_copy(arr, arr+3, arr+10, tab); // rotate that the arr+3 will be the first element

    std::cout << " arr: "; show(arr, 10);
    std::cout << "values rotated and copied from arr: "; show(tab, 10);
    std::cout << "From now, the fourth element is the first element of the array." << std::endl;

    return 0;
}