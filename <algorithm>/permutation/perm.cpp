#include <iostream>
#include <algorithm>

// prints collection with overloaded indexing operator
template <typename T>
void print(T * arr, size_t size){
    std::cout<<"{ ";    
    for(int i=0; i<size-1; i++) std::cout<<arr[i]<<", ";
    if (size>0) std::cout<< arr[size-1];
    std::cout<<"}\n";
} 

template <typename T>
void print_permutations(T * arr, size_t size){
  int count = 0;
  std::cout<<"\n\n---\n\nnext permutations of collection = "; print<int>(arr, size); 
  std::cout<<"printing until next_permutation returns true (lexicographically ascending order): \n\n";
  do { 
    print<T>(arr, size); 
    count++; 
  } while ( std::next_permutation(arr,arr+size) );

  std::cout <<" There are "<< count <<" permutations.  "<<"The next permutation (with returned value = false): ";   
  print<T>(arr, size);
}

int main () {
  int ints[] = {2,1,3,5};
  int sorted_ints[] = {1,2,3,5};
  size_t size = sizeof(ints)/sizeof(int);

  std::cout << "'std::next_permutation' returns true, if the next determined permutation  is lexicographically higher and false, if the next permutation is lexicographically lower or equal.\n ";
  
  print_permutations<int>(ints, size);
  print_permutations<int>(sorted_ints, size);

  return 0;
}
