// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node{
public:  
    node*left,*right;
    int data;
    bool lthread,rthread;
    node(){
        lthread=rthread=false;
        left=right=NULL;
        data=-1;
    }
    node(int x){
        data=x;
        lthread=rthread=false;
        left=right=NULL;
    }
    // friend class tbst;
};
class tbst{
public:
    node* root=NULL;
    
    node* insert(int x){
        node* ptr=root,*par=NULL;
        while(ptr){
            if(ptr->data==x){
                cout<<"DUPLICATE DATA\n";
                return root;
            }
            par=ptr;
            if(x<par->data){
                if(par->lthread){
                    ptr=ptr->left;
                }
                else{break;}
            }
            else{
                if(par->rthread){
                    ptr=ptr->right;
                }
                else{break;}
            }
        }
        node* nn=new node(x);
        if(par == NULL){                                                     
            root=nn;                                                    //    4
                                                                    //      3   5
        }
        else if(x < par->data){
            nn->left = par->left;
            nn->right= par;
            par->lthread=true;
            par->left=nn;
        }
        else{
            nn->right = par->right;
            nn->left= par;
            par->rthread=true;
            par->right=nn;
        }
        return root;
    }
    
    node* inorderSucc(node* root){
        if(root->rthread == false){
            return root->right;   
        }
        node* temp=root->right;
        while(temp->lthread){
            temp=temp->left;
        }
        return temp;
    }
    node* inorderPred(node* root){
        if(root->lthread == false){
            return root->left;   
        }
        node* temp=root->left;
        while(temp->rthread){
            temp=temp->right;
        }
        return temp;
    }
    
    void inorder(node* root){
        if(!root){
            cout<<"EMPTy\n";
            return;
        }
        cout<<"-------------INORDER-----------------\n";
        node* temp=root;
        while(temp->lthread){
            temp=temp->left;
        }
        while(temp){
            cout<<temp->data<<" ";
            temp=inorderSucc(temp);
        }
        cout<<endl;
    }
    node* caseA(node* root,node* par,node* ptr){
        if(!par){
            root=NULL;
        }
        if(par->left == ptr){    
            par->lthread=false;
            par->left=ptr->left;
        }
        else if(par->right == ptr){
            par->rthread=false;
            par->right=ptr->right;
        }
        delete(ptr);
        return root;
    }
    node* caseB(node* root,node* par,node* ptr){
        

        //
        node* child;
        if(ptr->lthread){
            child=ptr->left;
        }
        else{
            child=ptr->right;
        }
        if(!par){
            root=child;
        }
        else if(par->left == ptr){
            // par->lthread=false;
            par->left=child;
        }
        else if(par->right == ptr){
            // par->rthread=false;
            par->right=child;
        }
        
        node* p=inorderPred(ptr);
        node* s=inorderSucc(ptr);
        
        if(ptr->lthread){
            p->right=s;
        }
        else if(ptr->rthread){
            s->left=p;
        }
        delete(ptr);
        return root;
    }
    
    node* caseC(node* root,node* par,node* ptr){
        node* pars=ptr;
        node* suc=ptr->right;
        while(suc->lthread){
            pars=suc;
            suc=suc->left;
        }
        ptr->data = suc->data;
        
        if(!suc->lthread && !suc->rthread){
            root =caseA(root,pars,suc);
        }
        else{
            root =caseB(root,pars,suc);
        }
        return root;
    }
    void deleteNode(int x){
        bool found=false;
        node* ptr=root,*par=NULL;
        while(ptr){
            if(ptr->data==x){
                found =true;
                break;
            }
            par=ptr;
            if(x<par->data){
                if(par->lthread){
                    ptr=ptr->left;
                }
                else{break;}
            }
            else{
                if(par->rthread){
                    ptr=ptr->right;
                }
                else{break;}
            }
        }
        if(!found){
            cout<<"NOT present\n";
        }
        else{
            if(ptr->lthread && ptr->rthread){
                root= caseC(root,par,ptr);
            }
            else if(!ptr->rthread && !ptr->rthread){
                root= caseA(root,par,ptr);
            }
            else{
                root= caseB(root,par,ptr);
            }
        }
        // return root;
    }
};
int main() {
    tbst obj;
    obj.inorder(obj.root);
    obj.root = obj.insert(6);
    obj.root = obj.insert(23);
    obj.root = obj.insert(1);
    obj.root = obj.insert(3);
    obj.inorder(obj.root);
    obj.root = obj.insert(3);
    obj.root = obj.insert(4);
    obj.inorder(obj.root);
    obj.root = obj.insert(8);
    obj.root = obj.insert(2);
    obj.inorder(obj.root);
    obj.deleteNode(4);
    obj.inorder(obj.root);
    obj.deleteNode(6);
    obj.inorder(obj.root);
    obj.deleteNode(34);
    obj.root = obj.insert(45);
    obj.inorder(obj.root);

    return 0;
}   