//Here we will discuss about the memoization approach of the problem
//for any other idea discussed here, please look in the previous approaches for the same problem


#include<bits/stdc++.h>
using namespace std;

long findLIS(long [6][7], long [], long, long, long, long);


int main()
{
    long input[]={5,1,3,2,4,6};

    //since there won't be any value as 0, we can use 0 as uncomputed cell
    long memoization[6][7]={0}; //there are 6 items and the maximum value is 80;

    long n = sizeof(input)/sizeof(long);

    long currentIndex=0, currentMax=0, currentLength=0;

    cout<<findLIS(memoization, input, n, currentIndex, currentMax , currentLength);

    return 0;
}

//Here we have five parameters, out of which only 3 are changing
//we can use all these three to uniquely identiy a subproblem,
//however we can also use only two of these  ,those are currentIndex and currentMax to uniquely identiy the subproblem

//my intution tells me that currentIndex will be a parameter for sure
//my intution also tells me that there are only two parameters at most for such standard problems
//if we are at index i, there can we two or more subsequences of length y(say 3), hence currentLength is not a right measure to
//indetify a subproblem

long findLIS(long memoization[6][7], long input[], long n, long currentIndex, long currentMax, long currentLength)
{


    //we don't have to memoize this result since its out of the array, also it does no further computation
    if(currentIndex==n)
    {
        return currentLength;
    }

    //if its already computed, return the stored result;
    if(memoization[currentIndex][currentMax]!=0)
    {
        return memoization[currentIndex][currentMax];
    }


    long included=0, notIncluded=0;

    if(input[currentIndex]>currentMax)
    {
        included = findLIS(memoization, input, n, currentIndex+1, input[currentIndex], currentLength+1);
    }

    notIncluded = findLIS(memoization, input, n, currentIndex+1, currentMax, currentLength);

    //saving it before returning , a general practice
    memoization[currentIndex][currentMax] = max(included, notIncluded);
    return max(included, notIncluded);
}
