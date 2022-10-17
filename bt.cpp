#include <iostream>
#include<queue>
using namespace std;
struct node
{
int data;
node *left;
node *right;
};
int a[]={1,2,3,4,5,6,7,0,8,9,0,0,0,10,11,12,13,12,13,0,14,0,0,0,0,0,0,15,0,16,17};
struct node* insertion(int n)
{
node *temp=new node;
temp=NULL;
if(n>sizeof(a)/sizeof(int))
{
return temp;
}
else if(!a[n])
{
return temp;
}
else if(a[n])
{
temp=new node;
temp->data=a[n];
temp->left=insertion(2*n+1);
temp->right=insertion(2*n+2);
}
}
void postorder(node *root)
{
Jahanvi Gupta
21103150
B6
if(root==NULL)
return;
else
{
postorder(root->left);
postorder(root->right);
cout<<root->data<<" ";
}
}
void preorder(node *root)
{
if(root==NULL)
return;
else
{
cout<<root->data<<" ";
preorder(root->left);
preorder(root->right);
}
}
void inorder(node *root)
{
if(root==NULL)
return;
else
{
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}
}
void levelorder(node *root)
{
if (root == NULL) return;
queue < node * > q;
q.push(root);
while (q.empty() == false) {
node * node = q.front();
cout << node -> data << " ";
q.pop();
if (node -> left != NULL)
q.push(node -> left);
if (node -> right != NULL)
q.push(node -> right);
}
}
int main() {
node *root;
root=insertion(0);
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
levelorder(root);
}
