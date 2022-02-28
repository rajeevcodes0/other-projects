//He we will only discuss about the memoization approach
//for other ideas, see previous solutions

#include<bits/stdc++.h>
using namespace std;

long findMinPath(long [5][5], long [5][5], long, long, long, long);

int main()
{

    long cellCosts[5][5]={{4,7,8,6,4},{6,7,3,9,2},{3,8,1,2,4},{7,1,7,3,7},{2,9,8,9,3}};
    long memoization[5][5]={0}; //assuming that cost of cell won't be 0, otherwise we would have to initialize it with -1

    long rows=5, coloumns=5, currentRow=0, currentColoumn=0;

    cout<<findMinPath(memoization, cellCosts, rows, coloumns, currentRow, currentColoumn);
    return 0;
}


//here we have five parameters
//out of which only two are changing, to we will use these as a parameter to identiy our stored solutions

long findMinPath(long memoization[5][5], long cellCosts[5][5], long rows, long coloumns, long currentRow, long currentColoumn)
{
    if(memoization[currentRow][currentColoumn]!=0) //if result is already computed , then simply return it
    {
        return memoization[currentRow][currentColoumn];
    }

    if(currentRow == rows-1 && currentColoumn == coloumns-1)
    {
        memoization[currentRow][currentColoumn]= cellCosts[currentRow][currentColoumn]; //save the result before returning
        return cellCosts[currentRow][currentColoumn];
    }
    else
    {
        long fromBottom=INT_MAX , fromRight=INT_MAX;

        if(currentRow!=rows-1)
        {
            fromBottom = findMinPath(memoization, cellCosts, rows, coloumns, currentRow+1, currentColoumn);
        }
        if(currentColoumn!=coloumns-1)
        {
            fromRight = findMinPath(memoization, cellCosts, rows, coloumns, currentRow, currentColoumn+1);
        }

        //saving the result before returning
        memoization[currentRow][currentColoumn]= min(fromBottom, fromRight) + cellCosts[currentRow][currentColoumn];
        return min(fromBottom, fromRight) + cellCosts[currentRow][currentColoumn];
    }
}
