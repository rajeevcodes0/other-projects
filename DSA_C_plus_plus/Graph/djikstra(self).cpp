//the length problem is still not solved



long breaker=0;

#include<bits/stdc++.h>
using namespace std;

struct node
{
    long node_id;
    long distance;
};

class Graph
{
private:
    long rows=6, coloumns=6;

    long distanceFromSource[6];

public:

    long adjMatrix[6][6];
    long visited[6]={0,0,0,0,0,0};

    void initializeAdjMatrix();
    void initializeDistanceFromSource();
    void addEdge(long,long,long);
    void setDistance(long,long);
    long getDistance(long);
    void printAdjMatrix();

};

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

void Graph :: initializeDistanceFromSource()
{
    long i;

    for(i=0;i<rows;i++)
    {
        distanceFromSource[i]=INT_MAX;
    }
}

void Graph :: setDistance(long node, long distance)
{
    distanceFromSource[node]=distance;
}

long Graph :: getDistance(long node)
{
    return distanceFromSource[node];
}

void Graph :: addEdge(long u,long v, long weight)
{
    adjMatrix[u][v]=weight;
    adjMatrix[v][u]=weight;
}

void Graph :: printAdjMatrix()
{
    long i,j;

    for(i=0;i<rows;i++)
    {
        for(j=0;j<coloumns;j++)
        {
            cout<<adjMatrix[i][j]<<"   ";
        }
        cout<<endl;
    }
    cout<<endl;
}


class MinHeap
{
private:
    long length=0;
    struct node minHeap[500];
public:
    void addNode(long,long);
    void deleteNode();
    void heapify(long);
    void printMinHeap();
    struct node getMin();
};
MinHeap minHeap1;
Graph graph1;

void MinHeap :: addNode(long node_id, long distance)
{
    if(length==500)
    {
        cout<<"Heap is full, about to overflow"<<endl;
        return;
    }

    struct node Node;
    Node.node_id=node_id;
    Node.distance=distance;
    minHeap[length]=Node;

    length++;


    long currentPosition=length-1;
    long parent;

    while(currentPosition!=0)
    {
        parent=(currentPosition-1)/2;

        if(minHeap[parent].distance>minHeap[currentPosition].distance)
        {
            struct node temp;

            temp=minHeap[parent];
            minHeap[parent]=minHeap[currentPosition];
            minHeap[currentPosition]=temp;


            currentPosition=parent;
        }
        else
        {

            break;
        }
    }
}

void MinHeap :: deleteNode()
{
    if(length==0)
    {
        cout<<"Heap is already empty"<<endl;
    }
    else
    {
        swap(minHeap[0], minHeap[length-1]);
        length--;
        heapify(0);
    }
}

void MinHeap :: heapify(long currentPosition)
{

    long leftChildIndex, rightChildIndex;

    if(currentPosition*2+1 < length)
    {
        leftChildIndex=currentPosition*2+1;
    }
    else
    {
        leftChildIndex=-1;
    }


    if(currentPosition*2+2 < length)
    {
        rightChildIndex=currentPosition*2+2;
    }
    else
    {
        rightChildIndex=-1;
    }


    if(leftChildIndex==-1 && rightChildIndex==-1)
    {
        //cout<<"both -1"<<endl;
        return;
    }
    else
    {
        long indexOfLeast;

        if(leftChildIndex!=-1 && minHeap[leftChildIndex].distance < minHeap[currentPosition].distance)
        {
            indexOfLeast=leftChildIndex;
        }
        else
        {
            indexOfLeast=currentPosition;
        }

        if(rightChildIndex!=-1 && minHeap[indexOfLeast].distance > minHeap[rightChildIndex].distance)
        {
            indexOfLeast=rightChildIndex;
        }

        if(indexOfLeast!=currentPosition)
        {

            swap(minHeap[currentPosition], minHeap[indexOfLeast]);
            heapify(indexOfLeast);
        }
    }
}

void MinHeap :: printMinHeap()
{
    long i;
    cout<<endl<<endl;
    cout<<"Printing the minHeap array"<<endl;
    for(i=0;i<length;i++)
    {
        cout<<"{("<<minHeap[i].node_id<<"),("<<minHeap[i].distance<<")}";
    }
    cout<<endl;
}

struct node MinHeap :: getMin()
{
    return minHeap[0];
};

void initializeDjikstra(long);
void djikstra();

int main()
{
    //Note graph1 is global object

    graph1.initializeAdjMatrix();

    graph1.addEdge(0,1,7);
    graph1.addEdge(0,2,9);
    graph1.addEdge(0,5,14);
    graph1.addEdge(1,2,10);
    graph1.addEdge(1,3,15);
    graph1.addEdge(2,3,11);
    graph1.addEdge(2,5,2);
    graph1.addEdge(3,4,6);
    graph1.addEdge(4,5,9);

    graph1.initializeDistanceFromSource();

    long source;
    cout<<"Enter the source node"<<endl;
    cin>>source;

    initializeDjikstra(source);


    long i;

    cout<<"Note: The distance of Node 0 is first, then Node1 and so \nThe respective distances are as follow:"<<endl<<endl;

    for(i=0;i<6;i++)
    {
        cout<<graph1.getDistance(i)<<" ";
    }

    return 0;
}


void initializeDjikstra(long source)
{
    graph1.setDistance(source, 0);

    minHeap1.addNode(source, graph1.getDistance(source) );

    djikstra();

}

void djikstra()
{
    struct node minNode = minHeap1.getMin();

    minHeap1.deleteNode();


    long node_id = minNode.node_id;


    long node_distance = minNode.distance;

    long activation=0; //will djikstra be called again?

    for(long i=0;i<6;i++)
    {
        if(graph1.adjMatrix[node_id][i]!=0 && !graph1.visited[i])
        {
            activation=1;
            long newPosibleDistance=node_distance+graph1.adjMatrix[node_id][i];

            if(graph1.getDistance(i)>newPosibleDistance)
            {
                graph1.setDistance(i,newPosibleDistance);

                minHeap1.addNode(i,newPosibleDistance);
            }
        }
    }
    graph1.visited[node_id]=1;

    if(activation) //kind of a base condition
    {
        djikstra();
    }
}
