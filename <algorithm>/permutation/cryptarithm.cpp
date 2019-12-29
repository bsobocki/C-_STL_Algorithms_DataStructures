#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

std::unordered_set<char> get_chars(
    std::string & first, std::string & second, std::string & result){
        std::unordered_set<char> chars;
        chars.insert(first.begin(), first.end()); 
        chars.insert(second.begin(), second.end());
        chars.insert(result.begin(), result.end());
        return chars;
}

std::vector<std::pair<char, int>> solve_criptharithm(
    std::string& first, std::string& second, std::string& result) {
        std::unordered_set<char> chars = get_chars(first, second, result);
}

int main(){
    std::unordered_set<char> chars;
    std::vector<int> numbers;

    
    
    return 0;
}
