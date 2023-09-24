#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
    int rollno, age;
    string name;
    public:
    Student(int stdId, string stdName,int stdAge ){
        rollno= stdId;
        age= stdAge;
        name=stdName;
    }
    void setRollno(int stdId){
        rollno=stdId;
    }
    int getRollno(){
        return rollno;
    }
    void setAge(int stdAge){
        age=stdAge;
    }
    int getAge(){
        return age;
    }
    void setName(int stdName){
        name=stdName;
    }
    string getName(){
        return name;
    }
    void displayStudent(){
        cout<<"Roll No: "<<rollno <<endl;
        cout<<"Name :"<<name<<endl;
        cout<<"Age :"<<age<<endl;
    }  
};
void deleteStudent(vector<Student> &students){
    string name;
    cout<<"Enter Name to Delete: ";
    cin.ignore();
    getline(cin,name);
    for(int i=0; i<students.size();i++){
        if(students[i].getName()==name){
            students.erase((students.begin()+i));
            cout<<"\t\t Student Removed Successfully "<<endl;
        }
    }
}
void updateStudent(vector<Student> &students){
    string sname;
    bool found =false;
    int choice;

    cout<<"\t\t Enter Name to Update Record :";
    cin.ignore(); 
    getline(cin,sname);
    for(int i=0;i<students.size();i++){
        if(students[i].getName()==sname){
            found =true;
            cout<<"\t\t--------Student Found-------"<<endl;
            cout<<"\t\t 1. Update Rollno "<<endl;
            cout<<"\t\t 2. Update Age "<<endl;
            cout<<"\t\t 3. Update Name "<<endl;
            cout<<"\t\t Enter your choice: ";
            cin>> choice;

            switch(choice){
                case 1:
                {
                    int rno;
                    cout<<"\t\t Enter new Roll no ";
                    cin >>rno;
                    students[i].setRollno(rno);
                    break;
                } 
                case 2:
                {
                    string name;
                    cout<<"Enter New Name ";
                    cin.ignore();
                    getline(cin,name);
                    students[i].setName(name);
                    break;
                }
                case 3:
                {
                    int age;
                    cout<<"Enter New Age ";
                    cin>> age;
                    students[i].setAge(age);
                    break;
                }
                default:
                cout<<"\t\t Invalid Number" <<endl;
            }
        }
        if(!found){
            cout<<"\t\t Record Not Found"<<endl;
            return;
        }
    }
}
void searchStudent(vector<Student> &students){
    int rollno;
    cout<<"\t\t Enter Rollno :";
    cin>> rollno;

    for(int i=0; i<students.size();i++){
        if(students[i].getRollno()==rollno){
            cout<<"\t\t---------Student Found--------"<<endl;
            students[i].displayStudent();
            return;
        }
    }
}
void displayAllStudent(vector<Student> &students){
    if(students.empty()){
        cout<<"\t\t No Student Found"<<endl;
        return;
    }
    for(int i=0;i<students.size();i++){
        students[i].displayStudent();
        cout<<endl;
    }
}
void addNewStudent(vector<Student> &students){
    int rollno,age;
    string name;
    cout<<"Enter Rollno:";
    cin>>rollno;
    //if student already exists
    for(int i=0;i<students.size();i++){
        if(students[i].getRollno()==rollno){
            cout<<"\t\t Student Already Exists..."<<endl;
            return;
        }
    }
    cout<<"Enter name:";
    cin>>name;
    cout<<"Enter age:";
    cin>>age;

    Student newStudent(rollno,name,age);
    students.push_back(newStudent);
}
main(){
    vector<Student> students;
    students.push_back(Student(1,"Nivedita",20));
    char choice;

    do{
        system("cls");
        int op;
        cout<<"\t\t---------------------------"<<endl;
        cout<<"\t\t Student Management System"<<endl;
        cout<<"\t\t---------------------------"<<endl;
        cout<<"\t\t 1. Add new student"<< endl;
        cout<<"\t\t 2. Display all students"<<endl;
        cout<<"\t\t 3. Search student"<<endl;
        cout<<"\t\t 4. Update student"<<endl;
        cout<<"\t\t 5. Delete student"<<endl;
        cout<<"\t\t 6. Exit"<<endl;
    
        cout<<"Enter your choice: ";
        cin>>op;
        switch(op){
            case 1:
                addNewStudent(students);
                break;
            case 2:
                displayAllStudent(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                exit(1);
            default:
            cout<<"\t\t Wrong Choicee...."<<endl;
        }

        cout<<"\t\t Do you want to continue[YES/NO] ? :";
        cin>> choice;
    }
    while(choice=='Y'|| choice=='y');
}