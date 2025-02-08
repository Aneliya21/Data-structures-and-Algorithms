#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N = 0;
    cin >> N;

    vector<char> input(N, '0');

    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        input[i] = ch;
    }

    vector<int> numbers(N, 0);

    for (int i = 0; i < N; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            int num = input[i] - '0';
            numbers[i] = num + 1;
        }
        else if (input[i] >= 'a' && input[i] <= 'z') {
            int current = input[i] - 86;
            numbers[i] = current;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            int current = input[i] - 28;
            numbers[i] = current;
        }
    }

    vector<int> counter(62, 0);

    for (int i = 0; i < N; i++) {
        counter[numbers[i] - 1]++;

    }

    for (int i = 1; i <= 61; i++) {
        counter[i] += counter[i - 1];
    }

    vector<int> sortedNumbers(N);

    for (int i = N - 1; i >= 0; i--) {
        sortedNumbers[counter[numbers[i] - 1] - 1] = numbers[i];
        counter[numbers[i] - 1]--;
    }

    vector<char> output(N);

    for (int i = 0; i < N; i++) {
        if (sortedNumbers[i] >= 1 && sortedNumbers[i] <= 10) {
            char current = (sortedNumbers[i] - 1) + '0';
            output[i] = current;
            continue;
        }
        if (sortedNumbers[i] >= 11 && sortedNumbers[i] <= 36) {
            char current = sortedNumbers[i] + 86;
            output[i] = current;
            continue;
        }
        if (sortedNumbers[i] >= 37 && sortedNumbers[i] <= 62) {
            char current = sortedNumbers[i] + 28;
            output[i] = current;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << output[i];
    }

    return 0;
}
