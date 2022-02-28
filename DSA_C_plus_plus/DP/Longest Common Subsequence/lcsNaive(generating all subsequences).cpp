#include<iostream>
using namespace std;

void generateSubSequence(string, string, long, string []);
long setIndex;

int main()
{
    string firstString, secondString;

    cin>>firstString>>secondString;

    string firstStringSet[500], secondStringSet[500];

    setIndex=0;
    generateSubSequence(firstString,"",0, firstStringSet);
    long setIndexA = setIndex;

    for(long i=0;i<setIndexA;i++)
    {
        cout<<firstStringSet[i]<<endl;
    }

    setIndex=0;
    generateSubSequence(secondString,"",0, secondStringSet);
    long setIndexB = setIndex;


    for(long i=0;i<setIndexB;i++)
    {
        cout<<secondStringSet[i]<<endl;
    }


    long length=0;
    for(long i=0; i<setIndexA ;i++)
    {
        for(long j=0; j<setIndexB ;j++)
        {
            if(firstStringSet[i]==secondStringSet[j])
            {
                length = firstStringSet[i].length();
            }
        }
    }

    cout<<length;

    return 0;
}

void generateSubSequence(string oString, string tillNow, long index, string subSequenceSet[500])
{
    if(index==oString.length())
    {
        subSequenceSet[setIndex]=tillNow;
        setIndex++;
    }
    else
    {
        generateSubSequence(oString, tillNow, index+1, subSequenceSet);
        generateSubSequence(oString, tillNow+oString[index], index+1, subSequenceSet);
    }
}

