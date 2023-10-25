#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

void optimal_parens(std::vector<std::vector<int>>& s, int i, int j) {
    if (i == j) {
        std::cout << "A" << i + 1 << " ";
        return;
    }
    std::cout << "(";
    optimal_parens(s, i, s[i][j]);
    optimal_parens(s, s[i][j] + 1, j);
    std::cout << ")";
}
int matrix_chain_multiplication(const std::vector<int>& size) {
    int n = size.size() - 1;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            m[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {
                int q = m[i][k] + m[k + 1][j] + size[i] * size[k + 1] * size[j + 1];
                if (q < m[i][j]) {
                    s[i][j] = k;
                    m[i][j] = q;
                }
            }
        }
    }

    std::cout << "+----+----+----+----+----+" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j >= i) {
                std::cout << "|" << std::setw(4) << s[i][j];
            } else {
                std::cout << "|" << std::setw(5);
            }
        }
        std::cout << "|" << std::endl;
        std::cout << "+----+----+----+----+----+" << std::endl;
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

    std::cout << std::endl;
    std::cout << "Most optimal parenthesization: ";
    optimal_parens(s, 0, 4);

    std::cout << std::endl;
    return m[0][n - 1];
}

int main() {
    std::vector<int> p = {4, 10, 3, 12, 20, 7};
    int min_scalar_multiplications = matrix_chain_multiplication(p);
    std::cout << "\nMinimum scalar multiplications: " << min_scalar_multiplications << std::endl;
    return 0;
}