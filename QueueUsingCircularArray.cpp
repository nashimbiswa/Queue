#include<bits/stdc++.h>
using namespace std;

// Using Circular Array
// O(1) Enqueue and Dequeue

struct Queue
{
    int *arr;
    int front,size,capacity;
    Queue(int cap)
    {
        capacity=cap;
        arr=new int[capacity];
        size=0;
        front=0;
    }

    bool isEmpty()
    {
        return size==0;
    }
    
    bool isFull()
    {
        return size==capacity;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        return front;
    }

    int getRear()
    {
        if(isEmpty())
            return -1;
        return (front+size-1)%capacity;
    }

    bool enqueue(int val)
    {
        if(isFull())
            return 0;
        else
        {
            int rear=getRear();
            rear=(rear+1)%capacity;
            arr[rear]=val;
            ++size;
            return 1;
        }
    }

    bool dequeue()
    {
        if(isEmpty())
            return 0;
        front=(front+1)%capacity;
        --size;
        return 1;
    }

    int getSize()
    {
        return size;
    }
};

int main(int argc, char const *argv[])
{
    int cap;
    cout<<"Enter the capacity of the Queue:\n";
    cin>>cap;
    Queue q1(cap);
    int choice,val,dat,da;
    bool res1,res2;
    do
    {
        cout<<"\nEnter your choice:\n";
        cout<<"1. To enqueue.\n";
        cout<<"2. To dequeue.\n";
        cout<<"3. To get Front.\n";
        cout<<"4. To get Rear.\n";
        cout<<"5. To check size.\n";
        cout<<"6. To check Queue is Empty or Not\n";
        cout<<"7. To check Queue is Full or Not\n";
        cout<<"8. To Exit.\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter the data in the queue.\n";
            cin>>data;
            if(q1.enqueue(data))
            {
                cout<<"Successfully Inserted.\n";
            }else
            {
                cout<<"Queue is full. Can't insert the value\n";
            }
            break;
        case 2:
            if(q1.dequeue())
            {
                cout<<"Successfully deleted the element.\n";
            }else
            {
                cout<<"Queue is Empty. No Element to Dequeue.\n";
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
                cout<<"Front element is "<<q1.arr[dat]<<".\n";
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
                cout<<"Rear element is "<<q1.arr[da]<<".\n";
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
            res2=q1.isFull();
            if(res2)
                cout<<"Yes it is Full.\n";
            else
                cout<<"No it is not Full.\n";
            break;
        }
    if(choice==8)
        return 0;
    } while (true);    
    return 0;
}

