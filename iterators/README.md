# Iterators

This README.md file has been created based on information from [`cplusplus.com`](http://www.cplusplus.com/reference/iterator/). 

## [Table Of Contents](#table-of-contents)
  * **[Description](#description)**
  * **[More About Iterators](#description)**
    * **[Output Iterator](#output-iterator)**
    * **[Input Iterator](#input-iterator)**
    * **[Forward Iterator](#forward-iterator)**
    * **[Bidirectional Iterator](#bidirectional-iterator)**
    * **[Random Access Iterator](#random-access-iterator)**
  * **[How To Use](#how-to-use)**
  * **[Operations](#operations)**
  * **[Get iterator](#get-iterator)**
    * **[begin](#begin)**
    * **[cbegin](#cbegin)**
    * **[end](#end)**
    * **[cend](#cend)**
    * **[rbegin](#rbegin)**
    * **[rend](#rend)**
    * **[crbegin](#crbegin)**
    * **[crend](#crend)**
  * **[Iterator Generators](#iterator-generators)**
    * **[back_inserter](#back_inserter)**
    * **[front_inserter](#front_inserter)**
    * **[inserter](#inserter)**
    * **[make_move_iterator](#make_move_iterator)**
  * **[Predefined iterators](#predefined-iterators)**

## Description

> An *iterator* is any object that, pointing to some element in a range of elements (such as an array or a container), 
> has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) 
> and dereference (*) operators). 
>
> ~~ [cplusplus.com](http://www.cplusplus.com/reference/iterator/)  

The Idea of Iterators is to improve and to facilitate work on collections.  
It gives the opportunity to move to the element in the collection and to do something with it without knowing its structure.  

All iterable structures has a specific iterator type designed to iterate through its elements.  

## More About Iterators

One of forms of iterator is an pointer, because it can point an element in array, and iterate through the array by increment operator ++.

While pointers are the form of iterators, not all iterators have the same functionally of pointers. 

Depending on functionality they implemented Iterators are classified into five categories:
  * Output
  * Input
  * Forward
  * Bidirectional
  * Random Access

**`Input <-- Forward <-- Bidirectional <-- Random Access`**  
**`Output`**

**Forward** has properties of **Input** and **Output** (if it is not constant) and in addition its own.  
**Bidirectional** has properties of **Forward** and in addition its own.  
**Random Access** has properties of **Bidirectional** and in addition its own.  

All categories have properties:
  * copy-constructible, copy-assignable and destructible  
    ```cpp
    iterator a(c); 
    auto b = a;
    ```
  * incrementing  
    ```cpp
    ++a;
    a++;
    *a++ = t;
    ```  
    
**Constant Iterators** are iterators that do not fulfill the requirements fo an **output iterators**. Dereferencing them yields a reference to a constant element (such as ***const** T &*).  
    
### Input and Output Iterator

> **Input**(*I*) and **Output**(*O*) iterators are iterators that can be used in sequential **input**(*I*)/**output**(*O*) operations, where each value pointed by the iterator is **read**(*I*)/**written**(*O*) only once and then the iterator is incremented.
>
> ~~ ***cplusplus.com***

This iterators type only allow **reading**(*I*)/**writing**(*O*) values **from**(*I*)/**to**(*O*) a given component.  
You cannot **writing**(*I*)/**reading**(*O*) values from elements pointed by this iterator.  
It has to have a default constructor, copy constructor and operators: `=`, `++`.

### Output Iterator

The output iterator can be useful when you need to be sure that the collection will not be read, but only overwritten.  

Additional Properties:  
  * Can be dereferenced as an lvalue (if in a dereferenceable state).  
    ```
     It shall only be dereferenced as the left-side of an assignment statement.  
     Once dereferenced, its iterator value may no longer be dereferenceable.  
    ```

### Input Iterator

The input iterator can be useful when you need to be sure that the collection will not be overwritten, but only read.  

Additional Properties:
  * Can be compared for equivalence using the equality/inequality operators (meaningful if both iterators are be in domain).
    ```
    a == b
    a != b
    ```
  * Can be dereferenced as an rvalue (if in a dereferenceable state).  
    ```cpp
     *a 
     a->m
    ```
  * Its value type does not need to be assignable.  
    ```cpp
    t = u  // not required
    ```
  * Lvalues are swappable.  
    ```cpp
    swap(a,b);
    ```
### Forward Iterator

Forward iterators are iterators that you can go only forward from the beginning to the end in the indicated range.   
They are limited to one direction in which to iterate through a range (forward).  

This type of iterators can be useful if you must go through the collection one by one (for example printing the collection, change values, or building a new one based on the collection.
  
Forward Iterators are also valid input and output(if it is not constant) iterators.  

### Bidirectional Iterator

Bidirectional Iterator can be used to go through the collection in a range in both directions by incrementing and decrementing it (using `++` and `--`).  

This type of iterators can be useful if you must go through the collection one by one in both directions.  
For example printing or changing all values from the collection in the collection and in the reverse order.  

Additional Properties:  
 * Can be decremented (if a dereferenceable iterator value precedes it).  
   ```cpp
    --a;
    a--;
    *a--;
   ```  
  
All bidirectional iterators are also valid forward iterators.  

### Random Access Iterator

With help Random Access Iterator you can access elements at an arbitrary offset position relative to the one it pointing to.  

It offers the same functionality as pointers.  

You can use it, among others, when you need to go through the collection not only one by one,  
but for example through an elements with even indexes,  
or when you need to have a possibility to get the element on n-th position (n = 1, 2, ... , collection.size() ).  

Additional Properties:  
 * Supports the arithmetic operators `+` and `-` between an iterator and an integer value, or subtracting an iterator from another.
   ```cpp
   a + n;
   n + a;
   a - n;
   a - b;
   ```  
 * Can be compared with inequality relational operators `<, >, <= and >=`.
   ```cpp
   a < b;
   a > b;
   a <= b;
   a >= b;
   ``` 
 * Supports compound assignment operations `+=` and `-=`.
   ```cpp
   a += n;
   a -= n;
   ```  
 * Supports the offset dereference operator `[]`.
   ```cpp
   a[n]
   ```
All random access iterators also valid bidirectional iterators.  

## How To Use

Examples of use:
 * printing elements:
   * using [**range-based for statement**](https://docs.microsoft.com/en-us/cpp/cpp/range-based-for-statement-cpp?view=vs-2019):  
     ```cpp
     std::array<char, 9> chars = {'a', 'b', 'c', 'd', 'e', 'f'};

     // to use ranged-based for statement the collection must be iterable
     // you can use 'auto' instead 'char'
     for(auto chr: chars)
       std::cout<<chr<<std::endl;
     ```
    * using for loop:
      ```cpp
      std::vector<int> ints = {3, 2, 1, 4, 7, 9, 3, 1, 6};

      // 'auto' to deduce type std::vector<int>::iterator
      // ints.end() is the iterator pointing the virtual element following the last one
      for(auto iter = ints.begin(); iter != ints.end(); iter++){
        // using operator * we can get the value of the element pointed by 'iter' 
        std::cout<< *iter << std::endl; // dereferencing the iterator
      }
      ```  
     
 * doing something with collection in given range \[start_range, end_range\)  
   *for example sorting elements in ascending order*:
   ```cpp
   std::vector<int> ints = {9, 3, 7, 2, 0, 8, 1, 5, 4, 6};
   // get the iterator of std::vector<int> pointing on the first element(start) and the last one (end)
   std::vector<int>::iterator start_range = ints.begin();
   // if you want, you can use 'auto' instead 'std::vector<int>::iterator'
   auto end_range = ints.end();

   // sort elements in range [start, end)
   std::sort(start_range, end_range);

   end_range = start_range + 8;
   start_range += 2;

   // sorting elements in range [second, eighth] 
   // 'end' given as the second argument in std::sort does not belong to the sorting range
   std::sort(start_range, end_range);

   // now ints == {9, 3,   0, 1, 2, 5, 7, 8,   4, 6}
   ```
 * create a new std::unordered_set<int> from std::vector<int>:
   ```cpp
   std::vector<int> ints = {1, 1, 2, 3, 2, 7, 5, 8, 9, 5, 3, 2, 0};
   std::unordered_set<int> set(ints.begin(), ints.end());
   ```

## Operations
## Get Iterator
### begin
### end
### rbegin
### rend
## Iterator Generators
### back_inserter
### front_inserter
### inserter
### make_move_iterator
## Predefined iterators
