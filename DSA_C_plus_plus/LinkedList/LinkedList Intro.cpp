#include<bits/stdc++.h>
using namespace std;


//we will create objects of the nodes and connect them
class Node
{
public:
    int data;

    //pointer to the object of type Node
    Node* next;
};


void printList(Node*);

int main()
{

    //some pointer are created, no memory is allocated to them yet
    //they point to garbage addresses
    Node* head;
    Node* second;
    Node* third;


    //memory is allocated to them, and they now point to new addressed in head
    head = new Node();
    second = new Node();
    third = new Node();


    //filling of data and linking up
    head->data = 1;
    head->next = second;

    second->data =2;
    second ->next = third;

    third->data=3;
    third->next =NULL;

    //the list we have to print, its headPointer must be passed
    printList(head);

    return 0;
}

void printList(Node* head)
{
    //since head is a local variable, we can modify it without disturbing the linkedlist, however doing so will create logical confusion
    //hence creating 'current' variable
    Node* current=head;

    //the last node next section contains NULL, hence we will reach NULL only if we have traversed the whole linkedList
    while(current!=NULL)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
}
