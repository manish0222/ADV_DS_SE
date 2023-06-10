//============================================================================
// Name        : asgn7.cpp
// Author      : manish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <limits.h>
#include<bits/stdc++.h>
using namespace std;
//template<class T>
//class queue{
//	T arr[20];
//	int front,rear;
//public:
//	queue(){
//		front = rear = -1;
//	}
//	void push(T x){
//		if(rear==-1){
//			front++;rear++;
//			arr[front]=x;
//		}
//		else{
//			rear++;
//			arr[rear]=x;
//		}
//	}
//	void pop(){
//		front++;
//		if(front>rear){
//			front=rear=-1;
//		}
//	}
//	bool empty(){
//		return (rear==-1);
//	}
//	T frontNode(){
//		if(!empty()){
//			return arr[front];
//		}
//	}
//};
template <class T>
class graph{
public:
   unordered_map<T,list<pair<T,int>>> m;
   int edges,node;
    graph(){edges=node=-1;}
    void insert(T a,T b,int w,bool directed){
        m[a].push_back(make_pair(b,w));
        //0 is not directed
        if(!directed){
            m[b].push_back(make_pair(a,w));
        }
    }

    void prims(){
        vector<bool> mst(node+1);
        vector<int> parent(node+1);
        vector<int> key(node+1);
        
        for(int i=0;i<=node;i++){
            mst[i]=false;
            parent[i]=-1;
            key[i]=INT_MAX;
        }
        
        //starting to code
        key[1]=0;
        parent[1]=-1;
                //note till   <node
        for(int i=1;i<node;i++){
            
            // find min node
            int minum=INT_MAX;
            int u=-1;
            for(int v=1;v<=node;v++){
                if(!mst[v] && key[v] <= minum){
                    u=v;
                    minum=key[v];
                }
            }
            
            // mark min node true;
            mst[u]=true;
            //go in adjacent
            
            for(auto it:m[u]){
                int v=it.first;
                int w=it.second;
                if(mst[v]==false && w<key[v]){
                    parent[v]=u;
                    key[v]=w;
                }
            }
        }
        
        vector<pair<pair<int,int>,int>> ans;
        int val=0;
        for(int i=node;i>=2;i--){
            auto v=make_pair(parent[i],i);
            auto m=make_pair(v,key[i]);
            ans.push_back(m);
            // cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
            val+=key[i];
        }
        sort(ans.begin(),ans.end());
        for(auto [i,j]:ans){
            cout<<i.first<<" "<<i.second<<" "<<j<<endl;
        }
// 1 5 9
// 1 4 42
// 1 3 19
// 1 2 95
// 2 5 75
// 2 3 51
// 2 4 66
// 4 3 31
// 1 5 9
        cout<<"MST is "<<val<<endl;
    }
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
    void makepair(vector<int> &parent,vector<int> &rank){
        for(int i=0;i<node;i++){
            parent[i]=i;
            rank[i]=0;
        }
    }
    void unionSet(int u,int v,vector<int> &parent,vector<int> &rank){
        u=findParent(parent,u);
        v=findParent(parent,v);
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[v]<rank[u]){
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    int findParent(vector<int> &parent,int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent,parent[node]);
    }
    void kruskal(vector<vector<int>> &v){
        sort(v.begin(),v.end(),cmp);
        vector<int> parent(node);
        vector<int> rank(node);
        makepair(parent,rank);
        int ans=0;
        for(int i=0;i<edges;i++){
            int u=findParent(parent,v[i][0]);
            int s=findParent(parent,v[i][1]);
            int wt=v[i][2];
            
            if(u!=s){
                ans+=wt;
                unionSet(u,s,parent,rank);
            }
        }
        
        cout<<"mst is "<<ans<<"\n";
    }
};
int main() {
    graph<int> g;
    int n;
    do{
    	cout<<"\n1)Prims\n2)Kruskals\nChoice ";
    	int x;cin>>x;
    	if(x==1){
    	    cout<<"enter nodes ";cin>>g.node;
            cout<<"enter edges ";cin>>g.edges;
            for(int i=0;i<g.edges;i++){
                int a,b,c;
                cin>>a>>b>>c;
                g.insert(a,b,c,0);
            }
    	    g.prims();
    	}
    	else if(x==2){
          vector<vector<int>> v;
    	    cout<<"enter nodes ";cin>>g.node;
            cout<<"enter edges ";cin>>g.edges;
            for(int i=0;i<g.edges;i++){
                int a,b,c;
                cin>>a>>b>>c;
                vector<int> temp={a,b,c};
                v.push_back(temp);
            }
    	    g.kruskal(v);
    	}
    	else if(x==3){
    // 		g.dfs();
    	}

    	cout<<"continue by 1 ";
    	cin>>n;
    }while(n==1);

    return 0;
}

                           // CODE TWO OF PRIMS ALGORITHM

// #include <iostream>
// using namespace std;

// class graph{
//     int ver, wt;
//     int **adjMat;
//     public:
//     graph(){
//         ver = 0;
//         wt = 0;
//         adjMat = NULL;
//     }
//     graph(int v,int w){
//         ver = v;
//         wt = w;
//         adjMat = new int*[v];
//         for(int i=0;i<ver;i++){
//             adjMat[i] = new int[ver];
//         }
//         for(int i=0;i<ver;i++){
//             for(int j=0;j<ver;j++){
//                 adjMat[i][j] = 0;
//             }

//         }
//     }

//     void insert(int s,int d,int w ){
//         adjMat[s][d] = w;
//         adjMat[d][s] = w;
//     }

//     void display(){
//         for(int i=0;i<ver;i++){
//             for(int j=0;j<ver;j++){
//                 cout<<adjMat[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }

//     int Prim(int start,int **arr,int &path){
//         path = 0;
//         int reached[ver]={0},unreached[ver] = {1};
//         reached[start] = 1;
//         unreached[start] = 0;
//         for(int i=0;i<ver;i++){
//             int v1 = i,v2,mini = 1e5;
//             if(reached[i]==1){
//                 for(int j=0;j<ver;j++){
//                     if(adjMat[i][j]<mini && adjMat[i][j]!=0){
//                         mini = adjMat[i][j];
//                         v2 = j;
//                         reached[j] = 1;
//                         unreached[j] = 0;
//                     }
//                 }
//             }
//             path+=adjMat[v1][v2];
//             arr[v1][v2] = 1;
//             arr[v2][v1] = 1;
//         }
//         return path;
//     }
// };

// int main(){
//     int v,e;
//     cout<<"Enter number of vertices "<<endl;
//     cin>>v;
//     cout<<"Enter number of edges "<<endl;
//     cin>>e;
//     graph g(v,e);
//     for(int i=0;i<e;i++){
//         int s,d,w;
//         cout<<"Enter source "<<endl;
//         cin>>s;
//         cout<<"Enter destination "<<endl;
//         cin>>d;
//         cout<<"Enter weight "<<endl;
//         cin>>w;
//         g.insert(s,d,w);
//     }
//     g.display();
//     int **arr = new int *[v];
//     for(int i=0;i<v;i++){
//         arr[i] = new int[v];
//     }
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             arr[i][j] = 0;
//         }
//     }
//     int path = g.Prim(0,arr,path);
//     cout<<"Prim's Matrix"<<endl;
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl<<"Minimum path value is "<<path<<endl;

// }

