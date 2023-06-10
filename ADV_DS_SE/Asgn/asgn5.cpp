#include <iostream>
using namespace std;
class dict{
    string word,meaning;
    dict* next;
public:
    dict(){
        word=meaning="";
        next=NULL;
    }
    dict(string w,string m){
        word=w;
        meaning=m;
        next=NULL;
    }
    friend class Hash;
};
class Hash{
    dict* arr;
public:
    Hash(){
        arr=new dict[10];
        for (int i = 0; i < 10; i++)
        {
            arr[i].next=NULL;
        }
        cout<<"created\n";
    }
    int hashFunc(string w){
        int sum=0;
        for(int i=0;i<w.length();i++){
            sum+=int(w[i]);
        }
        return (sum%10);
    }
    void insert(string w,string m){
        dict* nn=new dict(w,m);
        int ind=hashFunc(w);
        dict* temp= &arr[ind];
        if(temp->next == NULL){
            arr[ind].next=nn;
        }
        else{
            temp=temp->next;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
    void search(string w){
        int ind=hashFunc(w);
        dict* temp=&arr[ind];
        while(temp){
            if(temp->word!=w){
                temp=temp->next;
            }
            else{
                break;
            }
        }
        if(!temp){cout<<"NPTthere\n";}
        else{
            cout<<"---FOUND\t";
            displayData(temp);cout<<endl;
        }
    }
    void deleteDict(string w){
        int ind=hashFunc(w);
        dict*prev=NULL;
        dict* temp=&arr[ind];
        while(temp){
            if(temp->word!=w){
                prev=temp;
                temp=temp->next;
            }
            else{
                break;
            }
        }
        if(!temp){cout<<"NPTthere\n";}
        else{
            cout<<"---FOUND\t";
            prev->next=temp->next;
            delete(temp);
            cout<<"DELETED\n";
        }
    }
    void displayData(dict* temp){
        cout<<"-> "<<temp->word<<" : "<<temp->meaning;
    }
    void display(){
        for(int i=0;i<10;i++){
            cout<<i<<" ";
            dict * temp=arr[i].next;
            while(temp){
                displayData(temp);
                temp=temp->next;
            }cout<<endl;
        }
    }
};
int main(){
    Hash obj;
    obj.insert("manish","prani");
    obj.insert("AA","mani");
    obj.insert("AAA","manis");
    obj.display();
    obj.search("mack");
    obj.search("AA");
    obj.deleteDict("babba");
    obj.deleteDict("manish");
    obj.display();
    obj.deleteDict("babba");
}