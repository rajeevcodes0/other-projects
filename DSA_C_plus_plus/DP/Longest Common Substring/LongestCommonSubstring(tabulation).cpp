//here we will discuss the tabulation approach, for any other idea, look at previous solutions

//From the recursive solution we have seen that
//we return 0 if firstIndex==-1 || secondIndex ==-1, i.e, if one string is empty
//we also return 0 if there is mismatch
//we return [firstIndex-1][secondIndex-1]+1, if there is a match (observe the recursive solution carefully)

//we will use these properties to build our table

#include<bits/stdc++.h>
using namespace std;

long findLengthOfLCS(string , string);
void showTable(long [7][7], long, long);
long findMaxInTable(long [7][7], long, long);

int main()
{
    string firstInput = "!xyabcm"; //we have taken extra dummy character to make indexing of table easy

    string secondInput = "!cdabcn";

    cout<<findLengthOfLCS(firstInput, secondInput);

    return 0;
}

long findLengthOfLCS(string firstInput, string secondInput)
{
    long rows = firstInput.length();
    long coloumns = secondInput.length();

    long table[7][7];

    //if one string is empty the length would always be zero, as in case 1 discussed above

    long i,j;

    for(i=0;i<rows;i++)
    {
        table[i][0]=0;
    }

    for(j=0;j<coloumns;j++)
    {
        table[0][j]=0;
    }

    for(i=1;i<rows; i++)
    {
        for(j=1;j<coloumns;j++)
        {
            if(firstInput[i]!=secondInput[j])
            {
                table[i][j]=0;
            }
            else
            {
                table[i][j]=table[i-1][j-1]+1;
            }
        }
    }

    //showing the filled table
    showTable(table, rows, coloumns);


    //since the result of this question is not present in the the last cell
    //we have to find the maximum values which is present in the table
    return findMaxInTable(table, rows, coloumns);


}

long findMaxInTable(long table[7][7], long rows, long coloumns)
{
    long maxValue = -1 * INT_MAX;

    long i,j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            if(table[i][j]>maxValue)
            {
                maxValue=table[i][j];
            }
        }
    }
    return maxValue;
}

void showTable(long table[7][7], long rows, long coloumns)
{
    long i,j;

    cout<<endl<<endl;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
