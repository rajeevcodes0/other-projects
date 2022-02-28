#include<iostream>
using namespace std;

long LCS(string, string);
long table[1024][1024];

void printLCS(string, string, string ,long, long);

int main()
{
    cout<<LCS("ABCBDAB", "BDCABA")<<endl;

    for(long i=0;i<8;i++)
    {
        for(long j=0; j<7;j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    printLCS("ABCBDAB", "BDCABA","",7,6);
    return 0;
}

long LCS(string firstString, string secondString)
{
    long row = firstString.length()+1;
    long coloumn = secondString.length()+1;

    long i,j;
    for(i=0;i<row;i++)
    {
        table[i][0]=0;
    }

    for(j=0;j<coloumn;j++)
    {
        table[0][j]=0;
    }

    for(i=1;i<row;i++)
    {
        for(j=1;j<coloumn;j++)
        {
            if(firstString[i-1]==secondString[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    return table[row-1][coloumn-1];
}

void printLCS(string firstString, string secondString, string tillNow, long currentRow, long currentColoumn)  //currentRow, currentColoumn to specify the current cell
{
//    cout<<"current cell "<<currentRow<<" "<<currentColoumn<<endl;
//    cout<<"till now we have "<<tillNow<<endl;
//    cout<<"current chars are "<<firstString[currentRow-1]<<" "<<secondString[currentColoumn-1]<<endl;

    if(currentRow==0 || currentColoumn==0)
    {

        //cout<<"row 0 reached"<<endl;
        cout<<tillNow<<endl;
        return;
    }

    if(firstString[currentRow-1]==secondString[currentColoumn-1])  //it depends which string has been taken as row and which as coloumn, since row start from 1 and string starts from 0
    {
        //cout<<"match"<<endl;
        tillNow = tillNow + firstString[currentRow-1]; //we have taken the character, build the table on paper to understand it fully
        printLCS(firstString , secondString , tillNow, currentRow-1, currentColoumn-1);
    }
    else
    {
        //cout<<"no match"<<endl;
        long upperCell = table[currentRow-1][currentColoumn];
        long leftCell = table[currentRow][currentColoumn-1];

        if(upperCell == leftCell )
        {
            //cout<<"if 1"<<endl;
            printLCS(firstString, secondString, tillNow, currentRow-1, currentColoumn);

            printLCS(firstString, secondString, tillNow, currentRow, currentColoumn-1);
        }
        else if(upperCell> leftCell)
        {
            //cout<<"if 2"<<endl;
            printLCS(firstString, secondString, tillNow, currentRow-1, currentColoumn);
        }
        else
        {
            //cout<<"if 3"<<endl;
            printLCS(firstString, secondString, tillNow, currentRow, currentColoumn-1);
        }
    }
}
