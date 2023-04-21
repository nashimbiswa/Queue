#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};

struct Queue
{
    int size;
    Node *front;
    Node *rear;
    Queue()
    {
        front=nullptr;
        size=0;
    }

    bool isEmpty()
    {
        if(!front)
            return 1;
        return 0;
    }

    bool enqueue(int data)
    {
        Node *newnode=new Node(data);
        if(getSize()==0)
        {
            front=rear=newnode;
            ++size;
        }
        else
        {
            rear->next=newnode;
            rear=rear->next;
            ++size;
        }
        return 1;
    }

    bool dequeue()
    {
        
        if(!front)
            return 0;
        Node *temp=front;
        front=front->next;
        if(!front)
            rear=0;
        delete (temp);
        --size;
        return 1;
    }
    
    int getSize()
    {
        return size;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        else
            return front->data;
    }

    int getRear()
    {
        if(isEmpty())
            return -1;
        return rear->data;
    }

    void display()
    {
        if(getSize()==0)
            cout<<"Queue is empty.\n";
        else
        {

            Node *temp=front;
            cout<<"Queue elements are as follows:\n";
            while (temp!=0)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            
        }
    } 
};

int main(int argc, char const *argv[])
{
    Queue q1;
    int choice,val,dat,da;
    bool res1,res2;
    do
    {
        
        cout<<"\n1. To enqueue.\n";
        cout<<"2. To dequeue.\n";
        cout<<"3. To get Front.\n";
        cout<<"4. To get Rear.\n";
        cout<<"5. To check size.\n";
        cout<<"6. To check Queue is Empty or Not\n";
        cout<<"7. To Display.\n";
        cout<<"8. To Exit.\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter the data in the queue:\n";
            cin>>data;
            q1.enqueue(data);
            break;
        case 2:
            val=q1.dequeue();
            if(val==0)
            {
                cout<<"Queue is Empty. No Element to Dequeue.\n";
            }
            else
            {
               cout<<"Successfully Dequeued.\n";
            }
            break;
        case 3:
            dat=q1.getFront();
            if(dat==-1)
            {
                cout<<"Queue is Empty.\n";
            }
            else
            {
                cout<<"Front element is "<<dat<<".\n";
            }
            break;
        case 4:
            da=q1.getRear();
            if(da==-1)
            {
                cout<<"Queue is Empty.\n";
            }
            else
            {
                cout<<"Rear element is "<<da<<".\n";
            }
            break;
        case 5:
            cout<<"Size is "<<q1.getSize()<<".";
            break;
        case 6:
            res1=q1.isEmpty();
            if(res1)
                cout<<"Yes it is empty.\n";
            else
                cout<<"No it is not empty.\n";
            break;
        case 7:
            q1.display();
            break;
        }
    if(choice==8)
        return 0;
    } while (true);    
    return 0;
}
