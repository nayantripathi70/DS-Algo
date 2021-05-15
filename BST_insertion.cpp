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
    
    bt.print2D(bt.root,0);
    return 0;
}