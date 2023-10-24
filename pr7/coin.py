from functools import lru_cache


def wrapper(coins, target):
    @lru_cache
    def coin(target):
        if target == 0:
            return 0
        return min(coin(target - c) for c in coins if c <= target) + 1

    return coin(target)


def coin_change(coins, target_sum):
    n = len(coins)
    dp = [[float("inf") for _ in range(target_sum + 1)] for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = 0
    for i in range(1, n + 1):
        for j in range(1, target_sum + 1):
            if coins[i - 1] <= j:
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j])
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[n][target_sum] if dp[n][target_sum] != float("inf") else -1


print(wrapper([1, 5, 10, 25], 63))
print(coin_change([1, 5, 10, 25], 63))
