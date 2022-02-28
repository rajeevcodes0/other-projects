#include<iostream>
using namespace std;

//function prototypes
void insertElement(long, long []);  //for inserting an element in the heap
void deleteElement(long [], long*); //for deleting an element from the heap
void arrangeAfterDeletion(long [], long, long*); //for managing the heap property that gets disturbed by deleting the root
void heapify(long [], long, long); //heapify method, its max heapify in this case
void printArray(long[],long); //for printing an array

int main()
{
    long input[5]={10,20,15,30,40};  //hardcoded input
    long sizeOfArray=sizeof(input)/sizeof(long); //calculating the size of the size of the array
    long heapSize=sizeOfArray;
    long i,choice;

    cout<<"Which method for creating heap?"<<endl;
    cout<<"1 for Heapify \n2 for Build Heap"<<endl;
    cin>>choice;

    if(choice==1)
    {
        for(i=heapSize/2;i>-1;i--)
        {
             heapify(input,i,heapSize);
        }
        cout<<"After Heapify"<<endl;
        printArray(input,sizeOfArray);
    }
    else if(choice==2)
    {
        for(i=0;i<sizeOfArray;i++)
        {
            insertElement(i, input);
        }
        cout<<"Heap Created"<<endl;
        printArray(input, sizeOfArray);
    }

    for(i=0;i<sizeOfArray;i++)
    {
        deleteElement(input, &heapSize);
    }
    cout<<"After Heap Sort"<<endl;
    printArray(input, sizeOfArray);
}

void insertElement(long i, long input[])
{
   if(i==0)
   {
       return;
   }
   else
   {
       if(input[(i-1)/2]<input[i])
       {
           swap(input[(i-1)/2],input[i]);
           insertElement((i-1)/2, input);
       }
   }
}


void deleteElement(long input[],long *heapSize)
{
    swap(input[0],input[*heapSize-1]);

    (*heapSize)--;
    long currentIndex=0;

    arrangeAfterDeletion(input, currentIndex, heapSize);

}

void arrangeAfterDeletion(long input[], long currentIndex, long *heapSize)
{
    long leftChild, rightChild;
    if(currentIndex*2+1<=*heapSize-1)
    {
        leftChild=input[currentIndex*2+1];
    }
    else
    {
        leftChild=-1;
    }

    if(currentIndex*2+2<=*heapSize-1)
    {
        rightChild=input[currentIndex*2+2];
    }
    else
    {
        rightChild=-1;
    }

    if(leftChild==-1 && rightChild==-1)
    {
        return;
    }
    else
    {
        long larger;
        if(leftChild>input[currentIndex])
        {
            larger=currentIndex*2+1;
        }
        else
        {
            larger=currentIndex;
        }

        if(rightChild>input[larger])
        {
            larger=currentIndex*2+2;
        }
        if(larger!=currentIndex)
        {
            swap(input[currentIndex],input[larger]);
            arrangeAfterDeletion(input, larger,heapSize);
        }
    }
}

void printArray(long input[],long sizeOfArray)
{
    long i;
    for(i=0;i<sizeOfArray;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}

void heapify(long input[],long i, long heapSize)
{
    long leftChild, rightChild;

    if(i*2+1<=heapSize-1)
    {
        leftChild=i*2+1;
    }
    else
    {
        leftChild=-1;
    }

    if(i*2+2<=heapSize-1)
    {
        rightChild=i*2+2;
    }
    else
    {
        rightChild=-1;
    }


    long largest;

    if(input[leftChild]>input[i])
    {
        largest=leftChild;
    }
    else
    {
        largest=i;
    }

    if(input[rightChild]>input[largest])
    {
        largest=rightChild;
    }

    if(largest!=i)
    {
        swap(input[largest],input[i]);
        heapify(input,largest,heapSize);
    }
}

