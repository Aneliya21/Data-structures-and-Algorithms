#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void printMedian(const vector<int>& vec) {
    int n = vec.size();
    
    if (n % 2 == 1) {
        cout << vec[n / 2] << endl;
    } 
    else {
        double median = (vec[n / 2 - 1] + vec[n / 2]) / 2.0;
        cout << median << endl;
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<int> numbers;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        auto pos = lower_bound(numbers.begin(), numbers.end(), num);
        numbers.insert(pos, num);
    
        printMedian(numbers);
    }
    
    return 0;
}
