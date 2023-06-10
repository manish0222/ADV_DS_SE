
#include <iostream>

#include <fstream>

#include <vector>

#include <algorithm>

#include <iomanip>

using namespace std;

class StudentData

{

public:

    char rno;

    string name;

    int div;

    static vector<int> rnoList;

    StudentData()

    {

        rno = ' ';

        name = "";

        div = 0;

    }

    void acceptData()

    {

        int roll;

        while (true)

        {

            cout << "Roll Number: ";

            cin >> roll;

            if (binary_search(rnoList.begin(), rnoList.end(), roll) == 0)

            {

                cout << roll << endl;

                rnoList.push_back(roll);

                this->rno = roll;

                cout << "rnoList: ";

                for (auto i : rnoList)

                {

                    cout << i << " ";

                }

                cout << endl;

                break;

            }

            else

            {

                cout << "The entered Roll number already exists!\n";

            }

        }

        cin.ignore();

        cout << "Name: ";

        getline(cin, name);

        // cin.ignore();

        cout << "Division: ";

        cin >> div;

        cin.ignore();

    }

};

vector<int> StudentData ::rnoList;

void storeData(StudentData &obj)

{

    fstream f;

    f.open("assignment4.txt", ios::app);

    f << "Roll Number: " << setw(20) << left << obj.rno // 13

      << "\nName: " << setw(20) << left << obj.name

      << "\nDivision: " << setw(20) << left << obj.div << "\n";

    f.close();

}

void readData()

{

    fstream f;

    f.open("assignment4.txt", ios::in);

    string x;

    while (!f.eof())

    {

        getline(f, x);

        cout << x << endl;

    }

    f.close();

}

int searchStudent(char rn)

{

    fstream f;

    f.open("assignment4.txt", ios::in);

    int pos = 0;

    char x;

    while (!f.eof())

    {

        // cout << "File pointer is at 3: " << f.tellg() << endl;

        pos += 13;

        f.seekg(pos);

        // cout << "File pointer is at 4: " << f.tellg() << endl;

        f >> x;

        if (x == rn)

        {

            // cout << x << endl;

            return pos;

        }

        else

        {

            string s1;

            pos += 21;

            f.seekg(pos);

            getline(f, s1);

            // cout << "File pointer is at 1: " << f.tellg() << endl;

            getline(f, s1);

            // cout << "File pointer is at 2:  " << f.tellg() << endl;

            pos = f.tellg();

        }

    }

    return -1;

    f.close();

}

void editName(string n, int fpos)

{

    fstream f;

    f.open("assignment4.txt", ios::in | ios::out);

    f.seekg(fpos);

    f << "                    ";

    f.seekg(fpos);

    f << n;

    cout << "Name has been edited!" << endl;

    f.close();

}

void editDiv(int d, int fpos)

{

    fstream f;

    f.open("assignment4.txt", ios::in | ios::out);

    f.seekg(fpos);

    f << "                    ";

    f.seekg(fpos);

    f << d;

    cout << "Division has been edited!" << endl;

    f.close();

}

void editData(char rno)

{

    int pos = searchStudent(rno);

    if (pos == -1)

    {

        cout << "Roll Number does not exist in file record" << endl;

        return;

    }

    // cout << "FILE POINTER IS AT: " << pos << endl;

    cout << "Enter infornation to be edited: \n1. NAME\n2. DIVISION\nEnter choice: ";

    int ch;

    cin >> ch;

    string name;

    int div;

    switch (ch)

    {

    case 1:

        cout << "Enter name to be edited: ";

        cin.ignore();

        getline(cin, name);

        if (name.length() <= 20)

        {

            editName(name, pos + 27);

        }

        else

        {

            cout << "Cant edit names with length more than 20\nPlease enter a shorter name!\n";

        }

        break;

    case 2:

        cout << "Enter division to be edited: ";

        cin >> div;

        editDiv(div, pos + 58);

        break;

    default:

        cout << "Incorrect choice entered" << endl;

        break;

    }

}

int main()

{

    int n;

    vector<StudentData> v;

    char ch = 'y';

    while (ch == 'y' || ch == 'Y')

    {

        cout << "---------------------------------\n";

        cout << "Enter data of student: " << endl;

        StudentData obj;

        obj.acceptData();

        v.push_back(obj);

        cout << "==================================\n";

        cout << "Do you want to add another student's data: ";

        cin >> ch;

    }

    for (int i = 0; i < v.size(); i++)

    {

        storeData(v[i]);

    }

    char op = 'y';

    while (op == 'y' || op == 'Y')

    {

        cout << "-------------------------------------\n";

        cout << "1. Create File\n2. Read file\n3. Add a student into file\n4. Edit data of student\nENTER CHOICE: " << endl;

        int choice;

        cin >> choice;

        StudentData o;

        switch (choice)

        {

        case 1:

            cout << "FILE CREATED" << endl;

            break;

        case 2:

            readData();

            break;

        case 3:

            cout << "Enter data of student: " << endl;

            o.acceptData();

            v.push_back(o);

            storeData(o);

            break;

        case 4:

            char roll_no;

            cout << "ENTER ROLL NUMBER TO BE EDITED: ";

            cin >> roll_no;

            editData(roll_no);

            break;

        default:

            cout << "Incorrect choice entered\n";

        }

        cout << "Do you want to continue: ";

        cin >> op;

    }

}


// //============================================================================
// // Name        : ASS11.cpp
// // Author      : 
// // Version     :
// // Copyright   : Your copyright notice
// // Description : Hello World in C++, Ansi-style
// //============================================================================

// #include <iostream>
// #include<string.h>
// #include<fstream>
// using namespace std;
// class student
// {
//     int rollno;
//     char div;
//     //char name[20],div,address[20];
//     string name,address;
// public:
//     student()
//     {
//         rollno=0;
//         div=' ';
//         name=" ";
//         address=" ";
//     }
//     void input();
//     void display();
//     int getrollno()
//     {
//         return rollno;
//     }

// };

// void student::input()
// {
//     cout<<"Student Details";
//     cout<<"\n Enter Student Name :";
//     cin>>name;

//     cout<<"\n Enter Student Roll No :";
//     cin>>rollno;

//     cout<<"\n Enter Student Division :";
//     cin>>div;

//     cout<<"\n Enter student Address:";
//     cin>>address;

// }

// void student::display()
// {
// 	cout<<name<<endl;
// 	cout<<rollno<<endl;
// 	cout<<div<<endl;
// 	cout<<address<<endl;
// }


// class sequential_file
// {
//     fstream file;
//     student obj;
// public:
//     void create(); //Creates new file
//     void add();
//     void search();
//     void del();
//     void print();

// };

// void sequential_file::create()
// {
//     char ch='y';
//     file.open("student_data.txt",ios::out|ios::binary);
//     while(ch=='y'||ch=='Y')
//     {
//         obj.input();
//         file.write((char*)&obj,sizeof(obj));
//         cout<<"\nWant to enter more entries:";
//         cin>>ch;
//     }
//     file.close();
// }


// void sequential_file::add()
// {
//     char ch='y';
//     file.open("student_data.txt",ios::app|ios::out|ios::binary);
//     while(ch=='y'||ch=='Y')
//     {
//         obj.input();
//         file.write((char*)&obj,sizeof(obj));
//         cout<<"\nWant to enter more entries:(Enter y/Y for yes)";
//         cin>>ch;
//     }
//     file.close();

// }

// void sequential_file::print()
// {
//  file.open("student_data.txt",ios::in|ios::binary);
//  if(!file)
//  {
//      cout<<"File Not Found ";

//  }
//  else
//     {
//      file.read((char*)&obj,sizeof(obj));
//      while(!file.eof())
//      {
//          obj.display();
//          file.read((char*)&obj,sizeof(obj));
//      }
//     }
//     file.close();
// }

// void sequential_file::search()
// {
//  int n,fl=0;
//  cout<<"Enter roll no . to be searched :";
//  cin>>n;
//  file.open("student_data.txt",ios::in|ios::binary);
//  if(!file)
//  {
//      cout<<"File Not Found ";

//  }
//  else
//  {
//      file.read((char*)&obj,sizeof(obj));
//      while(!file.eof())
//      {
//          if(n==obj.getrollno())
//          {
//              obj.display();
//              fl=1;
//              break;
//          }
//          else
//             file.read((char*)&obj,sizeof(obj));

//         if(fl==0)
//     {
//         cout<<"Record Not Found";
//     }
//     }

//  }
// }

// int main()
// {
//     student obj;
//     sequential_file sobj;
//     //obj.input();
//     //obj.display();
//     sobj.create();
//     //cout<<"appending data";
//     //sobj.add();
//     sobj.print();
//     sobj.search();

//     return 0;
// }





