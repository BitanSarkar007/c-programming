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

struct Node * create (struct Node * ht, int n)
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

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->next = NULL;
    int choice;
    while (1)
    {
        printf("\noptions:\n");
        printf("1. create a linked list\n");
        printf("2. insert at the beginning of list\n");
        printf("3. insert before a node\n");
        printf("4. insert after a node\n");
        printf("5. insert at end\n");
        printf("6. delete at the beginning of list\n");
        printf("7. delete before a node\n");
        printf("8. delete after a node\n");
        printf("9. delete at end\n");
        printf("10. search for an element\n");
        printf("11. reverse the linked list\n");
        printf("12. display\n");
        printf("0. exit\n");

        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            head = create(head)
            break;
        
        default:
            break;
        }

    }
    
    return 0;
}