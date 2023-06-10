#include <iostream>
using namespace std;
class heap{
    int arr[100];
    int size=0,n;
    // arr[0] =  1;
public:
    heap(){
        arr[0]=-1;
    }
    void create(){
        cout<<"ENTER total ";
        cin>>this->n;
        for(int i=0;i<n;i++){
            cout<<"enter ";
            int x;cin>>x;
            insert(x);
        }
    }
    
    void insert(int x){
        size++;
        int index=size;
        arr[index]=x;
        while(index>1){
            int parent=index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{return;}
        }
    }
    void heapify(int arr[],int n,int i){
        if(n==0) return;        //imp
        int large=i;
        int left=2*i;
        int right=2*i+1;
        
        if(left<=n && arr[left] > arr[large]){
            large=left;
        }
        if(right<=n && arr[right] > arr[large]){
            large=right;
        }
        if(large!=i){
            swap(arr[large],arr[i]);
            heapify(arr,n,large);
        }
    }
    
    void print(){
        cout<<"ARRAY - ";
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
    void heapsort(){
        int s=size;
        while(s>1){
            swap(arr[1],arr[s]);
            s--;
            heapify(arr,s,1);
        }
    }
};
int main(){
    heap obj;
    obj.create();
    obj.print();
    obj.heapsort();
    obj.print();
}