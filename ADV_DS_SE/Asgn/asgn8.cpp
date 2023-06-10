// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*left,*right;
    node(){
        data=-1;left=right=NULL;
    }
    node(int x){
        data=x;
        left=right=NULL;
    }
    friend class obst;
};
class obst{
public:
    pair<node*,int> insert(vector<int> &keys,vector<int> &freq,int start,int end){
        if(start>end){
            return {NULL,0};
        }
        int sum=0;
        for(int i=start;i<=end;i++) sum+=freq[i];
        
        int mn=INT_MAX,minInd=-1;
        
        for(int i=start;i<=end;i++){
            int cost=sum + ((i>start)?insert(keys,freq,start,i-1).second:0)+((i<end)?insert(keys,freq,i+1,end).second:0);
            if(cost<mn){
                mn=cost;
                minInd=i;
            }
        }
        node* root=new node(keys[minInd]);
        auto lt=insert(keys,freq,start,minInd-1);
        auto rt=insert(keys,freq,minInd+1,end);
        
        root->left=lt.first;
        root->right=rt.first;
        int ans=mn;
        return {root,ans};
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
};
int main() {
    vector<int> keys={10,12,15};
    vector<int> freq={34,50,5};
    obst obj;
    auto ans=obj.insert(keys,freq,0,2);
    cout<<"cost "<<ans.second<<endl;
    cout<<"inorder ";obj.inorder(ans.first);
    cout<<"preorder ";obj.preorder(ans.first);
    return 0;
}