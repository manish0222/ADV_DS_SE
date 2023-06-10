#include <iostream>
#include <climits>
using namespace std;
class Graph{
    int **graph;
    int ver,edges;
public:
    Graph(int v,int e){
        ver=v;
        edges=e;
        graph=new int*[ver];
        for (int  i = 0; i < ver; i++)
        {
           graph[i]=new int[ver];
        }
        for(int i=0;i<ver;i++){
            for(int j=0;j<ver;j++){
                graph[i][j]=0;  //creating a matrix
            }
        } 
    }
    void insert(){
        for(int i=0;i<edges;i++){
            cout<<"enter two vertices ";
            int a,b,w;cin>>a>>b;
            cout<<" weight ";
            cin>>w;
            graph[a][b]=w;
            graph[b][a]=w;
        }
    }
    void display(){
        cout<<"\t\t";
        for(int i=0;i<ver;i++){cout<<i<<"\t";}cout<<endl;
        for(int i=0;i<ver;i++){
            cout<<i<<" ";
            for(int j=0;j<ver;j++){
                cout<<"\t"<<graph[i][j];
            }cout<<endl;
        }
    }

    int minKey(int keys[],bool visited[]){
        int min=99999,minInd=-1;
        for(int i=0;i<ver;i++){
            if(visited[i]==false && keys[i]< min){
                min=keys[i];
                minInd=i;
            }
        }
        return minInd;
    }
    void prims(){
        int keys[ver],parent[ver];
        bool visited[ver];

        for(int i=0;i<ver;i++){
            keys[i]=99999;
            parent[i]=-1;
            visited[i]=false;
        }

        keys[0]=0;    //first node
        parent[0]=-1;

        for(int i=0;i<ver-1;i++){    // imp   ver -1 is imp
            int u=minKey(keys,visited);
            visited[u]=true;           // imp

            for(int v=0;v<ver;v++){
                if( (graph[u][v]) !=0 && (visited[v]==false) && ( graph[u][v] < keys[v] ) ){
                    parent[v]=u;
                    keys[v]=graph[u][v];
                }
            }
        }
        printMST(parent);
    }
    void printMST(int parent[]){
            int sum=0;
                            //imp  start from 1
            cout<<"Edge\tWeight\n";
            for(int i=1;i<ver;i++){
                cout<<parent[i]<<" "<<i<<"    "<<graph[i][parent[i]]<<endl;
                sum+=(graph[i][parent[i]]);
            }

            cout<<"\n--Total cost "<<sum<<endl;
    }
    int find(int i,int parent[]){
        while(parent[i]!=i){
            i=parent[i];
        }
        return i;
    }
    void union1(int i,int j,int parent[]){
        int a=find(i,parent);
        int b=find(j,parent);
        parent[a]=b;
    }
    void kruskals(){
        int parent[ver];
        int minCost=0;
        for(int i=0;i<ver;i++){
            parent[i]=i;    //imp
        }
        int edgecount=0;
        while(edgecount < ver-1){
            int min = INT_MAX,a=-1,b=-1;
            for(int i=0;i<ver;i++){
                for(int j=0;j<ver;j++){
                    if(find(i,parent)!=find(j,parent) && graph[i][j]<min && graph[i][j]!=0){
                        min=graph[i][j];
                        a=i;
                        b=j;
                    } 
                }
            }
            union1(a,b,parent);
            edgecount++;
            minCost+=min;
        }
        cout<<"TOTAL COST "<<minCost<<endl;
    }
};
int main(){
    Graph g(4,5);
    g.insert();
    g.display();
    g.prims();
    g.kruskals();
return 0;
}