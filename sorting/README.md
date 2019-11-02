# ___std::sort___ |  ___std::stable_sort___  |  ___std::partial_sort___
Functions for sorting _containers_.  
  
header: \<algorithm>

---  
## *[Table Of Contents](#table-of-contents)*
   - *__[Algorithm](#algorithm)__*  
      - [Implementation](#implementation)  
      - [Complexity](#complexity)   
   - *__[Prototype](#prototype)__*  
   - *__[Examples of use](#examples-of-use)__*   
      - [Array](#array)  
   - *__[Functions to compare elements](#functions-to-compare-elements)__*   
      - [Lambda abstraction](#lambda-abstraction)        
      - [Implemented functions](#implemented-functions)  
      - [Implemented functors](#implemented-functors)  
      - [Built-in functions](#built-in-functions)  
   
---  

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
```
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
```
{ 0, 1, 2, 3, 5, 7, 9 }
{ 0, 1, 2, 3, 5, 7, 9 }
```
## ___Functions to compare elements___
### Lambda abstraction
### Functions
### Functors
