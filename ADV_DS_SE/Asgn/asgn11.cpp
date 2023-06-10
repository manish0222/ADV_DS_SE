#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
class student{
    int roll;string name;
public:
    void input(){
        cout<<"Enter name ";cin>>name;
        cout<<"enter roll ";cin>>roll;
    }
    void display(){
        cout<<" "<<name<<" "<<roll<<"\n";
    }
    void change(){
        cout<<"enter new Name ";
        cin>>name;
    }
    friend class File;
};
class File{
    char fname[20];
public:
    File(char f[20]){
        strcpy(fname,f);
    }
    void write(int n){
        ofstream ofs;
        ofs.open(fname,ios::ate);
        if(!ofs){cout<<"Error ";}
        else{
            student s;
            for(int i=0;i<n;i++){
                s.input();
                ofs.write((char *)&s , sizeof(s));
            }
        }
        ofs.close();
    }
    void read(){
        ifstream ifs;
        ifs.open(fname,ios::in);
        if(!ifs){cout<<"Error ";}
        else{
            student s;
            while(ifs.read((char *)&s , sizeof(s))){
                s.display();
                // cout<<endl;
            }
        }
        ifs.close();
    }
    void deleteData(int rn){
        bool found=false;
        ifstream ifs(fname,ios::in);
        ofstream ofs("temp.txt",ios::out);
        if(!ifs || !ofs){
            cout<<"ERROR";
        }
        else{
            student s;
            while(ifs.read((char *)&s, sizeof(s))){
                if(s.roll==rn){
                    found=true;
                }
                else{
                    ofs.write((char *)&s , sizeof(s));
                }
            }
        }
        if(!found){cout<<"Data not present\n";}
        ifs.close();
        ofs.close();
        remove(fname);
        rename("temp.txt",fname);
    }
    void update(int rn){
        bool found=false;
        ifstream ifs(fname,ios::in);
        ofstream ofs("temp.txt",ios::out);
        if(!ifs || !ofs){
            cout<<"ERROR";
        }
        else{
            student s;
            while(ifs.read((char *)&s, sizeof(s))){
                if(s.roll == rn){
                    s.change();
                    found=true;
                }
                ofs.write((char *)&s , sizeof(s));
            }
        }
        if(!found){cout<<"Data not present\n";}
        ifs.close();
        ofs.close();
        remove(fname);
        rename("temp.txt",fname);
    }

};
int main(){
    cout<<"enter file ";
    char s[20];cin>>s;
    File f(s);
    f.write(2);
    f.read();
    f.deleteData(22);
    f.read();
    f.deleteData(21226);
    f.read();
    f.update(21266);
    f.read();
    f.update(32);
    f.read();
}
