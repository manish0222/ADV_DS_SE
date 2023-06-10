// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class client{
public:
  string name;
  int tele;
  bool status;
    client(){
        name="";
        tele=-1;
        status=false;
    }
    client(string name,int t){
        this->name=name;
        tele = t;
        status=false;
    }
    friend class hash1;
};
class hash1{
   client* arr1,*arr2;
public:
   int size;
    hash1(int size){
        this->size=size;
        arr1=new client[size];
        arr2=new client[size];
    }
    // void insertArr1(client &a){
    //     cout<<"IN arr1";
    //     int k=(a.tele)%(this->size);
    //     if(!arr1[k].status){
    //         cout<<"IN arr1  a";
    //         arr1[k]=a;
    //         arr1[k].status=true;
    //     }
    //     else{
    //         cout<<"IN arr1  b";
    //         int check=k;
    //         k=(k+1)%(this->size);
    //         while(arr1[k].status && k!=check){
    //             k=(k+1)%(this->size);
    //         }
    //         if(k==check){
    //             cout<<"FULL\n";
    //         }
    //         else{
    //             arr1[k]=a;   
    //             arr1[k].status=true;
    //         }
    //     }
    // }
    void insertArr2(client a){
        int k=(a.tele)%(this->size);
            int check=k;
            do{
                if(!arr2[k].status){
                    arr2[k]=a;
                    arr2[k].status=true;
                    break;
                }
                else{
                    // cout<<"in 2";
                    if((arr2[k].tele)%(this->size) != k && k==check){
                        client nn(arr2[k].name,arr2[k].tele);
                        arr2[k]=a;
                        arr2[k].status=true;
                        insertArr2(nn);
                        break;
                    }
                    else{
                        k=(k+1)%(this->size);
                    }
                }
            }while(k!=check);

        if(k==check){
            // cout<<"FULL\n";
        }
        // cout<<"COMPLETE\n";
    }
    void search(int x){
        int k=(x%size);
        int ind=k;
        client ans;
        bool found=false;
        if(arr1[k].tele == x){
            found=true;
            // ans.tele=arr[k].tele;
            // ans.name=arr[k].name;
        }
        else{
            k=(k+1)%size;
            while(k!=ind && arr1[k].tele!=x){
                k=(k+1)%(size);
            }
            if(k!=ind ) found=true;
        }
        if(!found){cout<<"NOT found\n";}
        else if(found){
            cout<<arr1[k].name<<" "<<arr1[k].tele<<endl; 
        }
    }
    void insert(client a){
        // insertArr1( a);
        int k=(a.tele)%(this->size);
        if(!arr1[k].status){
            // cout<<"IN arr1  a";
            arr1[k]=a;
            arr1[k].status=true;
        }
        else{
            // cout<<"IN arr1  b";
            int check=k;
            k=(k+1)%(size);
            while(arr1[k].status==true && k!=check){
                k=(k+1)%(this->size);
            }
            if(k==check){
                cout<<"FULL\n";
            }
            else{
                arr1[k]=a;   
                arr1[k].status=true;
            }
        }
        // if(k==check){cout<<"FULL\n";}
    }
    void display(){
        cout<<"1---without replacement\n";
        for(int i=0;i<size;i++){
            cout<<arr1[i].name<<" "<<arr1[i].tele<<" "<<endl;
        }
        cout<<"2---with replacement\n";
        for(int i=0;i<size;i++){
            cout<<arr2[i].name<<" "<<arr2[i].tele<<" "<<endl;
        }
    }
};
// manish 131
// ram 121
// integer 122
// moksh 133
// mack 100
// niminsh 1444
int main() {
    hash1 obj(5);
    // obj.size=5;
    cout<<"enter name and tele\n";
    for(int i=0;i<6;i++){
        int t;string name;
        cin>>name>>t;
        client a(name,t);
        obj.insert(a);
        obj.insertArr2(a);
        obj.display();
    }
    obj.display();
    obj.search(144);
    obj.search(121);
    obj.search(131);
    obj.search(155);
    return 0;
}