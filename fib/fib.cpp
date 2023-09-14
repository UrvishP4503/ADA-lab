#include <iostream>
#include <unordered_map>

double fib(int n, std::unordered_map<int, int> &memo) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    } else if (n <= 2) {
        return 1;
    } else {
        memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
        return memo[n];
    }
}

int main(int argc, char const *argv[]) {
    std::unordered_map<int, int> temp;

    auto i = fib(23, temp);

    std::cout << i;

    return 0;
}
