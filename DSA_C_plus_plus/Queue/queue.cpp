
/*
    PrimitiveQueue   : enqueue{O(1)} dequeue{O(n)} simple but takes O(n) for dequeue, which is bad
    OptimizedQueue : enqueue{O(1)} dequeue{O(1)} but its space is not properly used always
    Circular Queue   : enqueue{O(1)} dequeue{O(1)} but space is used properly , we only have to change enque, deque and show function of OptimizedQueue

*/


/*
    Note: In all the queues, frontPointer will be at 0 and rearPointer will be at 0
    Why ?
    1) The frontPointer will increment only when dequeue is performed
    2) We might be asked to give peak? if its initialized with -1, what would we return?
    3) During enqueue, we insert the element then we increment rear pointer
    4) If we put rearPointer as -1, how will be inqueue at -1?
    5) Condition for empty queue is frontPointer == rearPointer, however, it can be a full queue too in case of circular queue

*/


#include<iostream>
using namespace std;

class PrimitiveQueue //toTest
{
private:
    long capacity, rearPointer;

    long row[500];

public:
    void initializePrimitiveQueue(long);
    void enqueue(long);
    void dequeue();
    long isFull();
    long isEmpty();
    long peak();
    void showPrimitiveQueue();
};

void PrimitiveQueue :: initializePrimitiveQueue(long capacity)
{
    cout<<"Primitive Queue Initialized"<<endl<<endl;

    PrimitiveQueue :: capacity = capacity;
    rearPointer=0;
}

void PrimitiveQueue :: enqueue(long value)
{
    if(!isFull())
    {
        row[rearPointer]=value;
        rearPointer++;
    }
    else
    {
        cout<<"Primitive Queue is already full, please dequeue some element before enqueing more"<<endl<<endl;
    }

}

void PrimitiveQueue :: dequeue()
{
    if(!isEmpty())
    {
        long i;
        for(i=1;i<rearPointer;i++)
        {
            row[i-1]=row[i];
        }
        rearPointer--;
    }
    else
    {
        cout<<"Primitive Queue is already empty, please enqueue some element before dequeing"<<endl<<endl;
    }
}


long PrimitiveQueue :: isFull()
{
    return rearPointer==capacity;
}

long PrimitiveQueue :: isEmpty()
{
    return rearPointer==0;
}

long PrimitiveQueue :: peak()
{
    if(isEmpty())
    {
        return -1;
    }
    else
    {
        return row[0];
    }
}

void PrimitiveQueue :: showPrimitiveQueue()
{
    if(isEmpty())
    {
        cout<<"Primitive Queue is empty, can't show anything"<<endl<<endl;
    }
    else
    {
        long i;
        for(i=0;i<rearPointer;i++)
        {
            cout<<row[i]<<" ";
        }
        cout<<endl<<endl;
    }
}


class OptimizedQueue
{
private:
    long capacity, frontPointer, rearPointer;

    long row[500];

public:
    void initializeOptimizedQueue(long);
    void enqueue(long);
    void dequeue();
    long isFull();
    long isEmpty();
    long peak();
    void showOptimizedQueue();

};

void OptimizedQueue :: initializeOptimizedQueue(long capacity)
{
    cout<<"OptimizedQueue Initialized"<<endl<<endl;
    OptimizedQueue :: capacity=capacity;

    //in the begining both are at same point
    frontPointer=0;
    rearPointer=0;
}

void OptimizedQueue :: enqueue(long value)
{
    cout<<"Enquing"<<endl<<endl;
    if(!isFull()) //if OptimizedQueue is full, we can't insert more elements
    {
        row[rearPointer]= value;
        rearPointer++; //move rearpointer one step ahead, the OptimizedQueue in expanding from back, frontptr is not distrubed
    }
    else
    {
        cout<<"The OptimizedQueue full, please delete an element before inserting more"<<endl<<endl;
    }

}

void OptimizedQueue :: dequeue()
{
    cout<<"Dequing"<<endl<<endl;
    if(!isEmpty())  //if OptimizedQueue is empty, we can't dequeue
    {
        frontPointer++;
    }
    else
    {

        // if front pointer and rear pointer are at same point, is same as below condition, plus below condition is better, bc it restart these pointers
        frontPointer=0;
        rearPointer=0;

        cout<<"OptimizedQueue is already empty, please insert some element before removing"<<endl<<endl;
    }
}


long OptimizedQueue :: isFull()
{
    return rearPointer==capacity; //because rearPointer is always one step ahead of last element index
}

long OptimizedQueue :: isEmpty()
{
    return rearPointer==frontPointer; //obviously if both rear and front are at same point, the OptimizedQueue is empty
}

long OptimizedQueue :: peak()
{
    cout<<"The peak is "<<endl<<endl;
    return isEmpty()? -1 : row[frontPointer];   //if OptimizedQueue is empty return -1, else return the peak element peak
}

void OptimizedQueue :: showOptimizedQueue()
{
    if(isEmpty())
    {
        cout<<"OptimizedQueue is empty now"<<endl<<endl;
        return;
    }

    long i;


    //from frontptr to rear ptr, all other values in the OptimizedQueue would be garbage since its a OptimizedQueue
    for(i=frontPointer;i<rearPointer;i++)
    {
        cout<<row[i]<<" ";
    }
    cout<<endl<<endl;
}






class CircularQueue
{
private:
    long capacity, frontPointer, rearPointer, totalElements;  //in addition to old type of queues , we have the property totalElements to count the number of elements
    long row[500];

public:
    void initializeCircularQueue(long);
    void enqueue(long);
    void dequeue();
    long isFull();
    long isEmpty();
    long peak();
    void showCircularQueue();
};

void CircularQueue :: initializeCircularQueue(long capacity)
{
    cout<<"CircularQueue Initialized"<<endl;
    CircularQueue :: capacity=capacity;

    //in the begining both are at same point
    frontPointer=0;
    rearPointer=0;
    totalElements=0; //at present we have 0 elements
}

void CircularQueue :: enqueue(long value)
{
    cout<<"Enquing"<<endl;
    if(!isFull()) //if CircularQueue is full, we can't insert more elements, however, in CircularQueue the condition is different
    {
        row[rearPointer]= value; //put the value at the rearPointer index
        rearPointer= (++rearPointer)%capacity; //move rearpointer one step ahead, the CircularQueue in expanding from back, frontptr is not distrubed
        totalElements++; //each enque increases the number of elements
    }
    else
    {
        cout<<"The CircularQueue full, please delete an element before inserting more"<<endl;
    }

}

void CircularQueue :: dequeue()
{
    cout<<"Dequing"<<endl;
    if(!isEmpty())  //if CircularQueue is empty, we can't dequeue
    {
        frontPointer= (++frontPointer)%capacity; //we move frontPointer one step ahead, the ignored space is consided blank
        totalElements--; //each deque decreases the number of elements

        if(frontPointer==rearPointer) //if after dequeing , the frontPointer meets rearPointer, that clearly means that the CircularQueue is empty
        {
            frontPointer=rearPointer=0;   //in that case we put both the pointers at 0
        }
    }
    else
    {
        cout<<"OptimizedQueue is already empty, please insert some element before removing"<<endl;
    }
}


long CircularQueue :: isFull()
{
    return rearPointer==frontPointer && totalElements==capacity;

}

long CircularQueue :: isEmpty()
{
    return rearPointer==frontPointer && totalElements==0;
}

long CircularQueue :: peak()
{
    cout<<"The peak is "<<endl;
    return isEmpty()? -1 : row[frontPointer];   //if OptimizedQueue is empty return -1, else return the peak element peak
}

void CircularQueue :: showCircularQueue()
{
    if(isEmpty())
    {
        cout<<"CircularQueue is empty now"<<endl;
        return;
    }

    //from frontptr to rear ptr, all other values in the OptimizedQueue would be garbage since its a OptimizedQueue
    long elementsPrinted=0,i=frontPointer;
    while(elementsPrinted!=totalElements)
    {
        cout<<row[i]<<" ";
        elementsPrinted++;
        i=(++i)%capacity;
    }

    cout<<endl<<endl;
}




int main()
{

    //Operations on Optimized Queue
    OptimizedQueue queueOne;
    queueOne.initializeOptimizedQueue(5);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(1);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(7);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(6);
    queueOne.showOptimizedQueue();

    cout<<queueOne.peak()<<endl;

    queueOne.enqueue(8);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(17);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(22);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(3);
    queueOne.showOptimizedQueue();


    queueOne.dequeue();
    queueOne.showOptimizedQueue();
    queueOne.dequeue();
    queueOne.showOptimizedQueue();
    queueOne.dequeue();
    queueOne.showOptimizedQueue();
    queueOne.dequeue();
    queueOne.showOptimizedQueue();
    queueOne.dequeue();
    queueOne.showOptimizedQueue();
    queueOne.dequeue();
    queueOne.showOptimizedQueue();

    queueOne.enqueue(22);
    queueOne.showOptimizedQueue();
    queueOne.enqueue(3);
    queueOne.showOptimizedQueue();


    //Operations on PrimitiveQueue
    PrimitiveQueue queueTwo;
    queueTwo.initializePrimitiveQueue(5);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(1);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(7);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(6);
    queueTwo.showPrimitiveQueue();

    cout<<queueTwo.peak()<<endl;

    queueTwo.enqueue(8);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(17);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(22);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(3);
    queueTwo.showPrimitiveQueue();


    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();
    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();
    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();
    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();
    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();
    queueTwo.dequeue();
    queueTwo.showPrimitiveQueue();

    queueTwo.enqueue(22);
    queueTwo.showPrimitiveQueue();
    queueTwo.enqueue(3);
    queueTwo.showPrimitiveQueue();



     //Operations on Circular Queue
    CircularQueue queueThree;
    queueThree.initializeCircularQueue(5);
    queueThree.showCircularQueue();
    queueThree.enqueue(1);
    queueThree.showCircularQueue();
    queueThree.enqueue(7);
    queueThree.showCircularQueue();
    queueThree.enqueue(6);
    queueThree.showCircularQueue();

    cout<<queueThree.peak()<<endl;

    queueThree.enqueue(8);
    queueThree.showCircularQueue();
    queueThree.enqueue(17);
    queueThree.showCircularQueue();
    queueThree.enqueue(22);
    queueThree.showCircularQueue();
    queueThree.enqueue(3);
    queueThree.showCircularQueue();

    queueThree.dequeue();
    queueThree.showCircularQueue();

    queueThree.enqueue(22);
    queueThree.showCircularQueue();
    queueThree.enqueue(3);
    queueThree.showCircularQueue();

    queueThree.dequeue();
    queueThree.showCircularQueue();
    queueThree.dequeue();
    queueThree.showCircularQueue();
    queueThree.dequeue();
    queueThree.showCircularQueue();
    queueThree.dequeue();
    queueThree.showCircularQueue();
    queueThree.dequeue();
    queueThree.showCircularQueue();

    queueThree.enqueue(22);
    queueThree.showCircularQueue();
    queueThree.enqueue(3);
    queueThree.showCircularQueue();

    return 0;
}
