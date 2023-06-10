
// Online C++ compiler to run C++ program online
// #include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
    int data;
    node* next;
public:
    node(int x){
        data=x;
        next=NULL;
    }
    friend class graph;
};
class graph{
    node** head;
    int size;
public:
    graph(int x){
        // cout<<"int here";
        head=new node*[x];
        size=x;
        for(int i=0;i<x;i++){
            head[i]=new node(i);
        }
    }
    
    void insert(int s,int d){
        if(s<0 || s >= size || d < 0 || d >= size){
            cout<<"enter valid numbers\n";
            return;
        }
        node* nn=new node(d);
        node* temp=head[s];
        while(temp->next){
            temp=temp->next;
        }
        temp->next=nn;
        node* nn2=new node(s);
        temp=head[d];
        while(temp->next){
            temp=temp->next;
        }
        temp->next=nn2;
    }
    
    void bfs(int x){
        int arr[size]={0};
        queue<int> q;
        node* temp=head[x];
        q.push(x);
        // cout<<"inbfs  "<<q.front()<<"\n";
        while(!q.empty()){
            temp=head[q.front()];
            q.pop();
            // cout<<"inbfs  "<<q.front()<<"\n";
            if(arr[temp->data]==0){
                cout<<temp->data<<" ";
                arr[temp->data]=1;
            }
            temp=temp->next;
            while(temp){
                if(arr[temp->data]==0){
                   q.push(temp->data);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }
    
    void dfs(int x){
        int arr[size]={0};
        stack<int> q;
        node* temp=head[x];
        q.push(x);
        // cout<<"inbfs  "<<q.front()<<"\n";
        while(!q.empty()){
            temp=head[q.top()];
            q.pop();
            // cout<<"inbfs  "<<q.front()<<"\n";
            if(arr[temp->data]==0){
                cout<<temp->data<<" ";
                arr[temp->data]=1;
            }
            temp=temp->next;
            while(temp){
                if(arr[temp->data]==0){
                   q.push(temp->data);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<"-->";
            node* temp=head[i];
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main() {
    graph g(5);
    g.insert(0,1);
    g.insert(1,4);
    g.insert(2,1);
    g.insert(3,0);
    g.insert(2,3);
    g.display();
        // cout<<"DONE !\n";
    cout<<"BFS ";g.bfs(0);
    cout<<"DFS ";g.dfs(0);
    
    
    return 0;
}