#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

bool checkRight(Node* root, int value) {
    if(root == nullptr)
        return true;
    
    while(root->right){
        root = root->right;
    }

    return root->value < value;
}

bool checkLeft(Node* root, int value) {
    if(root == nullptr)
        return true;
    
    while(root->left){
        root = root->left;
    }

    return root->value > value;
}

bool isValidBST(Node* root) {
    if (root == nullptr) {
        return true;
    }

    return checkRight(root->left, root->value) && checkLeft(root->right, root->value) && isValidBST(root->left) &&                  isValidBST(root->right);
}

Node nodesContainer[3000000];

int main() {
    

    
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int N = 0;
        cin >> N;

        for (int j = 0; j < N; j++) {
            
            int value, leftIndex, rightIndex;
            cin >> value >> leftIndex >> rightIndex;

            nodesContainer[j].value = value;
            nodesContainer[j].left = leftIndex == -1 ? nullptr : &nodesContainer[leftIndex];
            nodesContainer[j].right = rightIndex == -1 ? nullptr : &nodesContainer[rightIndex];
        }

        cout << isValidBST(&nodesContainer[0]) << '\n';
    }

    return 0;
}