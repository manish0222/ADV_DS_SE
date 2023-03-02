
// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
class node{
    node*left,*right;
    int data;
public:
    node(int data){
        this->data=data;
        left=right=NULL;
    }

    friend class BinaryTree;
};
class BinaryTree{
public:
  node* root=NULL;
    // BinaryTree opearator=(BinaryTree &c){
    //     BinaryTree b;

    // }
  node* insert(node* root){
      cout<<"enter data ";
      int x;cin>>x;
      root=new node(x);
      if(x == -1){
          return NULL;
      }
      cout<<"enter left data of "<<x<<" ";
      root->left=insert(root->left);
      cout<<"enter right data of "<<x<<" ";
      root->right=insert(root->right);
      return root;
  }

  void inorderNonRecur(node* root){
      stack <node*> s;
      node* t=root;
      while(t!=NULL || !s.empty()){
          while(t!=NULL){
              s.push(t);
              t=t->left;
          }
          if(s.empty()){
              return;
          }
          t=s.top();
          s.pop();
          cout<<t->data<<" ";
          t=t->right;
      }

  }
  void preorederNonRecur(node* root){
	  stack<node*> s;
	  if(root==NULL){cout<<"empty node \n";return;}
	  s.push(root);
	  node* t=NULL;
	  while(!s.empty()){
		  t=s.top();
		  s.pop();
		  cout<<t->data<<" ";
		  if(t->left){s.push(t->left);}
		  if(t->right){s.push(t->right);}
	  }
  }
  void postOrderNonrecur(node* root){
	  if(root==NULL){
		  cout<<"empty ";
		  return;
	  }
	  stack<node*> s;
	  s.push(root);
	  while(!s.empty()){

	  }
  }
  void inorder(node* root){
      if(root==NULL){return;}
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
  }

  void preorder(node* root){
      if(root==NULL){return;}
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
  }

  void postorder(node* root){
      if(root==NULL){return;}
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
  }

  int Height(node* root){
      if(root == NULL){
          return 0;
      }
      int lval=Height(root->left);
      int rval=Height(root->right);
      int k=max(lval,rval)+1;
      return k;
  }

  void insertLevelWise(node* &root){
      queue<node*> q;
      cout<<"enter data for root ";
      int d;cin>>d;
      root=new node(d);
      q.push(root);
      while(!q.empty()){
          node*temp=q.front();
          q.pop();
          cout<<"enter left of "<<temp->data<<" ";
          int ld;cin>>ld;
          if(ld!=-1){
              temp->left=new node(ld);
              q.push(temp->left);
          }
          cout<<"enter right of "<<temp->data<<" ";
          int rd;cin>>rd;
          if(rd!=-1){
              temp->right=new node(rd);
              q.push(temp->right);
          }
      }
  }
  int inCount(node* root){
      if( root==NULL || (!(root->left) && !(root->right) )){
          return 0;
      }
      return 1+inCount(root->left)+inCount(root->right);
      //T.C = O(n)
  }

  int leafCount(node* root){
      if(!root->left && !root->right){
          return 1;
      }
      int j=0,k=0;
      if(root->left){k=leafCount(root->left);}
      if(root->right){j=leafCount(root->right);}
      return (k+j);
  }

  int intNode(node* root){
      int k=intNode(root->left);
      int j=intNode(root->right);
      if(root->left || root->right){
          return 1;
      }
  }

  void swapBT(node* &root){
      if(root==NULL)return ;
      swap(root->left,root->right);
      swapBT(root->left);
      swapBT(root->right);
  }

  node* deleteNode(node* root){
      if(root==NULL){
          return NULL;
      }
      deleteNode(root->left);
      deleteNode(root->right);
      delete (root);
  }
  void levelTrav(node* root){
      queue<node*> q;
      q.push(root);
      q.push(NULL);
      while(!q.empty()){
          node* temp=q.front();
          q.pop();
          if(temp==NULL){
              cout<<endl;
              if(!q.empty()){
                  q.push(NULL);
              }
          }
          else{
              cout<<temp->data<<" ";
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
          }
      }
  }
};
int main() {
    BinaryTree bt;
    bt.insertLevelWise(bt.root);
    // bt.root=bt.insert(bt.root);
    while(true){
        cout<<"enter\n0)enter data\n1)display\n2)swap tree\n3)find height\n" ;
        //"4)copy tree\n5)count all nodes\n6)delete nodes\n7)end\nchoice ";
        int n;cin>>n;
        if(n==0){
                bt.insertLevelWise(bt.root);
        }
        else if(n==1){
            cout<<"\n-----------------------------------------\n";
            cout<<"inorder ";bt.inorder(bt.root);cout<<"\n";
            cout<<"inorder non-recursively ";bt.inorderNonRecur(bt.root);cout<<"\n";
            cout<<"preorder ";bt.preorder(bt.root);cout<<"\n";
            cout<<"preoreder NonRecur ";bt.preorederNonRecur(bt.root);cout<<"\n";
            cout<<"postorder ";bt.postorder(bt.root);cout<<"\n";
            cout<<"postorder ";bt.postorder(bt.root);cout<<"\n";
            cout<<"-----------------------------------------\n";
        }
        else if(n==2){
            bt.swapBT(bt.root);
            cout<<"---Swapped----\n";
        }
        else if(n==3){
            cout<<"\n-----------------------------------------\n";
            cout<<"\t height of tree is "<<bt.Height(bt.root);cout<<"\n";
            cout<<"-----------------------------------------\n";

        }
//        else if(n==4){
//
//        }
        else if(n==5){
            cout<<"\n-----------------------------------------\n";
            cout<<"leafnode ";
            if(!bt.root){ cout<<"empty";cout<<"\n";}
            else{cout<<(bt.leafCount(bt.root));cout<<"\n";}
            cout<<"internalnode "<<bt.inCount(bt.root);cout<<"\n";
            cout<<"-----------------------------------------\n";
        }
//        else if(n==6){
//            bt.root=bt.deleteNode(bt.root);
//        }else if(n==7){
//            cout<<"_________Ended_________\n";
//        }
    }

    //bt.levelTrav(bt.root);  to display all data in that level

    // cout<<"inorder ";bt.inorder(bt.root);cout<<"\n";
    //     cout<<"preorder ";bt.preorder(bt.root);cout<<"\n";
    // cout<<"postorder ";bt.postorder(bt.root);cout<<"\n";
    //  BinaryTree test;
    //  test=bt;
    // cout<<"inorder ";test.inorder(test.root);cout<<"\n";

    return 0;
}


