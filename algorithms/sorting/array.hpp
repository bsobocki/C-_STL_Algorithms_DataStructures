#include <iostream>
#include <array>
#include <algorithm>
#include "../tools.hpp"

#ifndef STL_STRUCTURES_ARRAY_HPP
#define STL_STRUCTURES_ARRAY_HPP

//template<std::size_t SIZE>
//void show(std::array<int, SIZE>& array){
//    show(array.data(), array.size());
//}

void testSortOnArrays(){
    int arr [] = { 4, 6, 3, 8, 0, 5, 8, 0, 2, 1, 8, 6};
    int arr2 [] = { 4, 6, 3, 8, 0, 5, 8, 0, 2, 1, 8, 6};
    int * arr2_ptr = arr2;

    int array_size = sizeof(arr)/sizeof(arr[0]);

    std::array<int, 8> array = {3, 4, 1, 9, 0 ,5 ,2, 8};
    auto array2 = array;

    std::cout<<"\n### int [] / int * ###"<<std::endl;

    std::cout<<"Array before sorting: "; show(arr, array_size);
    
    std::sort(arr,arr + array_size);
    std::cout<<"Array after sorting without giving function to compare: "; show(arr, array_size);
    
    std::sort(arr2_ptr,arr2_ptr + array_size,std::less<>());
    std::cout<<"Array after sorting with 'std::less<>()': "; show(arr2_ptr, array_size);

    std::cout<<"\n### std::array<int, SIZE> ###"<<std::endl;

    std::cout<<"Array before sorting: "; show(array);

    std::sort(array.begin(),array.end(),std::greater<>());
    std::cout<<"Array after descending sorting: "; show(array);

    std::sort(array2.begin(),array2.end(),std::less<>());
    std::cout<<"Array after ascending sorting: "; show(array2);
}

#endif //STL_STRUCTURES_ARRAY_HPP
