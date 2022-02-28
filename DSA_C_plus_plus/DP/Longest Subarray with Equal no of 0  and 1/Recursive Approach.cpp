//idea:
//The basic idea here is first we check if the original array is already balanced or not, if its balanced, then its the longest subarray
//if its not, we first remove the leftmost element(starti+1, endi), in other instance, we remove the rightmost element(starti, endi-1)
//then we see which one is the greatest

//also when we exclude the rightmost or leftmost element, we don't recompute the variable balance again,
// we simple ++ it if it was 1(since it denotes -1) and -- it if it was 0(since it denotes +1)

#include<bits/stdc++.h>
using namespace std;

long findLongestLength(long [], long, long, long, long, long);

int main()
{
    //the array on which we have to work
    long input[10]={1, 1, 1, 1, 0, 1, 0, 1, 1, 1};

    long n=10; //no of elements

    //starti : starting index of the array
    //endi : ending index of the array
    //balance : + for 0 and - for 1, the variable denotes the balance i.e for 0, 1, 1, it is -1
    //isComputed : if the value balance is computed or not
    long starti=0, endi=9, balance=0 , isComputed=0;

    cout<<findLongestLength(input, n, starti, endi, balance, isComputed);
    return 0;
}

long findLongestLength(long input[], long n, long starti, long endi, long balance, long isComputed)
{

    //if there is only one element, so it won't have balance value 0, hence we can't form a balanced array
    //hence we return 0;
    if(starti==endi)//base case
    {
        return 0;
    }

    //if balance is not computed, we compute it
    //it runs only once, for the first call
    if(!isComputed)
    {
        long i=0;

        for(i=0;i<n;i++)
        {
            if(input[i]==0)
            {
                balance++;
            }
            else
            {
                balance--;
            }
        }

        //so that the value is not computed again, since we can derive the balance values for funtion call to come
        isComputed=1;
    }


    //if the original array is already balanced, we don't need to go further
    if(balance==0)
    {

        //the length without excluding
        long withoutExcluding = endi - starti +1;

        return withoutExcluding; //there is no point in going down
    }
    else
    {
        //if balance is not 0, we first exclude the rightmost and then leftmost element
        long excludingRight=0, excludingLeft=0;

        //if element to be removed is 0, we will decrease the value of balance
        if(input[endi]==0)
        {
            excludingRight = findLongestLength(input, n, starti, endi-1, balance-1, isComputed);
        }
        else//if element to be removed is 1, we will increase the value of balance
        {
            excludingRight = findLongestLength(input, n, starti, endi-1, balance+1, isComputed);
        }

        //if element to be removed is 1, we will decrease the value of balance
        if(input[endi]==1)
        {
            excludingLeft = findLongestLength(input, n, starti+1, endi, balance-1, isComputed);
        }
        else //if element to be removed is 0, we will increase the value
        {
            excludingLeft = findLongestLength(input, n, starti+1, endi, balance+1, isComputed);
        }

        //we return the max of both the ways, by excluding right and by excluding left
        return max(excludingLeft, excludingRight);
    }

}
