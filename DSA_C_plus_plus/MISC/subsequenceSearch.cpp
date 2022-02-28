#include<bits/stdc++.h>
using namespace std;

bool isSubsequencePresent(string,string,long,long);
int main()
{
    string mainString, toSearch;

    cout<<"Enter the mainString and string toSearch"<<endl;
    cin>>mainString>>toSearch;

    if(isSubsequencePresent(mainString, toSearch, 0, 0))
    {
        cout<<"Subsequence is present"<<endl;
    }
    else
    {
        cout<<"Subsequence is not present"<<endl;
    }
    return 0;
}

bool isSubsequencePresent(string mainString, string toSearch, long mainStringIndex, long toSearchIndex)
{
    if(toSearchIndex == toSearch.length()) //if the index has reached the end of toSearch string, then it means we have got all the characters
    {
        return true;
    }
    else if(mainStringIndex == mainString.length())  //if the index has reached the end of the mainString that means we have not found all the characters of the toSearch string
    {
        return false;
    }
    else
    {
        if(mainString[mainStringIndex]==toSearch[toSearchIndex])   //if we get same characters, that means we matched a character in toSearch, hence we increment both the indices by 1
        {
            return isSubsequencePresent(mainString,toSearch, mainStringIndex+1, toSearchIndex+1);
        }
        else // if we can't match the characters that means , the current character is of no use to us, hence we increment 1 in mainString index and leave toSearch index as it is
        {
            return isSubsequencePresent(mainString,toSearch, mainStringIndex+1, toSearchIndex);
        }
    }
}
