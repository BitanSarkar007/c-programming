#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow!!\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrInd = ptr->top - i + 1;
    if (arrInd < 0)
    {
        printf("This is not a valid position");
        return -1;
    }
    else
    {
        return ptr->arr[arrInd];
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

void display(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Empty stack!!\n");
    }
    else
    {
        for (int i = 0; i <= ptr->top; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int choice, v;
    while (1)
    {
        printf("options:\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. display\n");
        printf("0. exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter your value: \n");
            scanf("%d", &v);
            push(s, v);
            break;
        case 2:
            printf("%d popped from stack\n", pop(s));
            break;
        case 3:
            printf("%d\n", stackTop(s));
            break;
        case 4: 
            display(s);
            break;
        case 0:
            return 0;
        default:
            printf("Invalid choice!! \n");
        }
    }

    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    // struct stack *s;
    // s = (struct stack *)malloc(sizeof(struct stack *));
    // s->size = 5;
    // s->top = -1;
    // s->arr = (int *)malloc(s->size * sizeof(int));

    // // Pushing an element manually
    // // s->arr[0] = 7;
    // // s->top++;

    // // Check if stack is empty or full
    // // if (isEmpty(s))
    // // {
    // //     printf("The stack is empty \n");
    // // }
    // // else
    // // {
    // //     printf("The stack is not empty \n");
    // // }

    // push(s, 80);
    // push(s, 69);
    // push(s, 1);
    // push(s, 8);
    // push(s, 812); // --> Pused 5 values
    // // push(s, 80); // Stack Overflow

    // Printing values from stack
    // for (int j = 1; j <= s->top + 1; j++)
    // {
    //     printf("The value at position %d is %d\n ", j, peek(s, j));
    // }

    // printf("Popped %d from stack \n", pop(s)); // Last in first out
    // printf("Popped %d from stack \n", pop(s));

    // printf("The topmost value of the stack is %d\n", stackTop(s));
    return 0;
}