#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> gold(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> gold[i][j];
        }
    }
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, 0));
 
    dp[0][0] = gold[0][0];
 
    for (int j = 1; j < m; ++j) {
        dp[0][j] = dp[0][j - 1] + gold[0][j];
    }
 
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + gold[i][0];
    }
 
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dp[i][j] = gold[i][j] + std::max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    std::cout << dp[n - 1][m - 1] << std::endl;
    return 0;
}
