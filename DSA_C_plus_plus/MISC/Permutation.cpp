#include<bits/stdc++.h>
using namespace std;

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

void copyArray(long arrayOne[], long arrayTwo[], long length)
{
    long i;

    for(i=0;i<length;i++)
    {
        arrayTwo[i]=arrayOne[i];
    }
}

void permute(long input[], long length, long level)
{

    if(level==length)
    {
        printArray(input, length);
        return;
    }
    long i;
    for(i=level;i<length;i++)
    {
        long inputCopy[length];

        copyArray(input, inputCopy, length);

        swap(inputCopy[level], input[i]);

        permute(inputCopy, length, level+1);
    }
}

int main()
{
    long input[3]={1,2,3};

    permute(input, 3, 0);

    return 0;
}
