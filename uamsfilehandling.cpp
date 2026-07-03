#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

const int MAX_ADMINS = 5;     // Set a maximum number of admins
const int MAX_STUDENTS = 100; // Set a maximum number of students
const int MAX_RECORDS = 100;

string adminUsernames[MAX_ADMINS];
int adminPasswords[MAX_ADMINS];

string studentUsernames[MAX_STUDENTS];
int studentPasswords[MAX_STUDENTS];

string studentNames[MAX_STUDENTS];
int studentRollNos[MAX_STUDENTS];
float studentM_Marks[MAX_STUDENTS], studentF_Marks[MAX_STUDENTS], studentE_Marks[MAX_STUDENTS], studentAggs[MAX_STUDENTS];
string studentDepartments[MAX_STUDENTS];

string stuNames[MAX_RECORDS];
string stuRollNos[MAX_RECORDS];
string stuM_Marks[MAX_RECORDS];
string stuF_Marks[MAX_RECORDS];
string stuE_Marks[MAX_RECORDS];
string stuAggs[MAX_RECORDS];
string stuDepartments[MAX_RECORDS];

bool adminLoginSuccess = false;
bool studentLoginSuccess = false;

fstream temporary;
fstream adminFile;
fstream stuFile;

void Header();
int MainMenu();
void AdminMenu();
void StudentMenu();
void AddStudentRecord();
void ViewStudentRecord();
void DeleteStudentRecord();
void UpdateRecord();
void SignUpAdmin();
void SignInAdmin();
void SignUpStudent();
void SignInStudent();
float CalculateAggregate(float M_Marks, float F_Marks, float E_Marks);
string AssignDepartment(float aggregate);
string getField(string record, int field);
void readData();
float converter(string a);

int main()
{

    int userType = MainMenu();
    while (true)
    {

        if (userType == 1)
        {
            int opt;
            cout << "What You want to sign up or sign in : ";
            cin >> opt;
            if (opt == 1)
            {
                SignUpAdmin();
            }
            if (opt == 2)
            {
                SignInAdmin();
                if (adminLoginSuccess)
                {
                    cout << "Admin login successful." << endl;
                    Sleep(1000);
                    system("cls");

                    AdminMenu();
                }
                else
                {
                    cout << "Admin login failed." << endl;
                    exit(0);
                }
            }
        }
        else if (userType == 2)
        {
            int opt;
            cout << "What You want to sign up or sign in : ";
            cin >> opt;
            if (opt == 1)
            {
                SignUpStudent();
            }
            if (opt == 2)
            {
                SignInStudent();
                if (studentLoginSuccess)
                {
                    cout << "Student login successful." << endl;
                    Sleep(1000);
                    system("cls");

                    StudentMenu();
                }
                else
                {
                    cout << "Student login failed." << endl;
                    exit(0);
                }
            }
        }
        else
        {
            cout << "Invalid choice. Exiting UAMS. Goodbye!" << endl;
            exit(0);
        }
    }

    return 0;
}

int MainMenu()
{
    int choice;
    system("color 2A");
    cout << "-------------------------\n";
    cout << "       Main Menu          \n";
    cout << "-------------------------\n";
    cout << "1. Admin\n";
    cout << "2. Student\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

void SignUpAdmin()
{
    system("CLS");
    fstream adminFile;
    adminFile.open("signupadm.txt", ios::out);

    system("color 3B");

    cout << "Enter the username for admin to sign up: ";
    cin >> adminUsernames[0]; // Assuming only one admin for simplicity
    cout << "Enter the password for admin to sign up: ";
    cin >> adminPasswords[0];
    adminFile << adminUsernames[0] << endl
              << adminPasswords[0] << endl;

    adminFile.close();
    Sleep(2000);
    main();
}

void SignInAdmin()
{
    system("CLS");
    string input_username;
    int input_password;

    fstream adminFile;
    adminFile.open("signupadm.txt", ios::in);
    adminFile >> adminUsernames[0];
    adminFile >> adminPasswords[0];

    system("color 3B");

    cout << "Enter the username for admin to sign in: ";
    cin >> input_username;
    cout << "Enter the password for admin to sign in: ";
    cin >> input_password;

    if (adminUsernames[0] == input_username && adminPasswords[0] == input_password)
    {
        adminLoginSuccess = true;
    }
    adminFile.close();
}

void SignUpStudent()
{
    system("CLS");
    fstream stuFile;
    stuFile.open("signupstu.txt", ios::out);

    system("color 2A");

    cout << "Enter the username for student to sign up: ";
    cin >> studentUsernames[0]; // Assuming only one student for simplicity
    cout << "Enter the password for student to sign up: ";
    cin >> studentPasswords[0];

    adminFile << studentUsernames[0] << endl
              << studentPasswords[0] << endl;
    stuFile.close();
    Sleep(2000);
    main();
}

void SignInStudent()
{
    system("CLS");
    string input_username;
    int input_password;

    fstream stuFile;
    stuFile.open("signupstu.txt", ios::in);
    stuFile >> studentUsernames[0];
    stuFile >> studentPasswords[0];

    system("color 2A");

    cout << "Enter the username for student to sign in: ";
    cin >> input_username;
    cout << "Enter the password for student to sign in: ";
    cin >> input_password;

    if (studentUsernames[0] == input_username && studentPasswords[0] == input_password)
    {
        studentLoginSuccess = true;
    }
    stuFile.close();
}

void AdminMenu()
{
    while (true)
    {
        system("color 3B");
        system("CLS");
        int opt = -1;
        Header();
        cout << "1- Admin Menu\n";
        cout << "2- Exit Admin Menu\n";
        cout << "Choose option (1 for admin menu, 2 to exit): ";
        cin >> opt;

        if (opt == 1)
        {
            int adminOpt = -1;
            Header();
            cout << "----------------- Admin Menu ---------------------\n";
            cout << "1- Add Student \n";
            cout << "2- View Student Record \n";
            cout << "3- Delete Student Record \n";
            cout << "4- Update Student Record \n";
            cout << "5- Exit Admin Menu\n";
            cout << "-------------------------------------------------- \n";
            cout << "Choose option from the admin menu (1 for add, 2 for view, and so on...)" << endl;
            cout << "Enter your option: ";
            cin >> adminOpt;

            if (adminOpt == 1)
            {
                AddStudentRecord();
            }
            else if (adminOpt == 2)
            {
                ViewStudentRecord();
            }
            else if (adminOpt == 3)
            {
                DeleteStudentRecord();
            }
            else if (adminOpt == 4)
            {
                UpdateRecord();
            }
            else if (adminOpt == 5)
            {
                cout << "Exiting Admin Menu. Goodbye!" << endl;
                main();
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        else if (opt == 2)
        {
            cout << "Exiting UAMS. Goodbye!" << endl;
            main();
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void StudentMenu()
{
    while (true)
    {
        system("color 2A");
        system("CLS");
        int studentOpt = -1;
        Header();
        cout << "----------------- Student Menu ---------------------\n";
        cout << "1- View Your Record \n";
        cout << "2- Exit Student Menu\n";
        cout << "---------------------------------------------------- \n";
        cout << "Choose option from the student menu (1 for view, 2 to exit): ";
        cin >> studentOpt;

        if (studentOpt == 1)
        {
            ViewStudentRecord();
        }
        else if (studentOpt == 2)
        {
            cout << "Exiting Student Menu. Goodbye!" << endl;
            main();
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void AddStudentRecord()
{
    char add;
    Header();
    fstream adminFile;
    adminFile.open("adm.txt", ios::out);
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        cout << "------------------------------------------------ \n";
        cout << "Add Student Record " << i + 1 << "...\n";
        cin.ignore();
        cout << "Enter Name of Student = ";
        getline(cin, studentNames[i]);
        cout << "Enter Roll number = ";
        cin >> studentRollNos[i];
        cout << "Enter Matric Marks = ";
        cin >> studentM_Marks[i];
        cout << "Enter F.Sc Marks = ";
        cin >> studentF_Marks[i];
        cout << "Enter ECAT Test Marks = ";
        cin >> studentE_Marks[i];
        studentAggs[i] = CalculateAggregate(studentM_Marks[i], studentF_Marks[i], studentE_Marks[i]);
        studentDepartments[i] = AssignDepartment(studentAggs[i]);
        cout << "Aggregate: " << studentAggs[i] << endl;
        cout << "Department Preference: " << studentDepartments[i] << endl;
        Sleep(1000);
        system("cls");
        adminFile << studentNames[i] << "," << studentRollNos[i] << "," << studentM_Marks[i] << "," << studentF_Marks[i] << "," << studentE_Marks[i] << "," << studentAggs[i] << "," << studentDepartments[i] << endl;
        cout << "Enter Y to add new student or press N if you dont want to ";
        cin >> add;
        if (add == 'N')
        {
            break;
        }
    }
    adminFile.close();
}

void ViewStudentRecord()
{
    readData();
    int viewChoice;
    cout << "Enter the Student Number to View (1-" << MAX_STUDENTS << "): ";
    cin >> viewChoice;

    if (viewChoice >= 1 && viewChoice <= MAX_STUDENTS)
    {
        cout << "Viewing Student Record " << viewChoice << "...\n";
        cout << "Name: " << stuNames[viewChoice - 1] << endl;
        cout << "Roll number: " << stuRollNos[viewChoice - 1] << endl;
        cout << "Matric Marks: " << stuM_Marks[viewChoice - 1] << endl;
        cout << "F.Sc Marks: " << stuF_Marks[viewChoice - 1] << endl;
        cout << "ECAT Test Marks: " << stuE_Marks[viewChoice - 1] << endl;
        cout << "Aggregate: " << stuAggs[viewChoice - 1] << endl;
        cout << "Department Preference: " << studentDepartments[viewChoice - 1] << endl;
        Sleep(2000);
        system("cls");
    }
    else
    {
        cout << "Invalid choice. Please enter a number between 1 and " << MAX_STUDENTS << "." << endl;
    }
}

void DeleteStudentRecord()
{
    string record;
    int choice;
    int i = 0;
    system("cls");
    Header();
    cout << "Enter Student Number to Delete (1-" << MAX_STUDENTS << "): ";
    cin >> choice;

    adminFile.open("adm.txt", ios::in);
    temporary.open("Temporary.txt", ios::out);

    while (getline(adminFile, record))
    {
        if (i != choice - 1)
        {
            temporary << record << endl;
        }
        i++;
    }

    adminFile.close();
    temporary.close();
    remove("adm.txt");
    rename("Temporary.txt", "adm.txt");

    cout << "Deleted student data" << endl;
    cout << "Press any key to return to the main menu";
    getch();
    system("cls");
}

void UpdateRecord()
{
    string record;
    int choice;
    int i = 0;

    cout << "Enter Student Number to Update (1-" << MAX_STUDENTS << "): ";
    cin >> choice;
    cin.ignore();
    system("cls");
    Header();

    adminFile.open("adm.txt", ios::in);
    temporary.open("Temporary.txt", ios::out);

    while (getline(adminFile, record))
    {
        if (i == choice - 1)
        {
            cout << "Enter Name of Student = ";
            cin >> stuNames[choice - 1];
            cout << "Enter Roll number = ";
            cin >> stuRollNos[choice - 1];
            cin.ignore();
            cout << "Enter Matric Marks = ";
            cin >> stuM_Marks[choice - 1];
            cout << "Enter F.Sc Marks = ";
            cin >> stuF_Marks[choice - 1];
            cout << "Enter ECAT Test Marks = ";
            cin >> stuE_Marks[choice - 1];

            cout << "Aggregate: " << CalculateAggregate(converter(stuM_Marks[choice - 1]), converter(stuF_Marks[choice - 1]), converter(stuE_Marks[choice - 1])) << endl;
            cout << "Department Preference: " << AssignDepartment(CalculateAggregate(converter(stuM_Marks[choice - 1]), converter(stuF_Marks[choice - 1]), converter(stuE_Marks[choice - 1]))) << endl;

            temporary << stuNames[choice - 1] << ",";
            temporary << stuRollNos[choice - 1] << ",";
            temporary << stuM_Marks[choice - 1] << ",";
            temporary << stuF_Marks[choice - 1] << ",";
            temporary << stuE_Marks[choice - 1] << ",";
            temporary << CalculateAggregate(converter(stuM_Marks[choice - 1]), converter(stuF_Marks[choice - 1]), converter(stuE_Marks[choice - 1])) << ",";
            temporary << AssignDepartment(CalculateAggregate(converter(stuM_Marks[choice - 1]), converter(stuF_Marks[choice - 1]), converter(stuE_Marks[choice - 1]))) << endl;
        }
        else
        {
            temporary << record << endl;
        }
        i++;
    }

    adminFile.close();
    temporary.close();
    remove("adm.txt");
    rename("Temporary.txt", "adm.txt");

    cout << "Updated student data" << endl;
    getch();
    system("cls");
}

void Header()
{
    cout << "*******************************************************************************\n";
    cout << "***                                                                         ***\n";
    cout << "***                University Admission Management System (UAMS)            ***\n";
    cout << "***                                                                         ***\n";
    cout << "*******************************************************************************\n";
}

float CalculateAggregate(float M_Marks, float F_Marks, float E_Marks)
{
    return (M_Marks / 1100) * 17 + (F_Marks / 1100) * 50 + (E_Marks / 400) * 33;
}

string AssignDepartment(float aggregate)
{
    if (aggregate >= 80)
    {
        return "Computer Science";
    }
    else if (aggregate >= 70)
    {
        return "Electrical Engineering";
    }
    else if (aggregate >= 60)
    {
        return "Mechanical Engineering";
    }
    else
    {
        return "Your Merit is to low , Better Luck Next Time";
    }
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void readData()
{
    string record;
    adminFile.open("adm.txt", ios::in);
    stuFile.open("stu.txt", ios::in);
    int i = 0;
    while (getline(adminFile, record))
    {
        stuNames[i] = getField(record, 1);
        stuRollNos[i] = getField(record, 2);
        stuM_Marks[i] = getField(record, 3);
        stuF_Marks[i] = getField(record, 4);
        stuE_Marks[i] = getField(record, 5);
        stuAggs[i] = getField(record, 6);
        stuDepartments[i] = getField(record, 7);
        i++;
    }
    adminFile.close();
    stuFile.close();
}

float converter(string a)
{
    float result = 0;
    int x = 0;
    while (a[x] != '\0')
    {
        x = x + 1;
    }
    for (int n = 0; n < x; n++)
    {
        result = result * 10 + (a[n] - '0');
    }
    return result;
}
