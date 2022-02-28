//recursive solution

//lPSL = Longest Palindromic Subsequence Length

#include<iostream>
using namespace std;

long lPSL(string , long , long);

int main()
{
    string input;
    cin>>input;
    cout<<lPSL(input, 0, input.length()-1);
    return 0;
}


long lPSL(string input, long starti, long endi)
{
    if(starti>endi)  //empty string, because of starti+1, endi-1,  (1,2) will change into (2,1)
    {
        return 0;
    }

    if(starti==endi)  //there is only one character
    {
        return 1;
    }

    if(input[starti]==input[endi]) //if end and starting characteres are same, we find the lPSL of removing these both and adding 2 to them, since we already got 2 characters
    {
        return lPSL(input, starti+1, endi-1)+2;
    }
    else
    {
        return max(lPSL(input,starti, endi-1), lPSL(input, starti+1, endi));  //since we need the longest, so we take max of both the parts
    }
}
