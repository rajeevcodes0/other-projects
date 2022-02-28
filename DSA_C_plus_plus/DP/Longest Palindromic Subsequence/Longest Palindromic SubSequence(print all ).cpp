#include<bits/stdc++.h>
using namespace std;

void buildTable(string);

long table[1000][1000];

void printSubsequence(string, string , long, long);

int main()
{
    string input;
    cin>>input;

    buildTable(input);

    printSubsequence(input,"",0,input.length()-1);

    return 0;
}

void buildTable(string input)
{
    long length = input.length();


    long i,j;


    //fill 0 in (x,y) where x>y, since it signifies empty string
    for(i=0;i<length;i++)
    {
        for(j=0; j<i;j++)
        {
            table[i][j]=0;
        }
    }

    //fill 1 in (x,y) where x==y, since a string of length 1 is always a palindrome

    for(i=0;i<length;i++)
    {
        table[i][i]=1;
    }

    //will values elsewhere according to the derived formula

    long adder =1;
    while(adder<length)
    {
        long i=0,j=i+adder;

        while(j<length)
        {
            if(input[i]==input[j])
            {
                table[i][j]=table[i+1][j-1]+2; //add 2 to string which doesn't contain these character at first and last position
            }
            else
            {
                table[i][j]= max(table[i+1][j],table[i][j-1]);
            }
            i++,j++;
        }
        adder++;
    }

    for(i=0;i<input.length();i++)
    {
        for(j=0;j<input.length();j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}



void printSubsequence(string input, string currentString, long i, long j)
{

    if(table[i][j]==0)
    {
        currentString = currentString+reverse(currentString.begin(),currentString.end()); //this optimization is done so that we don't have to pop half of the string each time
        cout<<currentString<<endl;  //if value is 0, that means its even palindrome;
        return;
    }
    else if(table[i][j]==1) //if value is 1, that means this is odd length palindrome
    {
        string copyString = currentString; //so we copy it first

        currentString+=input[i]; //add the single character

        currentString = currentString + reverse(copyString.begin(), copyString.end()); //add our copy string

        cout<<currentString<<endl;

        return;
    }


    long left, down, diag;

    left=  table[i][j-1];

    down = table[i+1][j];

    diag = table[i+1][j-1];

    if(diag+2== table[i][j] && input[i]==input[j])  //+2 is equals to the current cell, then we have to take both the characters
    {
        currentString += input[i];
        printSubsequence(input, currentString, i+1,j-1);
    }
    else
    {
        if(left==down)
        {
            printSubsequence(input, currentString, i+1,j);
            printSubsequence(input, currentString, i, j-1);
        }
        if(left>down)
        {
            printSubsequence(input, currentString, i,j-1);
        }
        else
        {
            printSubsequence(input, currentString, i+1,j);
        }
    }
}
