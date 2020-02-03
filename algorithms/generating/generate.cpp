#include "../tools.hpp"

struct FibonacciNumbersGenerator {
    private:
        int prev = 0;
        int count = -1;
    public:
        int number = 1;
        int operator() (){
            count++;

            if (count == 0) return 0;
            if (count == 1) return 1;
            
            int temp = number;
            number += prev;
            prev = temp;
            
            return number;
        }
};

int main() {
    std::vector<int> fib_10;
    std::vector<int> fib_20 (20);

    std::generate_n(std::back_inserter(fib_10), 10, FibonacciNumbersGenerator());
    std::generate(fib_20.begin(), fib_20.end(), FibonacciNumbersGenerator());

    print("fib_10: ", fib_10);
    print("fib_20: ", fib_20);

    return 0;
}