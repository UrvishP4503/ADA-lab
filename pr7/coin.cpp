#include <iostream>
#include <limits>
#include <vector>

int coin_change(const std::vector<int>& coins, const int target_sum) {
    std::vector<int> dp(target_sum + 1, std::numeric_limits<int>::max());

    dp[0] = 0;

    for (int i = 1; i <= target_sum; ++i) {
        for (int c : coins) {
            if (c <= i) {
                dp[i] = std::min(dp[i], dp[i - c] + 1);
            }
        }
    }

    // if target_sum is possible then print the coins.
    if (dp[target_sum] != std::numeric_limits<int>::max()) {
        int i = target_sum;
        std::cout << "Selected Coins: ";
        while (i > 0) {
            for (int c : coins) {
                if (dp[i] == dp[i - c] + 1) {
                    std::cout << c << " ";
                    i -= c;
                    break;
                }
            }
        }
    }

    return dp[target_sum] != std::numeric_limits<int>::max() ? dp[target_sum] : -1;
}

int main() {
    std::vector<int> coins = {1, 5, 10, 25};
    int target_sum = 63;
    std::cout << "Given Coins: ";
    for (int c : coins) {
        std::cout << c << " ";
    }

    std::cout << std::endl;
    int min_coins = coin_change(coins, target_sum);

    std::cout << std::endl
              << "Target sum: " << target_sum << std::endl;
    std::cout << "Minimum number of coins needed: " << min_coins << std::endl;
    return 0;
}