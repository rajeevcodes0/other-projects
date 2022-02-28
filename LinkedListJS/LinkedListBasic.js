class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor(){
        this.head = null;
        this.size = 0;
    }

    insertAtHead (data){
        //head is pointing to a linked list
        if(this.head){
            let newNode = new Node(data);
            newNode.next = this.head;
            this.head = newNode;
        }else{
            //if head is pointing to null
            let newNode = new Node(data);
            this.head = newNode;
        }
        this.size++;
    }

    insertAtTail(data){
        //if head is pointing to null
        if(!this.head){
            //then it is same as inserting at head
            this.insertAtHead(data);
        }else{
            let current = this.head;
            //while current.next is not null
            while(current.next){
                current = current.next;
            }
            //we have reached the last node
            current.next = new Node(data);
        }
        this.size++;
    }

    insertAtIndex(data,targetIndex){

        if(targetIndex<0 && targetIndex>=this.size){
            console.log("Index out of bound");
            return;
        }
        //if head is pointing  to null
        if(!this.head){
            //this it is like inserting at the head
            this.insertAtHead(data);
        }else if(targetIndex===this.size-1){
            //if it is the last index, then it is like
            this.insertAtTail(data);
        }
        else{
            //if we are trying to insert at an index that doesn't exist
            if(targetIndex>=this.size){
                console.log("Index out of bound");
                return;
            }else{
                let front = this.head;
                let back  = this.head;
                let currentIndex = 0;

                for(let i=0;i<targetIndex;i++){
                    front = front.next;

                    if(i+1!==targetIndex){
                        back = back.next;
                    }
                }

                let newNode = new Node(data);

                back.next = newNode;
                newNode.next = front;
            }
            
        }
    }

    getDataAtIndex(targetIndex){
        //if index doesn't exist
        if(targetIndex<0 && targetIndex>=this.size){
            console.log("Index out of bound");
        }else{
            let currentIndex = 0;
            let currentNode = this.head;

            while(currentIndex !== targetIndex){
                
                currentNode = currentNode.next;
                currentIndex++;
            }
            //when we finally reach the node, print the value
            console.log(currentNode.data);

        }
    }

    removeTailNode(){
        //if head is pointing to null
        if(!this.head){
            console.log("Nothing to delete");
        }else if(this.size===1){
            //if there is only one element
            this.head = null
        }else{
            let currentNode = this.head;
            
            let currentIndex = 0;

            let lastIndex = this.index-1;

            while(currentIndex+1!==lastIndex){
                currentNode = currentNode.next;
            }

            //when we finally reach, we put null to its next
            currentNode.next  = null;
           
        }
        this.size--;
    }

    removeHeadNode(){
        //if the head is pointing to null
        if(!this.head){
            console.log("nothing to remove");
        }else{
            //bypass the first node
            let currentNode = this.head;
            this.head = currentNode.next;
        }

        this.size--;
    }

    removeNodeAtIndex(targetIndex){
        //if the index doesn't exist
        //this also covers the empty linked list case
        if(targetIndex<0 && targetIndex>=this.size){
            console.log("Index out of bound");
            return;
        }
        else if(targetIndex===this.size-1){
            //if targetNode is the last node of linked list
            this.removeTailNode();
        }else if(targetIndex===0){
            //if targetNode is the first node of the linked list
            this.removeHeadNode();
        }else{
            //we come here only we have at least 3 nodes in the list
            let back = this.head;

            let front = this.head;
            let currentIndex=0;
            
            while(currentIndex!==targetIndex){
                front = front.next;
                currentIndex++;

                //if even after incrementing we have not reached, the targetIndex, our back can move 
                //one step 
                if(currentIndex!==targetIndex){
                    back = back.next;
                }
            }
            //we have finally reached our target, now we have to move our front one step forward

            front = front.next;

            back.next = front;



            
        }
        this.size--;
    }
    
    clearList(){
        this.head = null;
        this.size=0;
        //the memory will be cleaned by garbage collector
    }

    display(){

        //if the list is empty
        if(!this.size){
            console.log("Nothing to show");
            return;
        }
        let currentIndex=0;
        let currentNode = this.head;
        while(currentIndex!==this.size){
            console.log(currentNode.data);
            //move a step forward
            currentNode = currentNode.next;
            //increment the index
            currentIndex++;

            

        }
    }
}

let myLinkedList = new LinkedList();


myLinkedList.insertAtHead(100);
myLinkedList.insertAtHead(200);
myLinkedList.insertAtHead(300);
myLinkedList.insertAtTail(400);


myLinkedList.display();

