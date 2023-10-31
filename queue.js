class Queue {

  constructor() {
    this.items = [];
  }

  enqueue(item) {
    this.items.push(item);
  }

  dequeue() {
    this.items.shift()
  }

  printQueue() {
    for (const element of this.items) {
      console.log(element);
    }
  }
}

