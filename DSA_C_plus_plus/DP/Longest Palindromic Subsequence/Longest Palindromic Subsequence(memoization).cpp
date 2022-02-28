//recursive solution

//lPSL = Longest Palindromic Subsequence Length

#include<bits/stdc++.h>
using namespace std;


long memoization[1000][1000];  //a 2d array to store the result

long lPSL(string , long , long); //prototype


int main()
{
    string input;
    cin>>input;



    long i, j;

    for(i=0;i<input.length();i++)
    {
        for(j=0;j<input.length();j++)
        {
            memoization[i][j]=-1;
        }
    }

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            cout<<memoization[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<lPSL(input, 0, input.length()-1);
    return 0;
}


long lPSL(string input, long starti, long endi)
{
    if(memoization[starti][endi]!=-1) //if result is already computed , then simply return it, else go down
    {
        return memoization[starti][endi];
    }

    long toReturn;

    if(starti>endi)  //empty string, because of starti+1, endi-1,  (1,2) will change into (2,1)
    {

        toReturn= 0;
    }
    else if(starti==endi)  //there is only one character
    {
        toReturn=1;
    }
    else if(input[starti]==input[endi]) //if end and starting characteres are same, we find the lPSL of removing these both and adding 2 to them, since we already got 2 characters
    {
        toReturn = lPSL(input, starti+1, endi-1)+2;
    }
    else
    {
        toReturn =  max(lPSL(input,starti, endi-1), lPSL(input, starti+1, endi));  //since we need the longest, so we take max of both the parts
    }

    memoization[starti][endi]=toReturn; //saving the result before returnign

    return memoization[starti][endi]; //reutrning the saved result
}
