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
           * empty set (default constructor),  
           * range (std::set\<T\>(container.begin(), container.end()))  

## example of use

Function to print collections:
```cpp
template <class Iterable>
std::string str(const Iterable & coll){
    std::stringstream str;
    auto it = coll.begin();
    auto end = coll.end()-1;

    str<< "{";
    for(it; it != end; it++) str<<*it<<", ";
    str<<*(end+1)<<"}";

return str.str();
}
```

Create std::set from other iterable containers:  

```cpp
template <typename T, class Iterable>  
std::set<T> make_set_move(const Iterable & it){
    return std::set<T>(std::make_move_iterator(it.begin()), std::make_move_iterator(it.end()));
}

template <typename T, class Iterable>  
std::set<T> make_set_copy(const Iterable & it){
    return std::set<T>(it.begin(), it.end());
}
```

Get unique values from collections:  

```cpp
std::vector<int> vec = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9};
std::cout<<"'vec' = "<<str(vec)<<std::endl;

auto set_int = make_set_copy<int>(vec); // {0, 1, 2, 3, 4, 5, 6, 9}
std::cout<<"unique integers from 'vec' = "<<str(set_int)<<std::endl<<std::endl;

std::vector<std::string> strings = {"siala", "baba", "mak", "nie", "wiedziala", "jak", "zatem", "baba", "nie", "zasiala"};
std::cout<<"'strings' before 'make_set_move' ="<<str(strings)<<std::endl;

auto set_str = make_set_move<std::string>(strings);
std::cout<<"unique values from 'strings' = "<<str(set_str)<<std::endl;

std::cout<<"\n'strings' after make_set_move ="<<str(strings);
std::cout<<"  // the repeated words weren't added, so they weren't moved by 'std::move_iterator'"<<std::endl;
```  
Output:
```
'vec' = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9}
unique integers from 'vec' = {0, 1, 2, 3, 4, 5, 6, 9}

'strings' before 'make_set_move' ={siala, baba, mak, nie, wiedziala, jak, zatem, baba, nie, zasiala}
unique values from 'strings' = {baba, jak, mak, nie, siala, wiedziala, zasiala, zatem}

'strings' after 'make_set_move' ={, , , , , , , baba, nie, }  // the repeated words were not added, so they were not moved by 'std::move_iterator'
```
