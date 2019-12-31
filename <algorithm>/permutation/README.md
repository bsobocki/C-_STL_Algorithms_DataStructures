# std::next_permutation

## use
std::next_permutation permutes given container in range \[first iterator, second iterator)
into the next lexicographically greater permutation.

```cpp
std::vector<int> vec = {1,2,3};
std::cout<<"Before permutation: ";
print_vector(vec);

std::next_permutation(vec.begin(), vec.end()); // permute in range [begin, end)

std::cout<<"After permutation: ";
print_vector(vec);
```
Output:
```
Before permutation: {1, 2, 3};
After permutation: {1, 3, 2};
```

## returned value
std::next_permutation' returns `true` 
if the next determined permutation is lexicographically higher than previous and `false` otherwise.

# cryptarithm.cpp
A simple program to solve cryptarithms.

## program
1) Extract characters from given strings to `std::unordered_set`.   
  
2) Until solution is not correct:  
   
   a) Permute collection of digits: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9} and extract N first elements to a new vector.  
    ```
    It's important that the collection is sorted in ascending order  
    because it is lexicographically the lowest permutation.
    ```
    ```
    N is a number of unique characters from given strings.  
    ```     
   b) Assign the digits to the characters in `std::unordered_map`.  
     
   c) Check the solution by converting strings to numbers using `std::unordered_map` and check if the sum of the first and the second number is equal to the third of them.  
  
3) Print the solution  
 
and assign its digits to the characters extracted from given strings.

# perm.cpp
Prints next permutations of two containers until std::next_permutation returns true (until the next permutation is lexicographically higher than previous).