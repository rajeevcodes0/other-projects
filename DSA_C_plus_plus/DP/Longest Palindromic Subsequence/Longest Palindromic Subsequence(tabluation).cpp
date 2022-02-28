#include<bits/stdc++.h>
using namespace std;

long lPSL(string);
int main()
{
    string input;
    cin>>input;
    cout<<lPSL(input);

    return 0;
}

long lPSL(string input)
{
    long table[input.length()][input.length()];


    //fill (x,y) 0 where x>y since they signify empty string

    long i,j;

    for(i=1;i<input.length()-1;i++)
    {
        for(j=0;j<i;j++)
        {
            table[i][j]=0;
        }
    }

    //fill (x,y) 1 where x==y, since single character represent palindrome of length 1

    for(i=0;i<input.length()-1;i++)
    {
        table[i][i]=1;
    }

    //now fill other value

    long length = input.length()-1;
    long adder=1;
    while(adder<=length)
    {
        i=0,j=i+adder;

        while(j<=length)
        {
            if(input[i]==input[j])
            {
                table[i][j]=table[i+1][j-1]+2;
            }
            else
            {
                table[i][j]=max(table[i+1][j],table[i][j-1]);
            }

            i++,j++;
        }
        adder++;
    }


    //return the last cell of the first row
    return table[0][input.length()-1];
}
