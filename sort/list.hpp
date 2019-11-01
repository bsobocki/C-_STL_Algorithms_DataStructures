#include <iostream>
#include <bits/stdc++.h>

#ifndef STL_STRUCTURES_LIST_HPP
#define STL_STRUCTURES_LIST_HPP

void testSortOnLists(){
    std::list<int> _list{4, 2, 6, 7, 4, 9, 0, 1, 3, 8};
    std::list<int> _list2 = _list;

    std::cout<<"\n### std::list<int>  |  list.sort() ###"<<std::endl;
    std::cout<<"list before sorting: ";
    for(auto i = _list.begin() ; i!= _list.end(); i++)
        std::cout<<" "<<*i;
    _list.sort();
    std::cout<<"\nlist after sorting: ";
    for(auto i = _list.begin() ; i!= _list.end(); i++)
        std::cout<<" "<<*i;
}

#endif //STL_STRUCTURES_LIST_HPP
