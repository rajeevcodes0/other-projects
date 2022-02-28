#include<bits/stdc++.h>
using namespace std;

//The array on which we have to do quering is declared globally
//so that we don't have to pass it in the function again and again

//This is the array on which we have to do query
long input[4]={3,2,4,1};

//The array in which the segment tree will be stored, its size in worst case might get 4*n
long segmentTree[16];

//function prototypes
void printArray(long [], long);
long query(long, long, long, long, long);
void build(long, long, long);
void update(long, long , long , long, long);

int main()
{
    build(0, 0, 3);

    //we start with the 0th index of the tree(we always have to)

    update(5, 3, 0, 0, 3);

    printArray(segmentTree, 16);
    cout<<query(0, 0, 3, 0, 3);
    return 0;
}

void build(long currentIndexOfTree, long starti, long endi)
{
    //if there is only one element in the range, it is the minimum of the range by default
    if(starti==endi)
    {
        //in such case we fill the currentIndexOfTree by taking value from the input array
        segmentTree[currentIndexOfTree] = input[starti];
    }
    else
    {
        //now since we have to build the halfs of the current array we take mid
        long mid = (starti+endi)/2;

        //we build the left part
        build(2*currentIndexOfTree+1, starti, mid);

        //we build the right part
        build(2*currentIndexOfTree+2, mid+1, endi);

        //we fill the current index with the minimum of both the parts
        segmentTree[currentIndexOfTree] = min(segmentTree[2*currentIndexOfTree+1], segmentTree[2*currentIndexOfTree+2]);
    }
}

long query(long currentIndexOfTree, long starti, long endi, long queryStarti, long queryEndi)
{
    //if the query indices totally overlap the range indices, the we simply return the value in the range, since thats what we
    //are looking for
    if(queryStarti <= starti && endi<=queryEndi)
    {
        return segmentTree[currentIndexOfTree];
    }
    //if the query range falls out of the current range, we simply return Infinity, because when we take minimum from both the sides
    //the infinity will cancel out
    //also query range may fall either side of the current range , either left of it or right of it
    else if(queryEndi<starti || queryStarti>endi)
    {
        return INT_MAX;
    }
    else
    {
        //if we have a partial overlap, i.e, the query range doesn't full cover the range or doesn't toally is out of the range
        //it might be covering some part of it, since we have the answer of the whole range in this node, we break this range into two parts
        //hoping to get the answer only for query range that is being covered
        long mid = (starti+endi)/2;


        //we return the minimum of both the parts then
        return min(query(2*currentIndexOfTree+1, starti, mid, queryStarti, queryEndi),
                   query(2*currentIndexOfTree+2, mid+1, endi, queryStarti, queryEndi) );

    }
}

void update(long newValue, long indexToUpdate , long currentTreeIndex, long starti, long endi)
{
    //if this is the index we are looking for, we update it
    if(starti==endi && starti==indexToUpdate)
    {
        input[indexToUpdate]=newValue;
        segmentTree[currentTreeIndex]=newValue;
    }
    else
    {

        long mid = (starti+endi)/2;


        //checking if the indexToUpdate falls on the right side or left side of the current range
        if(indexToUpdate<=mid)
        {
            update(newValue, indexToUpdate, 2*currentTreeIndex+1, starti, mid);
        }
        else
        {
            update(newValue, indexToUpdate, 2*currentTreeIndex+2, mid+1, endi);
        }

    }


    //finally we update the current node value using the child node values
    //since segment tree is a full binary tree, it will always have two child nodes

    //if this is not  a leaf node(because a leaf node can't have child nodes and if we compute it we may get garbage values)
    if(!(starti==endi))
    {
        segmentTree[currentTreeIndex]=min(segmentTree[2*currentTreeIndex+1], segmentTree[2*currentTreeIndex+2]);
    }
}

void printArray(long input[], long n)
{
    long i;
    for(i=0;i<n;i++)
    {
        cout<<input[i]<<" ";
    }
    cout<<endl;
}
