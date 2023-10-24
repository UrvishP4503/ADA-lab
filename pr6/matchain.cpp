#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

int matrix_chain_multiplication(const std::vector<int>& size) {
    int n = size.size() - 1;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            m[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + size[i] * size[k + 1] * size[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    std::cout << "+----+----+----+----+----+" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >= i) {
                std::cout << "|" << std::setw(4) << m[i][j];
            } else {
                std::cout << "|" << std::setw(5);
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+----+----+" << std::endl;
    }

    return m[0][n - 1];
}

int main() {
    std::vector<int> p = {4, 10, 3, 12, 20, 7};
    int min_scalar_multiplications = matrix_chain_multiplication(p);
    std::cout << "Minimum scalar multiplications: " << min_scalar_multiplications << std::endl;
    return 0;
}