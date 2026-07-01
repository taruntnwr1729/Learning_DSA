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

void Preorder(Node* root){
    if(root==NULL){
        return ;

    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Postorder(Node* root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->left->right = new Node(70);
    cout<<endl;
    cout<<"Preorder: ";
    Preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    Postorder(root);
    cout<<endl;
    cout << "Maximum depth of the tree is: " << maxDepth(root) << endl;

    return 0;
}