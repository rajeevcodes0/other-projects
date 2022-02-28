//here we will discuss about the tabulation approach, for other ideas, see previous solutions


//The states used here are based on the recursive solution

//table[i][j] is equals to:
// i) min(table[i+1][j], table[i][j+1])+cellCosts[i][j]) if we are not on the last row and last coloumn, we should take the minimum
//and add the cost of current cell to get the minimum cost till this cell

// ii) cellCosts[i][j] if the is the last cell, i.e, last row, last coloumn, since we can't move anywhere, the minimum cost would the
//value of cell itself

// iii) table[i+1][j]+cellCosts[i][j] if this is the last coloumn, we can move only bottom, so the minimum cost would be the sum
//of current cell and the bottom cell

// iv) table[i][j+1] + cellCosts[i][j] if this is the last row, we can move only right, so the minimum cost would be the sum
//of current cell and the right cell


#include<bits/stdc++.h>
using namespace std;

void fillTable(long [5][5], long [5][5], long, long);

void showTable(long [5][5], long, long);

int main()
{

    //the matrix
    long cellCosts[5][5]={
                                    {4,7,8,6,4},
                                    {6,7,3,9,2},
                                    {3,8,1,2,4},
                                    {7,1,7,3,7},
                                    {2,9,8,9,3}
                                };


    //the table in which we will store results
    long table[5][5];



    //no of rows and coloumns
    long rows=5, coloumns=5;

    //filling the table according to the states
    fillTable(table, cellCosts, rows, coloumns);

    //showing the table after filling it
    showTable(table, rows, coloumns);

    cout<<endl<<endl;

    //the result would be stored in the cell (0,0)
    cout<<table[0][0]<<endl;

    return 0;
}

void fillTable(long table[5][5], long cellCosts[5][5], long rows, long coloumns)
{
    long i,j;

    //our states are linking the lower states
    //i.e, to fill i,j we need i+1,j or i,j+1
    //so we need to fill the table from bottom and move upward



    //rules as descirbed above
    for(i=rows-1;i>-1;i--)
    {
        for(j=coloumns-1;j>-1;j--)
        {
            if(i!=rows-1 && j!=coloumns-1)
            {
                table[i][j]=min(table[i+1][j], table[i][j+1])+ cellCosts[i][j];
            }
            else if(i== rows-1 && j==coloumns-1)
            {
                table[i][j]=cellCosts[i][j];
            }
            else if(i==rows-1)
            {
                table[i][j]=table[i][j+1]+cellCosts[i][j];
            }
            else if(j== coloumns-1)
            {
                table[i][j]=table[i+1][j]+cellCosts[i][j];
            }
        }
    }
}

void showTable(long table[5][5], long rows, long coloumns)
{
    long i,j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}
