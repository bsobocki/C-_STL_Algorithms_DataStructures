# std::set

## declaration

```cpp
template < class T,  
           class Compare = less<T>,  
           class Alloc = allocator<T> >
class set;

```  

## description

Container that store unique elements following specific order.

constructors:  
    - empty set (default constructor),  
    - range (std::set\<T\>(container.begin(), container.end()))  

## example of use

```cpp
template <typename T, class Iterable>  
std::set<T> make_set(const Iterable & it){
    return std::set<T>(std::make_move_iterator(it.begin()), std::make_move_iterator(it.end()));
}

std::vector<int> vec = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9};
auto set = make_set<int>(vec); // {0, 1, 2, 3, 4, 5, 6, 9}

```  
