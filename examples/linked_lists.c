#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

void printList(node_t *head)
{
    node_t *temporary = head;

    while(temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

node_t *createNewNode(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

node_t *insertNodeHead(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void *insertAfterNode(node_t *node_to_insert, node_t *newnode)
{
    newnode->next = node_to_insert->next;
    node_to_insert->next = newnode;
}

node_t *findNode(node_t *head, int value)
{
    node_t *current = head;
    while(current != NULL)
    {
        if(current->value == value) return current;
        current = current->next;
    }
    return NULL;
}

int main(){
    node_t *head = NULL;
    node_t *tmp;

    for(int i = 0; i < 50; i++)
    {
        tmp = createNewNode(i+1);
        insertNodeHead(&head, tmp);
    }

    if (tmp = findNode(head, 25)) printf("Found node: %d\n", tmp->value);
    else printf("Node not found.\n");

    insertAfterNode(tmp, createNewNode(51));

    printList(head);

    return 0;
}