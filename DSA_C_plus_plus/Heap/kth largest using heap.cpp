#include<iostream>
using namespace std;

void maxHeapify(long [], long, long);
long extractMax(long [], long*);
void printArray(long [], long);

int main()
{
    long input[50];
    long n, i, position, answer, heapSize;

    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements of the array"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>input[i];
    }
    heapSize=n;

    for(i=heapSize/2;i>-1;i--)
    {
        maxHeapify(input,i,heapSize);
    }

    printArray(input,n);
    cout<<"Enter the position of element required, i.e, 5th largest, for that enter 5"<<endl;
    cin>>position;

    for(i=0;i<position;i++)
    {
        answer=extractMax(input, &heapSize);
    }


    cout<<answer<<endl;

}

void maxHeapify(long input[], long currentIndex, long heapSize)
{
    long leftChild, rightChild;
    long greatestIndex;


    if(currentIndex*2+1<=heapSize-1)
    {
        leftChild=currentIndex*2+1;
    }
    else
    {
        leftChild=-1;
    }

    if(currentIndex*2+2<=heapSize-1)
    {
        rightChild=currentIndex*2+2;
    }
    else
    {
        rightChild=-1;
    }

    if(leftChild==-1 && rightChild==-1)
    {
        return;
    }

    if(leftChild!=-1 && input[leftChild] > input[currentIndex])
    {
        greatestIndex=leftChild;
    }
    else
    {
        greatestIndex=currentIndex;
    }

    if(rightChild!=-1 && input[rightChild] > input[greatestIndex])
    {
        greatestIndex=rightChild;
    }

    if(greatestIndex!=currentIndex)
    {
        swap(input[greatestIndex],input[currentIndex]);
        maxHeapify(input, greatestIndex, heapSize);
    }
}


long extractMax(long input[], long *heapSize)
{
    long toReturn = input[0];

    swap(input[0],input[(*heapSize)-1]);
    (*heapSize)--;

    maxHeapify(input,0 , *heapSize);

    return toReturn;
}

void printArray(long input[], long length)
{
    long i;

    for(i=0;i<length;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
