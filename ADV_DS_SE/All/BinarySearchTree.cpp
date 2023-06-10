
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
		if(curr==NULL)return;
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
	    cout<<"\n------------------------------------------------\n";
	    cout<<"\t\t";cout<<"max is "<<mx<<" and min is "<<mn<<"\n";
	    cout<<"-------------------------------------------------\n";
	}

	node* search(int x){
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
        if(found){return curr;}
        else return NULL;
	}

	void swapTree(node* &root){
		if(root==NULL){return;}
		swap(root->left,root->right);
		swapTree(root->left);
		swapTree(root->right);
	}

	int longestPath(node* root){
		if(root==NULL){
			return 0;
		}
		int l=longestPath(root->left);
		int r=longestPath(root->right);
		int lp=max(r,l);
		lp++;
		return lp;
	}

	node* deleteNode(node* root,int key){
	    if(root==NULL){
	        return root;
	    }
	    if(root->no == key){
	        //0 child
	        if(root->left == NULL && root->right ==NULL){
	            delete root;
	            return NULL;
	        }
	        // 1 child
	        else if(root->left==NULL && root->right!=NULL){
	            node* temp=root->right;
	            delete root;
	            return temp;
	        }
	        else if(root->right==NULL && root->left!=NULL){
	            node* temp=root->left;
	            delete root;
	            return temp;
	        }
	        // 2 child
	        else{
	            node* curr=root->right;
	            while(curr->left!=NULL){
	                curr=curr->left;
	            }
	            root->no=curr->no;
	            root->right=deleteNode(root->right,curr->no);
	            return root;
	        }

	    }
	    //left la jaycha
	    else if(root->no >key){
	        root->left = deleteNode(root->left,key);
	        return root;
	    }
	    //right la jaycha
	    else{
	        root->right = deleteNode(root->right,key);
	        return root;
	    }
	    cout<<"\n------------------------------\n\t deleted node\n";
	    return root;
	}
};

int main() {
	BST bst;
		cout<<"enter total elements ";
		int x;cin>>x;
		for(int i=0;i<x;i++){
			cout<<"enter element ";
			int j;cin>>j;
			bst.insert(j);
		}
	while(true){
	    cout<<"enter\n1)to add\n2)inorder\n3)preorder\n"
	    		"4)postorder\n5)min max\n"
	    		"6)search\n7)swap\n"
	    		"8)longestPath\n9)delete node\n";
	    int n;cin>>n;
	    if(n==1){
	        cout<<"enter total elements ";
		    int x;cin>>x;
		    for(int i=0;i<x;i++){
		        cout<<"enter element ";
		        int j;cin>>j;
		        bst.insert(j);
		    }
	    }
	    else if(n==2){
	    	cout<<"\n------------------INORDER---------------------\n";
	    	cout<<"\t";bst.InOrder(bst.root);
	    	cout<<endl;
	    	cout<<"------------------------------------------------\n";
	    }
	    else if(n==3){
	    	cout<<"\n------------------PREORDER---------------------\n";
	    	cout<<"\t";bst.preOrder(bst.root);
	    	cout<<"\n------------------------------------------------\n";
	    }
	    else if(n==4){
	    	cout<<"\n------------------POSTORDER---------------------\n";
	    	cout<<"\t";bst.postOrder(bst.root);
	    	cout<<"\n------------------------------------------------\n";
	    }
	    else if(n==5){bst.MaxMin(bst.root);}
        else if(n==6){
            cout<<"enter number ";
            int x;cin>>x;
            node* k=bst.search(x);
            if(k==NULL){cout<<"Not Found\n";}
            else cout<<"Found\n";
        }
        else if(n==7){
        	bst.swapTree(bst.root);
        }
        else if(n==8){

        	cout<<"\n ------------------LONGEST PATH ---------------------\n";
        	int k=bst.longestPath(bst.root);
        	cout<<"\t";cout<<"longest path is "<<k<<endl;
        	cout<<"------------------------------------------------------\n";
        }
        else{
            cout<<"enter no to be deleted ";
            int x;cin>>x;
            bst.root = bst.deleteNode(bst.root,x);
            cout<<"deleted the node\n";
        }
    }
    return 0;
}
