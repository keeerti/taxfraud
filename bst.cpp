#include<iostream> 
#include<stack> 
#include<queue> 
using namespace std; 
class Node 
{ 
public: int 
data; 
Node* left; 
 Node* right; 
}; 
Node* createnode(int data) 
{ 
 Node* root=new Node(); 
root->data=data; root-
>left=NULL; root-
>right=NULL; 
 return root; 
} 
int getheight(Node* n) 
{ 
 if(n==NULL) 
 { 
 return 0; 
 } 
 else 
{ 
 int height=max(getheight(n->left),getheight(n->right)); 
return height+1; 
 } 
} 
void Insert(Node* root,int key) 
{ 
 Node* prev=NULL; 
while(root!=NULL) { 
 prev=root; 
 if(key==root->data) 
 { 
 cout<<"CANNOT INSERT "<<key<<endl; 
 return; 
 } 
 else if(key<root->data) 
 { 
 root= root->left; 
 } 
else 
 { 
 root = root->right; 
 } 
 } 
 Node* n = createnode(key); 
 if(key<prev->data) 
 { 
 prev->left=n; 
 } 
 else 
 { 
 prev->right=n; 
 } 
} 
void inorder(Node* root) 
{ 
 stack<Node*>s; Node* curr=root; 
while(curr!=NULL || s.empty()==false) 
 { 
 while(curr!=NULL) 
 { 
 s.push(curr); 
 curr=curr->left; 
 } 
 curr=s.top(); 
s.pop(); cout<<curr-
>data<<" "; 
 curr=curr->right; 
 } 
} 
void preorder(Node* root) 
{ 
 if(root==NULL) 
return; 
 stack<Node*>s; 
s.push(root); 
while(s.empty()==false) 
 { 
 Node* n=s.top(); 
cout<<n->data<<" "; 
s.pop(); if(n->right) 
 { 
 s.push(n->right); 
 } if(n-
>left) 
 { 
 s.push(n->left); 
 } 
 } 
} 
void postorder(Node* root) 
{ 
 if(root==NULL) 
return; 
 stack<Node*>s1,s2; 
s1.push(root); Node* 
node; 
while(s1.empty()==false) 
 { 
 node=s1.top(); 
s1.pop(); 
s2.push(node); if(node-
>left) 
 { 
 s1.push(node->left); 
 } 
 if(node->right) 
 { 
 s1.push(node->right); 
 } 
 } 
 while(s2.empty()==false) 
 { 
 node=s2.top(); 
s2.pop(); cout<<node-
>data<<" "; 
 } 
} 
void levelorder(Node* root) 
{ 
 if(root==NULL) 
return; 
 queue<Node*>q; 
q.push(root); 
 while(q.empty()==false) 
 { 
 Node* node=q.front(); 
 cout<<node->data<<" "; 
q.pop(); if(node->left) 
 q.push(node->left); 
if(node->right) 
 q.push(node->right); 
 } 
} 
int main() 
{ 
 Node* root=NULL; 
root=createnode(10); 
Insert(root,20); 
 Insert(root,30); 
 Insert(root,40); 
 Insert(root,50); 
 Insert(root,60); 
 Insert(root,70); 
 Insert(root,75); Insert(root,80); int 
height=getheight(root); cout<<"Height of 
binary tree: "<<height<<endl; 
 cout<<endl; 
cout<<"Inorder: "; 
inorder(root); cout<<endl; 
cout<<"Preorder: "; 
preorder(root); 
cout<<endl; 
cout<<"Postorder: "; 
postorder(root); 
cout<<endl; 
cout<<"Levelorder: "; 
levelorder(root); return 0; 
} 
