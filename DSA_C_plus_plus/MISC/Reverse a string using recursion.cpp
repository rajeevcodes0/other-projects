#include<bits/stdc++.h>
using namespace std;

string doReverse(string, string, long);

int main()
{

    string input ="INDIA";

    cout<<doReverse(input, "", input.length()-1);

    return 0;
}

string doReverse(string input, string reversed, long index)
{
    if(index==-1)
    {
        return reversed;
    }
    else
    {
        return input[index]+doReverse(input, reversed, index-1);
    }
}
