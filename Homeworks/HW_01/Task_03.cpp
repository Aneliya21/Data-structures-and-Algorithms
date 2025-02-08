#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool comparePoints(const std::pair<string, int>& f, const std::pair<string, int>& s) {
    return f.second > s.second;
}
bool compareNames(const std::pair<string, int>& f, const std::pair<string, int>& s) {
    if(f.second == s.second) {
        string name1 = f.first;
        string name2 = s.first;
        return (name1.compare(name2)) < 0;
    }
    return false;
}

int main() {
    int N = 0;
    cin >> N;
    
    vector<string> names(N);
    
    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;
        names[i] = name;
    }
    
    vector<int> points(N);
    
    for(int i = 0; i < N; i++) {
        int score;
        cin >> score;
        points[i] = score;
    }
    
    vector<std::pair<string, int>> result;
    
    for(int i = 0; i < N; i++) {
        std::pair<string, int> current(names[i], points[i]);
        result.push_back(current);
    }

    std::sort(result.begin(), result.end());
    std::stable_sort(result.begin(), result.end(), comparePoints);
    
    for(int i = 0; i < N; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }
    
    return 0;
}