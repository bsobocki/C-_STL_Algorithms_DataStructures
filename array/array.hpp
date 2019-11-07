#ifndef ARRAY_ARRAY_HPP
#define ARRAY_ARRAY_HPP

#include <array>
#include <iostream>

// function (1)
template <typename Iter>
void show(Iter arr){
    for(auto x : arr){
        std::cout<<x<<" ";
    }
}

// function (2)
template <class T, std::size_t SIZE>
void show(std::array<T, SIZE> arr){
    std::cout<<"{ ";
    for(auto & x : arr){
        std::cout<<x<<" ";
    }
    std::cout<<"}";
}

void initialize_test(){
    std::cout<<"\nINITIALIZE ARRAYS TEST\n"<<std::endl;
    std::array<int, 8> arr = {6, 3, 1, 8, 5, 9, 0, 2};
    std::array<int, 8> arr2{6, 1, 5, 0, 2};
    std::array<int, 8> arr3{{3, 8, 9}};
    auto arr4 = {4, 5, 6};
    std::cout<<"array 1 : ";
    show(arr); // function (2)
    std::cout<<"\narray 2 : ";
    show(arr2); // function (2)
    std::cout<<"\narray 3 : ";
    show(arr3); // function (2)
    std::cout<<"\narray 4 : ";
    show(arr4); // function (1)
    std::cout<<std::endl;
}

void get_value_test(){
    std::cout<<"\nGET VALUE TEST\n"<<std::endl;
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout<<"arr.at(7) = "<<arr.at(7)<<std::endl;
    std::cout<<"arr[7] = "<<arr[7]<<std::endl;
    std::cout<<"get<7> = "<<std::get<7>(arr)<<std::endl;
}
#endif //ARRAY_ARRAY_HPP
