#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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

void LevelOrder(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* current = q.front();
        q.pop();
        if (current == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<current->data<<" ";

        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }

    }

}

int Height(Node* root){
    if(root==NULL){
        return 0;
    }
    int LH = Height(root->left);
    int RH = Height(root->right);
    return max(LH,RH)+1;
    //TIME COMPLEXITY O(n)
}

int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int countL = count(root->left);
    int countR = count(root->right);
    int sum = countL + countR + 1;

    return sum;
}


int sum(Node* root){
    if(root==NULL){
        return 0;
    }
    int sumL = sum(root->left);
    int sumR = sum(root->right);
    int sumtotal = sumL + sumR + root->data;

    return sumtotal;
}

bool sametree(Node* p, Node* q){
    if(p==NULL||q==NULL){
        p==q;
    }
    bool leftpart=sametree(p->left,q->left);
    bool rightpart=sametree(p->right,q->right);

    return leftpart && rightpart && p->data == q->data;
}

bool isSubtree(Node* root, Node* subroot){
    if(root == NULL || subroot == NULL){
        return root == subroot;
    }
    if(root->data==subroot->data && sametree(root,subroot)){
        return true;
    }
    return isSubtree(root->left, subroot)||
    isSubtree(root->right, subroot);
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftDiam = diameter(root->left);
    int rightDiam = diameter(root->right);

    int currdiam = Height(root->left) + Height(root->right);

    return max( leftDiam, rightDiam, currdiam);

}


int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(50);
    root->left->right = new Node(70);
    root->left->right->right = new Node(80);
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

    cout<<"Height of the tree is: "<<Height(root);

    return 0;
}