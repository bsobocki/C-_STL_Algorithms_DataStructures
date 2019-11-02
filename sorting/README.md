# ___std::sort___ |  ___std::stable_sort___  |  ___std::partial_sort___
Functions for sorting _containers_.  
  
header: *\<algorithm>*

---  
## *[Table Of Contents](#table-of-contents)*
  - *__[std::sort](#std--sort)__*
     - *__[Algorithm](#algorithm)__*  
        - [Implementation](#implementation)  
        - [Complexity](#complexity)   
     - *__[Prototype](#prototype)__*  
     - *__[Examples of use](#examples-of-use)__*   
        - [Array](#array)  
   - *__[Functions to compare elements](#functions-to-compare-elements)__*   
      - [Lambda abstraction](#lambda-abstraction)        
      - [Functions](#functions)  
      - [Functors](#functors)  
   
---  
# ___std::sort___
## ___Algorithm___

### Implementation
This function is implemented as [QuickSort](https://www.geeksforgeeks.org/quick-sort/).  

### Complexity
Time Complexity: *__`O(N*log(N))`__* where *__`N`__* is the number of elements in the container.

## ___Prototype___  

**sort**(*startadress, endardess*);  
**sort**(*startadress, endadress, function_to_compare_elements*);  

## ___Examples of use___
### Array 
```cpp
int array1 [] = { 5, 7, 9, 0, 3, 1, 2 };  
int array2 [] = { 5, 7, 9, 0, 3, 1, 2 };  
int* array_ptr = array2;
int array_size = sizeof(array1)/sizeof(array1[0]);

std::sort(array1, array1 + array_size);  // no function to compare elements -> ascending sorting
std::sort(array2, array2 + array_size, std::less<>());  // ascending sorting

print_array(array1, array_size);
print_array(array2, array_size);
```
The output will be:  
```cpp
{ 0, 1, 2, 3, 5, 7, 9 }
{ 0, 1, 2, 3, 5, 7, 9 }
```
# ___Functions to compare elements___  

_Only functions with 2 arguments with the rights types!_  

For this examples we declare:  
```cpp
std::vector<int> vec = { /* here are many different integers */ };
```  
```cpp
std::vector<A> vec2;
/* push some elements */
```   
```cpp
struct A{
  int x;
  int y;
};
```
### Lambda abstraction  
```cpp
// the first part of vec will consist of all even numbers of vector
auto compare = [](const int & x, const int y) -> bool { return x%2 == 0; }
std::sort(vec.begin(), vec.end(), compare);
```
```cpp
// the first part of vec will consist of all numbers less than 0 of vector
std::partial_sort(vec.begin(), 
                  vec.begin() + 5, 
                  vec.end(), 
                  [](const int & x, const int & y) -> bool { 
                    return y >= 0 ; 
                    });
```
### Functions
```cpp
bool compareByX(const A & first, const A & second ){
  return first.x > second.x;
}

std::stable_sort(vec2.begin(), vec2.end(), compareByX);
```
### Functors  
```cpp
struct Compare{
  bool operator() (const int & x, const int & y) {
    return x <= y ;
  }
};

std::sort(vec.begin(), vec.end(), Compare());
std::stable_sort(vec.begin(), vec.end(), std::greater<>());
std::stable_sort(vec.begin(), vec.end(), std::less<>());
```
