#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// Case 1
struct Node *insertAtFirst(struct Node *head, int data)

{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
};


// Case 2
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


// Case 3
struct Node *insertAtEnd(struct Node *head, int data)

{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    
    return head;
};


// Case 4 Insert after a specific value for node
struct Node *insertAfterNode(struct Node *head ,struct Node *prevNode, int data)

{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    
    return head;
};

struct Node * create (struct Node * head, int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        struct Node * newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter value for new node: \n");
        scanf("%d", &x);
        newnode->data = x;
        newnode->next = NULL;
    }
    return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memeory for nodes in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 7;
    head->next = second;

    // Link second and third node
    second->data = 11;
    second->next = third;

    // Terminate list at the third node
    third->data = 66;
    third->next = NULL;

    //linkedListTraversal(head);
    // head = insertAtFirst(head, 56, 1);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    //head = insertAfterNode(head, second, 45);
    //printf("\n");
    //printf("***** After Insertion ***** \n\n");
    //linkedListTraversal(head);

    // struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    // head->next = NULL;
    // int a;
    // printf("Enter number of nodes needed: ");
    // scanf("%d", &a);
    // head = create (head, a);
    linkedListTraversal(head);
    return 0;
}