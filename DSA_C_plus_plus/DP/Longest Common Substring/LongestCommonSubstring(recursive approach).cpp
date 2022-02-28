//Here we will discuss the recursive approach to calculate the length of the longest common substring of two strings

#include<bits/stdc++.h>
using namespace std;

//Why we took maxSoFar global variable?
//In case of mismatch of characters , we have to return 0
//if the mismatch is found in the first call, we must return 0, then how can we return the actual length
//hence we have taken a variable, that notes the maximum length achieved so far

long maxSoFar=0;  //at start its length is 0

long findLengthOfLCS(string, string, long, long);

int main()
{
    string firstInput = "ababc";
    string secondInput = "babca";

    //indicies on which we are working
    long firstIndex = firstInput.length()-1;
    long secondIndex = secondInput.length()-1;

    //just call the function, the result will be stored in the global variable
    findLengthOfLCS(firstInput, secondInput, firstIndex, secondIndex);

    cout<<maxSoFar; //the length of longest common substring is stored in the global variable

    return 0;
}

long findLengthOfLCS(string firstInput, string secondInput, long firstIndex, long secondIndex)
{

    if(firstIndex == -1 || secondIndex == -1) //if one string is empty we can't have any common substring
    {
        return 0; //in such case, the length would be 0
    }


    //if two characters don't match, we first, remove on chracter from firstSting and try to get the max,
    //the we do the same with the other string,
    //we must return 0, since we got a mismatch
    if(firstInput[firstIndex] != secondInput[secondIndex])
    {
        findLengthOfLCS(firstInput, secondInput, firstIndex-1, secondIndex);
        findLengthOfLCS(firstInput, secondInput, firstIndex, secondIndex-1);

        return 0;//(the maximum value including these mismatching charcters
        //if we get a mismatch, then we must return 0, since we got a break
    }
    else
    {

        //if we get a match we remove both common characters and search for the max in the remaining string
        //and since we got a common character, we add in the result obtained from removing both the characters
        long fromBottomPlusOne = findLengthOfLCS(firstInput, secondInput, firstIndex-1, secondIndex-1)+1;

        if(fromBottomPlusOne> maxSoFar)
        {
            maxSoFar = fromBottomPlusOne;
        }

        return fromBottomPlusOne;
    }
}
s
