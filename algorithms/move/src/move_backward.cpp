#include "../../tools.hpp"
#include <list>

int main (){
    std::list<std::string> strs = { "first", "second", "third", "fourth", "fivth", "sixth", "seventh", "eighth"};
    std::vector<std::string> vec = {"ninth", "tenth"};
    vec.resize(strs.size()+5);

    std::cout << "list: "; show(strs);
    std::cout << "vec: "; show(vec);

    std::cout << std::endl;

    std::cout << "moving values . . .\n" << std::endl;
    std::move_backward(strs.begin(), strs.end(), vec.end());

    std::cout << "list: "; show(strs);
    std::cout << "vec: "; show(vec);

    return 0;
}