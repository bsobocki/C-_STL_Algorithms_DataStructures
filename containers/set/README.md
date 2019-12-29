# std::set

## declaration

```cpp
template < class T, 
            class Compare = less<T>, 
             class Alloc = allocator<T> >
class set;
``` 
## description

container that store unique elements following specyfic order

constructors:
    - empty set (default constructor)
    - range (std::set<T>(container.begin(), constainer.end()))

## example of use

template
<class Iterable>
std::set<T> make_set(const Iterable & it){
    return std::set<T>(it.begin(), it.end());
}

template
<class Iterable>
std::set<T> make_set(const Iterable & it){
    return std::set<T>(it.begin(), it.end(), 
}

std::set<T> 
