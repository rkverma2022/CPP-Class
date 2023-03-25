#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    char name[15];
    unsigned short int age;
    string department;
    unsigned short int year;

    void PrintStudentData()
    {
        cout << this->name << "\t" << this->age << "\t" << this->department << "\t" << this->year << endl;
    }

    template<class T>
    void ReadStudentData(T Name)
    {
        if(strcmp(Name, this->name) == 0)
        {
            cout << this->name << "\t" << this->age << "\t" << this->department << "\t" << this->year << endl;
            return;
        }
    
    }

   
};

int main()
{
    int n;
    cout << "::: Enter the Number of Students::::::" << endl;
    cin >> n;
    Student stu[100];

    for (int i = 0; i < n; i++)
    {
        cout << ":::::: Student[" << i + 1 << "] ::::::" << endl;
        cout << ": :: Name :: :   ";
        cin >> stu[i].name;
        cout << ":: Age :::   ";
        cin >> stu[i].age;
        cout << ":: Department :::    ";
        cin >> stu[i].department;
        cout << ":: year :::  ";
        cin >> stu[i].year;
    }

    bool flag = true;
    while (flag)
    {
        flag = false;
        char ch;
        cout << "Press:: a -To Print Student Data\nPress:: b - To Read Student Data" << endl;
        cin >> ch;
        char Name[15];
        switch (ch)
        {
        case 'a':
            cout<<"Print Students Data"<<endl;
            for (int i = 0; i < n; i++)
                stu[i].PrintStudentData();
            break;
        case 'b':
             cout<<"Read Students Data"<<endl;
            cout << "Enter The Name of Student : ";
            cin >> Name;

            for (int i = 0; i < n; i++)
            {
                stu[i].ReadStudentData(Name);
            }
            
            break;

        default: cout<<"::: Enter right key  ::"<<endl;
            break;
        }
        cout << ":: Want to Run Again :::" << endl;
        cin >> flag;
    }
    cout<<"::::: Thank you ::::::::"<<endl;

    return 0;
}