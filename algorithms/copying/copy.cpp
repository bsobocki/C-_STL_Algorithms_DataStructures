#include "../tools.hpp"
#include <list>

int main() {

    std::cout << " ---- copy ints ---- " << std::endl;

    std::vector<int> vec1 = {3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1};
    print("vec1: ", vec1);

    std::vector<int> vec2 (vec1.size());
    print("vec2: ", vec2);

    std::cout <<"copying data . . ." << std::endl;    
    // copy elements to the vec2
    std::copy(vec1.begin(), vec1.end(), vec2.begin());   // or std::back_inserter(vec2) instead  vec2(vec1.size()) and using vec2.begin()

    print("vec2: ", vec2);

    

    std::cout << std::endl;
    std::cout << " ---- move std::strings ---- " << std::endl;

    std::vector<std::string> strs1 = {"asd", "adg", "gasga", "hjadikh", "y23r83fh8"};
    std::cout<<"vector1: "; show(strs1);

    std::vector<std::string> strs2 = {"first"};
    std::cout<<"vector2: "; show(strs2);

    std::cout<<"moving data using std::copy . . ." << std::endl;
    std::copy(
        std::make_move_iterator(strs1.begin()),
        std::make_move_iterator(strs1.end()),
        std::back_inserter(strs2)
    );

    std::cout<<"vector1: "; show(strs1);
    std::cout<<"vector2: "; show(strs2);




    std::cout<< std::endl; 
    std::cout << "\n ---- print array using std::copy ---- "<<std::endl;

    char arr[8] = {'a', 'b', 'c', '1', 48, 100, 108, '9'}; // a b c 1 0 d l 9
    std::ostreambuf_iterator<char> out_it (std::cout);

    std::cout << "arr : ";
    std::copy(arr, arr+8, out_it); // copy to std::cout using ostreambuf iterator




    std::cout << std::endl;
    std::cout << "\n ---- std::copy_n ---- " << std::endl;

    std::list<int> l1 = {74, 67, 7, 35, 42, 1, 9, 0, 0, 0, 4, 3, 2, 23, 42};
    std::list<int> l2;

    std::copy_n(l1.begin(), 5, std::back_inserter(l2));

    std::cout<<"list 1: "; show(l1);
    std::cout<<"list 2 (first 5 elements): "; show(l2);
}