var reverseList = function(head) {
    let currentNode = head;
    let previousNode = null;
    let nextNode = null;

    while(currentNode!==null){
        nextNode = currentNode.next;
        currentNode.next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }
    return previousNode;
};