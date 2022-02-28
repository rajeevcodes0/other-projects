#include<bits/stdc++.h>
using namespace std;

void fillTable(long [7][11], long [], long [], long , long);

void printItems(long [7][11], long, long, long [], long []);

void showTable(long [7][11], long , long);

int main()
{

    long values[7]={0, 20, 5, 10, 40, 15, 25};

    long weights[7]={0, 1, 2, 3, 8, 7, 4};

    long table[7][11]={0};

    fillTable(table, values, weights, 7, 11);

    cout<<"Maximum obtainable values is "<<table[6][10]<<endl;

    cout<<"Selected ItemNo. are as follows"<<endl;
    printItems(table, 6, 10, values, weights);
    cout<<endl;


    cout<<"Table filled is as follows"<<endl;
    showTable(table, 7, 11);


    return 0;
}

void fillTable(long table[7][11], long values[], long weights[], long rows, long coloumns)
{
    long i,j;

    for(i=1;i<rows;i++)
    {
        for(j=1;j<coloumns;j++)
        {
            if(j<weights[i])
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                long taken = values[i]+table[i-1][j-weights[i]];
                long notTaken = table[i-1][j];

                if(taken>notTaken)
                {
                    table[i][j]=taken;
                }
                else
                {
                    table[i][j]= notTaken;
                }
            }
        }
    }
}


void showTable(long table[7][11], long rows, long coloumns)
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


void printItems(long table[7][11], long currentRow, long currentColoumn, long values[], long weights[])
{

    if(currentRow==0 || currentColoumn==0)
    {
        return;
    }

    long taken = values[currentRow]+table[currentRow-1][currentColoumn- weights[currentRow] ];

    long notTaken = table[currentRow-1][currentColoumn];

    long currentCell = table[currentRow][currentColoumn];

    if(currentCell==taken)
    {
        cout<<currentRow<<" ";
        printItems(table,currentRow-1, currentColoumn-weights[currentRow] , values, weights);
    }
    else if(currentCell == notTaken)
    {
        printItems(table, currentRow-1, currentColoumn, values, weights);
    }
}
