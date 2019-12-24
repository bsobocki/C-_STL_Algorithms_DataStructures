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
      * [front](#front)
  
---  

# Definition
in header: ***\<array>***  
   
```cpp
template <class T, std::size_t N> struct array;
```
# Member Functions

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

