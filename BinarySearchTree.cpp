//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : manish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node{
public:
	int no;
	node* left,*right;
	node(int no=0){
		left=right=NULL;
		this->no=no;
	}
};
class BST{
public:
	node* root=NULL;
	void insert(int x){
		node* nn=new node(x);
		node* curr=root,* parent;
		if(root==NULL){
			root=nn;
		}
		else{
			while(true){
				parent=curr;
				if(x < parent->no){
					curr=curr->left;
					if(curr==NULL){
						parent->left = nn;
						return;
					}
				}
				else{
					curr=curr->right;
					if(curr== NULL){
						parent->right=nn;
						return;
					}
				}
			}
		}
	}

	void InOrder(node* root){
		node* curr=root;
		if(curr==NULL) return;
		InOrder(curr->left);
		cout<<curr->no<<" ";
		InOrder(curr->right);
	}

	void preOrder(node* root){
		node* curr=root;
		if(curr==NULL) return;
		cout<<curr->no<<" ";
		preOrder(curr->left);
		preOrder(curr->right);
	}
	
	void postOrder(node* root){
		node* curr=root;
		if(curr==NULL) return;
		postOrder(curr->left);
		postOrder(curr->right);
		cout<<curr->no<<" ";
	}
	
	void MaxMin(node* root){
	    node* l=root;
	    int mn=root->no;
	    int mx=mn;
	    while(l->left != NULL){
	        l=l->left;
	    }
	    mn=l->no;;
	    l=root;
	    while(l->right !=NULL){
	        l=l->right;
	    }
	    mx=l->no;
	    cout<<"max is "<<mx<<" and min is "<<mn<<"\n";
	}
	void search(int x){
        bool found=true;
        node* curr=root;
        while(curr->no != x){
            if(curr!=NULL){
                if(curr->no<x){
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            if(curr==NULL){
                found=false;
                break;
            }
        }
        if(found){cout<<"Found\n";}
        else cout<<"Not Found\n";
	}
};

int main() {
	int u=6,k=0;
	BST bst;
	while(k<u){
		cout<<"enter ";
		int x;cin>>x;
		bst.insert(x);
		k++;
	}k=0;
	bst.InOrder(bst.root);cout<<endl;
	bst.preOrder(bst.root);cout<<endl;
	bst.postOrder(bst.root);cout<<endl;
	bst.search(4);
    	bst.MaxMin(bst.root);
	return 0;
}
