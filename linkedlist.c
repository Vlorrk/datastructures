#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
  void *nextListItemPointer;
  int listData;
} ListNode;

ListNode *FirstNodePointer = NULL;

// add a node to the list

void addNode(int data)
{
  ListNode *NewNodePointer = NULL;
  if (FirstNodePointer == NULL)
  { // checking if front empty

    NewNodePointer = malloc(sizeof(ListNode));

    NewNodePointer->listData = data;
    FirstNodePointer = NewNodePointer;
    NewNodePointer->nextListItemPointer = NULL;
  }
  else
  {
    NewNodePointer = malloc(sizeof(ListNode));

    NewNodePointer->listData = data;
    NewNodePointer->nextListItemPointer = FirstNodePointer;
    FirstNodePointer = NewNodePointer;
  }

  return;
}
// remove an item from list

void removeNode(int data)
{

  ListNode *current = FirstNodePointer;
  ListNode *previous = FirstNodePointer;

  while (current != NULL)
  {
    if (current->listData == data)
    {
      if (current == FirstNodePointer)
      {
        FirstNodePointer = current->nextListItemPointer;
      }
      else
      {
        previous->nextListItemPointer = current->nextListItemPointer;
        free(current);
        current = NULL;
      }
      printf("match found. data has been removed from the list \n");
      return;
    }
    previous = current;
    current = current->nextListItemPointer;
  }
  printf("no match was found \n");
  return;
}

// insert item to list

void insertNode(int data, int position)
{
  ListNode *CurrentNode = FirstNodePointer;
  while (CurrentNode != NULL && position != 0)
  {
    position--;
    CurrentNode = CurrentNode->nextListItemPointer;
  }

  if (position != 0)
  {
    printf("this position does not exist in list yet \n");
    return;
  }

  ListNode *NewListNode = malloc(sizeof(ListNode));

  NewListNode->listData = data;
  NewListNode->nextListItemPointer = CurrentNode->nextListItemPointer;
  CurrentNode->nextListItemPointer = NewListNode;

  return;
}

void printList()
{
  ListNode *current = FirstNodePointer;

  while (current != NULL)
  {

    printf("%d->", current->listData);
    current = current->nextListItemPointer;
  }

  printf("\n");

  return;
}
void printOptions()
{

  printf("\tYou have the following options:\n");
  printf("\t1. Add a node to the list\n");
  printf("\t2. Remove a node from the list\n");
  printf("\t3. Insert a node into the list\n");
  printf("\t4. Print the current list\n");
  printf("\t5. Quit\n");
}
int main()
{
  int option = 0;
  int position = 0;
  while (option != 5)
  {
    printOptions();

    int optionPicked = scanf("%d", &option);

    if (optionPicked == 1 && option > 0 && option < 5)
    {

      switch (option)
      {
      case 1:
        printf("what number do you want to add? ");
        scanf("%d", &option);
        addNode(option);
        option = -1;
        break;
      case 2:
        printf("what number do you want to remove? ");
        scanf("%d", &option);
        removeNode(option);
        option = -1;
        break;
      case 3:
        printf("what number should i add? ");
        scanf("%d", &option);
        printf("what position? \n");
        scanf("%d", &position);
        insertNode(option, position);
        option = -1;
        break;
      case 4:
        printList();
        break;
      case 5:
        break;
      }
    }
  }
  return 0;
}