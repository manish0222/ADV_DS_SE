//============================================================================
// Name        : Assign4.cpp
// Author      :
// Version     :
// Copyright   : With replacement
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class client{
public:
  int tele;
  int status;
  string name;
    client(){
        tele=-1;
        status=0;
        name="";
    }
    client(int t,int tele,string s){
        name=s;
        this->tele=tele;
        status=1;
    }
    friend class Hashtable;
};
class Hashtable{
    int size;
    client *arr;
    client *arr2;
public:
    Hashtable(){
        cout<<"enter size of array ";
        int s;cin>>s;
        this->size=s;
        arr=new client[size];
        arr2=new client[size];
    }
    void InsertWithoutReplacement(int st,int tele,string name){
    	client tp(st,tele,name);
        int x=(tp.tele)%(this->size);
    	        if(!arr[x].status){
    	            arr[x]=tp;
    	            arr[x].status=1;
    	        }
    	        else{
    	            int chk=x;
    	            x=(x+1)%(this->size);
    	            while(arr[x].status==1 && x!=chk){
    	                x=(x+1)%(this->size);
    	            }
    	            if(x==chk){
    	                cout<<"\n\t array is full\n";
    	            }
    	            else{
    	                arr[x]=tp;
    	                arr[x].status=1;
    	            }
    	        }
    }
    void insertWithReplacement(int st,int tele,string name){
        client tp(st,tele,name);
        int x=(tp.tele)%(this->size);
        int ind=x;
        do{
        	if(!arr2[x].status){
        		arr2[x]=tp;
        	    arr2[x].status=1;
        	    break;
        	}
        	else{
        		if((arr2[x].tele)%(this->size)!= x   && ind==x){
        			int status=arr2[x].status;
        			int tele=arr2[x].tele;
        			string name=arr2[x].name;
        			arr2[x]=tp;
        			arr2[x].status=1;
        			insertWithReplacement(status,tele,name);
        			break;
        		}
        	    else{
        	        x=(x+1)%(this->size);
        	    }
        	}
        }while(x!=ind);
    }
    void Display(){
        cout<<"\n  --Hash Table 1---     --Hash Table 2--\n";
        cout<<"   Tel No "<<"  "<<"Name  |"<<"  Tel-No "<<"  "<<"Name "<<"\n";
        for(int i=0;i<(this)->size;i++){
        	dataDisplay(arr[i],arr2[i]);
        }
        cout<<"---------------------------------------\n";
    }
    void search(int tel){
        int x=(tel)%(this->size);
        client a;
        client b;
        bool found=false;
        if(arr[x].tele==tel){
            a=arr[x];
            found=true;
        }
        else{
            int chk=x;
            x=(x+1)%(this->size);
            while(arr[x].tele!=tel && x!=chk){
                x=(x+1)%(this->size);
            }
            if(x==chk){
                cout<<"not present\n";
            }
            else{
                a=arr[x];
                found=true;
            }
        }
        if(arr2[x].tele==tel){
        	b=arr2[x];
        	found=true;
        }
        else{
            int chk=x;
            x=(x+1)%(this->size);
            while(arr2[x].tele!=tel && x!=chk){
                x=(x+1)%(this->size);
            }
            if(x==chk){
                cout<<"not present\n";
            }
            else{
                b=arr2[x];
                found=true;
            }
        }
        if(found){
        	cout<<"--Found  ";
        	dataDisplay(a,b);
        }
    }
    void dataDisplay(client a,client b){
        cout<<"    "<<a.tele<<"    | "<<a.name<<"  |  "<<b.tele<<"    | "<<b.name<<"\n";
    }
    void deleteData(int tel){
        int x=(tel)%(this->size);
        if(arr[x].tele==tel){
            arr[x].status=0;
            arr[x].tele=-1;
            arr[x].name="";
            cout<<"\nDEleted data\n";
        }
        else{
            int chk=x;
            x=(x+1)%(this->size);
            while(arr[x].tele!=tel && x!=chk){
                x=(x+1)%(this->size);
            }
            if(x==chk){
                cout<<"not present\n";
            }
            else{
                arr[x].status=0;
                arr[x].tele=-1;
                arr[x].name="";
                cout<<"\nDEleted data\n";
            }
        }
    }
};
int main() {
    Hashtable obj;
    while(true){
         cout << "\n1)Insert\n2).Display\n3).Search\n4).delete\n5).Exit\n";
        cout << "Enter your choice: ";
        int c;
        cin >> c;
        cout << endl;
        if (c == 1)
        {
        	cout<<"enter total entries ";
        	int x;cin>>x;
        	for(int i=0;i<x;i++){
        		string name;
        		int id=1;
        		long long t;
        		cout << "Enter Name : " << endl;
        		cin >> name;
        		        //   cout << "Enter status : " << endl;
        		        //   cin >> id;

        		cout << "Enter telephone Number : " << endl;
        		cin >> t;
        		obj.InsertWithoutReplacement(id, t, name);
        		obj.insertWithReplacement(id, t, name);
        	}
        }
        else if (c == 2)
        {
          obj.Display();
        }
        else if (c == 3)
        {
            cout << "Enter the telephone no. : " << endl;
            long long t;
            cin >> t;
            obj.search(t);
        }
        else if (c == 4)
        {
            long long t;
            cout << "Enter the telephone no. : " << endl;
            cin >> t;
            obj.deleteData(t);
        }
        else if (c == 5)
        {
            cout << "Thank you!!\n";
            break;
        }
    }

    return 0;
}



