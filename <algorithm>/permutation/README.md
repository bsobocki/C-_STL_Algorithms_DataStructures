# std::next_permutation

## use
std::next_permutation permutes given container in given range (first iterator, second iterator)
into the next lexicographically greater permutation.
```cpp
std::vector<int> vec = {1,2,3};
std::cout<<"Before permutation: ";
print_vector(vec);

std::next_permutation(vec.begin(), vec.end());

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
A simple program to solve cryptarithms by permute collection of digits: {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
(it's important that the collection is sorted in ascending order because it is lexicographically the lowest permutation)  
and assign its digits to the characters extracted from given strings.
