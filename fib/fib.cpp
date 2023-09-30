#include <functional>
#include <iostream>
#include <unordered_map>

// double fib(int n, std::unordered_map<int, double> &memo) {
//     if (memo.find(n) != memo.end()) {
//         return memo[n];
//     } else if (n <= 2) {
//         return 1;
//     } else {
//         memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
//         return memo[n];
//     }
// }

int main(int argc, char const *argv[]) {
    static std::unordered_map<int, double> memo;

    const std::function<double(int)> fib = [&](int n) -> int {
        return (memo.find(n) != memo.end()) ? memo[n]
               : (n <= 2)                   ? 1
                                            : (memo[n] = fib(n - 1) + fib(n - 2));
    };
    std::cout << fib(3);
}
