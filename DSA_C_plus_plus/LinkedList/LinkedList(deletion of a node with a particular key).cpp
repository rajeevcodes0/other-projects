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
    Node* headRefference =NULL;

    //inserting elements
    push(&headRefference, 5);
    push(&headRefference, 6);
    push(&headRefference, 3);
    push(&headRefference, 2);
    push(&headRefference, 9);
    printList(headRefference);

    //deleting
    deleteNode(&headRefference, 3);

    //after deletion
    printList(headRefference);


    return 0;
}

void push(Node** headRefference, long data)
{
    Node* newNode = new Node();

    newNode->data = data;

    newNode->next = *headRefference;

    *headRefference = newNode;
}

void printList(Node* headRefference)
{
    Node* targetNode = headRefference;

    while(targetNode!=NULL)
    {
        cout<<targetNode->data<<" ";
        targetNode=targetNode->next;
    }
    cout<<endl;
}

void deleteNode(Node** headRefference, long key)
{
    Node* targetNode = *headRefference;

    //find the node that contains the data
   while(targetNode!=NULL && targetNode->data!=key)
   {
       targetNode = targetNode->next;
   }

   //if the value of targetNode is still NULL that simply means that the key that we were searching for is not present in the list
   if(targetNode==NULL)
   {
       cout<<"The key is not present in the list"<<endl;
       return;
   }
   else
   {
       //if the node that contains the data is the headNode itself
       if(targetNode == *headRefference)
       {
           *headRefference= targetNode->next;

           delete targetNode;

           return;
       }

       //prev is the pointer that will be back to targetNode
       Node* prev = *headRefference;

       //move as long we don't get behind target node
       while(prev->next!=targetNode)
       {
           prev = prev->next;
       }

       //bypass the target node
       prev->next = targetNode->next;

       //delete the target node
       delete targetNode;
   }

}
