#include<iostream>
#include <fstream>
#include <cstring>
#define size 10
using namespace std;
class student{
    int roll,loc;
public:
    student(int r=0,int l=0){
        roll=r;
        loc=l;
    }
    friend class Hash;
};
class Hash{
public:
    student* arr;
    Hash(){
        arr = new student[size];
        for (int i = 0; i < size; i++)
        {
            arr[i].loc=-1;
            arr[i].roll=-1;
        }
    }
    int hashFunction(int r){
        return (r%size);
    }
    void display(){
        cout<<"\n---------------HASTABLE-------\n";
        for (int i = 0; i < size; i++)
        {
            if(arr[i].roll !=-1){
                cout<<i+1<<" "<<arr[i].loc<<" "<<arr[i].roll<<endl;
            }
        }
        cout<<"--------------------------------\n";
    }
    void insert(int rollno,int loc){
        int r=hashFunction(rollno);
        int ind=r;
        do
        {
            if(arr[r].roll ==-1){
                arr[r].roll=rollno;
                arr[r].loc = loc;
                break;
            }
            else{
                r=(r+1)%size;
            }
        } while (r!=ind);
        cout<<"DONE\n";
    }
    int search(int roll){
        int r=hashFunction(roll);
        int ind=r;
        do
        {
            if(arr[r].roll !=-1){
                return arr[r].loc;
                break;
            }
            else{
                r=(r+1)%size;
            }
        } while (r!=ind);
        return -1;
    }
    void remove(int rollno){
        int r=hashFunction(rollno);
        int ind=r;
        do
        {
            if(arr[r].roll == rollno){
                arr[r].roll=-1;
                arr[r].loc = -1;
                break;
            }
            else{
                r=(r+1)%size;
            }
        } while (r!=ind);
    }
    
};
class File{
    char fname[20];
    char buffer[100];
    int roll;
    string name;
    Hash h;
public:
    File(char f[]){
        strcpy(fname,f);
    }
    void write(){
        ofstream fout;
        fout.open(fname,ios::out);
        if(!fout){
            cout<<"FILE ERROR\n";
        }
        else{
            cout<<"ENTER TOTAL DATA\n";
            int count;cin>>count;
            for(int i=0;i<count;i++){
                cout<<"enter name ";cin>>name;
                cout<<"enter rollnumber ";cin>>roll;
                h.insert(roll,fout.tellp());
                fout<<roll<<" "<<name<<endl;
            }
        }
        fout.close();
    }
    void read(){
        ifstream fin;
        fin.open(fname,ios::in);
        if(!fin){
            cout<<"FILE ERROR\n";
        }
        else{
            int i=0;
            cout<<"\n---------------DATA---------\n";
            while (!fin.eof()){
                fin.getline(buffer,100);
                cout<<"record "<<i+1<<" "<< buffer<<endl;
                i++;
            }
            cout<<"---------------------------------\n";
        }
        fin.close();
        h.display();
    }
    void search(int rn){
        ifstream fin;
        fin.open(fname,ios::in);
        if(!fin) cout<<"EROOR\n";
        else{
            int loc=h.search(rn);
            if(loc==-1){
                cout<<"NO DATA\n";
            }
            else{
                fin.seekg(loc,ios::beg);
                fin.getline(buffer,40);
                cout<<"\nRECORD FoUND\n";
                cout<< buffer<<endl;
            }
        }
        fin.close();
    }
    void removeData(int rn){
        ifstream fin;
        fin.open(fname,ios::in);
        if(!fin){
            cout<<"eroor openning file\n";
        }
        else{
            int loc=h.search(rn);
            if(loc==-1){
                cout<<"NOdata\n";
            }
            else{
                fin.seekg(loc,ios::beg);
                fin.getline(buffer,40);
                cout<<"\nrecord to be delted\n";
                cout<< buffer<<endl;
            }
        }
        fin.close();

        ofstream fout;
        fout.open("temp.txt",ios::out);
        fin.open(fname,ios::in);
        if(!fin || !fout){
            cout<<"ERROR IN FILE\n";
        }
        else{
            int r;
            while(!fin.eof()){
                fin.getline(buffer,100);
                sscanf(buffer,"%d",&r);     //imp
                if(r!=rn){
                    fout<<buffer<<endl;
                }
            }
        }
        fin.close();
        fout.close();
        remove(fname);
        rename("temp.txt",fname);
        h.remove(rn);                     //imp
    }
};
int main(){
    cout<<"ENTER FILE ";
    char s[20];cin>>s;
    File f(s);
    f.read();
    f.write();
    f.read();
    f.search(21226);
    f.search(212);
    f.search(21233);
    f.read();
    f.removeData(2122);
    f.removeData(21226);
    f.read();

    return 0;
}