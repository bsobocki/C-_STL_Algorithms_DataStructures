#include "../tools.hpp"

int main(){
    int arr[10] = {0, 1 ,2 ,3 ,4 ,5 ,6 , 7, 8, 9};

    std::cout << " arr: "; show(arr, 10);
    
                                     //  v <----------------- v      
    std::rotate(arr, arr+7, arr+10); // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} ---> {7, 8, 9, 0, 1, 2, 3, 4, 5, 6}

    std::cout << "arr with rotate: "; show(arr, 10);

    return 0;
}