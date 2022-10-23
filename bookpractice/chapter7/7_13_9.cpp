#include <iostream>
#include <cstring>
using namespace std;
const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of 
// an array of student structures and an int representing the 
// number of elements of the array. It terminates input upon filling 
// the array or upon encountering a blank line for the student 
// name. The function returns the actual number of array elements 
// filled.
int getinfo(student pa[], int n);

// display1() takes a student structure as an 
// argument and displays the structure's contents
void display1(student st);

// display2() takes the address of student structure as an 
// argument and displays the structure's contents
void display2(const student * ps);

// display3() takes the address of the first element of an array
// arguments and displays the contents of the structures
void display3(const student pa[],int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student * ptr_stu= new student[class_size];
    int entered = getinfo(ptr_stu,class_size);
    for (int i=0;i<entered;i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu,entered);
    delete [] ptr_stu;
    cout << "Done\n";
    return 0;
}
int getinfo(student pa[], int n)
{
    int i =0;
    for (;i<n;i++)
    {
        cout << "Enter the " << i+1 << "student's fullname: ";
        cin.getline(pa[i].fullname,SLEN);
        if (strlen(pa[i].fullname) == 0)
            break;  // 当输入为换行的时候，字符串长度为0
        cout << "Enter the " << i+1 <<"student's hobby: ";
        cin >> pa[i].hobby;
        cout << "Enter the " << i+1 << "student's ooplevel: ";
        if (!(cin >> pa[i].ooplevel))
            break;
        cin.get(); //清除数字后的换行符以避免影响字符串输入，需用这个
                   //，不能用cin.clear

    }
    return i;
}

void display1(student st)
{
    cout << "fullname: " << st.fullname << endl;
    cout << "hobby: " << st.hobby << endl;
    cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student * ps)
{
    cout << "fullname: " << ps->fullname << endl;
    cout << "hobby: " << ps->hobby << endl;
    cout << "ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[],int n)
{
    for (int i = 0;i<n;i++)
    {
        cout << "fullname: " << (pa+i)->fullname << endl;
        cout << "hobby: " << (pa+i)->hobby <<endl;
        cout << "ooplevel: " << (pa+i)->ooplevel << endl;
    }
}