//He we will talk about memoization of recursive solution of longest common substring
//for understanding the recursive approach, read preivous solutions

#include<bits/stdc++.h>
using namespace std;

long maxSoFar =0;

long findLengthOfLCS(long [][100],string, string, long, long);
void fillTable(long [][100], long , long , long);

int main()
{
    string firstInput = "xyabcm";
    string secondInput = "cdabcn";

    long firstIndex = firstInput.length()-1;
    long secondIndex = secondInput.length()-1;

    long memoization[100][100];
    //since the memoization can contain values from 0 to infinity we must fill it with -1 so show uncomputed cells

    fillTable(memoization, 100, 100, -1);

    findLengthOfLCS(memoization, firstInput, secondInput, firstIndex, secondIndex);

    cout<<maxSoFar<<endl;


    return 0;
}

//We have got 5 inputs for the function
//memoization: its just for storing result
//firstInput, secondInput : both are static
//firstIndex and secondIndex : only these two values are chaning in the function
//so we will build the table based on these two and store the returning values for these parameters


long findLengthOfLCS(long memoization[][100], string firstInput, string secondInput, long firstIndex, long secondIndex)
{
    if(memoization[firstIndex][secondIndex]!=-1) //if its already computed, return the computed value
    {
        return memoization[firstIndex][secondIndex];
    }

    if(firstIndex == -1 || secondIndex == -1)
    {
        return 0;
    }

    if(firstInput[firstIndex]!=secondInput[secondIndex])
    {
        findLengthOfLCS(memoization, firstInput, secondInput, firstIndex-1, secondIndex);
        findLengthOfLCS(memoization, firstInput, secondInput, firstIndex, secondIndex-1);

        memoization[firstIndex][secondIndex]=0; //storing before returning
        return 0;
    }
    else
    {
        long bottomPlusOne = findLengthOfLCS(memoization, firstInput, secondInput, firstIndex-1, secondIndex-1)+1;

        if(bottomPlusOne>maxSoFar)
        {
            maxSoFar = bottomPlusOne;
        }

        memoization[firstIndex][secondIndex]=bottomPlusOne; //storing before returning

        return bottomPlusOne;
    }


}


void fillTable(long memoization[][100], long rows, long coloumns, long value)
{
    long i, j;

    for(i=0;i<rows; i++)
    {
        for(j=0;j<coloumns;j++)
        {
            memoization[i][j]=value;
        }
    }
}
