//still to work on insertAfter and have to do commenting
#include<bits/stdc++.h>
using namespace std;

//nodes will be treated as objects
//where each object will have data and a pointer to next object

class Node
{
public:
    long data;
    Node* next;
};

//function prototypes
void insertAtFront(Node**, long);
void insertAfter(Node*, long);
void insertAtEnd(Node** , long);
void printList(Node*);

int main()
{
    Node* headRefference=NULL;

    //since the head refference might have to be changed, we pass the refference of it
    insertAtFront(&headRefference, 4);
    insertAtFront(&headRefference, 7);
    insertAtFront(&headRefference, -1);
    insertAtEnd(&headRefference, 8);

    //we don't have to change the head refference in this case
    insertAfter(headRefference,15);

    //we also don't have to change the head refference, hence we pass headRefference directly
    printList(headRefference);

    return 0;
}


//since headRefference will have to be changed, hence the address of a pointer is stored in a pointer to pointer
void insertAtFront(Node** headRefference, long data)
{
    //new data is assigned, and address of it from head is returned in newNode
    Node* newNode = new Node();

    //we fill in data in data part
    newNode->data = data;

    //we assign NULL in the address part
    newNode->next = NULL;


    //if there is no node present in the linkedList
    if(*headRefference == NULL)
    {
        *headRefference = newNode;
    }
    else
    {
        newNode->next = *headRefference;

        *headRefference = newNode;
    }
}

//to insert the node after a given  target node
//since we can change the heap data from any part of the program, we didn't receive pointer to pointer
void insertAfter(Node* targetNode, long data)
{
    if(targetNode == NULL)
    {
        cout<<"The previous node can't be NULL"<<endl;

        return;
    }
    else
    {
        Node* newNode = new Node();

        newNode->data = data;

        newNode->next = targetNode->next;

        targetNode->next = newNode;

    }
}

void insertAtEnd(Node** headRefference, long data)
{
    Node* newNode = new Node();

    newNode->data = data;

    newNode->next = NULL;

    Node* currentNode = *headRefference;

    if(*headRefference==NULL)
    {
        *headRefference = newNode;
        return;
    }

    while(currentNode->next!=NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
}

void printList(Node* headRefference)
{
    Node* currentNode;

    currentNode = headRefference;

    while(currentNode!=NULL)
    {
        cout<<currentNode->data<<" ";
        currentNode  = currentNode->next;
    }

}
