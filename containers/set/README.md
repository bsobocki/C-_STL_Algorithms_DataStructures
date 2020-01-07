# std::set

The content of the document is based on informations from [cppreference.com](https://en.cppreference.com/w/cpp/container/set) and [cplusplus.com](http://www.cplusplus.com/reference/set/set/).

## [Table Of Contents](#table-of-contents)
   * **[Declaration](#declaration)**
   * **[Description](#description)**
   * **[Example Of Use](#example-of-use)**
   * **[Iterators](#iterators)**
   * **[Operations](#operations)**
      * **[find](#find)**
      * **[count](#count)**
      * **[lower_bound](#lower_bound)**
      * **[upper_bound](#upper_bound)**
      * **[equal_range](#equal_range)**
   * **[Modifiers](#modifiers)**
      * **[insert](#insert)**
      * **[erase](#erase)**
      * **[swap](#swap)**
      * **[clear](#clear)**
      * **[emplace](#emplace)**
      * **[emplace_hint](#emplace_hint)**
   * **[Capacity](#capacity)**
      * **[empty](#empty)**
      * **[size](#size)**
      * **[max_size](#max_size)**
   * **[Observes](#observes)**
      * **[key_comp](#key_comp)**
      * **[value_comp](#value_comp)**
   * **[Allocator](#allocator)**
      * **[get_allocator](#get_allocator)**

## Declaration

```cpp
template < class T,  
           class Compare = less<T>,  
           class Alloc = allocator<T> >
class set;

```  

## Description

Container that store unique elements following specific order.

Constructors:  
   * *empty set* (default constructor)  
   * *range* (std::set\<T\>(container.begin(), container.end()))  

## Example Of Use

Function to print collections:
```cpp
template <class Iterable>
std::string str(const Iterable & coll){
    std::stringstream str;
    auto it = coll.begin();
    auto end = coll.end()-1;

    str<< "{";
    for ( it; it != end; it++ ) str << *it << ", ";
    str << *it << "}"; 

    return str.str();
}
```

Create std::set from other iterable containers:  

```cpp
template <typename T, class Iterable>  
std::set<T> make_set_move(const Iterable & it){
    return std::set<T>(std::make_move_iterator( it.begin() ), std::make_move_iterator( t.end() ) );
}

template <typename T, class Iterable>  
std::set<T> make_set_copy(const Iterable & it){
    return std::set<T>(it.begin(), it.end() );
}
```

Get unique values from collections:  

```cpp
std::vector<int> vec = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9};
std::cout << "'vec' = " << str(vec) << std::endl;

auto set_int = make_set_copy<int>(vec); // {0, 1, 2, 3, 4, 5, 6, 9}
std::cout << "unique integers from 'vec' = " << str(set_int) << std::endl << std::endl;

std::vector<std::string> strings = {"siala", "baba", "mak", "nie", "wiedziala", "jak", "zatem", "baba", "nie", "zasiala"};
std::cout << "'strings' before 'make_set_move' = " << str(strings) << std::endl;

auto set_str = make_set_move<std::string>(strings);
std::cout << "unique values from 'strings' = " << str(set_str) << std::endl;

std::cout << "\n'strings' after 'make_set_move' = " << str(strings);
std::cout << "  // the repeated words weren't added, so they weren't moved by 'std::move_iterator'" << std::endl;
```  
Output:
```
'vec' = {1, 1, 2, 2, 3, 4, 5, 6, 5, 9, 0, 2, 1, 3, 9}
unique integers from 'vec' = {0, 1, 2, 3, 4, 5, 6, 9}

'strings' before 'make_set_move' = {siala, baba, mak, nie, wiedziala, jak, zatem, baba, nie, zasiala}
unique values from 'strings' = {baba, jak, mak, nie, siala, wiedziala, zasiala, zatem}

'strings' after 'make_set_move' = {, , , , , , , baba, nie, }  // the repeated words weren't added, so they weren't moved by 'std::move_iterator'

```

## Iterators

## Operations
### find
### count
### lower_bound
### upper_bound
### equal_range
## Modifiers
### insert
### erase
### swap
### clear
### emplace
### emplace_hint
## Capacity
### empty
### size
### max_size
## Observes
### key_comp
### value_comp
## Allocator
### get_allocator
