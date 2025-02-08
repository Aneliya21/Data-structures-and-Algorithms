#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

long sumContainer[20000000] { 0 };
unsigned minInd = 10000000;
unsigned maxInd = 10000000;
Node nodesContainer[1000000];

void sumColumns(Node* root, size_t index){
    if(root == nullptr) {
        return;
    }
    
    sumContainer[index] += root->data;
    
    if(index < minInd)
        minInd = index;
    
    if(maxInd < index)
        maxInd = index;
    
    sumColumns(root->left, index - 1);
    sumColumns(root->right, index + 1);
}


int main() {
    unsigned N;
    std::cin >> N;
    
    for (unsigned i = 0; i < N; i++) {
        
        int value, leftIndex, rightIndex;
        std::cin >> value >> leftIndex >> rightIndex;
        
        nodesContainer[i].data = value;
        nodesContainer[i].left = leftIndex == -1 ? nullptr : &nodesContainer[leftIndex];
        nodesContainer[i].right = rightIndex == -1 ? nullptr : &nodesContainer[rightIndex];
    }
    
    sumColumns(&nodesContainer[0], minInd);
    
    for (unsigned i = minInd; i <= maxInd; i++) {
        
        if(sumContainer[i] != 0)
            std::cout << sumContainer[i] << " ";
    }
    return 0;
}
