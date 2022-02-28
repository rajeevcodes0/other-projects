//Here we will only discuss how to print the sum forming subset
//For any other idea discussed here, look back upon the previous solutions

#include<bits/stdc++.h>
using namespace std;

void fillTable(bool [6][15], long [], long, long);

void showTable(bool [6][15], long , long);

void showSubset(bool [6][15], long [], long, long, long, long);

int main()
{
    long input[6]={0,7,3,2,5,8};

    bool table[6][15]={false};

    table[0][0]=true;

    fillTable(table,input,6,15);

    showSubset(table, input, 5,14, 6, 15);

    return 0;
}

void fillTable(bool table[6][15], long input[], long rows, long coloumns)
{
    long i,j;

    for(i=1;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {

            if(table[i-1][j]==true)
            {
                table[i][j]=true;
            }
            else if(input[i]>j)
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                if(table[i-1][j-input[i]])
                {
                    table[i][j]=true;
                }
                else
                {
                    table[i][j]=false;
                }
            }
        }
    }
}


void showSubset(bool table[6][15], long input[], long currentRow ,long currentColoumn, long rows, long coloumns)
{
    if(input[currentRow]>currentColoumn)
    {
        showSubset(table, input, currentRow-1, currentColoumn, rows, coloumns);
    }

    bool up = table[currentRow-1][currentColoumn];

    bool farLeft = table[currentRow-1][currentColoumn-input[currentRow] ];

    bool currentCell = table[currentRow][currentColoumn];


    if(up == currentCell)
    {
        showSubset(table, input, currentRow-1, currentColoumn, rows, coloumns);
    }
    else if(farLeft == currentCell)
    {
        cout<<input[currentRow]<<" "; //the element which has been selected
        showSubset(table, input, currentRow-1, currentColoumn-input[currentRow], rows, coloumns);
    }
    else
    {
        return;
    }
}
