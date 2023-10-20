#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Computers {

  char cpu[50];
  char gpu[50];
  int storage;
} Computer;

int factorial(int factor) {
  if (factor == 0) {
    return 1;
  }

  return (factor * factorial(factor - 1));
}

// linked list
typedef struct {
  void *next;
  int data;
} Node;

Node *head = NULL;

// add a node to the list
Node *addNode(int data) {
  Node *new = NULL;
  // if list is empty
  if (head == NULL) { // meaning head (front of list) is not pointing to any
                      // list item (hence NULL)

    new = malloc(sizeof(Node)); // allocate mem for new list item

    new->data = data;
    head = new;
    new->next = NULL;
  } else { // head is NOT empty (head != NULL)

    new = malloc(sizeof(Node));

    new->data = data;
    new->next = head;
    head = new;
  }

  return new;
}

// remove a node from the list

// insert a node into a position on the list

// print list

void printList() {
  Node *current = head;

  while (current != NULL) {

    printf("%d->", current->data);
    current = current->next;
  }

  printf("\n");

  return;
}

void printOptions() {
  printf("\tYou have the following options:\n");
  printf("\t1. Add a node to the list\n");
  printf("\t2. Remove a node from the list\n");
  printf("\t3. Insert a node into the list\n");
  printf("\t4. Print the current list\n");
  printf("\t5. Quit\n");

  return;
}

int main() {
  Computer nzxt;

  strcpy(nzxt.cpu, "i7-6700k");
  strcpy(nzxt.gpu, "NVIDA 4GB 2060");
  nzxt.storage = 1000;

  printf("CPU: %s\n", nzxt.cpu);
  printf("GPU: %s\n", nzxt.gpu);
  printf("Storage: %dGB\n", nzxt.storage);

  int option = -1;
  while (option != 5) {

    printOptions();

    int optionPicked = scanf("%d", &option);

    if (optionPicked == 1 && option > 0 && option < 5) {
      switch (option) {
      case 1:
        // add operation
        printf("What number would you like to add? ");
        scanf("%d", &option);
        Node *new = addNode(option);
        break;
      case 2:
        // remove operation
        break;
      case 3:
        // insert operation
        break;
      case 4:
        // print list
        printList();
        break;
      case 5:
        // quit
        break;
      }
    }
  }

  return 0;
}
