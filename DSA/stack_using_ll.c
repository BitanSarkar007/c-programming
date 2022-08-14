#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct htptr 
{
    struct node *head;
    int count;
};

void display(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct htptr *isEmpty(struct htptr *ptr)
{
    if (ptr == NULL)
    {
        printf("Stack is empty");
        return ptr;
    }
    else
    {
        printf("Stack is not empty\n");
        return ptr;
    }
}

struct htptr *isFull(struct htptr *top)
{
    if (top->count == )
    {
        return top;
    }
    else
    {
        return top;
    }
}

struct htptr *push(struct htptr *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        top->count++;
        return top;
    }
}

int pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        struct Node *n = top;
        struct Node *o = n->next;
        top = o;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos)
{
    struct Node *p = top;
    for (int i = 0; (i < pos - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

void stackTop(struct Node* top)
{
    printf("top = %d\n",top->data);
}

int main()
{

    struct htptr *ht = (struct htptr*)malloc(sizeof(struct htptr));
    ht->head = NULL;
    ht->count = 0;
    int choice,entry;
    while(1){
        printf("options:\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("0. exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the value:\n");
            scanf("%d", &entry);
            ht = push(ht, entry);
            break;
        case 2:
            ht = pop(ht);
            break;
        case 3:
            peek(ht);
            break;
        case 0:
            return 0;
        default:
            printf("invalid choice\n");                    
        }   
    }
    return 0;
}

    // int element;
    // top = push(top, 77);
    // top = push(top, 7);
    // top = push(top, 8);
    // top = push(top, 9);
    // top = push(top, 100);
    // linkedListTraversal(top);
    // element = pop(top);
    // printf("Popped element is %d\n", element);
    // element = pop(top);
    // printf("Popped element is %d\n", element);
    // top = push(top, 100);
    // linkedListTraversal(top);
    // printf("The value at position %d is: %d\n", 4, peek(4));
    // stackTop(top);