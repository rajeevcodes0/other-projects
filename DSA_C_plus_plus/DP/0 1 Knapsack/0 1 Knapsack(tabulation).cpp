//the bottom up tabulation approach depends on the idea, that we either take on item or we don't
//as seen in the recursive approach
//we will build the table as we have built in the case of 'rod cutting problem' and since each item can
//be taken only once, after taking it we look the remaining part in the upper row rather than in the same row, as
//was the case with 'rod cutting problem'

#include<bits/stdc++.h>
using namespace std;

void fillTable(long [7][11], long [], long [], long, long);
void showTable(long [7][11], long, long);

int main()
{
    long values[7] = {0, 20, 5, 10, 40, 15, 25}; //extra 0 taken to make indexing easier during filling table

    long weights[7] = {0, 1, 2, 3, 8, 7, 4};

    long table[7][11]={0}; //there would be n+1 number of rows and m+1 coloumns, n=noOfItems, m= totalCapacity
    //+1 because, there would be and extra row for empty item and  extra coloumn for bag of size 0, to be more precise to make the state equations fit


   fillTable(table, values, weights, 7,11);

   showTable(table, 7, 11);
   cout<<endl<<endl;

   cout<<table[6][10];

    return 0;
}


void fillTable(long table[7][11], long values[], long weights[], long rows, long coloumns)
{
    long i, j;

    //since if we don't have any item(an item of weight 0) , we won't get any values, no matter how big a bag we have got(reason to make the first row 0)
    //and if we have a bag of size 0, no matter how precious items we have got, the values will get no values(reason to make first coloumn 0)
    //since the table has already been initialized with zero we don't have to initialize the first row and coloumn with zero


    //here i represents the current item
    //j represents the size of bag
    for(i=1;i<rows;i++)
    {
        for(j=1;j<coloumns;j++)
        {
            if(weights[i]>j)
            {
                table[i][j]=table[i-1][j];
            }
            else
            {

                long valueIfItemTaken = values[i]+table[i-1][ j-weights[i] ] ; //value of item in consideration + optimal value for remaining weight, which has already been computed
                long valueIfItemNotTaken = table[i-1][j];


                if(valueIfItemTaken>valueIfItemNotTaken)
                {
                    table[i][j]=valueIfItemTaken;
                }
                else
                {
                    table[i][j]=valueIfItemNotTaken;
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
