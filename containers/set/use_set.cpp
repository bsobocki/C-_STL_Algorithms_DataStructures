#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T, class Iterable> 
std::set<T> make_set(const Iterable & it){
    return std::set<T>(std::make_move_iterator(it.begin()), std::make_move_iterator(it.end()));
}

template <class Iterable>
void print_collection(const Iterable & it){
  std::cout<<"{ ";
  for(auto elem : it)
    std::cout<<elem<<", ";
  std::cout<<"}";
}

int main(){
  std::vector<int> vec = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9};
  auto set = make_set<int>(vec);

  std::cout<<"vector = "; print_collection(vec);
  std::cout<<std::endl;
  std::cout<<"set = "; print_collection(set);
  return 0;
}