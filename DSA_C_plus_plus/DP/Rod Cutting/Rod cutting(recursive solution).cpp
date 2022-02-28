//it must be noted that we can make the cut of same length as many times as we want
//hence, if we have length 5, and we make a cut of 1, we get (4,1) , then we can again make a cut of 1, making it (3,1,1)
//this idea is important for the bottom up DP approach

#include<bits/stdc++.h>
using namespace std;

long findMaxProfit(long, long[]); //finds the maximum profit for a rod of length n
long countOfCalls; //counts the total no. of function calls made, for the sake of comparison

int main()
{
    long n=8;

    long prices[n+1] = {0, 3, 5, 8, 9, 10, 17, 17, 20}; //since prices start with 1, we took size as n+1

    cout<<findMaxProfit(n, prices)<<endl;
	
    cout<<"The function was called "<<countOfCalls<<" times"<<endl;

    return 0;

}

long findMaxProfit(long n, long prices[])
{
    countOfCalls++;
	
    if(n==1) //if length is 1, we can't divide it further, hence we simply return the price
    {
        return prices[1];
    }
    else
    {
        long i,partOne,partTwo;  //we divide the current rod into two parts, and find the optimal value for each part and sum them up, these two parts can be further divided

        long maxValue = prices[n]; //if we did not make any cut, doing i=0 caused infinite loop in the below for loop
		
        for(i=1;i<=n/2;i++) //since for 3,5 and 5,3 we do the same computation, since we only did it till n/2, holds good for both odd as well as even
        {
            partOne=i; //part one is i, ie, 1,2,3 ..
            partTwo=n-i; //part two is n-1, i.e, 7,6,5....
 
            long returnedResult = findMaxProfit(partOne,prices)+findMaxProfit(partTwo,prices); //we find the optimal solution for both the parts saparately and sum them up

            if(returnedResult>maxValue) //if this returned value is greater the the values found so far, this includes making no cut too, we update the maximum value
            {
                maxValue =returnedResult;
            }

        }
        return maxValue; //we finally return the value for the value of n
    }


}
