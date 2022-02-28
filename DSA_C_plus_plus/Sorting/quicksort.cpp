//nlog(n) in best case because , the best partition would be in half, doing so the height of tree formed will be minimum , that is log(n)
//also at each level of tree we are doing n operation, so nlog(n) is the total cost.


#include<iostream>
using namespace std;

void quickSort(long [], long, long);
long partitionFunction(long [], long , long);
void printArray(long [], long);
int main()
{
   long input[7]={7,3,8,1,5,0,8};

    quickSort(input,0,6);
    printArray(input,7);
    return 0;

}
void quickSort(long input[], long startIndex, long endIndex)
{
    if(startIndex>=endIndex)
    {
        return;
    }
    else
    {
        long partitionPoint = partitionFunction(input,startIndex,endIndex);

        quickSort(input,startIndex,partitionPoint-1);
        quickSort(input,partitionPoint+1, endIndex);
    }
}

long partitionFunction(long input[], long startIndex, long endIndex)
{
    long pivotValue = input[endIndex];

    long wall=startIndex;

    for(long i=startIndex;i<endIndex;i++)
    {
        if(input[i]<pivotValue)
        {
            swap(input[wall],input[i]);
            wall++;
        }
    }
    swap(input[wall],input[endIndex]);
    return wall;
}

void printArray(long input[], long length)
{
    long i;
    cout<<endl;
    for(i=0;i<length;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
