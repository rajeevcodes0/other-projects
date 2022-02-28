#include<bits/stdc++.h>
using namespace std;

//here we would discuss the tabulation approach only, for the other concerned part, look in commnets of previous solutions


//Here the value of table[i][j] would be:
//1. True , if(table[i-1][j]==true), this is because a solution has already been reached without the current element
//2. True , if(input[i]+table[i-1][j-input[i]] == j), this is because if we can get the current value with the help of current number,
//and other former numbers(a question which has already been computed) then we can get this value
//3. table[i-1][j], if(input[i]>j), because we can't include the currentItem , hence we have to go with the solution that was computed without the use of it

//Note: here we can have bool type table as contrast by memoization method , since we will compute all the values, only T or F will be there

//We will also have an extra 0 row and  0 zero coloumn. Why? Because the sum can be 0, in case of case 2 in table[i-1][j-input[i]], hence coloumn zero
//Also there are times when we need to check value in row 0, how will be check it case of row1, hence row 0


//the size of table would be (n+1, m+1), where n is no of items and m is totalSum, +1 since each contain a 0 row and coloumn
void fillTable(bool [6][15],long [], long, long);

void showTable(bool [6][15], long, long);

int main()
{
    long input[6]={0,7,3,2,5,8}; //an extra zero to make indexing easier while tablulation

    bool table[6][15] = {false}; //this initializes the first row as false too, which we had to do it anyway, hence we did not initialize with true
    table[0][0]=true; //because we can have sum 0 with no element :D wow!!

    fillTable(table, input, 6,15);
    showTable(table, 6,15);

    cout<<table[5][14];

    return 0;
}


void fillTable(bool table[6][15], long input[], long rows, long coloumns)
{
    long i,j;

    //since 0th row has already been filled , we start with the 1st row

    for(i=1;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            if(input[i]>j)
            {
                table[i][j]=table[i-1][j];
                continue;
            }
            if(table[i-1][j]) //if table[i-1][j] is true , if its true we don't need to compute anything
            {
                table[i][j]=true;
                continue;
            }
            else
            {
                if(table[i-1][ j-input[i] ]) //if we include the current element  and the remaining sum can be achieved with the help of remaing items , the answer that is present in table[ i-1 ][ j-input[i] ]
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

void showTable(bool table[6][15], long rows, long coloumns)
{
    long i,j;

    cout<<endl<<endl;

    for(i=0;i<rows; i++)
    {
        for(j=0;j<coloumns;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
