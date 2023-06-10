#include <iostream>
using namespace std;
class node{
int data;
node*left,*right;
public:
    node(int x){
        data=x;
        left=right=NULL;
    }
    friend class bst;
};
class bst{
public:
  node* root;
  bst(){
      root=NULL;
  }
  void insert(int x){
      node* nn=new node(x);
      node* par=NULL,*curr=root;
      if(!root){
          root=nn;
      }
      else{
          while(true){
              while(curr){
                  par=curr;
                  if(par->data == x){
                      cout<<"DUPLICATE\n";
                      return;
                  }
                  if(x < par->data){
                      curr=curr->left;
                      if(!curr){
                          par->left=nn;
                          return;
                      }
                  }
                  else{
                      curr=curr->right;
                      if(!curr){
                          par->right=nn;
                          return;
                      }
                  }
              }
          }
      }
  }
  void inorder(node* root){
      if(!root){return;}
      inorder(root->left);
      cout<<root->data<<" ";
      inorder(root->right);
  }
  void preorder(node* root){
      if(!root){return;}
      cout<<root->data<<" ";
      preorder(root->left);
      preorder(root->right);
  }
  void postorder(node* root){
      if(!root){return;}
      postorder(root->left);
      postorder(root->right);
      cout<<root->data<<" ";
  }
  void search(int x){
      bool found=true;
      node* temp=root;
      while(temp->data !=x){
              if(temp){
                  if(x<temp->data){
                      temp=temp->left;
                  }
                  else{
                      temp=temp->right;
                  }
              }
              if(!temp){
                  found=false;
                  break;
              }
      }
      if(!found){
          cout<<"not present\n";
        //   return NULL;
      }
      else{
          cout<<"Found\n";
        //   return temp;
      }
  }
  node* deleteNode(node* root,int x){
      if(!root){
          return NULL;
      }
      else if(root->data == x){
          if(!root->right && !root->left){
              delete (root);
              return NULL;
          }
          else if(!root->right && root->left){
              node* temp=root->left;
              delete(root);
              return temp;
          }
          else if(root->right && !root->left){
              node* temp=root->right;
              delete(root);
              return temp;                                                  
          }
          else{
              node* temp=root->right;
              while(temp->left){
                  temp=temp->left;
              }
              root->data=temp->data;
              root->right-deleteNode(root->right,temp->data);
          }
         return root;
      }
      else if(root->data > x){
          root->left=deleteNode(root->left,x);
          return root;
      }
      else{
          root->right=deleteNode(root->right,x);
          return root;
      }
      return root;
  }
};
int main() {
    bst obj;
    obj.insert(2);
    obj.insert(4);
    obj.insert(3);
    obj.root=obj.deleteNode(obj.root,5);
    cout<<"inordder ";obj.inorder(obj.root);cout<<endl;
    cout<<"preordder ";obj.preorder(obj.root);cout<<endl;
    obj.insert(5);
    cout<<"inordder ";obj.inorder(obj.root);cout<<endl;
    cout<<"preordder ";obj.preorder(obj.root);cout<<endl;
    obj.root=obj.deleteNode(obj.root,5);
    obj.insert(1);
    cout<<"inordder ";obj.inorder(obj.root);cout<<endl;
    cout<<"preordder ";obj.preorder(obj.root);cout<<endl;
    obj.root=obj.deleteNode(obj.root,7);
    cout<<"inordder ";obj.inorder(obj.root);cout<<endl;
    cout<<"preordder ";obj.preorder(obj.root);cout<<endl;
    obj.search(1);
    obj.search(3);
    obj.search(5);
    obj.search(6);
    return 0;
}