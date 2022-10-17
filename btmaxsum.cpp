#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
struct node
{
 int data;
 node *left;
 node *right;
};
int maxsum=0;
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
vector<int> longestPath(node* root)
{
 if (root == NULL) {
 vector<int> temp
 = {};
 return temp;
 }
 vector<int> rightvect
 = longestPath(root->right);
 vector<int> leftvect
 = longestPath(root->left);
 if (leftvect.size() > rightvect.size())
 leftvect.push_back(root->data);
 else
 rightvect.push_back(root->data);
 return (accumulate(leftvect.begin(),leftvect.end(),0) 
>accumulate(rightvect.begin(),rightvect.end(),0)
 ? leftvect
 : rightvect);
}
int main() {
node *root;
root=insertion(0);
vector<int> a=longestPath(root);
for (int i = 0; i < a.size(); i++)
 cout << a[i] << " ";
 cout << endl;
 cout << "\nSum = "
 << accumulate(a.begin(), a.end(), 0);
 return 0;
}
