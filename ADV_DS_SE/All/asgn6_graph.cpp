//============================================================================
// Name        : asgn6.cpp
// Author      : manish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================\
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class node{
    int data;
    node* next;
public:
    node(){
        data=-1;
        next=NULL;
    }
    node(int data){
        this->data=data;
        next=NULL;
    }
    friend class graph;
};
class graph{
    node** head;
    bool *visited;                                       //most important take head as ** double pointer
    int ver;
 public:
    graph(int v){
        ver=v;
        head=new node*[v];
        visited = new bool[v];
        for(int i=0;i<ver;i++){
            head[i]=new node(i);
            visited[i]=false;
        }
    }
    
    void insert(int s,int d){
        if(s<0 || d<0 ||s>=ver || d>=ver){
            cout<<"enter feasible ranged values\n";
            return;
        }
        node* n1=new node(d);
        node* temp = head[s];
        while(temp->next){
            temp=temp->next;
        }
        temp->next=n1;
        node* temp2=head[d];
        while(temp2->next){
            temp2=temp2->next;
        }
        temp2->next=new node(s);
    }
    
    void display(){
        for(int i=0;i<ver;i++){
            cout<<"--> ";
            node* temp=head[i];
            while(temp){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    
    void bfs(int s){
        node* start=head[s];
        queue<int> q;
        // visited[ver];
        int arr[ver]={0};
        q.push(start->data);
        node*temp=NULL;
        while(!q.empty()){
            temp=head[q.front()];
            if(!arr[temp->data]){
                cout<<temp->data<<" ";
            }
            arr[temp->data]=1;
            q.pop();
            temp=temp->next;
            while(temp){
                if(!arr[temp->data]){
                    q.push(temp->data);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }
    
    void dfs(int s){
        cout<<"DFS ";
        stack<int> st;
        node* temp=head[s];
        int arr[ver]={0};
        st.push(temp->data);
        while(!st.empty()){
            temp=head[st.top()];
            if(!arr[temp->data]){
                cout<<temp->data<<" ";
            }
            arr[temp->data]=1;
            st.pop();
            temp=temp->next;
            while(temp){
                if(!arr[temp->data]){
                    st.push(temp->data);
                }
                temp=temp->next;
            }
        }
        cout<<endl;
    }
};
int main() {
    graph g(4);
    g.insert(1,2);
    g.insert(2,3);
    g.insert(3,0);                                      //make menu DRIVEN BY YOURSELF
    g.insert(0,1);
    // g.insert(1,3);
    g.display();
    g.bfs(0);
    g.bfs(1);
    g.bfs(3);
    g.dfs(0);
    g.dfs(1);
    g.dfs(3);

    return 0;
}

                                                         //  METHOD 2  USING MAPS
                                         // ACTUAL PROBLEMSET IS EXPECTS US TO HAVE ADJACENCY LIST
// #include <iostream>
// //#include <unordered_map>
// //#include <map>
// //#include <set>
// //#include <stack>
// //#include <vector>
// #include<bits/stdc++.h>
// using namespace std;
// //template<class T>
// //class queue{
// //	T arr[20];
// //	int front,rear;
// //public:
// //	queue(){
// //		front = rear = -1;
// //	}
// //	void push(T x){
// //		if(rear==-1){
// //			front++;rear++;
// //			arr[front]=x;
// //		}
// //		else{
// //			rear++;
// //			arr[rear]=x;
// //		}
// //	}
// //	void pop(){
// //		front++;
// //		if(front>rear){
// //			front=rear=-1;
// //		}
// //	}
// //	bool empty(){
// //		return (rear==-1);
// //	}
// //	T frontNode(){
// //		if(!empty()){
// //			return arr[front];
// //		}
// //	}
// //};
// template <class T>
// class graph{
// public:
//    map<T,set<T>> m;
//    int edges,node;
//     graph(){edges=node=-1;}
//     void insert(T a,T b,bool directed){
//         m[a].insert(b);
//         //0 is not directed
//         if(!directed){
//             m[b].insert(a);
//         }
//     }

//     void bfs(){
//         unordered_map<T,bool> visitedNode;
//         vector<T> v;
//         queue<T> q;
//         for(auto i:m){
//             visitedNode[i.first]=false;
//         }
//         auto i=m.begin();
//         q.push(i->first);
//         visitedNode[(i)->first]=true;
//         while(!q.empty()){
// //            int front=q.frontNode();
//         	int front=q.front();
//             q.pop();
//             v.push_back(front);
//             for(auto i: m[front]){
//                 if(!visitedNode[i]){
//                 	cout<<"in "<<i<<" ";
//                     q.push(i);
//                     visitedNode[i]=1;
//                 }
//             }
//         }
//         cout<<"bfs traversal [ ";
//         for(auto i:v){
//             cout<<i<<" ";
//         }cout<<" ]"<<endl;
//     }

//     void dfs(){
//         unordered_map<T,bool> visitedNode;
//         vector<T> v;
//         stack<T> q;
//         for(auto i:m){
//             visitedNode[i.first]=false;
//         }
//         auto i=m.begin();
//         q.push(i->first);
//         while(!q.empty()){
//             int front=q.top();
//             q.pop();
//             if(!visitedNode[front]){
//             	v.push_back(front);
//             	visitedNode[front]=true;
//             }
//             for(auto i=m.begin();i!=m.end();i++){
//             	if (!visitedNode[i->first]){
//             		q.push(i->first);
//             	}
//             }
//         }
//         cout<<"DFS traversal [ ";
//         for(auto i:v){
//             cout<<i<<" ";
//         }cout<<" ]"<<endl;

//     }

//     void display(){
//     	cout<<" Traversal\n";
//         for(auto i:m){
//             cout<<i.first<<"-> ";
//             for(auto j:i.second){
//                 cout<<j<<", ";
//             }
//             cout<<endl;
//         }
//     }
// };
// int main() {
//     graph<int> g;
//     cout<<"enter nodes ";cin>>g.node;
//     cout<<"enter edges ";cin>>g.edges;
//     for(int i=0;i<g.edges;i++){
//         int a,b;
//         cin>>a>>b;
//         g.insert(a,b,0);
//     }
//     int n;
//     do{
//     	cout<<"\n1)Display matrix\n2)Bfs traversal\n3)DFS traversal\nChoice ";
//     	int x;cin>>x;
//     	if(x==1){
//     	    g.display();
//     	}
//     	else if(x==2){
//     	    g.bfs();
//     	}
//     	else if(x==3){
//     		g.dfs();
//     	}

//     	cout<<"continue by 1 ";
//     	cin>>n;
//     }while(n==1);

//     return 0;
// }
