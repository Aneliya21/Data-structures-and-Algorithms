#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int countWays(int n) {
    if (n == 1) return 2;
    if (n == 2) return 2; 
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    dp[1][0] = 1; 
    dp[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][2] + dp[i - 1][1]) % MOD; 
        dp[i][1] = dp[i - 1][2] % MOD;               
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD; 
    }

    return (dp[n][0] + dp[n][2]) % MOD;
}

int main() {
    int n;
    cin >> n;
    cout << countWays(n) << endl;
    return 0;
}
