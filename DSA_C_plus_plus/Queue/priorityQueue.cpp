#include<iostream>
using namespace std;

class PriorityQueue
{
private:
    long capacity, rearPointer;

    long row[500];
public:
    void initializePriorityQueue(long);
    void enqueue(long);
    void dequeue();
    long peak();
    long isEmpty();
    long isFull();
    void showPriorityQueue();
};

void PriorityQueue :: initializePriorityQueue(long capacity)
{
    PriorityQueue :: capacity=capacity;
    rearPointer=0;
}

void PriorityQueue :: enqueue(long value)
{
    if(isFull())
    {
       cout<<"Queue is already full"<<endl;
    }
    else
    {
        row[rearPointer++]=value;

        long currentPosition=rearPointer-1;

        while(currentPosition!=0)
        {
            if(row[currentPosition-1] > value)
            {
                row[currentPosition] = row[currentPosition-1];
            }
            else
            {
                break;
            }
            currentPosition--;
        }
        row[currentPosition]=value;
    }
}

void PriorityQueue :: dequeue()
{
    if(isEmpty())
    {
        cout<<"The queue is already empty, can't dequeue any further"<<endl;
    }
    else
    {
        long i;

        for(i=1;i<capacity;i++) //in case of 1 element it doesn't affect much either
        {
            row[i-1]=row[i];
        }
        rearPointer--;
    }
}


long PriorityQueue :: peak()
{
    return rearPointer==0 ? -1 : row[0];
}

long PriorityQueue :: isEmpty()
{
    return rearPointer==0;
}

long PriorityQueue :: isFull()
{
    return rearPointer == capacity;
}

void PriorityQueue :: showPriorityQueue()
{
    if(isEmpty())
    {
        cout<<"The queue is empty, can't print anything"<<endl;
    }
    else
    {
        long i;

        for(i=0;i<rearPointer;i++)
        {
            cout<<row[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    PriorityQueue queueOne;

    queueOne.initializePriorityQueue(5);

    queueOne.enqueue(3);
    queueOne.showPriorityQueue();

    queueOne.enqueue(2);
    queueOne.showPriorityQueue();

    queueOne.enqueue(1);
    queueOne.showPriorityQueue();

    queueOne.enqueue(4);
    queueOne.showPriorityQueue();

    queueOne.enqueue(0);
    queueOne.showPriorityQueue();

    queueOne.enqueue(4);
    queueOne.showPriorityQueue();

    queueOne.enqueue(4);
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    queueOne.dequeue();
    queueOne.showPriorityQueue();

    cout<<"Peak"<<queueOne.peak()<<endl;

    return 0;
}
