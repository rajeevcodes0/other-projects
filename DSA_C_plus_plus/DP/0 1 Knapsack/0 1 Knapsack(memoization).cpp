//to memoize we must understand what parameters do we choose over which we will memoize
//we must understand that the 'value' will be different for some 'remaining weight x' with two other
//values of the 'currentItem' , since both represent different opportunities

#include<bits/stdc++.h>
using namespace std;


long findMaxProfit(long , long , long , long [], long [], long [7][11], long);

int main()
{

    long values[6]={20, 5, 10, 40, 15, 25};

    long weights[6] = {1, 2, 3, 8, 7, 4};

    long totalWeight=10;

    long memoization[7][11/*total weight*/]={0}; //extra one because of zero indexing


    cout<<findMaxProfit(totalWeight, 0, 0, values, weights, memoization, 6);
    return 0;
}

long findMaxProfit(long remainingWeight, long currentValue, long currentItem, long values[], long weights[], long memoization[7][11], long totalItems)
{
    if(currentItem>=totalItems)
    {
        return currentValue; //we won't memoize this value since its out of the table
    }

    if(memoization[currentItem][remainingWeight]!=0)
    {
        return memoization[currentItem][remainingWeight];
    }

    long ifIncluded=0, ifNotIncluded=0;

    if(remainingWeight>=weights[currentItem])
    {
        ifIncluded=findMaxProfit(remainingWeight - weights[currentItem], currentValue+values[currentItem], currentItem+1, values, weights, memoization, totalItems);
    }

    ifNotIncluded = findMaxProfit(remainingWeight, currentValue, currentItem+1, values, weights, memoization,  totalItems);


    long toReturn = max(ifIncluded, ifNotIncluded);

    memoization[currentItem][remainingWeight] = toReturn; //we memoize this values because this is what exactly returned from a fuction, it also sets on our chosen parameters

    return toReturn;
}
