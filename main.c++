/*
Student Reportcard management system :-
This code use queue to take input from user. For implimenting queue I am using singleton class and restricting cooy constructor and 
overloading assingment operator.It upload data from the file into the queue while accessing the file for updates or modifications.
For writing and reading from file and uploading the data into the queue Iam using new_file and edit_mode as freind functions.
Our code follows OOPs concepts and privents every aspects of unauthorized access. 

1.  main.c++ is the entry point which checks for password and options like edit and open new file.
2.  node.h contains the implimentation of queue by using structure for each node and singleton class for carrying functions and
    implimenting different access modifiers.
3.  node_queue.c++ contains the code for inserting data in queue from user and from file.
4.  files_operation.c++ contain the code for uploading and downloading data from file into the queue.

*/
#include "files_operation.c++"
#include<cstdlib>

int main()
{
    a:
    int main_choice,password=1234;
    cout<<"\n\n\t\tWELCOME TO STUDENT REPORTCARD MANAGEMENT SYSTEM\n\n";
    cout<<"\t\t1. OPEN FILE FOR NEW ENTRIES\n";
    cout<<"\t\t2. OPEN EXISTING FILE FOR DISPLAY AND EDITING\n";
    cout<<"\t\t3.EXIT\n";
    cout<<"Press(1/2/3)......\t\t: ";
    cin>>main_choice;
    
    if(main_choice==1)// open file for new entry from queue
    {
        cout<<"Enter password  ......\t";
        cin>>password;
        if(password==1234)
        new_file();
        else
        {
            cout<<"Wrong Password !!!!";
            goto a;
        }
    }
    else if (main_choice==2)
        {
            edit_mode();
            goto a;
        }
        else
        {
            exit(0);
        }
    
}
