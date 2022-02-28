//Read the recursive solution to understand the memoized solution, here we just saved the value whenever required


#include<bits/stdc++.h>
using namespace std;

long findMaxProfit(long, long[], long[]);
long countOfCalls;

int main()
{
    long n=8;

    long prices[n+1] = {0, 3, 5, 8, 9, 10, 17, 17, 20};

    long memoization[n+1]={0}; //an array to store the result for n for the function findMaxProfit(n)

    cout<<findMaxProfit(n, prices,memoization)<<endl;
	
    cout<<"The function was called "<<countOfCalls<<" times"<<endl;


    return 0;

}

long findMaxProfit(long n, long prices[], long memoization[])
{
    countOfCalls++;

    if(memoization[n]!=0) //if value is available , just return it
    {
        return memoization[n];
    }

    if(n==1) //if value is 1, we can't divide it further, hence, if its first time, store the result and return it
    {
        memoization[1]=prices[1];
        return prices[1];
    }
    else
    {
        long i,partOne,partTwo;

        long maxValue = prices[n]; //if we had taken it full
        for(i=1;i<=n/2;i++)
        {
            partOne=i;
            partTwo=n-i;

            long returnedResult = findMaxProfit(partOne,prices,memoization)+findMaxProfit(partTwo,prices, memoization);

            if(returnedResult>maxValue)
            {
                maxValue =returnedResult;
            }

        }
		//all same as recursive approach
        memoization[n]=maxValue; //we just save the value before returning
        return maxValue;
    }


}

