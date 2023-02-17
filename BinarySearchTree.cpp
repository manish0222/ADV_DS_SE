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
	BST bst;
	while(true){
	    cout<<"enter\n1)to add\n2)inorder\n3)preordder\n4)postorder\n5)min max\n6)search\n7)swap\n";
	    int n;cin>>n;
	    if(n==1){
	        cout<<"entertotal elements ";
		    int x;cin>>x;
		    for(int i=0;i<x;i++){
		        cout<<"enter element ";
		        int j;cin>>j;
		        bst.insert(j);   
		    }
	    }
	    else if(n==2){bst.InOrder(bst.root);cout<<endl;}
	    else if(n==3){	bst.preOrder(bst.root);cout<<endl;}
	    else if(n==4){	bst.postOrder(bst.root);cout<<endl;}
	    else if(n==5){bst.MaxMin(bst.root);}
        else if(n==6){
            cout<<"enter number ";
            int x;cin>>x;
            	bst.search(4);
        }
        else{
            
        }
	}
	return 0;
}
