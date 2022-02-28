//the main idea of recursive approach is wether we take the element or we dont, in one function we take it, in other we don't

#include<iostream>
using namespace std;

long findMaxProfit(long, long, long, long [], long [], long);

int main()
{

    long weights[]={1,2,3,8,7,4};

    long values[]={20,5,10,40,15,25};

    long totalWeight =10;

    cout<<findMaxProfit(totalWeight, 0,0, weights, values,6,0);

    return 0;
}

long findMaxProfit(long remainingWeight, long currentValue, long currentItem, long weights[], long values[], long totalItems)
{


    if(currentItem>=totalItems)
    {
        return currentValue;
    }

    long ifIncluded=0, ifNotIncluded=0;

    if(remainingWeight>=weights[currentItem])
    {

        ifIncluded = findMaxProfit(remainingWeight-weights[currentItem], currentValue+values[currentItem], currentItem+1, weights, values,totalItems,callNo);
    }

    ifNotIncluded = findMaxProfit(remainingWeight, currentValue, currentItem+1, weights, values, totalItems, callNo);

    return max(ifIncluded, ifNotIncluded); //we return the max of the both options, since we need the optimum value

}
