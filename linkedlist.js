class ListNode {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor(head = null) {
    this.head = head;
  }
  //add node to list
  addNode(data) {
    let newNode = new ListNode();

    if (this.head == null) {
      newNode.data = data;
      newNode.next = null;
      this.head = newNode;
    } else {
      newNode.data = data;
      newNode.next = this.head;
      this.head = newNode;
    }
  }
  //remove node from list

  removeNode(data) {
    let currentNode = new ListNode();
    let previousNode = new ListNode();

    currentNode = this.head;
    previousNode = this.head;

    while (currentNode != null) {
      if (currentNode.data == data) {
        if (currentNode == this.head) {
          this.head = this.head.next;
        } else {
          previousNode.next = currentNode.next;
          currentNode = null;
        }
        return;
      }
      previousNode = currentNode;
      currentNode = currentNode.next;
    }
    console.log(`could not find ${data} in the list`);
    return;
  }
  //insert node to list

  insertNode(data, position) {
    let current = this.head;
    let previous = new ListNode();
    while (position != 0 && current.next != null) {
      position--;
      previous = current;
      current = current.next;
    }
    if (position != 0) {
      console.log("this position does not exist in the list \n");
      return;
    }

    let newnode = new ListNode(data);
    newnode.next = current;
    previous.next = newnode;
    return;
  }

  //print the current list
  printList() {
    let current = this.head;
    var str = "";
    while (current != null) {
      str += current.data + " -> ";
      current = current.next;
    }
    console.log(str + "\n");
  }
}
