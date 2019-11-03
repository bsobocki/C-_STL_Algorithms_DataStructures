# ___std::sort___ |  ___std::stable_sort___  |  ___std::partial_sort___
  
header: ***\<algorithm>***

---  
## *[Table Of Contents](#table-of-contents)*
  - *__[sort](#sort)__*  
     - *Description*
     - *Algorithm*  
        - Implementation  
        - Complexity  
     - *Prototype  
  - *__[stable_sort](#stable_sort)__*  
     - *Description*
     - *Algorithm*  
        - Implementation  
        - Complexity   
     - *Prototype*  
  - *__[partial_sort](#partial_sort)__*  
     - *Description*
     - *Algorithm*  
        - Complexity   
     - *Prototype*    
  - *__[nth_element](#nth_element)__*  
     - *Description*
     - *Prototype*   
  - *__[is_sorted](#is_sorted)__*  
     - *Description*
     - *Prototype*  
  - *__[is_sorted_until](#is_sorted_until)__*  
     - *Description*
     - *Prototype*  
   - *__[Functions to compare elements](#functions-to-compare-elements)__*   
      - *[Lambda abstraction](#lambda-abstraction)*        
      - *[Functions](#functions)*  
      - *[Functors](#functors)*  
   - *__[Sorting in different ways](#sorting-in-different-ways)__*   
   
---  
  
# ___sort___
## ___Description___
A generic function for comparison sorting in range \[first, last\).   
By using this function **we have no guarantee** that for elements of equivalent value the order from the original array will be maintained.
## ___Algorithm___

### Implementation
This function is usually implemented as **[IntroSort](https://www.geeksforgeeks.org/introsort-or-introspective-sort/)** or **[QuickSort](https://www.geeksforgeeks.org/quick-sort/)**.  

### Complexity
Time Complexity: *__`O(N*log(N))`__* where *__`N`__* is the number of elements in the container.

## ___Prototype___  

**std::sort**(*startadress, endardess*);  
**std::sort**(*startadress, endadress, function_to_compare_elements*);  
  
---  
  
# ___stable_sort___
## ___Description___
Function sorting a data container in range \[first, last\).   
Using this function **we have guarantee** that the order of the element with equivalent value is the same as in the array before sorting.
## ___Algorithm___

### Implementation
Usually implemented as **[Merge Sort](https://www.geeksforgeeks.org/merge-sort/)**.  
  
According to [stackOverflow.com](https://stackoverflow.com/questions/23985891/what-is-the-difference-between-stdsort-and-stdstable-sort/23986246):  
> In the case HP/ Microsoft
> **std:stable_sort**
> is a hybrid bottom up _merge sort_,
> using _insertion sort_ to create sorted groups of 32 elements,
> then doing bottom up _merge sort_ with the groups.
>
> **Merge sort** is also `O(N*log(N))`,
> taking a bit longer for sorting arrays of objects,
> but merge sort is often faster
> if sorting an array of pointers to objects where a comparison function is included in the call.  

### Complexity
Time Complexity (according to *GeekForGeek*):  
*__`O(N*log^2(N))`__* if additional memory linearly proportional to length is not available.  
*__`O(N*log(N))`__* otherwise. 
  
where *__`N`__* is the number of elements in the container (distance from first to last).

## ___Prototype___  

**std::stable_sort**(*startadress, endardess*);  
**std::stable_sort**(*startadress, endadress, function_to_compare_elements*);  
  
---  
  
# ___partial_sort___
## ___Description___  
  
> Rearranges the elements in the range \[first,last), 
> in such a way that the elements before middle 
> are the smallest elements in the entire range and 
> are sorted in ascending order, while the remaining elements 
> are left without any specific order.
>
> -- <cite>cplusplus.com</cite>  

For example:
```cpp
int a [] = {3, 4, 2, 5, 1, 10};
int _size = sizeof(a)/sizeof(a[0]);
partial_sort(a, a +_size/2, a+_size,  A());
print_array(a);
```
output:  
```cpp
{ 1, 2, 3, 5, 4, 10 }
```
## ___Algorithm___  
### Complexity
Time Complexity (according to *cppreference*):   
*__`O(N*log(M))`__* 
  
where:  
*__`N`__* is the distance from the first to the last element.  
*__`M`__* is the distance from the first to the moddle element.  

## ___Prototype___  

**std::partial_sort**(*startadress, middle, endardess*);  
**std::partial_sort**(*startadress, middle, endadress, function_to_compare_elements*);  
  
---  
    
# ___nth_element___
## ___Description___  
  
> Rearranges the elements in the range \[first,last), 
> in such a way that the element at the nth position is the element that would be in that position in a sorted sequence.
>  
> The other elements are left without any specific order, 
> except that none of the elements preceding nth are greater than it, and none of the elements following it are less.
>  
> The elements are compared using operator< for the first version, and comp for the second.
>
> -- <cite>cplusplus.com</cite>  

For example:
```cpp
int a [] = {10, 1, 0, 3, 4, 2, 5, 1, 7, -7 , -3 , 7};
int _size = sizeof(a)/sizeof(a[0]);
nth_element(a, a + 7, a+_size);
print_array(a);
```
output:  
```cpp
{ 1, -7, 0, 1, -3, 2, 3, 4, 5, 7, 10, 7}
```

## ___Prototype___  

**std::nth_element**(*startadress, nth, endadress*);  
**std::nth_element**(*startadress, nth, endadress, function_to_compare_elements*);  
  
---  
      
# ___is_sorted___
## ___Description___  
A predicates returns 
```cpp 
true 
``` 
if the range \[first,last\) is sorted into ascending order.

>The elements are compared using *operator __\<__* for the first version, and *comp* for the second.
>
>-- <cite>cplusplus.com</cite>  

## ___Prototype___  

**std::is_sorted**(*startadress, nth, endadress*);  
**std::is_sorted**(*startadress, nth, endadress, function_to_compare_elements*);  
  
---  
      
# ___is_sorted_until___
## ___Description___  
> Returns an iterator to the first element in the range \[first,last) which does not follow an ascending order.
>
> The range between first and the iterator returned is sorted.
> 
> If the entire range is sorted, the function returns last.
> 
> The elements are compared using operator< for the first version, and comp for the second
>
>-- <cite>cplusplus.com</cite>  

## ___Prototype___  

**std::is_sorted_until**(*startadress, nth, endadress*);  
**std::is_sorted_until**(*startadress, nth, endadress, function_to_compare_elements*);  
  
---  

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
                  vec.begin() + 3, 
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

# Sorting in different ways  

You can sort not only ascending or descending!
Depending on the functions to compare you can sort an array in different ways.  
## You can use this functions if you want to have an array sorted by:   
### parity of elements  
```cpp
auto comp = [](const int & x, const int & y) -> bool {
  return x % 2 == 0;
}
```  
or 
```cpp
auto comp = [](const int & x, const int & y) -> bool {
  return y % 2 == 0;
}
```  
If you want to sort the array so that the odd numbers are at the beginning.  

### positivity of numbers   
```cpp
auto comp = [] (const int & x, const int & y) -> bool {
  return x > 0;
}
```
