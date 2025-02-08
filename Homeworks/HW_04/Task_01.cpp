#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Apple {
    unsigned x;
    unsigned y;

    Apple(unsigned x, unsigned y) : x(x), y(y) {}
};

bool isValid(unsigned x, unsigned y, unsigned N, unsigned M) {
    return x <= N && x > 0 && y > 0 && y <= M;
}


void ddz(int x, int y, int &countOfRotten, queue<Apple>& rotten, bool allApples[1000][1000]) {
    Apple current(x, y);
    rotten.push(current);
                
    allApples[x][y] = true;
    countOfRotten++;
}

int main() {
    
    unsigned N, M, T;
    cin >> N >> M >> T;
    
    long long maxApples = N * M;
    
    bool allApples[N + 1][M + 1] = {};  
    queue<Apple> rotten;
    
    unsigned x = 0, y = 0;
    unsigned countOfRotten = 0;
    
    while (cin >> x >> y) {
        if (isValid(x, y, N, M)) {    
            Apple toPush(x, y);
            rotten.push(toPush);
            allApples[x][y] = true;
            countOfRotten++;
        }
        
    }

    for (unsigned i = 0; i < T; i++) {
        
        unsigned toCheck = rotten.size();
        
        for (unsigned j = 0; j < toCheck; j++) {
            
            unsigned currX = rotten.front().x;
            unsigned currY = rotten.front().y;
            
            rotten.pop();
            
            if (isValid(currX - 1, currY, N, M) && !allApples[currX - 1][currY]) {
                rotten.push(Apple(currX - 1, currY));
                allApples[currX - 1][currY] = true;
                countOfRotten++;
            }
            if (isValid(currX, currY - 1, N, M) && !allApples[currX][currY - 1]) {
                rotten.push(Apple(currX, currY - 1));
                allApples[currX][currY - 1] = true;
                countOfRotten++;
            }
            
            if (isValid(currX + 1, currY, N, M) && !allApples[currX + 1][currY]) {
                rotten.push(Apple(currX + 1, currY));
                allApples[currX + 1][currY] = true;
                countOfRotten++;
            }
            
            if (isValid(currX, currY + 1, N, M) && !allApples[currX][currY + 1]) {
                rotten.push(Apple(currX, currY + 1));
                allApples[currX][currY + 1] = true;
                countOfRotten++;
            }
        
        }
    }

    cout << maxApples - countOfRotten;
    return 0;
}