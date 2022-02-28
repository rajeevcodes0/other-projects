//we have to find the shortest path from 0,0 to the last cell in the last row
#include<iostream>
using namespace std;

long findMinPath(long [5][5], long , long, long , long);

int main()
{
	//cost of each cells
    long cellCosts[5][5]={{4,7,8,6,4}, {6,7,3,9,2}, {3,8,1,2,4},{7,1,7,3,7}, {2,9,8,9,3}};

    long rows=5, coloumns=5, currentRow=0, currentColoumn=0;

    cout<<findMinPath(cellCosts, rows, coloumns, currentRow, currentColoumn);


    return 0;
}

long findMinPath(long cellCosts[5][5], long rows, long coloumns, long currentRow, long currentColoumn)
{
    //if we have reached the last cell, we can't move any further, hence we simply add it to our path
    if(currentRow ==  rows-1 && currentColoumn == coloumns-1)
    {
        return cellCosts[currentRow][currentColoumn];
    }
    else
    {
        //fromRight and fromBottom are the values we recieve from bottom and right, its by default set to INT_MAX
        //because suppose if we can't move bottom further(we are on the last row), then taking the min will make this value as if
        //it was never there
        long fromRight=INT_MAX, fromBottom=INT_MAX;

        if(currentRow!=rows-1)
        {
            fromBottom = findMinPath(cellCosts, rows, coloumns, currentRow+1, currentColoumn);
        }

        if(currentColoumn!=coloumns-1)
        {
            fromRight = findMinPath(cellCosts, rows, coloumns, currentRow, currentColoumn+1);
        }

		//we must add the cost of currentCell to the shortest path obtained, to get the correct value
        return min(fromRight, fromBottom) +cellCosts[currentRow][currentColoumn] ;
    }
}
