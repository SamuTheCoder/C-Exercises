#include <stdio.h>
#include <stdlib.h>

#define LLSIZE 10

// default constructor for linked list
#define INIT_LinkedList(X) (LinkedList X = {.first = NULL, .size = LLSIZE})

typedef struct
{
    int data;
    Node *next;
} Node;

typedef struct
{
    Node *first;
    int size;
} LinkedList;

void append(Node **headRef, int newData, u_int8_t mode, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newData;

    switch (mode)
    {
    case 1:
        newNode->next = *headRef;
        break;
    case 2:
        int i = 0;
        Node* current = *headRef;
        Node* previousNextNode;
        //Search for the position
        while (*headRef != NULL)
        {
            current = current->next;
            if (i == pos)
            {
                previousNextNode = current->next;
                current->next = newNode;
                newNode->next = previousNextNode;
                break;
            }
            i++;
        }
        break;

    case 3:
        newNode->next = NULL;

        // Check if list is empty
        if (headRef == NULL)
        {
            *headRef = newNode;
            return;
        }

        Node *last = *headRef;

        // Search for the last node
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = newNode;
        break;

    default:
        break;
    }
}

void remove(Node **headRef, int pos){
    Node* start = *headRef;

    int i = 0;
    while(start->next != NULL){
        start = start->next;
        if (i == pos-1)
        {
            //get the next node of the node to remove
            Node* nextNode = (start->next)->next;
            free(start->next);
            start->next = nextNode;
        }
        i++;
    }
    
}
