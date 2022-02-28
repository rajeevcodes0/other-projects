//Idea:


//Either the current element will be added to the current increasing subsequence or a new incresasing subsequence will
//start from here

//We can add the current element to the current increasing subsequence, only if its greater than the max of the subsequence
//Now two cases arise
//i) if the current element is greater than current max of subsequence, we can either include it, or we don't
//ii)if its less than current max, then we definetly don't include it


#include<bits/stdc++.h>
using namespace std;

long maxLength=0;

long lengthOfLIS(long [], long, long, long, long);

int main()
{
    long input[]={50,3,10,7,40,80};

    long n= sizeof(input)/sizeof(long);
    long currentIndex=0, currentLength=0, currentMax=-1;

    cout<<lengthOfLIS(input, n, currentIndex, currentLength, currentMax);

    return 0;
}

long lengthOfLIS(long input[], long n, long currentIndex, long currentLength, long currentMax)
{

    //if the currentIndex goes out of the array, we simply return the length, since we can't go further
    if(currentIndex==n)
    {
        return currentLength;
    }

    //the maximum length obtained, one by including and the other by not including
    long included=0, notIncluded=0;

    //we can include the current element only when its greater than the currentMax
    if(input[currentIndex]>currentMax)
    {
        //if we include, then the current element will be maximum of the subsequence, and it increases the length by 1
        included = lengthOfLIS(input, n, currentIndex+1, currentLength+1, input[currentIndex]);
    }

    //even if the element is greater than currentMax of the subsequence, we necessarily need not to include it in the subsequence
    notIncluded = lengthOfLIS(input, n, currentIndex+1, currentLength, currentMax);

    //we return the maximum of both the values, by including and by not including
    return max(included, notIncluded);

}
