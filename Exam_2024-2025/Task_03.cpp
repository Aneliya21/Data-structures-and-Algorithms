#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N, K;
    cin >> N >> K;
    
    vector<int> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    unordered_map<int, vector<int>> um;
    um[0].push_back(-1);
    
    int currSum = 0, count = 0, maxS = -1;

    for (int i = 0; i < N; i++) {
        currSum += input[i];

        if (um.count(currSum - K)) {
            for (int start : um[currSum - K]) {
                int size = i - start;
                maxS = max(maxS, size);
                count++;
            }
        }
        
        um[currSum].push_back(i);
    }

    if (count == 0) {
        cout << -1 << endl;
    } else {
        cout << maxS << " " << count << endl;
    }

    return 0;
}
