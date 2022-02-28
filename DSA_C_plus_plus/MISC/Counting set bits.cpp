//Logic : multiplying a number by 2 adds 0 at its end in its binary representation
//multiplying the same number by 2 and adding 1 , adds 1 at its end in its binary representation

#include<bits/stdc++.h>
using namespace std;

//here we will discuss the approach to calculate the set bit of a number, from 0 to n in order of n

//from 0 to 100000
long setbits[100001];

void calculateSetBits(long, long);

int main()
{

    calculateSetBits(1, 1);

    cout<<setbits[3];
    return 0;
}

void calculateSetBits(long noOfOnes, long currentNumber)
{
    //we don't wish to calculate above this limit
    if(currentNumber>=100000)
    {
        return;
    }

    setbits[currentNumber]=noOfOnes;

    calculateSetBits(noOfOnes, 2*currentNumber);
    calculateSetBits(noOfOnes+1, 2*currentNumber+1);

}
