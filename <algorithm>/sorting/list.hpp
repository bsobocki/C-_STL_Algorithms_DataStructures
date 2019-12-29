#include <iostream>
#include <bits/stdc++.h>

#ifndef STL_STRUCTURES_LIST_HPP
#define STL_STRUCTURES_LIST_HPP

struct TRUE{
    bool operator() (const int & x, const int & y){
        return true;
    }
};

void showList(const std::list<int> & list){
    std::cout<<"{";
        for(const int & i : list)
            std::cout<<" "<<i;
        std::cout<<" }";
}

void testSortOnLists(){
    std::list<int> list{4, 2, 6, 7, 4, 9, 0, 1, 3, 8};
    std::list<int> list2 = list;

    std::cout<<"\n### std::list<int>  |  list.sort() ###"<<std::endl;
    std::cout<<"list before sorting: "; showList(list);

    list.sort();
    std::cout<<"\nlist after sorting: "; showList(list);

    list2.sort(TRUE());
    std::cout<<"\nreverse list using the functor 'TRUE': "; showList(list2);

}

#endif //STL_STRUCTURES_LIST_HPP
