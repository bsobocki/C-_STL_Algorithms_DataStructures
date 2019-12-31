# Iterators

This file README.md has been created with help `cplusplus.com`. 

## [Table Of Contents](#table-of-contents)
  * **[Description](#description)**
  * **[More About Iterators](#description)**
    * **[Output Iterator](#output-iterator)**
    * **[Input Iterator](#Input-iterator)**
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

**Forward** has properties of **Input** and **Output** and in addition its own.  
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
    
### Input and Output Iterator

> Input and Output iterators are iterators that can be used in sequential input/output operations, where each value pointed by the iterator is read(*Input*)/written(*Output*) only once and then the iterator is incremented.
>
> ~~ ***cplusplus.com***

This iterators type only allow reading/writing values from/to a given component.  
You cannot writing/reading values from elements pointed by this iterator.  
It has to have a default constructor, copy constructor and operators: =, ++.

### Output Iterator

Properties:
  * Can be dereferenced as an lvalue (if in a dereferenceable state).  
    ```
    *It shall only be dereferenced as the left-side of an assignment statement.*  
    *Once dereferenced, its iterator value may no longer be dereferenceable.*  
    ```

### Input Iterator

Properties:
  * Can be dereferenced as an rvalue (if in a dereferenceable state).
    ```cpp
    	*a
      a->m
    ```


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
