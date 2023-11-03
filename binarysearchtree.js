class Node {
  constructor(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }

  add(data) {
    const node = this.root;

    if (node == null) {
      this.root = new Node(data);
      return;
    }
    else {
      function searchTree(node) {
        if (data < node.data) {
          if (node.left == null) {
            node.left = new Node(data);
            return;
          } else if (node.left != null) {
            return searchTree(node.left);
          }
        } else if (data > node.data) {
          if (node.right == null) {
            node.right = new Node(data);
            return;
          } else if (node.right != null) {
            return searchTree(node.right);
          }
        } else { return null; }
      }
      return searchTree(node);
    }
  }

  findMin() {
    let current = this.root;
    while (current.left != null) {
      current = current.left
    }
    return current.data;
  }
  findMax() {
    let current = this.root;
    while (current.right != null) {
      current = current.right;
    }
    return current.data;
  }

  find(data) {
    let current = this.root;
    while (current.data != data) {
      if (data == current.data) {
        return current.data;
      } else if (data < current.data) {
        current = current.left;
      } else {
        current = current.right;
      }
      if (current == null) {
        return null;
      }
    }
  }
  remove(data) {
    this.root = removeNode(this.root, data);

    function removeNode(node, data) {
      if (node == null) {
        return null;
      }
      if (data == node.data) {
        if (node.left == null && node.right == null) {
          return null;
        }
        if (node.left == null) {
          node = node.right;
        }
        if (node.right == null) {
          node = node.right;
        }
        //if node has left two children
        var tempNode = node.right;
        while (tempNode.left != null) {
          tempNode = tempNode.left;
        }

        node.data = tempNode.data;
        node.right = removeNode(node.right, tempNode.data);
        return node;
      } else if (data < node.data) {
        node.left = removeNode(node.left, data);
        return node;
      } else if (data > node.data) {
        node.right = removeNode(node.right, data);
        return node;
      }
    }
  }

  findMinHeight(node = this.root) {
    if (node == null) {
      console.log(`this ${node} just returned -1\n`);
      return -1;
    }
    console.log(`${node.data} is above recursion calls\n`);
    let left = this.findMinHeight(node.left);
    console.log(`this ${node.data} just went under left \n`);
    let right = this.findMinHeight(node.right);
    console.log(`this ${node.data} just went under right \n`);

    if (left < right) {
      console.log(`this ${node.data} just went to left < right. left is ${left} \n`);
      return left + 1;
    } else {
      console.log(`this ${node.data} just went to right > left. right is ${right}  \n`);
      return right + 1;
    }
  }
  findMaxHeight(node = this.root) {
    if (node == null) {
      return -1;
    }

    let left = this.findMaxHeight(node.left);
    let right = this.findMaxHeight(node.right);

    if (left > right) {
      return left + 1;
    } else {
      return right + 1;
    }
  }
  inOrder() {
    if (this.root == null) {
      return null;
    } else {
      var result = new Array();
      function traverseInOrder(node) {
        node.left && traverseInOrder(node.left);
        result.push(node.data);
        node.right && traverseInOrder(node.right);
      }
      traverseInOrder(this.root);
      return result;
    }
  }
  preOrder() {
    if (this.root == null) {
      return null;
    } else {
      var result = new Array();
      function traversePreOrder(node) {
        result.push(node.data);
        node.left && traversePreOrder(node.left);
        node.right && traversePreOrder(node.right);
      }
      traversePreOrder(this.root);
      return result;
    }
  }
  postOrder() {
    if (this.root == null) {
      return null;
    } else {
      var result = new Array();
      function traversePostOrder(node) {
        node.left && traversePostOrder(node.left);
        node.right && traversePostOrder(node.right);
        result.push(node.data);
      }
      traversePostOrder(this.root);
      return result;
    }
  }
}


let tree = new BinaryTree();
tree.add(9);
tree.add(4);
tree.add(17);
tree.add(3);
tree.add(6);
tree.add(22);
tree.add(5);
tree.add(7);
tree.add(20);

console.log(tree.findMinHeight());

