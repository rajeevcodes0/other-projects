//Idea:
//In this problem we create subproblems using suffix/prefix method

#include<bits/stdc++.h>
using namespace std;

long findMaxSumSubarray(long [], long, long, long, long);

int main()
{
    //The original array
    long input[5]={2,-9, 5, -4, 10};

    //n is the no of elements
    //sum is the total sum of the original array, the next time we compute the sum of subarray, we don't compute all
    //we simply subtract the leaving exlement from the sun
    //starti is the start index of the subarray
    //endi is the end index of the subarray
    long n=5, sum=0, starti =0, endi = 4;


    //taking sum of the whole array
    for(long i=0;i<n;i++)
    {
        sum += input[i];
    }


    cout<<findMaxSumSubarray(input, n, starti, endi, sum);


    return 0;
}

long findMaxSumSubarray(long input[], long n, long starti, long endi, long sum)
{
    //if there is only one element there is no need to go further, the sum of that array is returned
    if(starti==endi)
    {
        return input[starti];
    }
    else
    {
        //we take sum withoutExcluding any element, excluding the rightmost element and then leftmost element
        //and return the maximum of all

        long withoutExcluding=-1*INT_MAX, rightExcluding=-1*INT_MAX, leftExcluding=-1*INT_MIN;

        withoutExcluding = sum;

        //we subtract the element which we are removing
        rightExcluding=findMaxSumSubarray(input, n, starti, endi-1, sum-input[endi]);

        leftExcluding=findMaxSumSubarray(input, n, starti+1, endi, sum-input[starti]);

        return max(max(withoutExcluding, rightExcluding),leftExcluding);
    }
}
