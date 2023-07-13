#include<iostream>
using namespace std;

struct node// node strucutre of the queue
{
    string name,roll_no,subject[5],status;
    int reg_no;
    float marks[5],percentage;
    node *next;//structure pointer for next node
};

class queue{
    node *start,*temp,*delt,*end;

    queue(){
        start=temp=delt=end=NULL;
    }

    ~queue(){}

    queue(const queue&) = delete; // Disallow copying
    queue& operator=(const queue&) = delete; // Disallow assignment

    public:
    
    static queue& getInstance() {
        static queue instance;
        return instance;
    }

    void input();
    void raw_input();
    void disp();
    void del();
    void entry_func();

    friend void new_file();//freind function to enter new data in the file
    friend void edit_mode();//friend function to load file data into the queue
};
