# std::array  
Description of the std::array container with its methods.  
It is based on the content of the websites:  [cppreference - array](https://en.cppreference.com/w/cpp/container/array) and [cplusplus - array](http://www.cplusplus.com/reference/array/array/)

---  
  
# [Table of contents](#table-of-contents)  
  * [Description](#description)
  * [Definition](#definition)  
  * [Member Functions](#member-functions)  
    * [Some Constructors](#some-constructors)
    * [Copying assignment](#copying-assignment)
    * [Get element](#get-element)
      * [at](#at)  
      * [indexing operator](#indexing-operator)  
      * [front](#front)
      * [back](#back)
    * [data](#data)
    * [Iterators](#iterators)
    * [Capacity](#capacity)
      * [empty](#empty)
      * [size and max_size](#size-and-max_size)
    * [Operations](#operations)
      * [fill](#fill)
      * [swap](#swap)
  * [Non-Member Functions](#non-member-functions)
    * [lexicographically compare](#lexicographically-compare)
    * [get](#get)
    * [swap](#swap)
    * [to_array](#to_array)
  * [Generator](#generator)
    * [make_array](#make_array)
  
---  

# Description  

*\(since C++ 11)*  
A STL container represents arrays with constant size.   
From ***`cppreference.com`*** we know, that unlike a C-style array, it doesn't decay to T* automatically. 

You can use it like normal C-style array (overloaded indexing operator "\[ \]"), with some features, like access to the size of the container, by calling mathod "size()"

# Definition
in header: ***\<array>***  
   
```cpp
template <class T, std::size_t N> struct array;
```
# Member Functions  
  
## Some Constructors

   * *empty*
      ```cpp
      std::array<T, 7> my_arr; // {0, 0, 0, 0, 0, 0, 0}
      ```
   * *initializer_list*
      ```cpp
      std::array<int, 10> your_arr{ {3, 2, 1, 4, 5} }; // {3, 2, 1, 4, 5, 0, 0, 0, 0, 0}
      
      std::array<int, 4> her_arr { 1, 3, 4, 5};
      ```
   * *copy constructor*
      ```cpp
      std::array<int, 5> our_array ( your_array );
      ```
      
## Copying Assignment

   * *copying assignment*
      ```cpp
      std::array<int, 8> their_array = his_array;
      
      std::array<int, 8> his_arr = {6, 3, 1, 8, 5, 9, 0, 2};
      ```
  
## Get element
  
### at  

```cpp 
reference at(size_type pos);
```  

Returns a reference to the element on the position **`pos`** *with bounds checking*.  
**`if !(pos < size())`** throws exception: *`std::out_of_range`*   

**Complexity:** O(1)

  
### indexing operator

```cpp 
reference operator[](size_type pos);
```  

Returns a reference to the element on position **`pos`** *without bounds checking*.  

**Complexity:** O(1)

  
### front

```cpp
reference front();
```

Returns reference to the first element.   

**Example:**
```cpp
  std::array<int, 7> arr = {1, 2, 3, 4, 5, 6, 7}; // declaration of the new std::array object

  int front = arr.front(); 
  // eguals to the
  int begin = *arr.begin();

  std::cout<<"Is \"front\" equal to \"begin\" ?\nAnswer: "<< (front == begin ? "Yes" : "No") <<std::endl;
```
**Output:**  
```
Is "front" equal to "begin" ?  
Yes
```

**Complexity:** O(1)

  
### back

```cpp
reference back();
```

Returns reference to the last element.   

**Example:**
```cpp
    std::array<int, 7> arr = {1, 2, 3, 4, 5, 6, 7}; // declaration of the new std::array object

    int back = arr.back(); 
    // eguals to the
    int end = *(arr.end()-1);

    std::cout<<"Is \"back\" equal to \"end\" ?\nAnswer: "<< (back == end ? "Yes" : "No") << std::endl;
    std::cout<<"\"end\" ="<<end;
```
**Output:**  
```
  Is "back" equal to "end" ?  
  Yes
  "end" = 7
```

**Complexity:** O(1)


## data  
  
```cpp
T* data() noexcept;
```  

Returns pointer to the underlying array serving as element storage.  
If array is not empty, `.data()` returns pointer compares equal to the address of the first element.  

**Complexity:** O(1)


## Iterators

Iterators are the objects which are used to point at the element address in the container memory.

for example you can use it to display elements:  
```cpp
  std::array<int, 7> arr = {1, 2, 3, 4, 5, 6, 7};
  std::array<int, 7>::iterator it = arr.begin(); // iterator pointing at the first element of 'arr'
  for(it; it != arr.end(); it++) 
    std::cout<<*it<<std::endl;
```  

Output:  
```
  1
  2
  3
  4
  5
  6
  7
```  

std::array has member functions that returns iterators: `begin()`, `end()`, `rbegin()`, `rend()`, `cbegin()`, `cend()`, `crbegin()`, `crend()`.  

For more informations about *Iterators* check ["Get iterators"](https://github.com/bsobocki/Cpp_STL_Algorithms_Containers/blob/master/iterators/README.md#get-iterator) in [README.md](https://github.com/bsobocki/Cpp_STL_Algorithms_Containers/blob/master/iterators/README.md) in the folder named ["iterators"](https://github.com/bsobocki/Cpp_STL_Algorithms_Containers/tree/master/iterators).

## Capacity

### empty

Returns `true` if the array is empty and `false` otherwise.

Example:
```cpp
std::array<int, 10> arr{ {3, 2, 1, 4, 5} }; // {3, 2, 1, 4, 5, 0, 0, 0, 0, 0}
std::cout<< "Is " << str(arr) << " empty?" << std::endl;
std::cout<< std::boolalpha << arr.empty() << std::endl;

std::array<int, 10> arr2; // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
std::cout<< "Is " << str(arr2) << " empty?" << std::endl;
std::cout<< std::boolalpha << arr2.empty() << std::endl;

std::array<int, 0> ar;
std::cout<< "Is " << str(ar) << " empty?" << std::endl;
std::cout<< std::boolalpha << ar.empty() << std::endl;
```
Output:
```
Is {3, 2, 1, 4, 5, 0, 0, 0, 0, 0} empty?
false
Is {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} empty?
false
Is {} empty?
true
```

### size and max_size

Returns size of element in the array.
In this container type number of elements is constant, so the value returned by `max_size()` is equal to the value returned by `size()`; 

```cpp
std::array<int, 10> arr{}; // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
std::cout<<"How much elements does " << str(arr) << " have?" <<std::endl;
std::cout<< arr.size() <<std::endl;

std::array<int, 10> arr2; // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
std::cout<<"How much elements does " << str(arr2) << " have?" <<std::endl;
std::cout<< arr2.max_size() <<std::endl;
```

Output:
```
How much elements does {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} have?
10
How much elements does {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} have?
10
```

## Operations
### fill 

Assigns the value given as argument to each element;

```cpp
std::array<int, 10> arr{}; // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
std::cout<<"arr before 'fill(7)' : " << str(arr) << std::endl;

arr.fill(7);

std::cout<<"arr now : " << str(arr) << std::endl;
```

Output:
```
arr before 'fill(7)' : {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
arr now : {7, 7, 7, 7, 7, 7, 7, 7, 7, 7}
```

### swap

Exchanges all values with the container given as argument.  
Does not cause iterators and references to associate with the other container. 

Example:
```cpp
std::array<int, 10> arr{}; // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
std::array<int, 10> arr2 = {3, 2, 4, 1, 4, 5, 4};
std::cout<<"arr before swapping: " << str(arr) << std::endl;
std::cout<<"arr2 before swapping: " << str(arr2) << std::endl;

arr.swap(arr2);

std::cout<<"arr now: " << str(arr) << std::endl;
std::cout<<"arr2 now: " << str(arr2) << std::endl;
```

Output:
```
arr before swapping: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
arr2 before swapping: {3, 2, 4, 1, 4, 5, 4, 0, 0, 0}
arr now: {3, 2, 4, 1, 4, 5, 4, 0, 0, 0}
arr2 now: {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
```

# Non-Member Functions
### lexicographically compare
### get
### swap
### to_array
# Generator
### make_array

**header:** *\<experimental/array\>*

Creates a ***std::array*** whose size is equal to the number of arguments and whose elements are initialized from the corresponding arguments.

Example from [cppreference](https://en.cppreference.com/w/cpp/experimental/make_array):
```cpp
#include <experimental/array>
#include <iostream>
#include <type_traits>
 
int main()
{
    decltype(auto) arr = std::experimental::make_array(1, 2, 3, 4, 5);
    bool is_array_of_5_ints = std::is_same<decltype(arr), std::array<int, 5>>::value;
    std::cout << "Returns an array of five ints? ";
    std::cout << std::boolalpha << is_array_of_5_ints << '\n';
}
```

Output:
```
Returns an array of five ints? true
```
