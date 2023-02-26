// Online C++ compiler to run C++ program online
#include <iostream>
#include <queue>
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
  
  void insertLevelWise(node* &root){
      queue<node*> q;
      cout<<"enter data for root ";
      int d;cin>>d;
      root=new node(d);
      q.push(root);
      while(!q.empty()){
          node*temp=q.front();
          q.pop();
          cout<<"enter left of "<<temp->data;
          int ld;cin>>ld;
          if(ld!=-1){
              temp->left=new node(ld);
              q.push(temp->left);
          }
          cout<<"enter right of "<<temp->data;
          int rd;cin>>rd;
          if(ld!=-1){
              temp->right=new node(rd);
              q.push(temp->right);
          }
      }
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
    cout<<"inorder ";bt.inorder(bt.root);cout<<"\n";
    cout<<"preorder ";bt.preorder(bt.root);cout<<"\n";
    cout<<"postorder ";bt.postorder(bt.root);cout<<"\n";
    bt.levelTrav(bt.root);
    return 0;
}
