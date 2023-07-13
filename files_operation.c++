#include <fstream>
#include "node_queue.c++"

int main();

void new_file()
{
    char ch;
    ofstream f1;
    f1.open("test.dat",ios::app);
    if(!f1){
        cout<<"File can't be opened"<<endl;
        return;
    }
    queue::getInstance().entry_func();

    do{
    f1<<queue::getInstance().start->name<<"\n";    
    f1<<queue::getInstance().start->roll_no<<"\n";   
    f1<<queue::getInstance().start->reg_no<<"\n";
    f1<<queue::getInstance().start->subject[0]<<"\n";
    f1<<queue::getInstance().start->marks[0]<<"\n";
    f1<<queue::getInstance().start->subject[1]<<"\n";
    f1<<queue::getInstance().start->marks[1]<<"\n";
    f1<<queue::getInstance().start->subject[2]<<"\n";
    f1<<queue::getInstance().start->marks[2]<<"\n";
    f1<<queue::getInstance().start->subject[3]<<"\n";
    f1<<queue::getInstance().start->marks[3]<<"\n";
    f1<<queue::getInstance().start->subject[4]<<"\n";    
    f1<<queue::getInstance().start->marks[4]<<"\n";
    f1<<queue::getInstance().start->percentage<<"\n";
    f1<<queue::getInstance().start->status;

    queue::getInstance().temp=queue::getInstance().start;
    queue::getInstance().start=queue::getInstance().start->next;
    delete queue::getInstance().temp;
    queue::getInstance().temp=NULL;
    }while(queue::getInstance().start!=NULL);
    cout<<"File has been Sucessfully Created..."<<endl;
    f1.close();
    main();
}

void edit_mode()
{
    ifstream f2;
    f2.open("test.dat",ios::app);
    cout<<endl;
    while(!f2.eof()){
        //open file and load data in queue
        queue::getInstance().temp=new node;
        f2>>queue::getInstance().temp->name;    
        f2>>queue::getInstance().temp->roll_no;   
        f2>>queue::getInstance().temp->reg_no;
        f2>>queue::getInstance().temp->subject[0];
        f2>>queue::getInstance().temp->marks[0];
        f2>>queue::getInstance().temp->subject[1];
        f2>>queue::getInstance().temp->marks[1];
        f2>>queue::getInstance().temp->subject[2];
        f2>>queue::getInstance().temp->marks[2];
        f2>>queue::getInstance().temp->subject[3];
        f2>>queue::getInstance().temp->marks[3];
        f2>>queue::getInstance().temp->subject[4];    
        f2>>queue::getInstance().temp->marks[4];
        f2>>queue::getInstance().temp->percentage;
        f2>>queue::getInstance().temp->status;
        queue::getInstance().input();
        cout<<"I am here";
    }
    f2.close();
    queue::getInstance().disp();//each node contains name,reg,roll,marks of 5 subjects,percentage,pass or fail.
}
