// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class node{
public:
    int data;
    node*left,*right;
    node(int x){
        data=x;
        left=right=NULL;
    }
    friend class bt;
};
class bt{
public:
    node* root;
    void operator=(bt &obj)
    {
        this->root = copytree(obj.root);
    }
    node *copytree(node *t)
    {
        node *cp = NULL;
        if (t != NULL)
        {
            cp = new node(t->data);
            cp->left = copytree(t->left);
            cp->right = copytree(t->right);
        }
        return cp;
    }
    node* insert(node* root){
        cout<<" enter ";
        int x;cin>>x;
        root=new node(x);
        if(x==-1){
            return NULL;
        }
        cout<<"enter data in left of "<<x<<" ";
        root->left=insert(root->left);
        cout<<"enter data in right of "<<x<<" ";
        root->right=insert(root->right);
        return root;
    }
    void inorderNR(node* root){
        stack<node*> s;
        // s.push(root);
        node* t=root;
        while( t!=NULL || !s.empty()){
            while(t!=NULL){
                s.push(t);
                t=t->left;
            }
            if(s.empty()) return;
            t=s.top();
            s.pop();
            cout<<t->data<<" ";
            t=t->right;
        }
    }
    void preorderNR(node* root){
        if(!root){cout<<"empty\n";return;}
        stack<node*> s;
        s.push(root);
        node* t=NULL;
        while(!s.empty()){
            t=s.top();
            s.pop();
            cout<<t->data<<" ";
            if(t->right){s.push(t->right);}
            if(t->left){s.push(t->left);}
        }
    }
    void inorder(node* root){
        if(!root)return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    void preorder(node* root){
        if(!root)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorderNR(node* root){
        if(!root){cout<<"EMPTY\n";return;}
        vector<int> v;
        stack<node*> s;
        s.push(root);
        node*par=NULL;
        while(!s.empty()){
            node*curr=s.top();
            if(par==NULL || par->left==curr || par->right==curr){
                // cout<<"in1 ";
                if(curr->left){
                    s.push(curr->left);
                }
                else if(curr->right){
                    s.push(curr->right);
                }
                else{
                    s.pop();
                    v.push_back(curr->data);
                }
            }
            else if(curr->left == par){
                // cout<<"in2 ";
                if(curr->right){
                    s.push(curr->right);
                }
                else{
                    s.pop();
                    v.push_back(curr->data);
                }
            }
            else if(curr->right==par){
                // cout<<"in3 ";
                s.pop();
                v.push_back(curr->data);
            }
            par=curr;
        }
        for(auto i:v){
            cout<<i<<" ";
        }cout<<endl;
    }
    int leaf(node* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return (leaf(root->left)+leaf(root->right));
    }
    void postorder(node* root){
        if(!root)return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    int countNode(node* root){
        if(!root) return 0;
        return 1+countNode(root->right)+countNode(root->left);
    }
    int height(node* root){
        if(!root) return 0;
        int l=height(root->left);
        int r=height(root->right);
        return max(l,r)+1;
    }
    void swaptree(node* root){
        if(!root) return;
        swap(root->left,root->right);
        swaptree(root->left);
        swaptree(root->right);
    }
};
int  main(){
    bt obj;
    // for(int i=0;i<5;i++){
        // int x;cin>>x;
        obj.root=obj.insert(obj.root);
    // }
    cout<<"inorder ";obj.inorder(obj.root);cout<<endl;
    cout<<"inorderNR ";obj.inorderNR(obj.root);cout<<endl;
    cout<<"preorder ";obj.preorder(obj.root);cout<<endl;
    cout<<"preorderNR ";obj.preorderNR(obj.root);cout<<endl;
    cout<<"postorder ";obj.postorder(obj.root);cout<<endl;
    cout<<"postorderNR ";obj.postorderNR(obj.root);
    cout<<"leaf "<<obj.leaf(obj.root)<<endl;
    cout<<"nodes "<<obj.countNode(obj.root)<<endl;
    cout<<"height "<<obj.height(obj.root)<<endl;
    obj.swaptree(obj.root);
    bt newobj=obj;
    cout<<"inorder ";newobj.inorder(newobj.root);cout<<endl;
    newobj.root->left=NULL;
    cout<<"inorder ";newobj.inorder(newobj.root);cout<<endl;
return 0;
}