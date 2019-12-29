# std::array  
Description of the std::array container with its methods.  
It is based on the content of the websites:  [cppreference - array](https://en.cppreference.com/w/cpp/container/array) and [cplusplus - array](http://www.cplusplus.com/reference/array/array/)

---  
  
# [Table of contents](#table-of-contents)  
  * [Description](#description)
  * [Definition](#definition)  
  * [Member Functions](#member-functions)  
    * [Get element](#get-element)
      * [at](#at)  
      * [indexing operator](#indexing-operator)  
      * [front](#front)
      * [back](#back)
    * [data](#data)
    * [Iterators](#iterators)
  
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
  
  
  
## Get element
  
...  
  
### at  

```cpp 
reference at(size_type pos);
```  

Returns a reference to the element on the position **`pos`** *with bounds checking*.  
**`if !(pos < size())`** throws exception: *`std::out_of_range`*   

**Complexity:** O(1)

...  
  
### indexing operator

```cpp 
reference operator[](size_type pos);
```  

Returns a reference to the element on position **`pos`** *without bounds checking*.  

**Complexity:** O(1)

...  
  
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

...  
  
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

...  

## data  
  
```cpp
T* data() noexcept;
```  

Returns pointer to the underlying array serving as element storage.  
If array is not empty, `.data()` returns pointer compares equal to the address of the first element.  

**Complexity:** O(1)

...  

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
...  

### begin 
  
```cpp
iterator begin() noexcept;
```
Returns iterator to the first element.

if the container is empty then arr.begin() == arr.end()

### end

```cpp
iterator end() noexcept;
```
Returns iterator to the element following the last element.

### cbegin

```cpp
const_iterator cbegin() const noexcept;
```  
Returns const iterator to the first element.

### cend

```cpp
const_iterator cend() const noexcept;
```
Returns const iterator to the element following the last element.

## Reverse Iterators

You can use them to pass through the container in reverse order.

For example:
```cpp
  std::array<int, 7> arr = {1, 2, 3, 4, 5, 6, 7};
  std::array<int, 7>::reverse_iterator it = arr.rbegin();
  for(it; it != arr.rend(); it++) 
    std::cout<<*it<<std::endl;
```

Output:
```
  7
  6
  5
  4
  3
  2
  1
```  

...  



### rbegin 
  
```cpp
reverse_iterator rbegin() noexcept;
```
Returns iterator to the first element of the reversed container.

if the container is empty then arr.begin() == arr.end()

### rend

```cpp
reverse_iterator rend() noexcept;
```
Returns iterator to the element following the last element of the reversed container.

### crbegin

```cpp
const_reverse_iterator crbegin() const noexcept;
```  
Returns const reverse iterator to the first element of the reversed container.

### crend

```cpp
const_reverse_iterator crend() const noexcept;
```
Returns const reverse iterator to the element following the last element of the reversed container.
