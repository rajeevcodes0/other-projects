//code from geeks with some of my comments

#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

//prints occurances of txt[] in pat[]

void KMPSearch(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);

    //create lps[] that will hold the longest prefix suffix values of pattern

    int lps[M];

    //preprocess the pattern (calculate lps[] array)

    computeLPSArray(pat,M,lps);

    int i=0; //index for txt[]
    int j=0; //index for pat[]

    while(i<N)
    {
        if(pat[j]==txt[i])
        {
            j++;
            i++;
        }

        if(j==M)
        {
            cout<<"Found patter at index "<<i-j; //j is the length of patter, and i is end point where we found the last character hence we subtract
            j=lps[j-1]; //because the patter might be aa and the text might be aaa, patter is present at 0 as well as 1
        }

        //mismatch after j matches

        else if(i<N && pat[j]!=txt[i])
        {
            //Do no match lps[0] ...lps[j-1] characters, they will match anyway

            if(j!=0)
            {
                j=lps[j-1]; //because lps[j-1] characters already match we don't need to match them again
            }
            else
            {
                i=i+1; //if j is 0 , we can't make any advance shits, since we haven't made matches so far.
            }
        }
    }



}

void computeLPSArray(char* pat, int M, int* lps)
{
    //length of the previous longest prefix suffix

    int len=0;

    lps[0]=0; //lps[0] is always 0, because there is no proper prefix or suffix for length 1

    //the loop calculates lps[i] for i=1 to M-1

    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;

            lps[i]=len;

            i++;
        }
        else //(pat[i]!=pat[len])
        {
            //since characters upto pat[i-1] and pat[len-1] mathech, we look at lps[len-1], form this we get to
            // know the longest length of prefix suffix, suppose the value of lps[len-1] is 2, that means the longest prefix suffix is of length 2
            // so we go to index 2, because the longest prefix suffix of length 2, range from 0 to 1, if character at index 2, matches with i,
            // assign the value of lps[i] as lps[len]+1;


            if(len!=0)
            {
                len = lps[len-1];
            }
            else //if (len==0)  //in case len is 0 and mismatch is found, that means we have no previous matches, and we can't go back further, hence answer is 0
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

int main()
{
    char txt[]="ABABDABACDABABCABAB";
    char pat[]="ABABCABAB";

    KMPSearch(pat, txt);

    return 0;
}
