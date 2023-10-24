#include <iostream>
#include <vector>

int knapsack(const int W, const std::vector<int>& wt, const std::vector<int>& val, const int n) {
    std::vector<std::vector<int>> K(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0) {
                K[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                K[i][w] = std::max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }

    return K[n][W];
}

int main() {
    std::vector<int> val = {10, 40, 30, 50};
    std::vector<int> wt = {5, 4, 6, 3};
    int W = 10;
    int n = val.size();
    int max_val = knapsack(W, wt, val, n);
    std::cout << "Maximum value: " << max_val << std::endl;
    return 0;
}
