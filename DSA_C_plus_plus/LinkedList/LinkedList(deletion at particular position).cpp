//we will discuss only the deletion idea here, for other ideas, look at the previous solution

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    long data;
    Node* next;
};

void push(Node**, long);
void printList(Node*);
void deleteNode(Node**, long);

int main()
{
    Node* headRefference = NULL;

    push(&headRefference, 3);
    push(&headRefference, 7);
    push(&headRefference, 9);
    push(&headRefference, 1);


    //before deletion
    printList(headRefference);

    long position = 0;
    deleteNode(&headRefference, position);


    //after deletion
    printList(headRefference);

    return 0;
}

void push(Node** headRefference, long data)
{
    Node* newNode = new Node();

    newNode->data = data;

    newNode->next = NULL;

    if(*headRefference==NULL)
    {
        *headRefference = newNode;
        return;
    }
    else
    {
        newNode->next = *headRefference;

        *headRefference = newNode;
        return;
    }
}

void printList(Node* headRefference)
{
    Node* currentNode = headRefference;

    while(currentNode!=NULL)
    {
        cout<<currentNode->data<<" ";
        currentNode = currentNode->next;
    }

    cout<<endl;
}

void deleteNode(Node** headRefference, long position)
{
    Node* targetNode = *headRefference;

    //keep decreasing position, until we reach the target node
    while(position--)
    {
        targetNode = targetNode->next;
    }

    //if the targetNode is the head node itself the idea of prev bypassing target node will not work, hence we do this
    if(targetNode == *headRefference)
    {
        *headRefference = targetNode->next;
        delete targetNode;
    }
    else
    {
        Node* prev = *headRefference;

        while(prev->next != targetNode)
        {
            prev = prev->next;
        }

        prev->next = targetNode->next;

        delete targetNode;
    }

}
