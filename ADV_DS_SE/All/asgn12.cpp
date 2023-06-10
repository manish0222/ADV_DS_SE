//============================================================================
// Name        : mock2.cpp
// Author      : manish
// Version     : 1
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
using namespace std;
class Hashtable{
public:
int location;
int Hash_func(char n[]){
    int i,ascii =0;
    for(i=0;n[i]!='\0';i++){
        ascii += n[i];
    }
    return(ascii % 10);
}
};
class DAF: public Hashtable
{
public:
fstream F;
char buffer[40];
Hashtable HT[10];
void create_HT(){
   for(int i=0;i<10;i++){
       HT[i].location = 0;
   }
}
void create(){
    F.open("manish.txt",ios::out);
    if(!F){
        cout<<"Error in creating File!!"<<endl;
    }
    else{
        cout<<"File created Successfully!!"<<endl;
        F.close();
    }
}
void write(){
    F.open("manish.txt",ios::app);
    cout<<"Enter total data to be entered:";
    int n;
    cin>>n;
    char em_id[10],name[10];
    int salary,exp;

    for(int i=0;i<n;i++){
        cout<<"Enter employee Id:" ;
        cin>>em_id;
        cout<<"Enter Employee name: ";
        cin>>name;
        cout<<"Enter Employee Salary: ";
        cin>>salary;
        cout<<"Enter Employee Experience: ";
        cin>>exp;
        int locat = F.tellp();
        F<<em_id<<" - "<<name<<" - "<<salary<<" - "<<exp<<endl;
        int pos = Hash_func(em_id);

        cout<<"Location "<<i+1<<" : "<<locat<<endl;
        HT[pos].location = locat;
    }
    F.close();
}
void read(){
    F.open("manish.txt",ios::in);
    cout<<"\n-------------------------------\n";
    int i=0;
    while(1){
        F.getline(buffer,40);
         if(F.eof()){
             break;
        }
        cout<<i+1<<" : "<<buffer<<endl;
         i++;
    }
     F.close();
     cout<<"\n-------------------------------\n";
}
void search(){
    F.open("manish.txt",ios::in);
    char key[10];
    cout<<"Enter Employee ID : ";
    cin>>key;
    cout<<"\n----------------DATA FOUND---------------\n";
    int pos1 = Hash_func(key);
    int loc = HT[pos1].location;
    F.seekg(loc,ios::beg);
    F.getline(buffer,40);
    cout<<" "<<buffer;
    cout<<endl;
    F.close();
    cout<<"\n-----------------------------------------\n";

}
void Delete(){
    F.open("manish.txt",ios::in);
    char key[10];
    cout<<"Enter Employee ID : ";
    cin>>key;
    int pos1 = Hash_func(key);
    int loc = HT[pos1].location;
    HT[pos1].location = 0;
    F.seekg(loc,ios::beg);
    F.getline(buffer,40);
    char line[40];
    fstream F1;
    F1.open("temp.txt",ios::out);
    while(F.getline(line,40)){
        if(line != buffer){
            F1<<line<<endl;
        }
    }
    F.close();
    F1.close();
    // F1.open("temp.txt",ios::in);
    // int i=0;
    // while(1){
    //     F1.getline(buffer,40);
    //      if(F1.eof()){
    //          break;
    //     }
    //     cout<<i+1<<" : "<<buffer<<endl;
    //      i++;
    // }
    //  F1.close();
	char oldname[] = "temp.txt";
	char newname[] = "manish.txt";
	if(rename(oldname,newname) != 0){
		cout<<"Error in renaming"<<endl;
	}
	else{
		cout<<"File renamed!!"<<endl;
	}
	}
};
int main(){

    DAF D;
    D.create_HT();
    int n=1;
    D.create();
    while(n==1){
    	cout<<"1)write \n2)read\n3)search\n4)delete\n5)exit press 0\nchoice   ";
    	int ch;cin>>ch;
    	if(ch==1){
			D.write();
    	}
    	else if(ch==2){
			D.read();
    	}
    	else if(ch==3){
			D.search();
    	}
    	else if(ch==4){
    		D.Delete();
    	}
    	else{
    		cout<<"enter 1 to continue ";
    		cin>>n;
    	}

    }

    return 0;
}






















////============================================================================
//// Name        : mock2.cpp
//// Author      : manish
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//class Record {
//    int id;
//    string name;
//    int salary;
//    string designation;
//
//public:
//    Record();
//    int getIdno();
//    void getData();
//    void putData();
//};
//
//Record::Record() {
//    id = 0;
//    name = ' ';
//    designation = ' ';
//    salary = 0;
//}
//
//int Record::getIdno() {
//    return (id);
//}
//
//void Record::getData() {
//    cout << "\nEnter Details: ";
//    cout << "\nId no: ";
//    cin >> id;
//    cout << "Name: ";
//    cin >> name;
//    cout << "Salary: ";
//    cin >> salary;
//    cout << "Designation: ";
//    cin >> designation;
//}
//
//void Record::putData() {
//    cout << "\nId No.: ";
//    cout << id;
//    cout << "\t\tName: ";
//    cout << name;
//    cout << "\nSalary: ";
//    cout << salary;
//    cout << "\tDesignation: ";
//    cout << designation;
//}
//
//class File {
//    ifstream fin;
//    ofstream fout;
//    fstream fs;
//
//public:
//    void insert();
//    void display();
//    void search(int);
//    int Delete(int);
//    int edit(int);
//};
//
//void File::insert() {
//    Record r;
//    r.getData();
//    fout.open("EmployeeDB", ios::ate | ios::app);
//    fout.write((char *)&r, sizeof(r));
//    fout.close();
//}
//
//void File::display() {
//    Record r;
//    fin.open("EmployeeDB");
//    fin.seekg(0, ios::beg);
//    while (fin.read((char *)&r, sizeof(r)))
//        r.putData();
//
//    fin.close();
//}
//
//void File::search(int id) {
//    Record r;
//    int flag = 0;
//    fin.open("EmployeeDB");
//    fin.seekg(0, ios::beg);
//    while (fin.read((char *)&r, sizeof(r))) {
//        if (r.getIdno() == id) {
//            flag = 1;
//            break;
//        }
//    }
//
//    fin.close();
//    if (flag == 1) {
//        cout << "\nRecord Found:";
//        r.putData();
//    }
//    else
//        cout << "\nRecord not Found ";
//}
//
//int File::Delete(int id) {
//    Record r;
//    int flag = 0;
//    fin.open("EmployeeDB");
//    fout.open("Temp", ios::ate | ios::app);
//    fin.seekg(0, ios::beg);
//    while (fin.read((char *)&r, sizeof(r))) {
//        if (r.getIdno() == id) {
//            flag = 1;
//        }
//        else {
//            fout.write((char *)&r, sizeof(r));
//        }
//    }
//    fin.close();
//    fout.close();
//    remove("EmployeeDB");
//    rename("Temp", "EmployeeDB");
//    return (flag);
//}
//
//int File::edit(int id) {
//    Record r;
//    int flag = 0;
//    fs.open("EmployeeDB");
//    fs.seekg(0, ios::beg);
//    while (fs.read((char *)&r, sizeof(r))) {
//        if (r.getIdno() == id) {
//            flag = 1;
//            cout << "\nEnter New Details: ";
//            r.getData();
//            fs.seekp((int)fs.tellg() - sizeof(r), ios::beg);
//            fs.write((char *)&r, sizeof(r));
//        }
//    }
//    fs.close();
//    return (flag);
//}
//
//int main() {
//    File f;
//    int ch, n, i, flag = 0;
//    do {
//        cout << "\n\n\t-----M E N U-----";
//        cout << "\n\n1. Build A Master Table";
//        cout << "\n2. List A Table";
//        cout << "\n3. Insert a New Entry";
//        cout << "\n4. Delete Old Entry";
//        cout << "\n5. Edit an Entry";
//        cout << "\n6. Search for a Record";
//        cout << "\n7. Quit";
//        cout << "\nEnter your Choice: ";
//        cin >> ch;
//        switch (ch) {
//            case 1:
//                if (flag == 0) {
//                    cout << "\nEnter No of Records to insert : ";
//                    cin >> n;
//                    for (i = 0; i < n; i++) {
//                        f.insert();
//                    }
//                    flag = 1;
//                }
//                else {
//                    cout << "\nSorry.. Table is Already build... \n If want to add record please select Insert a New Entry in option.....";
//                }
//                break;
//            case 2:
//                f.display();
//                break;
//            case 3:
//                f.insert();
//                break;
//            case 4:
//                cout << "\nEnter Id No of Employee Whose Record is to be Deleted: ";
//                cin >> n;
//                i = f.Delete(n);
//                if (i == 1)
//                    cout << "\nRecord Deleted Successfully";
//                else
//                    cout << "\nRecord not Found";
//                break;
//            case 5:
//                cout << "\nEnter Id No of Employee Whose Record is to be Edit: ";
//                cin >> n;
//                i = f.edit(n);
//                if (i == 1)
//                    cout << "\nRecord Modified Successfully";
//                else
//                    cout << "\nRecord not Found";
//                break;
//            case 6:
//                cout << "\nEnter Id No of Employee Whose Record is to be Searched: ";
//                cin >> n;
//                f.search(n);
//                break;
//            case 7:
//                break;
//            default:
//                cout << "\nEnter Valid Choice.....";
//        }
//    } while (ch != 7);
//    return (0);
//}
