#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[50];
    Date birthDate;

    Person* parent;

    void Print()
    {
        cout << "Name: " << name
            << " [" << birthDate.day << "."
            << birthDate.month << "."
            << birthDate.year << "]\n";
    }
};

struct User
{
    char name[50];
    int age;
    float level;
};

void UserPrint(User user);
User UserCreateEmpty();
void UserStructExample();


int main()
{
    Date date1;
    date1.day = 14;
    date1.month = 5;
    date1.year = 2001;

    Person person1;
    strcpy_s(person1.name, "Leo");
    person1.birthDate = date1;

    person1.Print();

    Person person2;
    strcpy_s(person2.name, "Jim");
    person2.birthDate.day = 21;
    person2.birthDate.month = 10;
    person2.birthDate.year = 1998;

    //cout << sizeof(person1) << "\n";

    Person* person3 = new Person;

    person3->birthDate = date1;

    delete person3;

    //cout << sizeof(person3) << "\n";



    time_t currTime = time(nullptr);
    //cout << currTime;

    tm* currTM = localtime(&currTime);
    //cout << (*currTM).tm_sec << "\n";
    /*cout << (*currTM).tm_min << "\n";
    cout << (*currTM).tm_hour << "\n";
    cout << (*currTM).tm_mday << "\n";
    cout << (*currTM).tm_mon + 1 << "\n";
    cout << (*currTM).tm_year + 1900 << "\n";*/

}

void UserPrint(User user)
{
    cout << user.name 
         << " (" << user.age << ") -> " 
         << user.level << "\n";
}
User UserCreateEmpty()
{
    User user;
    strcpy_s(user.name, 1, "");
    user.age = 0;
    user.level = 0.0f;

    return user;
}
void UserStructExample()
{
    User user1 = UserCreateEmpty();

    UserPrint(user1);

    user1.age = 23;
    strcpy_s(user1.name, 4, "Bob");
    user1.level = 11.5;

    UserPrint(user1);

    User users[3];

    users[0].age = 23;
    strcpy_s(users[0].name, 4, "Bob");
    users[0].level = 11.5;

    users[1].age = 41;
    strcpy_s(users[1].name, 4, "Tom");
    users[1].level = 9;

    users[2].age = 35;
    strcpy_s(users[2].name, 4, "Sam");
    users[2].level = 10.3;

    for (int i = 0; i < 3; i++)
        UserPrint(users[i]);
}
