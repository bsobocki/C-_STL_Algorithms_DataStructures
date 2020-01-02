# Iterators

This file README.md has been created based on information from [`cplusplus.com`](http://www.cplusplus.com/reference/iterator/). 

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

Additional Properties:
  * Can be dereferenced as an lvalue (if in a dereferenceable state).  
    ```
     It shall only be dereferenced as the left-side of an assignment statement.  
     Once dereferenced, its iterator value may no longer be dereferenceable.  
    ```

### Input Iterator

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
  
Forward Iterators are also valid input and output(if it is not constant) iterators.  

### Bidirectional Iterator

Bidirectional Iterator can be used to go through the collection in a range in both directions.  

Additional Properties:  
 * Can be decremented (if a dereferenceable iterator value precedes it).  
   ```cpp
    --a;
    a--;
    *a--;
   ```  
  
All bidirectional iterators are also valid forward iterators.  

### Random Acess Iterator

With help Random Access Iterator you can access elements at an arbitrary offset position relative to the one it pointing to.  

It offers the same functionality as pointers.  

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
