#include<bits/stdc++.h>
using namespace std;
#define SPACE 10

class Tree{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

class BST{
public:
    Tree *root=NULL;
    Tree *temp;
    
    Tree *minValueNode(Tree *node){
        while(node->left!=NULL)
            node=node->left;
        return node;
    }
    //Insert Node Using Recursion.
    Tree *insert(Tree *node,int val){
        if(node==NULL)
            node=new Tree(val);
        else if(val<node->data)
            node->left=insert(node->left,val);
        else if(val>node->data)
            node->right=insert(node->right,val);
        else
            cout<<"No Dupicates Allow."<<endl;
        return node;
    }
    //Delete Node using Recursion.
    Tree *delNode(Tree *node,int val){
        if(node==NULL)
            return node;
        else if(val<node->data)
            node->left=delNode(node->left,val);
        else if(val>node->data)
            node->right=delNode(node->right,val);
        else{
            if(node->left==NULL){
                temp=node->right;
                delete node;
                return temp;
            }
            else if(node->right==NULL){
                temp=node->left;
                delete node;
                return temp;
            }
            else{
                temp=minValueNode(node->right);
                node->data=temp->data;
                node->right=delNode(node->right,temp->data);
            }
        }
        return node;
    }

    void inOrderTraversal(Tree *node){
        if(node==NULL)
            return;
        inOrderTraversal(node->left);
        cout<<node->data<<" ";
        inOrderTraversal(node->right);
    }
    //Print Array in Tree Format Left to right.
    void print2D(Tree *node,int space){
        if(node==NULL)
            return;
        space=space+SPACE;
        print2D(node->right,space);
        cout<<endl;
        for(int i=SPACE;i<space;i++)
            cout<<" ";
        cout<<node->data<<endl;
        print2D(node->left,space);
    }
};

template<class T>   //Using This for taking Input Without Variables.
T get(istream& is){ //use get<int>(cin).
    T val;
    is>>val;
    return val;
}

int main()
{
    BST bt;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)//Input : 6 20 15 25 14 16 30 
        bt.root=bt.insert(bt.root,get<int>(cin));
        
    cout<<"InOrder Traversal(LNR): ";
    bt.inOrderTraversal(bt.root);
    bt.delNode(bt.root,20);
    
    bt.print2D(bt.root,0);
    return 0;
}