#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

/**
 * @brief Find the factorial of an number.
 * 
 * This function uses the recursive approach.
 * 
 * @param n The of that we have to find factorial of.
 * @return The factorial of 'n'.
 */
double factorial_r(int n) {
    if (n <= 1) {
        return 1;
    }

    return factorial_r(n - 1) * n;
}

/**
 * @brief Find the factorial of an number.
 * 
 * This function uses the iterative approach.
 *  
 * @param n The of that we have to find factorial of.
 * @return The factorial of 'n'.
 */
double factorial_i(int n) {
    double ans = 1;

    while (n >= 2) {
        ans *= n;
        n--;
    }
    return ans;
}

/**
 * @brief Find the nth number in fibonacci series.
 * 
 * This function uses the recursive approach.
 * 
 * @param n The 'nth' number. 
 * @return The 'nth' fibonacci number.
 */
double fibonacci_r(int n) {
    if (n <= 2) {
        return 1;
    }

    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

/**
 * @brief Find the nth number in fibonacci series.
 * 
 * This function uses the iterative approach.
 * 
 * @param n The 'nth' number. 
 * @return The 'nth' fibonacci number.
 */
double fibonacci_i(int n) {
    if (n <= 2) {
        return 1;
    }

    double ans = 1;
    double pre = 1;

    for (int i = 3; i <= n; i++) {
        double temp = ans;
        ans += pre;
        pre = temp;
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    std::vector<std::chrono::duration<double, std::nano>> ans;

    for (int i = 21; i < 31; i++) {
        auto start = std::chrono::system_clock::now();
        auto t = fibonacci_i(i);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
        ans.push_back(elapsed_seconds);
    }

    for (int i = 21; i < 31; i++) {
        auto start = std::chrono::system_clock::now();
        auto t = fibonacci_r(i);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
        ans.push_back(elapsed_seconds);
    }

    for (int i = 21; i < 31; i++) {
        auto start = std::chrono::system_clock::now();
        auto t = factorial_i(i);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
        ans.push_back(elapsed_seconds);
    }

    for (int i = 21; i < 31; i++) {
        auto start = std::chrono::system_clock::now();
        auto t = factorial_r(i);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double, std::nano> elapsed_seconds = end - start;
        ans.push_back(elapsed_seconds);
    }

    std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;
    std::cout << "|" << std::setw(10) << "Number"
              << "|" << std::setw(15) << "Iterative"
              << "|" << std::setw(15) << "Recursive"
              << "|" << std::setw(15) << "Iterative"
              << "|" << std::setw(15) << "Recursive"
              << "|" << std::endl
              << "|" << std::setw(10) << "of inputs"
              << "|" << std::setw(15) << "fibonacci"
              << "|" << std::setw(15) << "fibonacci"
              << "|" << std::setw(15) << "factorial"
              << "|" << std::setw(15) << "factorial"
              << "|" << std::endl;
    std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "|" << std::setw(10) << (i + 1) + 20 << "|"
                  << std::setw(11) << ans[i].count() << " ms |"
                  << std::setw(11) << ans[i + 9].count() << " ms |"
                  << std::setw(11) << ans[i + 9].count() << " ms |"
                  << std::setw(11) << ans[i + 9].count() << " ms |" << std::endl;
        std::cout << "+----------+---------------+---------------+---------------+---------------+" << std::endl;
    }

    return 0;
}
