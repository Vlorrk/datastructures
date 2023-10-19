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
typedef struct Nodes {
  void *next;
  int data;
} Node;

Node *head = NULL;

// add a node to the list

// remove a node from the list

// insert a node into a position on the list

void printOptions() {
  printf("\tYou have the following options:\n");
  printf("\t1. Add a node to the list\n");
  printf("\t2. Remove a node from the list\n");
  printf("\t3. Insert a node into the list\n");
  printf("\t4. Quit\n");
}

int main() {
  Computer nzxt;

  strcpy(nzxt.cpu, "i7-6700k");
  strcpy(nzxt.gpu, "NVIDA 4GB 2060");
  nzxt.storage = 1000;

  printf("CPU: %s\n", nzxt.cpu);
  printf("GPU: %s\n", nzxt.gpu);
  printf("Storage: %dGB\n", nzxt.storage);

  int *pointer; 
  int newVariable = 20;

  pointer = &newVariable;
  printf("\n%p - this is just 'pointer'.\n", pointer);
  printf("%p - this is the &address of newVariable.\n", &newVariable);
  printf("%d - this is using *pointer to get the value.\n", *pointer);


  // int option = -1;
  // while (option != 4) {
  //
  //   printOptions();
  //   scanf("%d", &option);
  // }

  return 0;
}
