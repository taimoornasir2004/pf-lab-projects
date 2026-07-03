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

string std_name[MAX_STUDENTS], father_name[MAX_STUDENTS],cnic[MAX_STUDENTS],phone_number[MAX_STUDENTS], bload_group[MAX_STUDENTS], hostel_name[MAX_STUDENTS], record[MAX_STUDENTS];
int roll_nos[MAX_STUDENTS], bed_capacity[MAX_STUDENTS], room_nos[MAX_STUDENTS];


string rollnos[MAX_RECORDS];
string bedcapacity[MAX_RECORDS];
string roomnos[MAX_RECORDS];
string Cnic[MAX_RECORDS];
string phonenumber[MAX_RECORDS];

fstream temp;
fstream admFile;
fstream studentFile;

bool adminLoginSuccess = false;
bool studentLoginSuccess = false;

void Header();
int MainMenu();
void AdminMenu();
void StudentMenu();
void AddStudentRecord();
void ViewStudentRecord();
void UpdateRecord();
void DeleteStudentRecord();
void SignUpAdmin();
void SignInAdmin();
void SignUpStudent();
void SignInStudent();
string getField(string record, int field);
void readData();

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
    fstream admFile;
    admFile.open("signupadmin.txt", ios::out);

    system("color 3B");

    cout << "Enter the username for admin to sign up: ";
    cin >> adminUsernames[0]; // Assuming only one admin for simplicity
    cout << "Enter the password for admin to sign up: ";
    cin >> adminPasswords[0];
    admFile << adminUsernames[0] << endl
              << adminPasswords[0] << endl;

    admFile.close();
    Sleep(2000);
    main();
}

void SignInAdmin()
{
    system("CLS");
    string input_username;
    int input_password;

    fstream adminFile;
    admFile.open("signupadmin.txt", ios::in);
    admFile >> adminUsernames[0];
    admFile >> adminPasswords[0];

    system("color 3B");

    cout << "Enter the username for admin to sign in: ";
    cin >> input_username;
    cout << "Enter the password for admin to sign in: ";
    cin >> input_password;

    if (adminUsernames[0] == input_username && adminPasswords[0] == input_password)
    {
        adminLoginSuccess = true;
    }
    admFile.close();
}

void SignUpStudent()
{
    system("CLS");
    fstream studentFile;
    studentFile.open("signupstudent.txt", ios::out);

    system("color 2A");

    cout << "Enter the username for student to sign up: ";
    cin >> studentUsernames[0]; // Assuming only one student for simplicity
    cout << "Enter the password for student to sign up: ";
    cin >> studentPasswords[0];

    studentFile << studentUsernames[0] << endl
              << studentPasswords[0] << endl;
    studentFile.close();
    Sleep(2000);
    main();
}

void SignInStudent()
{
    system("CLS");
    string input_username;
    int input_password;

    fstream studentFile;
    studentFile.open("signupstudent.txt", ios::in);
    studentFile >> studentUsernames[0];
    studentFile >> studentPasswords[0];

    system("color 2A");

    cout << "Enter the username for student to sign in: ";
    cin >> input_username;
    cout << "Enter the password for student to sign in: ";
    cin >> input_password;

    if (studentUsernames[0] == input_username && studentPasswords[0] == input_password)
    {
        studentLoginSuccess = true;
    }
    studentFile.close();
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

void Header()
{
    cout << "*******************************************************************************\n";
    cout << "***                                                                         ***\n";
    cout << "***                   Hostel Management System (HMS)                        ***\n";
    cout << "***                                                                         ***\n";
    cout << "*******************************************************************************\n";
}

void AddStudentRecord()
{
    char add;
    Header();
    fstream admFile;
    admFile.open("admin.txt", ios::out);
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {

        cout << "------------------------------------------------ \n";
        cout << "Add Student Record " << i + 1 << "...\n";
        cin.ignore();
        cout << "Enter Name of Student = ";
        getline(cin, std_name[i]);
        cout << "Enter Name of Student Father = ";
        getline(cin, father_name[i]);
        cout << "Enter Roll number = ";
        cin >> roll_nos[i];
        cout << "Enter Your CNIC = ";
        cin >> cnic[i];
        cout << "Enter Your Phone Number = ";
        cin >> phone_number[i];
        cout << "Enter Your Hostel Name = ";
        cin >> hostel_name[i];
        cout << "Enter Your Hostel Room No = ";
        cin >> room_nos[i];
        cout << "Enter Your Room Bed Capacity = ";
        cin >> bed_capacity[i];
        cout << "Enter Your Bload Group = ";
        cin >> bload_group[i];
        Sleep(1000);
        admFile<<std_name[i]<<","<<father_name[i]<<","<<roll_nos[i]<<","<<cnic[i]<<","<<phone_number[i]<<","<<hostel_name[i]<<","<<room_nos[i]<<","<<bed_capacity[i]<<","<< bload_group[i];

        system("cls");
        cout << "Enter Y to add new student or press N if you dont want to ";
        cin >> add;
        if (add == 'N')
        {
            break;
        }
    }
    admFile.close();
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
        cout << "Roll number: " << rollnos[viewChoice - 1] << endl;
        cout << "Student Name: " << std_name[viewChoice - 1] << endl;
        cout << "Father Name: " << father_name[viewChoice - 1] << endl;
        cout << "CNIC: " << Cnic[viewChoice - 1] << endl;
        cout << "Phone Number: " << phonenumber[viewChoice - 1] << endl;
        cout << "Hostel Name: " << hostel_name[viewChoice - 1] << endl;
        cout << "Hostel Room No: " << roomnos[viewChoice - 1] << endl;
        cout << "Room Bed Capacity: " << bedcapacity[viewChoice - 1] << endl;
        cout << "Bload Group: " << bload_group[viewChoice - 1] << endl;
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

    admFile.open("admin.txt", ios::in);
    temp.open("Temp.txt", ios::out);

    while (getline(admFile, record))
    {
        if (i != choice - 1)
        {
            temp << record << endl;
        }
        i++;
    }

    admFile.close();
    temp.close();
    remove("admin.txt");
    rename("Temp.txt", "admin.txt");

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
    system("cls");
    Header();

    admFile.open("admin.txt", ios::in);
    temp.open("Temp.txt", ios::out);

    while (getline(admFile, record))
    {
        if (i == choice - 1)
        {
            cout << "Updating Student Record " << choice << "...\n";
            cin.ignore();
            cout << "Enter Name of Student = ";
            cin >> std_name[choice - 1];
            cout << "Enter Name of Student Father = ";
            cin >> father_name[choice - 1];
            cout << "Enter Roll number = ";
            cin >> roll_nos[choice - 1];
            cout << "Enter Your CNIC = ";
            cin >> cnic[choice - 1];
            cout << "Enter Your Phone Number = ";
            cin >> phone_number[choice - 1];
            cout << "Enter Your Hostel Name = ";
            cin >> hostel_name[choice - 1];
            cout << "Enter Your Hostel Room No = ";
            cin >> room_nos[choice - 1];
            cout << "Enter Your Room Bed Capacity = ";
            cin >> bed_capacity[choice - 1];
            cout << "Enter Your Bload Group = ";
            cin >> bload_group[choice - 1];
            Sleep(1000);
            system("cls");

            temp << std_name[choice - 1] << ",";
            temp << father_name[choice - 1] << ",";
            temp << roll_nos[choice - 1] << ",";
            temp << cnic[choice - 1] << ",";
            temp << phone_number[choice - 1] << ",";
            temp << hostel_name[choice - 1] << ",";
            temp << room_nos[choice - 1] << ",";
            temp << bed_capacity[choice - 1] << ",";
            temp << bload_group[choice - 1] << endl;
        }
        else
        {
            temp << record << endl;
        }
        i++;
    }

    admFile.close();
    temp.close();
    remove("admin.txt");
    rename("Temp.txt", "admin.txt");

    cout << "Updated student data" << endl;
    getch();
    system("cls");
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
    admFile.open("admin.txt", ios::in);
    studentFile.open("student.txt", ios::in);
    int i = 0;
    while (getline(admFile, record))
    {
        std_name[i] = getField(record, 1);
        father_name[i] = getField(record, 2);
        rollnos[i] = getField(record, 3);
        Cnic[i] = getField(record, 4);
        phonenumber[i] = getField(record, 5);
        hostel_name[i] = getField(record, 6);
        roomnos[i] = getField(record, 7);
        bedcapacity[i] = getField(record, 8);
        bload_group[i] = getField(record, 9);
        i++;
    }
    admFile.close();
    studentFile.close();
}
