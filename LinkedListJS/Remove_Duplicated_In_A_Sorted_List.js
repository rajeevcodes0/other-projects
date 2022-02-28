var deleteDuplicates = function(head) {
    let currentNode = head;
    let previousNode = head;

    while(currentNode!==null  && currentNode.next!==null){
        currentNode = currentNode.next;

        if(currentNode.val === previousNode.val){
            previousNode.next = currentNode.next;
            
        }else{
            previousNode = currentNode;
        }
    }
    return head;
};