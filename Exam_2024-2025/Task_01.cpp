#include <bits/stdc++.h>
using namespace std;
 
struct Land {
    double d, p, index;
   
    bool operator<(const Land& other) const {
        if (p == other.p) {
            return d > other.d;
        }
        return p < other.p;
    }
};
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
 
    int N;
    cin >> N;
   
    vector<Land> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].d;
        cin >> v[i].p;
        v[i].index = i + 1;
    }
   
    vector<double> l(N);
    for (int i = 0; i < N; i++) {
        double r = v[i].d / 2;
        l[i] = 2*r*r;
    }
   
    vector<double> prices(N);
    for (int i = 0; i < N; i++) {
        int price = v[i].p;
        prices[i] = price / l[i];
    }
   
    vector<Land> r(N);
    for (int i = 0; i < N; i++) {
        r[i].d = v[i].d;
        r[i].p = prices[i];
        r[i].index = i;
    }
   
    sort(r.begin(), r.end());
   
    for (int i = 0; i < N; i++) {
        cout << r[i].index + 1 << " ";
    }
 
    return 0;
}