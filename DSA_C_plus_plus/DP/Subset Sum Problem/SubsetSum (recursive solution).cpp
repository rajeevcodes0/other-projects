#include<bits/stdc++.h>
using namespace std;

bool subsetSum(long [], long, long,long,long);

int main()
{
    long input[5]={7,3,2,5,8};

    cout<<subsetSum(input, 0, 55, 0, 5);

    return 0;
}

//The parameters for the funtion are as follows
//input[] : contains all the items, its a must, since we need to sum up the elements once we include them
//totalSum : contains the totalSum calculated till now, build the recursion tree for this problem to understand this
//currentIndex : the currentItem in consideration, only then we can decide wether we have to take it or not
//totalItems : The total number of items, need for base case

bool subsetSum(long input[], long totalSum, long targetSum,long currentIndex  ,long totalItems)
{
    if(currentIndex==totalItems) //if currentIndex gets out of the array, that means we haven't found the required sum, and also we don't have remaining elements, hence we return false
    {
        return false;
    }

    if(totalSum==targetSum) //if we have reached our targetSum, there is no need to go further
    {
        return true;
    }
    else
    {
        bool taken = subsetSum(input, totalSum+input[currentIndex], targetSum, currentIndex+1, n); //if we take the element
        bool notTaken = subsetSum(input, totalSum, targetSum, currentIndex+1, n); // if we don't take the element

        return taken || notTaken; //even if one part of the tree says 'we got the sum' , then it means we got the sum, no matter what the other part says
    }
}
