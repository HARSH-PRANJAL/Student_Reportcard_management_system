#include "node.h"



void queue::input()// function to connect new nodes in the queue
{
    if(start==NULL)
    {
        start=end=temp;
    }
    else
    {
        end->next=temp;
        end=temp;
    }
}

void queue::raw_input()//function to take input from user in the new node
{
    temp=new node;
    if(temp==NULL)
    {
        cout<<"Disk memory full !!!!";
        return;
    }
    cout<<"Enter name of the student :      ";
    cin>>temp->name;
    cout<<"Enter roll number of the student:    ";
    cin>>temp->roll_no;
    cout<<"Enter registration number of the student:    ";
    cin>>temp->reg_no;
    temp->subject[0]="MATHS";
    cout<<"Enter the marks of MATHS:    ";
    cin>>temp->marks[0];
    temp->subject[1]="SCLD";
    cout<<"Enter the marks of SCLD:    ";
    cin>>temp->marks[1];
    temp->subject[2]="DCCN";
    cout<<"Enter the marks of DCCN:    ";
    cin>>temp->marks[2];
    temp->subject[3]="DS";
    cout<<"Enter the marks of DS:    ";
    cin>>temp->marks[3];
    temp->subject[4]="C++";
    cout<<"Enter the marks of C++:    ";
    cin>>temp->marks[4];

    temp->percentage=0;
    for(int i=0;i<5;i++)
    {
        temp->percentage+=temp->marks[i];
    }

    temp->percentage/=5;
    if(temp->percentage>33)
        temp->status="PASS";
    else
        temp->status="FAIL";
    temp->next=NULL;
    cout<<"Insertion completed";
}

void queue::disp()//function to display the queue
{
    if(start==NULL)
    {
        cout<<"Queue is empty !!!!";
        return;
    }
    else
    {
        int i=1;
        temp=start;
        do{
            cout<<"\n\n";
            cout<<i<<" "<<temp->name<<" ( "<<temp->status<<" )"<<endl;
            cout<<"ROLL NUMBER :    "<<temp->roll_no<<endl;
            cout<<"REGISTRATION NUMBER :    "<<temp->reg_no<<endl;
            cout<<temp->subject[0]<<" :     "<<temp->marks[0]<<endl;
            cout<<temp->subject[1]<<" :     "<<temp->marks[1]<<endl;
            cout<<temp->subject[2]<<" :     "<<temp->marks[2]<<endl;
            cout<<temp->subject[3]<<" :     "<<temp->marks[3]<<endl;
            cout<<temp->subject[4]<<" :     "<<temp->marks[4]<<endl;
            cout<<"Percentage secured :     "<<temp->percentage<<"%"<<endl;
            ++i;
            temp=temp->next;
        }while(temp->next!=NULL && temp!=NULL);
    }
}

void queue::del()// delete the node of the queue
{
    if(start==NULL)
    {
        cout<<"Queue is empty !!!!\n";
        return;
    }
    else
    {
        cout<<"\nEnter index number to delete the node    :   ";
        int pos;
        cin>>pos;
        temp=start;

        if(pos==1)//delete first node
        {
            delt=start;
            start=start->next;
            delete delt;
            delt=NULL;
        }
        else
        {
            for(int i=1;i<pos-1;i++)//delete any node other then first node
            {
                temp=temp->next;
            }
            delt=temp->next;
            temp->next=delt->next;
            delete delt;
            delt=NULL;
        } 
        cout<<"Deletion completed";
    }
}


void queue::entry_func()//function to run queue operation menue
{
    int choice;
    while(1)
    {
        cout<<"\n\t\t1. Insert\n";
        cout<<"\t\t2. Display\n";
        cout<<"\t\t3. Delete\n";
        cout<<"\t\t4. Exit\n";
        cout<<"\t\tPress(1/2/3/4)......\t\t: ";
        cout<<"\nEnter the index number to perform operation :  ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            raw_input();
            input();
            break;
        case 2:
            //sort();
            disp();
            break;
        case 3:
            del();
            break;
        case 4:
            return;
            break;
        default:
        cout<<"Please enter correct option";
            break;
        }
    }
}