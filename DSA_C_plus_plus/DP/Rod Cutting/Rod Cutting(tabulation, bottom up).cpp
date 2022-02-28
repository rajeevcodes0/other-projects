#include<bits/stdc++.h>
using namespace std;

void fillTable(long [][9], long, long []);

void show(long [][9], long);

int main()
{
    long n=8;

    long prices[n+1]={0,1,5,8,9,10,17,17,20};

    //left side has length of parts available
    //upper side as total rod length

    //a cell (3,6) means, if we have available cuts (1,2 and 3) and length 6, what will be optimal value
    //now, we can either make the cut of size 3 here or not, if we do, problem comes down to (3,6-3) ie (3,3) which is in the same row
    //if we dont' make the cut, the problem comes down to (2,6), which is already computed
    //this information is enough for the time when you look it again

    long table[9][9]={0}; //note that the row in which part length is 0, got initialized by 0, automatically by this, hence we don't need to do it

    fillTable(table, n+1,prices); //table and size of table, and price of each part

    cout<<"The optimum cost would be "<<table[8][8]<<endl;

    return 0;
}

void fillTable(long table[][9], long n, long prices[])
{
    long i,j;

    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            //make the table and fill it to understand the following two lines properly
            long cutMade=prices[i]+table[i][j-i];  //if a cut made we include price of this cut part and find the optimum price of remaining part


            long cutNotMade = table[i-1][j];


            if(i>j) //that means cut can't be made, since cut length is greater than the rod itself :D
            {
                table[i][j]=cutNotMade;
                continue; //so that it doesn't go down
            }

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


    show(table,n);
}


void show(long table[][9], long n)
{

    cout<<"The table is as follows"<<endl<<endl;
    long i,j;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
