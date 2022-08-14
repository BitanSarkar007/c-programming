#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct htptr // Template for head tail ptrs
{
    struct node *head;
    struct node *tail;
};

struct htptr *create(struct htptr *ptrs)
{
    int count = 0;
    int value;
    struct node *newNode;
    while (1)
    {
        if (ptrs->head == NULL) // Inserting first node
        {
            printf("Enter the value of the first node: ");
            scanf("%d", &value);
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = value;
            newNode->next = NULL;
            ptrs->head = ptrs->tail = newNode;
        }
        else // Rest of the nodes
        {
            printf("Enter the value of the next node: ");
            scanf("%d", &value);
            if (value == -9999)
            {
                break;
            }
            else
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = value;
                newNode->next = NULL;
                ptrs->tail->next = newNode;
                ptrs->tail = newNode;
            }
        }
    }
    return ptrs;
}

struct htptr *insertAtFirst(struct htptr *ptrs, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = ptrs->head;
    newNode->data = value;
    ptrs->head = newNode;
    return ptrs;
}

struct htptr *insertAtIndex(struct htptr *ptrs, int value, int index)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *p = ptrs->head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    newNode->data = value;
    newNode->next = p->next;
    p->next = newNode;

    return ptrs;
}

struct htptr *insertAtEnd(struct htptr *ptrs, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    struct node *p = ptrs->head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = NULL;
    // struct node * q = ptrs->tail;
    // q->next = newNode;
    // ptrs->tail = newNode;
    // newNode->next = NULL;
    return ptrs;
}

// void insert_end(struct htptr *ptrs)
// {
//     struct node *ptr, *newNode, *pt;
//     int value;
//     printf("Enter the value of the node \n");
//     scanf("%d", &value);
//     newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = value;
//     newNode->next = NULL;
//     ptr = ptrs->tail;
//     ptr->next = newNode;
//     ptrs->tail = newNode;
// }
struct htptr *insertAfter(struct htptr *ptrs, int value, int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    struct node *p = ptrs->head;

    while (p->data != key && p->next != NULL)
    {
        p = p->next;
    }
    if (p->next == NULL && p->data != key)
    {
        printf("Entered key does not exist!!!\n");
        return ptrs;
    }
    else
    {
        newNode->next = p->next;
        p->next = newNode;
    }

    return ptrs;
}

struct htptr *insertBefore(struct htptr *ptrs, int value, int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    struct node *p = ptrs->head;
    struct node *q = ptrs->head;
    if (key == ptrs->head->data)
    {
        insertAtFirst(ptrs, value);
    }

    else
    {
        while (p->next != NULL && p->data != key)
        {
            q = p;
            p = p->next;
        }
        if (p->next == NULL && p->data != key)
        {
            printf("\n\n*****************\n\n");
            printf("\n\nEntered key does not exist!!!\n\n");
            return ptrs;
        }
        else
        {
            newNode->next = q->next;
            q->next = newNode;
        }
    }

    return ptrs;
}

struct htptr *deleteAtFirst(struct htptr *ptrs)
{
    struct node *p = ptrs->head;
    ptrs->head = ptrs->head->next;
    free(p);
    return ptrs;
}

struct htptr *deleteAfter(struct htptr *ptrs, int key)
{
    struct node *p = ptrs->head;
    struct node *q = ptrs->head;
    while (p->next != NULL && p->data != key)
    {
        q = p;
        p = p->next;
    }
    if (p->next == NULL && p->data != key)
    {
        printf("\n\n*****************\n\n");
        printf("\n\nEntered key does not exist!!!\n\n");
        return ptrs;
    }
    else
    {

        q->next = p->next;
        free(p);
    }

    return ptrs;
}

struct htptr *deleteBefore(struct htptr *ptrs, int key)
{
    struct node *p = ptrs->head;
    struct node *q = ptrs->head;
    struct node *r = ptrs->head;
    while (p->next != NULL && p->data != key)
    {
        r = q;
        q = p;
        p = p->next;
    }
    if (p->next == NULL && p->data != key)
    {
        printf("\n\n*****************\n\n");
        printf("\n\nEntered key does not exist!!!\n\n");
        return ptrs;
    }
    else
    {

        r->next = q->next;
        free(q);
    }

    return ptrs;
}

int search(struct htptr *ptrs, int key)
{
    struct node *p = ptrs->head;
    int count = 0;
    while (p->next != NULL && p->data != key)
    {
        p = p->next;
        count++;
    }
    if (p->next == NULL && p->data != key)
    {
        return -1; // sentinel
    }
    else
    {
        return count;
    }
}

struct htptr *reverse(struct htptr *ptrs)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *c = ptrs->head;
    struct node *p = NULL;
    struct node *n;
    while (c != NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    ptrs->head = p;
    return ptrs;
}


void print(struct htptr *ptrs)
{
    int count = 0;
    printf("elements of the linked list are:\n");
    struct node *n = ptrs->head;
    if (ptrs->head == NULL)
    {
        printf("empty linked list\n");
    }
    else
    {
        while (n != NULL)
        {
            printf("%d -> ", n->data);
            n = n->next;
            count++;
        }
        printf("x\n");
        printf("number of nodes: %d\n", count);
    }
}

int main(void)
{
    int option, value, index, key;
    struct htptr *ht = (struct htptr *)malloc(sizeof(struct htptr));
    ht->head = ht->tail = NULL;
    printf("Options: \n");
    printf("Enter 1 to create a linked list\n");
    printf("Enter 2 to insert an element at the beginning of your linked list\n");
    printf("Enter 3 to insert an element at an index of your choice\n");
    printf("Enter 4 to insert an element at end\n");
    printf("Enter 5 to insert an element after a specific element\n");
    printf("Enter 6 to insert an element after a specific element\n");
    printf("Enter 7 to delete first element\n");
    printf("Enter 8 to delete after a specific element\n");
    printf("Enter 9 to delete before a specific element\n");
    printf("Enter 10 to search an element\n");
    printf("Enter 11 to reverse the linked list \n");
    printf("Enter 0 to exit \n");
    while (1)
    {
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            create(ht);
            print(ht);
            break;
        }
        case 2:
        {
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insertAtFirst(ht, value);
            print(ht);
            break;
        }
        case 3:
        { 
            printf("Enter the index and value: ");
            scanf("%d %d", &index, &value);
            insertAtIndex(ht, value, index);
            print(ht);
            break;
        }
        case 4:
        {
            printf("Enter your value: ");
            scanf("%d", &value);
            insertAtEnd(ht, value);
            print(ht);
            break;
            // insert_end(ht);
            // print(ht);
            // break;
        }
        case 5:
        {
            printf("Enter the value and key: ");
            scanf("%d %d", &value, &key);
            ht = insertAfter(ht, value, key);
            print(ht);
            break;
        }
        case 6:
        {
            printf("Enter the value and key: ");
            scanf("%d %d", &value, &key);
            ht = insertBefore(ht, value, key);
            print(ht);
            break;
        }
        case 7:
        {
            ht = deleteAtFirst(ht);
            print(ht);
            break;
        }
        case 8:
        {
            printf("Enter the element after which you want to delete: ");
            scanf("%d", &key);
            ht = deleteAfter(ht, key);
            print(ht);
            break;
        }
        case 9:
        {
            printf("Enter the element before which you want to delete: ");
            scanf("%d", &key);
            ht = deleteBefore(ht, key);
            print(ht);
            break;
        }
        case 10:
        {
            printf("Enter the element you want to search: ");
            scanf("%d", &key);
            int output = search(ht, key);
            if (output == -1)
            {
                printf("Element not found!!\n");
            }
            else
            {
                printf("Element found at index: %d\n", output);
            }

            break;
        }
        case 11:
        {
            printf("Linked list before reverse :\n");
            print(ht);
            ht = reverse(ht);
            printf("Linked list after reverse :\n");
            print(ht);
            break;
        }
        case 0:
        {
            return 0;
        }
        default:
        {
            printf("wrong input - try again");
        }
        }
    }
    return 0;
}