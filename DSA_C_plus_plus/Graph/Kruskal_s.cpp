#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long totalWeight;

class Graph;
class MinHeap;
class UnionFind;

struct node
{
    long source;
    long destination;
    long weight;
};

class Graph
{
private:
  long rows=9, coloumns=9;

  long adjMatrix[9][9];

  long selected[9]={0}; //to tell if a given vertex has been selected or not
  long noOfSelected=0;
public:
    void initializeAdjMatrix();
    void addEdge(long,long,long);
    void setSelected(long,long);
    long getSelected(long);
    long getNoOfSelected();
    long isCycle(long,long);
    void kruskal();
};

class MinHeap //we don't need addNode method in kruskal, we will use Heapify since all nodes(edges) are present beforehand, don't use sorting
{
private:
    long length=0;
    struct node minHeap[500];
public:
    long getLength(); //to set the length of the minHeap array
    void deleteNode();
    struct node getMin();
    void heapify(long);
    void appendNodeInArray(long,long,long);
    void printMinHeap();
    long isEmpty();
};

class UnionFind
{
private:
    long parent[9];
public:
    void initializeParent();
    long findParent(long);
    void unionSets(long, long);
    void printParent();
};

Graph graph1;
MinHeap minHeap1;
UnionFind unionFind1;

void Graph :: initializeAdjMatrix()
{
    long i,j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            adjMatrix[i][j]=0;
        }
    }
}

void Graph :: addEdge(long u, long v, long w)
{
    adjMatrix[u][v]=w;
    adjMatrix[v][u]=w;
    minHeap1.appendNodeInArray(u,v,w);
}

void Graph :: setSelected(long node_id, long value)
{
    selected[node_id]=value;
}

long Graph :: getSelected(long node_id)
{
    return selected[node_id];
}

long Graph :: isCycle(long source, long destination)
{
    if(unionFind1.findParent(source)==unionFind1.findParent(destination))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Graph :: kruskal()
{
    cout<<"Inside kruskal"<<endl;

    cout<<"Hello sachin MinHeap is Empty or not "<<minHeap1.isEmpty()<<endl;
    if(minHeap1.isEmpty())
    {
        return;
    }

    struct node Node = minHeap1.getMin();

    cout<<"current minimum node is "<<endl;
    cout<<Node.source<<" "<<Node.destination<<" "<<Node.weight<<endl;

    minHeap1.deleteNode(); //since we have got the min node, its of no use to us now

    cout<<"After deleting that node"<<endl;
    minHeap1.printMinHeap();

    long sourceOfEdge, destinationOfEdge;

    sourceOfEdge = Node.source;

    destinationOfEdge = Node.destination;

    if(!graph1.isCycle(sourceOfEdge, destinationOfEdge))
    {
        unionFind1.unionSets(sourceOfEdge,destinationOfEdge); //this will create problem with base condition
        unionFind1.printParent();
        totalWeight+=Node.weight;
        kruskal();
    }
    else
    {
        kruskal();
    }
}

long Graph :: getNoOfSelected()
{
    return noOfSelected;
}


long MinHeap :: getLength()
{
    return length;
}

void MinHeap :: deleteNode()
{
    if(length<=0)
    {
        cout<<"Min Heap is already empty, can't remove further"<<endl;
    }
    else
    {
        swap(minHeap[0],minHeap[length-1]);
        length--;

        heapify(0); //to rearrange the minHeap after deletion since the heap got distrubed
    }
}

struct node MinHeap :: getMin()
{
    return minHeap[0];
};

void MinHeap :: heapify(long parentIndex)
{
    long leftChildIndex, rightChildIndex;

    if(parentIndex*2+1 < length)
    {
        leftChildIndex = parentIndex*2+1;
    }
    else
    {
        leftChildIndex = -1;
    }

    if(parentIndex*2+2 < length)
    {
        rightChildIndex = parentIndex*2+2;
    }
    else
    {
        rightChildIndex = -1;
    }

    if(leftChildIndex == -1 && rightChildIndex == -1)
    {
        return;
    }
    else
    {
        long indexOfLeast = parentIndex;

        if(leftChildIndex != -1)
        {
            if(minHeap[leftChildIndex].weight < minHeap[parentIndex].weight)
            {
                indexOfLeast = leftChildIndex;
            }
        }

        if(rightChildIndex != -1)
        {
            if(minHeap[rightChildIndex].weight < minHeap[indexOfLeast].weight)
            {
                indexOfLeast = rightChildIndex;
            }
        }


        if(parentIndex != indexOfLeast)
        {
            swap(minHeap[parentIndex],minHeap[indexOfLeast]);

            heapify(indexOfLeast);
        }
    }
}

void MinHeap :: appendNodeInArray(long u, long v, long w)
{
    struct node Node;

    Node.source = u;
    Node.destination = v;
    Node.weight = w;

    minHeap[length]=Node;
    length++;
}


void MinHeap :: printMinHeap()
{
    long i;

    cout<<"The minHeap is as follows"<<endl;
    for(i=0;i<length;i++)
    {
        cout<<minHeap[i].weight<<" ";
    }
    cout<<endl;
}

long MinHeap :: isEmpty()
{
    if(minHeap1.length==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void UnionFind :: initializeParent()
{
    memset(parent,-1,sizeof(parent));
}

long UnionFind :: findParent(long index)
{
    if(parent[index]==-1)
    {
        return index;
    }
    else
    {
        return findParent(parent[index]);
    }
}

void UnionFind :: unionSets(long u, long v)
{
    long parentU = findParent(u);

    long parentV = findParent(v);

    parent[ parentV ] = parentU;

}

void UnionFind :: printParent()
{
    long i;

    cout<<"The parent array is as follows"<<endl;
    for(i=0;i<9;i++)
    {
        cout<<parent[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    long tree[2][9];

    unionFind1.initializeParent();

     graph1.addEdge(0,1,4);
     graph1.addEdge(0,7,8);
     graph1.addEdge(1,2,8);
     graph1.addEdge(1,7,11);
     graph1.addEdge(2,3,7);
     graph1.addEdge(2,5,4);
     graph1.addEdge(2,8,2);
     graph1.addEdge(3,4,9);
     graph1.addEdge(3,5,14);
     graph1.addEdge(4,5,10);
     graph1.addEdge(5,6,2);
     graph1.addEdge(6,7,1);
     graph1.addEdge(6,8,6);
     graph1.addEdge(7,8,7);

     minHeap1.printMinHeap();

     for(long i=minHeap1.getLength()/2; i>-1 ; i--)
     {
         minHeap1.heapify(i);
     }

     minHeap1.printMinHeap();

     graph1.kruskal();

     cout<<totalWeight<<endl;

     return 0;
}
