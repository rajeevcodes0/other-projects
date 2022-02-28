//Here we will discuss about the printing of all the longest common substrings for other ideas read previous solutions

//Idea
//Find the maximum value in the table, then traverse the table again, noting down the index of those values(if more than one)
//then finally printing all those substrings

#include<bits/stdc++.h>
using namespace std;

void fillTable(long [7][7], long, long, string, string);

void showTable(long [7][7], long, long);

long findMaxValue(long [7][7], long, long);

void printSubstrings(long [7][7], long, long, long, string, string);

int main()
{
    string firstInput = "!xyabcm";
    string secondInput = "!cdabcn";

    long table[7][7];

    fillTable(table, 7, 7, firstInput, secondInput);


    return 0;
}

void fillTable(long table[7][7], long rows, long coloumns , string firstInput, string secondInput)
{
    long i,j;

    for(i=0;i<rows;i++)
    {
        table[i][0]=0;
    }

    for(j=0;j<coloumns;j++)
    {
        table[0][j]=0;
    }

    for(i=1;i<rows;i++)
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

    showTable(table, 7,7);

    long maxValue = findMaxValue(table, 7, 7);  //finding the maximum value of the table

    printSubstrings(table, maxValue,  7, 7, firstInput, secondInput); //printing the substrings
}

void showTable(long table[7][7], long rows, long coloumns)
{
    long i, j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}

long findMaxValue(long table[7][7], long rows, long coloumns)
{
    long i,j;

    long toReturn =0;

    for(i=1;i<rows;i++)
    {
        for(j=1;j<coloumns;j++)
        {
            if(table[i][j]>toReturn)
            {
                toReturn = table[i][j];
            }
        }
    }

    return toReturn;
}

void printSubstrings(long table[7][7], long maxValue,  long rows, long coloumns, string firstInput, string secondInput)
{
    long indices[2][10]={0}; //to store the indices, i.e (6,5) , we assume maximum of 10 of such would be there

    long coloumnNo=0; //the coloumn no of the indices array we are pointing at

    long i,j;

    for(i=1;i<rows; i++)
    {
        for(j=1;j<coloumns;j++)
        {
            if(table[i][j]==maxValue)
            {
                indices[0][coloumnNo]=i;
                indices[1][coloumnNo]=j;
                coloumnNo++;
            } 
        }
    }

    while(coloumnNo!=0)
    {
        long cellRowNo = indices[0][coloumnNo-1];
        long cellColoumnNo = indices[1][coloumnNo-1];


        long x=cellRowNo ,y=cellColoumnNo;


        string toPrint = "";

        while(table[x][y]!=0) //while this cell value doesn't get zero
        {
            toPrint = toPrint + firstInput[x]; //keep on adding the characters


            x--,y--; //go diagonally up
        }

        reverse(toPrint.begin(), toPrint.end()); //since the string obtained is reversed, we must reverse it to get original string

        cout<<toPrint<<endl;

        coloumnNo--; //to work on the other index in indices table
    }
}
