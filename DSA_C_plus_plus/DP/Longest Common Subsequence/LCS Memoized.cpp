#include<bits/stdc++.h>
using namespace std;

long LCS(string, string, long , long, long);

long memoization[100][100];

int main()
{
    for(long i=0;i<100;i++)
    {
        for(long j=0;j<100;j++)
        {
            memoization[i][j]= -1;
        }
    }


    cout<<LCS("XMJYAUZ", "MZJAWXU", 6,6,0);
    return 0;
}

long LCS(string firstInput, string secondInput, long firstIndex, long secondIndex, long callNumber)
{
    if(memoization[firstIndex][secondIndex]!=-1)
    {
        return memoization[firstIndex][secondIndex];
    }

    callNumber++;
    if(firstIndex<0 || secondIndex<0)
    {
        return 0;
    }

    if(firstInput[firstIndex]==secondInput[secondIndex])
    {
        memoization[firstIndex][secondIndex]= LCS(firstInput, secondInput, firstIndex-1, secondIndex-1, callNumber)+1;

        return memoization[firstIndex][secondIndex];
    }
    else
    {
         memoization[firstIndex][secondIndex]= max(LCS(firstInput, secondInput, firstIndex, secondIndex-1, callNumber), LCS(firstInput, secondInput, firstIndex-1, secondIndex, callNumber));

        return memoization[firstIndex][secondIndex];
    }
}
