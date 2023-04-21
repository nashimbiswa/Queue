// O(1) enqueue
// O(n) dequeue
#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int size;
    int capacity;
    int *arr;
    int front;
    int rear;
    Queue(int cap)
    {
        capacity=cap;
        size=0;
        arr=new int[capacity];
    }
    bool checkIsFull()
    {
       return (size==capacity);
    }

    void enqueue(int value)
    {
        if(checkIsFull())
        {
            cout<<"Queue is full\n";
        }
        else{
            arr[size]=value;
            ++size;
        }
    }
    
    bool checkIsEmpty()
    {
        return (size==0);   
    }

    int dequeue()
    {
        if(checkIsEmpty())
            return INT16_MIN;
        else
        {
            int data=arr[size-1];
            for(int i=0;i<size-1;++i)
            {
                arr[i]=arr[i+1];
            }
            --size;
            return data;
        }
    }

    int getFront()
    {
        if(checkIsEmpty())
            return -1;
        return arr[0];
    }

    int getRear()
    {
        if(checkIsEmpty())
            return -1;
        return arr[size-1];
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        if(checkIsEmpty())
        {
            cout<<"Queue is emmpty.\n";
        }
        else
        {
            cout<<"Queue element are as follows:\n";
            for (int i = 0; i < size; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<"Front element is "<<getFront()<<"\n";
            cout<<"Rear element is "<<getRear()<<"\n";
        }
        
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
        cout<<"8. To Display.\n";
        cout<<"9. To Exit.\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter the data in the queue.\n";
            cin>>data;
            q1.enqueue(data);
            break;
        case 2:
            int val;
            val=q1.dequeue();
            if(val==INT16_MIN)
            {
                cout<<"Queue is Empty. No Element to Dequeue.\n";
            }
            else
            {
                cout<<"Dequeue element is "<<val<<".\n";
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
            res1=q1.checkIsEmpty();
            if(res1)
                cout<<"Yes it is empty.\n";
            else
                cout<<"No it is not empty.\n";
            break;
        case 7:
            res2=q1.checkIsFull();
            if(res2)
                cout<<"Yes it is Full.\n";
            else
                cout<<"No it is not Full.\n";
            break;
        case 8:
            q1.display();
            break;
        }
    if(choice==9)
        return 0;
    } while (true);    
    return 0;
}
