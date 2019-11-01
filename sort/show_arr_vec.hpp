#ifndef STL_STRUCTURES_SHOW_ARR_VEC_HPP
#define STL_STRUCTURES_SHOW_ARR_VEC_HPP

void show(const int * const data, const int & size){
    std::cout<<" { ";
    for(unsigned int i=0; i<size-1; i++){
        std::cout<<data[i]<<", ";
    }
    std::cout<<data[size-1]<<" }\n";
}

template<class T>
void show(const T & container){
    show(container.data(), container.size());
}

#endif //STL_STRUCTURES_SHOW_ARR_VEC_HPP
