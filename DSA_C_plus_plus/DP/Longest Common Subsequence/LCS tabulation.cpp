#include<bits/stdc++.h>
using namespace std;

long LCS(string, string, long, long);

int main()
{
    cout<<LCS("XMJYAUZ", "MZJAWXU", 0, 0);

}

long LCS(string firstString, string secondString, long firstIndex, long secondIndex)
{
    long lengthOfFirstString = firstString.length();
    long lengthOfSecondString = secondString.length();

    long table[lengthOfFirstString+1][lengthOfSecondString+1]; // 1 extra row and coloumn is used to represent the fact that (someSting, Null) makes no common subsequence


    long i, j;

    //since we already discused, it will be all zero in the extra row and coloumn


    for(i=0;i<lengthOfFirstString+1;i++)
    {
        table[i][0]=0;
    }

    for(j=0;j<lengthOfSecondString+1;j++)
    {
        table[0][j]=0;
    }


    for(i=1;i<lengthOfFirstString+1;i++)
    {
        for(j=1;j<lengthOfSecondString+1;j++)
        {
            if(firstString[i-1]==secondString[j-1])  //i-1,j-1  because first string is on row side and second string is on coloumn side
            {
                table[i][j]=table[i-1][j-1]+1; //since the characters match , we must take it
            }
            else
            {
                table[i][j]=max(table[i-1][j], table[i][j-1]);  //finding max by removing either of the characters
            }
        }
    }

    return table[lengthOfFirstString][lengthOfSecondString]; //the last index of the table
}
