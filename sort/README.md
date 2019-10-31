# std::sort
Algorithm for sorting data structures in the range \[first, last\).

## Examples of use
___Array___ :  
__T__* array = { _elements_ };  
__T__ array [] = { _elements_ };  
```
std::sort(array, array + sizeof(array)/sizeof(array[0]), []() -> bool {...});
```
