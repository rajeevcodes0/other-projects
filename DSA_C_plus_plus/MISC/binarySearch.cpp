#include<bits/stdc++.h>
using namespace std;

bool isPresent(long, long [], long);

int main()
{
    long input[10]={5,10,15,20,25,30,35,40,45,50};

    cout<<isPresent(45,input,10);

}

bool isPresent(long value, long input[], long n)
{
    long starti=0;
    long endi=n-1;

    while(starti<=endi)
    {
        long midi= (starti+endi)/2;

        if(input[midi]==value)
        {
            return true;
        }
        else
        {
            if(input[midi]<value)
            {
                starti=midi+1;
            }
            else
            {
                endi=midi-1;
            }
        }
    }
    return false;
}
