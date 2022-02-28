#include<iostream>
using namespace std;
long adder(long [], long, long);
int main()
{
    long input[5]={2,1,3,4,5};
    cout<<adder(input,0, 4);
}

long adder(long input[], long startI, long endI)
{
    if(startI==endI)
    {
        return input[startI];
    }
    else
    {
        long midPoint = (startI+endI)/2;

        return adder(input, startI, midPoint)+ adder(input, midPoint+1, endI);
    }

}
