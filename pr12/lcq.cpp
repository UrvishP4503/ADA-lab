#include <iostream>
#include <string>
#include <vector>

std::string longest_common_subsequence(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Initialize a 2D vector to store the lengths of LCS
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS
    std::string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs = str1[i - 1] + lcs;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return lcs;
}

int main() {
    std::string str1 = "stone";
    std::string str2 = "longest";

    std::string result = longest_common_subsequence(str1, str2);
    std::cout << "string 1: " << str1 << " and string 2: " << str2 << "\n";
    std::cout << "The Longest Common Subsequence is: " << result << std::endl;

    str1 = "ABCDGH";
    str2 = "AEDFHR";

    std::string result2 = longest_common_subsequence(str1, str2);
    std::cout << "\nstring 1: " << str1 << " and string 2: " << str2 << "\n";
    std::cout << "The Longest Common Subsequence is: " << result2 << std::endl;

    return 0;
}
