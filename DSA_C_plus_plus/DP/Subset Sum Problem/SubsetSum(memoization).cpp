//here we will discuss only the memoization approach, to understand the basic approach of this program
//check out the comments in recusive solution

//there are five parameters in the subsetSum() function out of which:
//input: can't be taken as a parameter for the memoization, its static and doesn't change
//totalSum : can be taken, this is changing
//targetSum : can't be taken, this is static
//currentIndex : can be taken , this is changing
//totalItems : can't be taken, its static

//hence we build a table of two parameters, totalSum and currentIndex

//Now talking about range
//The  totalSum can range upto the total sum of all the elements
//the currentIndex ranges from 0 to n-1


//Note, since both true and false are the possible values of the function, we can't have a bool type memoization , because
//we can't represent uncomputed cells
//here 1 means true, 2 means false, and 0 means uncomputed

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(long [5][100], long [], long , long, long, long);

int main()
{
    long input[5]={7,3,2,5,8};

    long memoization[5][100]={0}; //in the start all values are uncomputed

    cout<<subsetSum(memoization, input, 0, 14, 0, 5); //here 14 is the target sum

    return 0;
}

bool subsetSum(long memoization[5][100], long input[], long totalSum , long targetSum, long currentIndex, long totalItems)
{
    if(currentIndex==totalItems) //we don't have to memoize this since this out of the bound of our table, currentIndex is greater than 4
    {
        return false;
    }

    if(totalSum == targetSum)
    {
        memoization[currentIndex][totalSum]=1; //just saving the result before returning, otherwise it would be lost
        return true;
    }
    else
    {
        bool taken = subsetSum(memoization, input, totalSum + input[currentIndex], targetSum, currentIndex+1, totalItems);

        bool notTaken = subsetSum(memoization, input, totalSum, targetSum, currentIndex+1, totalItems);

        bool toReturn = taken||notTaken;

        if(toReturn) //if toReturn is true
        {
            memoization[currentIndex][totalSum]=1;
        }
        else
        {
            memoization[currentIndex][totalSum]=2;
        }



        return toReturn;
    }
}
