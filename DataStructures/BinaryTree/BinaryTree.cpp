#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{

    public:
    int data;
    Node* left;
    Node* right;

    public:
    Node(int key){
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

//THIS FUNCTION TELLS ABOUT NO. OF LEVELS OF BINARY TREE

int maxDepth(Node* root){
    if(root == NULL){
        return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh,rh);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->left->right = new Node(70);
    cout << "Maximum depth of the tree is: " << maxDepth(root) << endl;

    return 0;
}