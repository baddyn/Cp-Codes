#include<bits/stdc++.h>
using namespace std;

struct node
{ int data;
node* left;
node* right;
};   // arrays can also   be used for complete binary trees


node* getnewnode(int data)
{node* temp=new node;
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}
node* insert(node* root,int data)
{ if(root==NULL)
root=getnewnode(data);
else 
if(data<= root->data)
root->left=insert(root->left,data);
else 
root->right=insert(root->right,data);
return root;
    }

bool search(node* root,int data)
{if(root==NULL)
return false;
else if(root->data==data)
return true;
else if (root->data>=data)
return search(root->left,data);
else return search(root->right,data);}

int findmin(node* root) //here root is local so can modify it
{                        // iterative method
if(root==NULL)
return -1;
    while(root->left!=NULL)
    root=root->left;
    return root->data;
    }
    
    
int findmax(node* root) // recursive method
{if(root==NULL)
return -1;
else if(root->right==NULL)
    return root->data;
    else 
    return findmax(root->right);
    }
    
    
    int height_of_tree( node* root) // same as max depth
{ int leftheight;
int rightheight;
if(root==NULL)
return -1;
leftheight=height_of_tree(root->left);
rightheight=height_of_tree(root->right);
return max(leftheight,rightheight)+1;}

void levelorder(node* root)
{ if(root==NULL)
return ;
queue<node*>q;
q.push(root);
while(!q.empty())
{ node* current=q.front();
q.pop();
cout<<current->data<<"  ";
if(current->left!=NULL)
q.push(current->left);
if(current->right!=NULL)
q.push(current->right);}}


int main()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    node* root=NULL;
root=insert(root,5);
root=insert(root,6);
root=insert(root,7);
root=insert(root,8);
root=insert(root,10);
root=insert(root,100);
root=insert(root,101);
root=insert(root,102);
root=insert(root,104);
int number;
cin>>number;
if(search(root,number)==true)
cout<<"found";
else 
    cout<<"not found";
    cout<<endl<<findmin(root)<<endl;;
    cout<<findmax(root)<<endl;
    cout<<height_of_tree(root)<<endl;
    levelorder(root);
    cout<<endl;
    }
