# std::sort
Algorithm for sorting data structures in the range \[first, last\).

## Examples of use
Array :  
T* array = { _elements_ };
T array [] = { _elements_ };
```
std::sort(array, array + sizeof(array)/sizeof(array[0]), []() -> bool {...});
```