#include "../tools.hpp"

int main(){
    std::vector<char> tab = {'a', 'b', 'c', 'p', 'm', 'j', 'a', 'm', 'a', 'i', 'c', 'a'};
    std::string txt = "jamaica";

    std::cout << "vec<char> = "; show(tab);
    std::cout << "txt = "; show(txt);

    std::sort(tab.begin(), tab.end());
    std::sort(txt.begin(), txt.end());

    std::cout << "\nsorted vec<char> = "; show(tab);
    std::cout << "sorted txt = "; show(txt);

    std::cout << "\nDoes sorted 'vec<char>' includes sorted 'txt'?" << std::endl;

    // std::includes == check if the sorted range [first1,last1) contains all the elements in the sorted range [first2,last2).
    auto incl = std::includes(tab.begin(), tab.end(), txt.begin(), txt.end());

    std::cout << std::boolalpha << incl << std::endl;

    return 0;
}