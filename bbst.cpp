#include <iostream> 
#include <stack> using 
namespace std; 
class Node 
{ 
public: 
 int key; Node* 
left,*right; int 
height; Node(int 
n) 
 { 
 key=n; 
 left=right=NULL; 
 } 
}; 
int height(Node *root) 
{ 
 if(root==NULL) 
return 0; 
 return 1 + max(height(root->left),height(root->right)); 
} 
Node *rightRotate(Node *y) 
{ 
 Node *x = y->left; 
Node *T2 = x->right; 
x->right = y; y->left 
= T2; 
 y->height = max(height(y->left),height(y->right)) + 1; x-
>height = max(height(x->left),height(x->right)) + 1; return 
x; 
} 
Node *leftRotate(Node *x) 
{ 
 Node *y = x->right; 
Node *T2 = y->left; 
y->left = x; x->right 
= T2; 
 x->height = max(height(x->left),height(x->right)) + 1; y-
>height = max(height(y->left),height(y->right)) + 1; return 
y; 
} 
int getBalance(Node *N) 
{ 
 if (N == NULL) 
 return 0; 
 return height(N->left) - height(N->right); 
} 
Node* insertNode(Node* node, int key) 
{ 
 if (node == NULL) 
 { 
 Node * n=new Node(key); 
 return n; 
 } 
 if (key < node->key) 
 node->left = insertNode(node->left, key); 
else if (key > node->key) node->right = 
insertNode(node->right, key); else return 
node; 
 node->height = 1 + max(height(node->left), 
 height(node->right)); int 
balance = getBalance(node); if (balance > 
1 && key < node->left->key) return 
rightRotate(node); if (balance < -1 && key 
> node->right->key) 
 return leftRotate(node); if (balance 
> 1 && key > node->left->key) 
 { 
 node->left = leftRotate(node->left); 
 return rightRotate(node); 
 } 
 if (balance < -1 && key < node->right->key) 
 { 
 node->right = rightRotate(node->right); 
 return leftRotate(node); 
 } 
 return node; 
} 
int main() 
{ 
 Node *root=NULL; 
root=insertNode(root,10); 
root=insertNode(root,20); 
root=insertNode(root,30); 
root=insertNode(root,40); 
root=insertNode(root,50); 
root=insertNode(root,60); 
root=insertNode(root,70); 
root=insertNode(root,75); 
root=insertNode(root,80); cout<<"Height 
of tree: "<<height(root); 
 return 0; 
}
