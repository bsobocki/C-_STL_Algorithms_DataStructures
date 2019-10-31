# std::sort
Algorithm for sorting data structures in the range \[first, last\).

## Examples of use
___Array___ :  
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
