var reverseList = function(head) {
    //if the list is empty
   if(head===null){
       return;
   }

   if(head.next === null){
       //if this is the last element, then it is already reversed
       // console.log("hi",head);
       return head;
   }else{
       let currentNode = head;
       let nextNode = head.next;

       let reveredListHead = reverseList(nextNode);

       currentNode.next.next = currentNode;
       currentNode.next = null;

       return reveredListHead;
   }


};