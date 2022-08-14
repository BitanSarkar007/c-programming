#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct htptr
{
    struct Node *head;
    struct Node *tail;
};

struct htptr *create(struct htptr *ptrs)
{
    int count = 0;
    int value;
    struct Node *new_Node;
    while (1)
    {
        if (ptrs->head == NULL)
        {
            printf("enter the value for first Node\n");
            scanf("%d", &value);
            new_Node = (struct Node *)malloc(sizeof(struct Node));
            new_Node->data = value;
            new_Node->next = NULL;
            ptrs->head = ptrs->tail = new_Node;
        }
        else
        {
            printf("enter value for next Node\n");
            scanf("%d", &value);
            if (value == -9999)
            {
                break;
            }
            else
            {
                new_Node = (struct Node *)malloc(sizeof(struct Node));
                new_Node->data = value;
                new_Node->next = NULL;
                ptrs->tail->next = new_Node;
                ptrs->tail = new_Node;
            }
        }
    }
    return ptrs;
}

void insert(int pos, int element, struct htptr *ptrs)
{
    struct Node *t, *p;
    if (pos == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = element;
        t->next = ptrs->head;
        ptrs->head = t;
    }
    else if (pos > 0)
    {
        p = ptrs->head;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = element;
            t->next = p->next;
            p->next = t;
        }
    }
}
struct Node *delete (struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

void display(struct Node *n)
{
    int count = 1;
    while (n != NULL)
    {
        printf(" element %d: %d\n", count, n->data);
        n = n->next;
        count++;
    }
    printf("\n");
}

int main()
{
    struct htptr *ht = (struct htptr *)malloc(sizeof(struct htptr));
    ht->head = ht->tail = NULL;
    ht = create(ht);
    display(ht->head);
    insert(2, 23462, ht->head);
    return 0;
}