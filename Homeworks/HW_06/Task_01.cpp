#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int MAX_TIME = 10080;

int main() {
    int n;
    cin >> n;
    
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    vector<int> dp(MAX_TIME + 1, 0);
    dp[0] = 1;

    for (int t : times) {
        for (int j = MAX_TIME; j >= t; --j) {
            dp[j] = (dp[j] + dp[j - t]) % MOD;
        }
    }

    long long result = 0;
    for (int i = 0; i <= MAX_TIME; ++i) {
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;
    return 0;
}
