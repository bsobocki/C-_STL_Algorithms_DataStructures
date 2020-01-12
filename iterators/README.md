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
    * **[advance](#advance)**
    * **[distance](#distance)**
    * **[prev](#prev)**
    * **[next](#next)**
  * **[Predefined iterators](#predefined-iterators)**
    * **[insert_iterator](#insert_iterator)**
    * **[back_insert_iterator](#back_insert_iterator)**
    * **[front_insert_iterator](#front_insert_iterator)**
    * **[move_iterator](#move_iterator)**
    * **[ostream_iterator](#ostream_iterator)**
  * **[Iterator Generators](#iterator-generators)**
    * **[back_inserter](#back_inserter)**
    * **[front_inserter](#front_inserter)**
    * **[inserter](#inserter)**
    * **[make_move_iterator](#make_move_iterator)**
  * **[Get iterator](#get-iterator)**
    * **[begin and end](#begin-and-end)**
    * **[cbegin and cend](#cbegin-and-cend)**
    * **[rbegin and rend](#rbegin-and-rend)**
    * **[crbegin and crend](#crbegin-and-crend)**

## Description

> An *iterator* is any object that pointing to some element in a range of elements (such as an array or a container), 
> has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) 
> and dereference (*) operators). 
>
> ~~ [cplusplus.com](http://www.cplusplus.com/reference/iterator/)  

The Idea of Iterators is to improve and to facilitate work on collections.  
It gives the opportunity to move to the element in the collection and to do something with it without knowing its structure.  

All iterable structures has a specific iterator type designed to iterate through its elements.  

## More About Iterators

One of forms of iterators is an pointer, because it can point an element in array and iterate through the array by increment operator ++.

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

If you want to browse the **vector\<int\>** *from beginning to end* you can use ***std::vector\<int\>::iterator*** but if you want to do it *from end to beginning* you can use ***std::vector\<int\>::reverse_iterator***.  

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

      std::cout<<"vector = ";
      // 'auto' to deduce type std::vector<int>::iterator
      // ints.end() is the iterator pointing the virtual element following the last one
      for(auto iter = ints.begin(); iter != ints.end(); iter++)
        // using operator * we can get the value of the element pointed by 'iter' 
        std::cout<< *iter  << "  "; // dereferencing the iterator
      
      std::cout<<std::endl;
        
      std::cout<<"reversed vector = ";
       // print vector from end to beginning
      for(std::vector<int>::reverse_iterator iter = ints.rbegin(); iter != ints.rend(); iter++)
        std::cout<< *iter << "  ";
        
        std::cout<<std::endl;
      }
      ```  
      Output:
      ```
      vector = 3  2  1  4  7  9  3  1  6  
      reversed vector = 6  1  3  9  7  4  1  2  3  
      ```
     
 * doing something with collection in given range \[start_range, end_range\)  
   *for example sorting elements in ascending order*:
   ```cpp
   std::vector<int> ints = {9, 3, 7, 2, 0, 8, 1, 5, 4, 6};
   // get the iterator of std::vector<int> pointing on the first element(start) and the last one(end)
   std::vector<int>::iterator start = ints.begin();
   // if you want, you can use 'auto' instead 'std::vector<int>::iterator'
   auto end = ints.end();

   auto end_range = start + 8; // ninth position
   auto start_range += start + 2; // third position

   // sorting elements in range [second, eighth] 
   // 'end' given as the second argument in std::sort does not belong to the sorting range 
   // so in this case the ninth position does not belong to the sorting range
   std::sort(start_range, end_range);

   // now ints == {9, 3,   0, 1, 2, 5, 7, 8,   4, 6}

   // sort elements in range [start, end)
   std::sort(start, end);
   
   // now ints == {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
   ```
 * create a new std::unordered_set<int> from std::vector<int>:
   ```cpp
   std::vector<int> ints = {1, 1, 2, 3, 2, 7, 5, 8, 9, 5, 3, 2, 0};
   std::unordered_set<int> set(ints.begin(), ints.end());
   ```
  
## Operations

### advance

Advances the iterator it by n element positions.    

For **Random Access Iterator** this function call operator `+` or `-` just once for the second argument to move *the iterator*.    
For other iterators types this function call operator `++` or `--`  until n elements have been advanced.   

Example:

```cpp
std::vector<int> ints = {9, 3, 7, 2, 0, 8, 1, 5, 4, 6};
std::vector<int>::iterator start = ints.begin();

std::cout<<"first element = "<<*start<<std::endl;

std::advance(start, 6);

std::cout<<"seventh element = "<<*start<<std::endl;
```  

Output:

```
first element = 9
seventh element = 1
```

**Complexity**:   
Constant for random-access iterators.  
Otherwise, linear in n.  

### distance

As the name implies, std::distance calculates the distance (number of elements) between two iterators.  

For **random access iterators** the function uses operator `-`, but for other types of iterators it uses operator `++` repeatedly.  

You can use it to check how big is your subset from `first` to `last`:  

```cpp
template <class Iter, typename T>
Iter get_iter_with_value(Iter begin, Iter end, const T & val){
    while(begin != end && *begin != val)   begin++;
    return begin;
}
```  
  
  
```cpp
std::vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

auto c_iter = get_iter_with_value(chars.begin(), chars.end(), 'c');
auto o_iter = get_iter_with_value(chars.begin(), chars.end(), 'o');

std::cout<<"number of elements form 'c' to 'o' = "<< std::distance(c_iter, o_iter) <<std::endl;
// only for random access iterators
std::cout<<"number of elements form 'c' to 'o' = "<< o_iter - c_iter <<std::endl;
```
Output:  

```
number of elements form 'c' to 'o' = 12
number of elements form 'c' to 'o' = 12
```
**Complexity**:
Constant for random-access iterators.  
Otherwise, linear in n.  
  
---

For examples in description about **begin** and **end**:  
```cpp
template <class Coll>
void print_coll(Coll coll){
  std::cout<<"{  ";
  for(auto elem : coll) std::cout<<elem<<"  ";
  std::cout<<"}"<<std::endl;
}
```  

### begin 

Returns an iterator pointing to the first element in the sequence.

Example:
```cpp
std::set<int> set = {3, 1, 4, 2, 5}; 

std::cout<<"set == ";
print_coll(set);

auto set_beg = set.begin();
auto std_beg = std::begin(set);

std::cout<<"Is the value in the set pointed by set_beg equal to std_beg?\n";
std::cout<<(*set_beg == *std_beg ? "Yes" : "No")<<std::endl;
std::cout<<"set_beg == "<<*set_beg<<std::endl;
std::cout<<"std_beg == "<<*std_beg<<std::endl;
```  
Output:  
```
set == {  1  2  3  4  5  }
Is the value in the set pointed by set_beg equal to std_beg?
Yes
set_beg == 1
std_beg == 1
```

### end

Returns an iterator pointing to the past-the-end element in the sequence.


Example:
```cpp
std::set<int> set = {3, 1, 4, 2, 5}; 
std::vector<int> vec;

for(auto it = std::begin(set); it != std::end(set); it++)
    vec.push_back(*it * *it);

std::cout<<"set == ";
print_coll(set);
std::cout<<"vec == ";
print_coll(vec);
```

Output:
```
set == {  1  2  3  4  5  }
vec == {  1  4  9  16  25  }
```

If the collection `coll` is empty then `std::begin(coll) == std::end(coll)`.  

### prev

Returns an iterator pointing to the element that would be pointed to by the iterator advanced by -n positions.  

For *random access iterator* the function will call the operator `-`.  
Otherwise it uses repeatedly the operator `++` or  `--` on the copied iterator until n elements have been advanced.  

Example:  
```cpp
std::vector<int> vec = {1, 8, 2, 5};

auto second_from_end = std::prev(vec.end(), 2);

std::cout<<"the element that is second from the end is equal "<<*second_from_end<<std::endl;
```  

Output:  
```
the element that is second from the end is equal 2
```  

**Complexity**:  
O(1) for *random access iterators*  
O(n) for *bidirectional iterators*

### next

Returns the iterator pointing to the element that would be pointed to by the iterator advanced by n positions.  


For *random access iterator* the function will call the operator `+` or `-`.  
Otherwise it uses repeatedly the operator `++` or  `--` on the copied iterator until n elements have been advanced.  

Example:  
```cpp
std::unordered_set<int> u_set = {4, 2, 5, 7, 1, 8, 8};

std::cout<<"u_set is equal: { ";
std::for_each(std::begin(u_set), 
              std::next(u_set.begin(), u_set.size()),  // <----- std::next -> begin + size() -> end() 
              [](int i){ std::cout<<i<<" ";});
std::cout<<"}"<<std::endl;
```

Output:  
```
u_set is equal: { 8 1 7 5 2 4 }
```
**Complexity**:  
Constant for random-access iterators.  
Otherwise, linear in n.  


## Predefined iterators


Declaration of function to print collection:
```cpp
template <class Iterable>
void print(const Iterable & coll){
    std::cout<<"{ ";
    for(auto elem : coll) std::cout<<elem<<" ";
    std::cout<<"}";
}
```

### All types of insert iterators

#### member types

| ***member***	| ***definition*** in *insert iterator* |
|--------------|----------------------------------------------|
| *iterator_category* |	**output_iterator_tag** |
| *value_type* |	**void** |
| *difference_type*	| **void** |
| *pointer* |	**void** |
| *reference* |	**void** |
| *iterator_type* |	**void** |  

#### member functions

This iterators types have following member functions:
 * Constructor
 * operators: 
   * `=`
   * `*`
   * `++`


### insert_iterator

*insert_iterators* are special *output iterators*, that allow algorithms which usually overwite elements in container (for example **std::copy**) to instead insert new elements at the specific position in the container.

The container needs to have an `insert` member function (such as most standard containers).  

See example to better understand insert_iterator:
```cpp
//                       begin +1   +2   +3   +4   +5  +6
//                         v    v    v    v    v    v   V
std::list<char> chars = { '.', '.', '.', '.', '.', '.',   '#','#', '#', '#' };
std::list<char> text_chars = {'a', 'w', 'e', 's', 'o', 'm', 'e', '_', 'e', 'x', 'a', 'm', 'p', 'l', 'e'}; 

std::list<char>::iterator ch_iter = chars.begin();

std::advance(ch_iter, 6);

auto sixth_pos_inserter = std::inserter(chars, ch_iter);

std::copy(text_chars.begin(), text_chars.end(), sixth_pos_inserter);

std::cout<<" chars = "; print(chars);
```
Output: 
```
chars = { . . . . . . a w e s o m e _ e x a m p l e # # # # } 
```

### back_insert_iterator

*back_insert_iterators* are special *output iterators*, that allow algorithms which usually overwite elements in container (for example **std::copy**) to instead insert new elements at the end (using ***push_back()***).  

Obviously, the container needs to have member function `push_back`.  

The best way to show how it works is to show the example of use (with std::transform and std::copy)!  
  
Example:  
```cpp
// std::back_inserter returns the back_insert_iterator of the container given as argument

std::vector<short> source = {1, 4, 3, 5, 3, 56};
std::vector<short> result;
std::transform(source.begin(), source.end(), std::back_inserter(result), [](const short & i) {return i*i;});

std::cout<<"result : "; print(result);

std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
std::vector<char> chars = {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
std::vector<char> chars2 = {'q', 'r' ,'s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

auto alphabet_back_inserter = std::back_inserter(alphabet);

std::copy(chars.begin(), chars.end(), alphabet_back_inserter);
std::copy(chars2.begin(), chars2.end(), alphabet_back_inserter);


std::cout<<"alphabet : "; print(alphabet);
```
Ouput:  
```
result : 1 16 9 25 9 3136 
alphabet : a b c d e f g h i j k l m n o p q r s t u v w x y z 
```  

###  front_insert_iterator

*front_insert_iterators* are special *output iterators*, that allow algorithms which usually overwite elements in container (for example **std::copy**) to instead insert new elements at the beggining (using ***push_front()***). 

Obviously, the container needs to have member function `push_front`.  

The example of use can be similar to the one above because functionality of both iterators types is similar:  
```cpp
// std::front_inserter returns the front_insert_iterator of the container given as argument

std::deque<short> source = {1, 4, 3, 5, 3, 56}; 
std::deque<short> result;

// we don't use reverse_iterator
// so the result will be in reversed order 
// because we will be pushing element at the beginning 
std::transform(source.begin(), source.end(), std::front_inserter(result), [](const short & i) {return i*i;});

std::cout<<"result : "; print(result);

 // at the beginning add to the alphabet letters from 'p' to 'h'
std::deque<char> chars = {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
// after that add at the beginning letters from 'g' to 'a'
std::deque<char> chars2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
std::deque<char> alphabet = {'q', 'r' ,'s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

auto alphabet_front_inserter = std::front_inserter(alphabet);

// use reverse_iterators to push front in reverse order
// so the alphabet will have correct order 
std::copy(chars.rbegin(), chars.rend(), alphabet_front_inserter);
std::copy(chars2.rbegin(), chars2.rend(), alphabet_front_inserter);


std::cout<<"alphabet : "; print(alphabet);
```

Output:  
```
result : 3136 9 25 9 16 1 
alphabet : a b c d e f g h i j k l m n o p q r s t u v w x y z 
```

### move_iterator

*move_iterator* is an iterator adaptor, which can be used like underlying iterator (must be at least *LegacyInputIterator*) except that dereferencing converts the value returned by the underlying iterator into an rvalue.  

If you use *move_iterator* as *input iterator* the values readed by the iterator will be moved from, rather than copied from.  


```cpp
std::list<std::string> list1 = { "Hi!", " ","My", "name", "is", "Bartosz."};
std::list<std::string> list2 = { " ", "Nice", "to", "meet", "you,", "friend"};

std::cout<<"Before std::copy with move_terators: "<<std::endl;

std::cout<<"list1 = "; print(list1);
std::cout<<std::endl;
std::cout<<"list2 = "; print(list2);

std::copy ( std::make_move_iterator(list2.begin()),
            std::make_move_iterator(list2.end()),
            std::back_inserter(list1) );

std::cout<<std::endl<<std::endl;

std::cout<<"After: "<<std::endl;

std::cout<<"list1 = "; print(list1);
std::cout<<std::endl;
std::cout<<"list2 = "; print(list2);
std::cout<<"// <- empty strings"<<std::endl;
```
Output: 
```
Before std::copy with move_terators: 
list1 = { Hi!   My name is Bartosz. }
list2 = {   Nice to meet you, friend }

After: 
list1 = { Hi!   My name is Bartosz.   Nice to meet you, friend }
list2 = {       } // <- empty strings
```

### ostream_iterator

From **cplusplus.com**:
> Ostream iterators are output iterators that write sequentially to an output stream (such as cout).
>
> They are constructed from a basic_ostream object, to which they become associated, so that whenever an assignment operator (=) is used on the ostream_iterator (dereferenced or not) it inserts a new element into the stream.
>
> Optionally, a delimiter can be specified on construction. This delimiter is written to the stream after each element is inserted.
>

```cpp
std::list<char> l = { 'h', 'e', 'l', 'l', 'o' };

std::ostream_iterator<char> ostr_iter (std::cout,", "); // the separator = ", "

std::copy(l.begin(), l.end(), ostr_iter); // copy data to the ostream "cout" using ostr_iter == print data
```
Output:
```
h, e, l, l, o, 
```
## Iterator Generators

You can use iterators not only for get elements from the collection. They can also be used to push back or push front some elements to the container and to move elements.  

### inserter

Connstructs a new insert_iterator. See [insert_iterator](#insert_iterator).

### back_inserter

Connstructs a new back_insert_iterator. See [back_insert_iterator](#back_insert_iterator).

### front_inserter

Constructs a new front_insert_iterator. See [front_insert_iterator](#front_insert_iterator).

### make_move_iterator

Constructs a new move_iterator. See [move_iterator](#move_iterator).

## Get Iterator

### begin and end

#### begin 
  
```cpp
iterator begin() noexcept;
```
Returns an iterator to the first element.

if the container `c` is empty then `c.begin() == c.end()`

#### end

```cpp
iterator end() noexcept;
```
Returns an iterator to the element following the last element.

### cbegin and cend

#### cbegin

```cpp
const_iterator cbegin() const noexcept;
```  
Returns a const iterator to the first element.

#### cend

```cpp
const_iterator cend() const noexcept;
```
Returns a const iterator to the element following the last element.

### rbegin and rend

#### rbegin 
  
```cpp
reverse_iterator rbegin() noexcept;
```
Returns an iterator to the first element of the reversed container.

if the container is empty then `c.rbegin() == c.rend()`

#### rend

```cpp
reverse_iterator rend() noexcept;
```
Returns an iterator to the element following the last element of the reversed container.

### crbegin and crend


#### crbegin

```cpp
const_reverse_iterator crbegin() const noexcept;
```  
Returns a const reverse iterator to the first element of the reversed container.

#### crend

```cpp
const_reverse_iterator crend() const noexcept;
```
Returns a const reverse iterator to the element following the last element of the reversed container.
