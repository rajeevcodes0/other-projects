//Question : find the maximum XOR of a subarray of size k
//idea
//we have to find the XOR of (0,K), (1,K+1), (2,K+2) and so on
//we can note that, we can obtain (1,K+1) from (0,K) be removing input[0] and adding input[k+1]
//and important XOR inverse property is b^a^a = b


#include<bits/stdc++.h>
using namespace std;


long findMax(long [], long, long);

int main()
{
    long n,k; // n is size of the original array, k is the maximum size of the subarray

    cin>>n>>k;

    long input[n];

    long i;

    for(i=0;i<n;i++)
    {
        cin>>input[i];
    }

    cout<<findMax(input, n, k)<<endl;


    return 0;
}

long findMax(long input[], long n, long k)
{
    long i;

    long base=0; //we consider the XOR of subarray form 0 to k-1 be base, since all can be derived form this

    long maximum=0; //the maximum value obtained so far

    for(i=0;i<k;i++) //creating base
    {
        base=base^input[i];
    }

    maximum = base;

    for(i=k;i<n;i++)
    {
        base=base^input[i-k]; //remove the first item
        base=base^input[i]; //add a new item
        if(base>maximum) //see if newly generated subarray has greater value than max itself
        {
            maximum=base;
        }
    }

    return maximum; //return the result

}
