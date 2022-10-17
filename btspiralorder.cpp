#include <iostream>
#include<queue>
#include<stack>
#include <bits/stdc++.h>
using namespace std;
struct node
{
char data;
node *left;
node *right;
};
struct node * newNode(char F)
{
node *N=new node;
N->left=NULL;
N->right=NULL;
N->data=F;
return N;
}
node *insertnode(char c,queue<node *>&q,struct node *root)
{
node * Node=newNode(c);
if(root==NULL)
{
root=Node;
}
else if(q.front()->left==NULL)
q.front()->left=Node;
else
{
q.front()->right=Node;
q.pop();
}
q.push(Node);
return root;
}
node * createtree()
{
node *root=NULL;
char arr[9]={'A','B','C','D','E','F','G','H','I'};
queue<node *>q;
for(int i=0;i<9;i++)
root=insertnode(arr[i],q,root);
return root;
}
void levelorder(node *root)
{
if(root==NULL)
return;
queue<node *>q1;
q1.push(root);
while(q1.empty()==false)
{
node *f=q1.front();
cout<<f->data<<" ";
q1.pop();
if(f->left!=NULL)
q1.push(f->left);
if(f->right!=NULL)
q1.push(f->right);
}
}
void spiralorder(node *root)
{
stack<struct node*>s1;
stack<struct node*>s2;
s1.push(root);
while(!s1.empty()||!s2.empty())
{
while(!s1.empty())
{
node *temp1=s1.top();
cout<<temp1->data<<" ";
s1.pop();
if(temp1->right)
s2.push(temp1->right);
if(temp1->left)
s2.push(temp1->left);
}
while(!s2.empty())
{
node *temp2=s2.top();
cout<<temp2->data<<" ";
s2.pop();
if(temp2->left)
s1.push(temp2->left);
if(temp2->right)
s1.push(temp2->right);
}
}
}
int main()
{
node *root;
root=createtree();
cout<<"LEVEL ORDER"<<endl;
levelorder(root);
cout<<endl;
cout<<"SPIRAL ORDER"<<endl;
spiralorder(root);
}
