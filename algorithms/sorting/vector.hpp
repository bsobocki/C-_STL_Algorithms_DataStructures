#include <iostream>
#include <vector>
#include <algorithm>
#include "show_arr_vec.hpp"

#ifndef STL_STRUCTURES_VECTOR_HPP
#define STL_STRUCTURES_VECTOR_HPP

auto parity(const int & x, const int & y) -> bool {
    return x%2==0 ;
}

void testSortOnVectors(){
    std::vector<int> vec1 = {4, 3, 2, 0, 7, 5, 1, 10, 13, 12, 90, -3};
    auto vec2 = vec1;
    auto vec3 = vec1;

    std::cout<<"\n### std::vector<int> ###\n";

    std::cout<<"Vector before sorting: "; show(vec1);
    
    std::sort(vec1.begin(),vec1.end(),parity);
    std::cout<<"Vector after sorting by number parity: "; show(vec1);

    auto oddFirst = [](const int & y, const int & x) -> bool { return x%2==0; };
    std::sort(vec2.begin(),vec2.end(),oddFirst);
    std::cout<<"Vector after sorting by odd numbers: "; show(vec2);
    
    std::sort(vec3.begin(),vec3.end(),std::less<>());
    std::sort(vec3.begin(),vec3.end(),
              [](const int & x, const int & y) -> bool {
                  return x%2==0;
              });
    std::cout<<"Array sorting by number parity with sorting both parts: "; show(vec3);
}

#endif //STL_STRUCTURES_VECTOR_HPP
