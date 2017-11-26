#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkedList
{
    int     value;
    struct _LinkedList *next;
}LinkedList;

LinkedList*     head;

int SearchNode(int val, LinkedList* node);
int DeleteNode(int val);
int InsertNode(int val);
int PrintLinkedList();

int main(void)
{
    LinkedList *TempNode;

    head = NULL;
    TempNode = NULL;

    InsertNode(1);
    PrintLinkedList();
    InsertNode(2);
    PrintLinkedList();
    InsertNode(3);
    PrintLinkedList();
    SearchNode(4, TempNode);
    SearchNode(3, TempNode);
    DeleteNode(2);
    PrintLinkedList();
    DeleteNode(2);

    return 0;
}

int SearchNode(int val, LinkedList* node)
{
    LinkedList* TempNode;

    TempNode = head;
    while (TempNode != NULL)
    {
        if (TempNode->value == val)
        {
            node = TempNode;
            printf("Search : %d\n", node->value);
            return 0;
        }

        TempNode = TempNode->next;
    }
    printf("Target %d Not Found\n", val);
    return 1;
}

int DeleteNode(int val)
{
    LinkedList* TempNode, *TargetNode;

    TempNode = head;
    TargetNode = TempNode->next;

    while( (TargetNode->next) != NULL)
    {
        if ( (TargetNode->value) == val)
        {
            TempNode->next = TargetNode->next;
            printf("Delete Target Node: %d\n", TargetNode->value);
            free(TargetNode);
            return 0;
        }

        TempNode = TempNode->next;
        TargetNode = TargetNode->next;
    }

    printf("Target Not Found: %d\n", val);
    return 1;
}

int InsertNode(int val)
{
    LinkedList* NewNode, *TempNode;

    NewNode = (LinkedList*)malloc(sizeof(LinkedList));
    NewNode->value = val;
    NewNode->next = NULL;

    if (head == NULL)
    {
        head = NewNode;
    }
    else
    {
        TempNode = head;
        while((TempNode->next) != NULL)
        {
            TempNode = TempNode->next;
        }
        TempNode->next = NewNode;
    }

    return 0;
}

int PrintLinkedList()
{
    LinkedList* TempNode;

    TempNode = head;

    while(TempNode != NULL)
    {
        printf("%d ", TempNode->value);
        TempNode = TempNode->next;
    }
    printf("\n");

    return 0;
}
