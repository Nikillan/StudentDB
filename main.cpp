#include<iostream>
#include<string>
#include<iomanip>


using namespace std;

struct student
{
    int std_id;
    char dept[4];
    char std_name[20];
    struct student *next;
}typedef stud;

stud* head = NULL;
stud* tail = NULL;


stud* createStudent(void)
{
    stud *newStd;
    newStd = (stud*)malloc(sizeof(stud));
    newStd -> std_id = 0;
    newStd -> next = NULL;
    return newStd;
}

void addFirst(void)
{
    stud *temp;
    temp = createStudent();
    cout << "Enter Name: " << endl;
    cin >> temp -> std_name;
    cout << endl << "Enter Department: ";
    cin >>  temp -> dept;
    cout << "Enter Roll Number: " << endl;
    cin >>  temp -> std_id;
    if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    temp -> next = head;
    head = temp;
    return;
}
short int stdsize = 0;
void addLast(void)
{
    stud *temp;
    temp = createStudent();
    ++stdsize;
    cout << "Enter Name" << endl;
    cin >> temp -> std_name;
    cout << "Enter Department: " << endl;
    cin >>  temp -> dept;
    cout << "Enter Roll Number: " << endl;
    cin >>  temp -> std_id;
    if(tail == NULL)
    {
        tail = temp;
        head = tail;
        return;
    }
    tail -> next = temp;
    tail = temp;
    return;
}

void removeStudent(int rem)
{
    stud *th1;
    stud *th2;
    if(head == NULL)
        return;
    if(head -> next == NULL)
    {
        th1 = tail;
        tail = head;
        free(th1);
        th1 = NULL;
        return;
    }
    else if(rem <= 1)
    {
        th1 = head;
        head = head -> next;
        free(th1);
        th1 = NULL;
        return;
    }
    else if(rem >= stdsize)
    {
        th2 = head;
        while(th2)
        {
            th1 = th2 -> next;
            if(th1 == NULL)
            {
                th2 -> next = NULL;
                tail = th2;
                return;
            }
            th2 = th2 -> next;
        }

    }

    th2 = head;
    th1 = th2 -> next;

    while(rem > 1)
    {
        if(rem == 2)
        {
            th2 -> next = th1 -> next;
            free(th1);
            th1 = NULL;
            return;
        }
        th2 = th2 -> next;
        th1 = th2 -> next;

    }

}

int main()
{
    char check;
    stud *th;
    short int choice;
    cout << "1: Student List" <<endl;
    cout << "2: Add Student" <<endl;
    cout << "3: Remove Student" <<endl;
//    cout << "4: Mark List" <<endl;
    while(1)
    {
        cin  >> choice;
        th = head;
        switch(choice)
        {
        case 1:
            while(th)
            {
                cout << setw(15) << left << "Name" << th -> std_name << endl;
                cout << setw(15) << left << "Department" << th -> dept << endl;
                cout << setw(15) << left << "Roll Number" << th -> std_id << endl;

                th = th -> next;
            }
            break;
        case 2:
            addLast();
            break;
        case 3:
            short int remid;
            cout << "Enter Student Roll Number" << endl;
            cin >> remid;

        }

    }
    while(1)
    {
        cout << "Add name (Y/ N)" << endl;
        cin >> check;
        if(check == 'n' || check == 'N')
            break;
    }
    th = head;

}
