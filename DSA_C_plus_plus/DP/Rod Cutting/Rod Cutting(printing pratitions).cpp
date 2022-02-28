//see the previous solutions on this topic to understand the DP code
//this part deals with printing the partitions


#include<bits/stdc++.h>
using namespace std;

void fillTable(long [][9], long , long []);

void showTable(long [][9], long);

void printPartitions(long [][9], long,  long [], long, long);

int main()
{
    long n=8;

    long prices[n+1]={0,1,5,8,9,10,17,17,20};

    long table[9][9]={0};

    fillTable(table, n+1, prices);

    showTable(table, n+1);

    printPartitions(table, n+1, prices, n,n);

    return 0;
}

void fillTable(long table[][9], long n, long prices[])
{
    long i,j;

    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {

            long cutMade = prices[i]+table[i][j-i];

            long cutNotMade = table[i-1][j];


            if(i>j)
            {
                table[i][j]=cutNotMade;
            }
            else
            {
                if(cutMade>cutNotMade)
                {
                    table[i][j]=cutMade;
                }
                else
                {
                    table[i][j]=cutNotMade;
                }
            }
        }
    }
}

void showTable(long table[][9], long n)
{
    long i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printPartitions(long table[][9], long n, long prices[], long currentRow, long currentColoumn)
{
    if(currentColoumn==0) //if length of the rod is 0 we can't make further cuts
    {
        return;
    }

    if(currentRow>currentColoumn) //means cut length is greater than the rod itself, hence, we can't make the cut
    {
        printPartitions(table, n, prices, currentRow-1, currentColoumn); //since we couldn't make the cut by this length, hence go above
    }
    else
    {

        bool haveWeMadeTheCut = table[currentRow][currentColoumn]==prices[currentRow]+table[currentRow][currentColoumn-currentRow];
        //if cut have been made,this would hold true, why?
        // after making the cut, the remaining length would be currentColoumn - current Row
       // currentColoumn represents the length of the rod while currentRow represents the length of the cut to be made

        if(haveWeMadeTheCut)
        {
            cout<<currentRow<<" "; //print partition size
            printPartitions(table, n, prices, currentRow, currentColoumn-currentRow);
        }
        else
        {

            //if cut is not made, go one row above
            printPartitions(table,n, prices, currentRow-1, currentColoumn);
        }

    }
}
