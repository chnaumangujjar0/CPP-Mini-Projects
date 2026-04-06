#include <iostream>
#include<vector>
using namespace std;

class Student
{  public:
    string name;
    int regNo;
    int marks;

    Student( int regNo, string name, int marks) : regNo(regNo), name(name),  marks(marks) {}
};
class StudentSystem{
    vector<Student> students;
    public:

    void addStudent(int regNo,string name,int marks){
        students.push_back((Student(regNo,name,marks)));
        cout<<"\n Student Added Successfully!";
    }
    
    void display(){
        if(students.empty()){
            cout<<"\n No Student Available! ";
            return;
        }

        for(Student &s : students){
            cout<<"\n Reg No : "<<s.regNo;
            cout<<"\n Name : "<<s.name;
            cout<<"\n Marks : "<<s.marks;
            cout<<"\n ------------------------";
        }
    }

    void searchStudent(int regNo){
        bool found = false;
        for(Student &s: students){
            if(s.regNo == regNo){
                found = true;
                cout<<"\n ----------------------";
                cout<<"\n Reg No : "<<s.regNo;
                cout<<"\n Name : "<<s.name;
                cout<<"\n Marks : "<<s.marks;
                cout<<"\n ----------------------";
                break;
            }
        }
        if(!found) cout<<"\n Student not found";
    }

    void updateData(int regNo){
        string name;
        int marks;
        int choice;
        bool found = false;
        for(Student &s : students){
            if(s.regNo == regNo){
                found = true;
                cout<<"\n 1. For Updating Name";
                cout<<"\n 2. For Updating Marks";
                cout<<"\n Enter Choice : ";
                cin>>choice;
                if(choice == 1){
                    cout<<"\n Enter New Name : ";
                    cin.ignore();
                    getline(cin,name);
                    s.name = name;
                    cout<<"\n Name updated Succesfully!";
                    return ;
                }else if( choice == 2){
                    cout<<"\n Enter Marks : ";
                    cin>>marks;
                    s.marks = marks;
                    cout<<"\n Marks Updated Succesfully!";
                    return ;
                }else{
                    cout<<"\n Invalid Choice!";
                    cout<<"\n Data is not updated!";
                }
            }
        }
       if(!found) cout<<"\n Student not found!";
    }

    void removeStudent(int regNo)
    {
        bool found = false;

        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].regNo == regNo)
            {
                found = true;
                students.erase(students.begin() + i);
                cout << "\n Student removed successfully!\n";
                return;
            }
        }

        if (!found)
        {
            cout << "\n Student not found!\n";
        }
    }

};
int main()
{
    StudentSystem s;
    int regNo = 1000 ;
    string name;
    int marks;
    cout<<"\n ========= Student Management System ==========";
    while(true){
        int choice;
        cout<<"\n 1. Add Student ";
        cout<<"\n 2. Display Students";
        cout<<"\n 3. Search Student";
        cout<<"\n 4. Delete Student";
        cout<<"\n 5. Update Data ";
        cout<<"\n 6. Exit";
        cout<<"\n Enter Your Choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"\n Enter Name : ";
            cin.ignore();
            getline(cin,name);
            cout<<"\n Enter Marks : ";
            cin>>marks;
            regNo++;
            s.addStudent(regNo,name,marks);
            break;
        case 2:
            s.display();
            break;
        case 3:
            cout<<"\n Enter Reg No : ";
            cin>>regNo;
            s.searchStudent(regNo);
            break;
        case 4:
            cout<<"\n Enter Reg No : ";
            cin>>regNo;
            s.removeStudent(regNo);
            break;
        case 5:
            cout<<"\n Enter Reg No : ";
            cin>>regNo;
            s.updateData(regNo);
            break;
        case 6:
            cout<<" Exited!";
            return 0;
        default:
            cout<<"\n Invalid Choice!";
            break;
        }
    }
    return 0;
}