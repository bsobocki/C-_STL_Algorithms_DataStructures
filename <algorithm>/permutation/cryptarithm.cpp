#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <exception>
#include <typeinfo>

/*
    "cryptarithm solution in an easy and slow way"
    A small program with using std::next_permutation
    to generate next permutations of numbers 
    which are assigned to characters from given string.

    author: Bartosz Sobocki
*/

using u_set = std::unordered_set<char>;
using s_vec = std::vector<short>;
using u_map = std::unordered_map<char, int>;
using str_arr = std::array<std::string, 3>;

const u_set get_chars(const std::string & str);
const s_vec N_digits_of_the_next_permutation(const short int N);
const u_map next_cryptarithm_solution(const u_set & chars);
long long int str_to_num_from_solution(u_map & solution, const std::string & str);
bool check_solution(u_map & solution, const str_arr & args);
const u_map solve_cryptarithm(const std::string& first, const std::string& second, const std::string& result );
void print_solution(u_map & solution);

class ThereIsNoMorePermutations: public std::exception{
    public: 
        virtual const char* what() const throw(){
            return "All permutations were used! There's no solution of the Cryptarithm.";
        }
};

int main(){
    /*
        asd             412
     +  sas             141
     -------- =>  -----------
        bbc             553
    */
    u_map solution = solve_cryptarithm("asd","sas","bbc");
    print_solution(solution);

    std::cout<<std::endl;
   
    /*
        aaa
      + aaa
       ----- => "All permutations were used! There's no solution of the Criptharithm."
        aab
    
      'b' and 'a' are different characters, so their numbers should also be different 
    */
   solution = solve_cryptarithm("aaa", "aaa", "aaa");

    return 0;
}

const u_map solve_cryptarithm(
        const std::string& first, 
        const std::string& second, 
        const std::string& result ) 
{
    u_map solution;
    try{
        const str_arr args = {first, second, result};
        const u_set chars = get_chars(first + second + result);
        solution = next_cryptarithm_solution(chars);

        while(!check_solution(solution, args)) 
            solution = next_cryptarithm_solution(chars);
    }
    catch (const ThereIsNoMorePermutations & e){
        std::cout<<"ThereIsNoMorePermutations"<<" : "<<e.what()<<std::endl;
    }
    return solution;
}

const u_set get_chars(const std::string & str){
    u_set chars;
    
    chars.insert(str.begin(), str.end()); 
    
    return chars;
}

const u_map next_cryptarithm_solution(const u_set & chars){
    const s_vec digits = N_digits_of_the_next_permutation(chars.size());
    u_map solution;
    auto ch_iter = chars.begin();
    auto d_iter = digits.begin();

    // chars.size() == digs.size() !!!
    while(ch_iter != chars.end())
        solution[*ch_iter++] = *d_iter++;
    
    return solution;
}

bool check_solution(u_map & solution, const str_arr & args){
    long long int num1 = str_to_num_from_solution(solution, args[0]);
    long long int num2 = str_to_num_from_solution(solution, args[1]);
    long long int res = str_to_num_from_solution(solution, args[2]);

    return num1 + num2 == res;
}

const s_vec N_digits_of_the_next_permutation(const short int N){
    static s_vec digs = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    if ( ! std::next_permutation(digs.begin(), digs.end()) ) throw ThereIsNoMorePermutations();
    
    return s_vec(digs.begin(), digs.begin()+N);
}

long long int str_to_num_from_solution(u_map & solution, const std::string & str){
    std::string num;
    
    for(auto elem : str)
        num.push_back(static_cast<char>(solution[elem] + '0'));
    
    return std::stoi(num);
}

void print_solution(u_map & solution){
    std::cout<<"K : V"<<std::endl<<"-----"<<std::endl;
    for(auto & elem : solution)
        std::cout<<elem.first<<" : "<<elem.second<<std::endl;
}