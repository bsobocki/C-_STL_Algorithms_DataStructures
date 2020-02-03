#include <iostream>
#include <algorithm>

// prints collection with indexing operator
template <typename T>
void print(T * arr, size_t size){
    std::cout<<"{ ";    
    for(int i=0; i<size-1; i++) std::cout<<arr[i]<<", ";
    if (size>0) std::cout<< arr[size-1];
    std::cout<<"}\n";
} 

template <typename T>
void print_next_permutations(T * arr, size_t size){
  int count = 0;
  std::cout<<"\n\n---\n\nnext permutations of collection = "; print<int>(arr, size); 
  std::cout<<"printing until next_permutation returns true (lexicographically ascending order): \n\n";
  while ( std::next_permutation(arr,arr+size) ) { 
    print<T>(arr, size); 
    count++; 
  } 

  std::cout <<" There are "<< count <<" permutations.  "<<"The next permutation (with returned value = false): ";   
  print<T>(arr, size);
}

template <typename T>
void print_prev_permutations(T * arr, size_t size){
  int count = 0;
  std::cout<<"\n\n---\n\nnext permutations of collection = "; print<int>(arr, size); 
  std::cout<<"printing until prev_permutation returns true (lexicographically descending order): \n\n";
  while ( std::prev_permutation(arr,arr+size) ) { 
    print<T>(arr, size); 
    count++; 
  } 

  std::cout <<" There are "<< count <<" permutations.  "<<"The next permutation (with returned value = false): ";   
  print<T>(arr, size);
}

int main () {
  int ints1[] = {2,3,1,5,2};
  int ints2[] = {2,3,1,5,2};
  int sorted_ints1[] = {1,2,2,3,5};
  int sorted_ints2[] = {1,2,2,3,5};
  size_t size = sizeof(ints1)/sizeof(int);
  
  print_next_permutations<int>(ints1, size);
  print_prev_permutations<int>(ints2, size);

  print_next_permutations<int>(sorted_ints1, size);
  print_prev_permutations<int>(sorted_ints2, size);

  return 0;
}
