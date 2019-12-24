# std::array
*\(since C++ 11)*  
A STL container represents arrays with constant size.   
From ***`cppreference.com`*** we know, that unlike a C-style array, it doesn't decay to T* automatically. 
  
---  
  
# [Table of contents](#table-of-contents)  
  
  * [Definition](#definition)  
  * [Member Functions](#member-functions)  
    * [Get element](#get-element)
      * [at](#at)  
      * [indexing operator](#indexing-operator)  
      * 
  
---  

# Definition
in header: ***\<array>***  
   
```cpp
template <class T, std::size_t N> struct array;
```
# Member Functions

## Get element

### at  

Definition: *reference at(size_type pos)*

### indexing operator

Definition: *reference operator [] (size_type pos)*
