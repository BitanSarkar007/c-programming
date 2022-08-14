#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct htptr
{
    struct node *head;
    struct node *tail;
};

struct htptr *create(struct htptr *ptr)
{
    struct node *newNode;
    int value;
    while (1)
    {
        if (ptr->head == NULL)
        {
            printf("Enter the value of first node: \n");
            scanf("%d", &value);
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;
            ptr->head = ptr->tail = newNode;
        }
        else
        {
            printf("Enter the value of new node: \n");
            scanf("%d", &value);
            if (value == -9999)
            {
                break;
            }
            else
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                newNode->data = value;
                newNode->prev = ptr->tail;
                newNode->next = NULL;
                ptr->tail->next = newNode;
                ptr->tail = newNode;
            }
        }
    }
    return ptr;
}

struct htptr *insertAtBeginning(struct htptr *ptr)
{
    struct node *newNode;
    int val;
    printf("Enter the value to be inserted at beginning: \n");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = ptr->head;
    newNode->prev = NULL;
    ptr->head = newNode;
    return ptr;
}

struct htptr *insertAtEnd(struct htptr *ptr)
{
    struct node *newNode;
    int val;
    printf("Enter the value to be inserted at end: \n");
    scanf("%d", &val);
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = ptr->tail;
    ptr->tail->next = newNode;
    ptr->tail = newNode;
    return ptr;
}

struct htptr *insertBefore(struct htptr *ptr)
{
    struct node *newNode;
    struct node *p = ptr->head;
    int key, val;
    printf("Enter the value before which you want to insert the node: \n");
    scanf("%d", &key);
    if (key == ptr->head->data)
    {
        insertAtBeginning(ptr);
        return ptr;
    }
    else if (key == ptr->tail->data)
    {
        insertAtEnd(ptr);
        return ptr;
    }
    else
    {
        while (p->next != NULL && p->data != key)
        {
            p = p->next;
        }
        if (p == NULL && p->data != key)
        {
            printf("Key not found\n");
        }
        else
        {
            printf("Enter the value of new node: \n");
            scanf("%d", &val);
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = val;
            newNode->next = p;
            newNode->prev = p->prev;
            p->prev->next = newNode;
            p->prev = newNode;
        }
        return ptr;
    }
}

struct htptr *insertAfter(struct htptr *ptr, int key)
{
    struct node* p = ptrs->head;
    struct node* q = p->next;
    while(p->data != nd && p->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    if(p->next == NULL)
    {
        printf("Element not found!!\n");
    }
    else
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->next = p->next;
        p->next = new_node;
        new_node->data = new;
    }
    return ptr;
}


void display(struct htptr *ptr)
{
    struct node *p = ptr->head;
    while (p != NULL)
    {
        printf("Element: %d\n", p->data);
        p = p->next;
    }
}

struct htptr *reverse(struct htptr* ptr)
{
    struct node *p,*c,*n;
    c = ptr->head;
    p = NULL;
    while(c!=NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    ptr->head = p;
    return ptr;
}

int search(struct htptr *ptr, int key)
{
    struct node *p = ptr->head;
    int count = 1;
    while(p->data != key && p->next != NULL)
    {
        p = p->next;
        count++;
    }
    if(p->next == NULL && p->data != key)
    {
        return -1; //sentinel
    }
    else
    {
        return count;
    }
}

struct htptr *deleteAtBeginning(struct htptr *ptr)
{
    struct node *p = ptr->head;
    struct node *q = p->next;
    ptr->head = q;
    free(p);
    return ptr;
}

struct htptr *deleteAtEnd(struct htptr *ptr)
{
    struct node *p = ptr->tail;
    struct node *q = ptr->head;
    while(q->next != p)
    {
        q = q->next;
    }
    q->next = NULL;
    ptr->tail = q;
    free(p);
    return ptr;
}

struct htptr *deleteBefore(struct htptr *ptr,int nd)
{
    struct node *p = ptr->head;
    struct node *d = p->next;
    struct node *q = p->next->next;
    while(q->data != nd && q->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    if(q->next == NULL)
    {
        printf("Element not found!!\n");
    }
    else
    {
        p->next = q;
        free(d);
    }
    return ptr;
}

struct htptr *deleteAfter(struct htptr *ptr,int nd)
{
    struct node *p = ptr->head;
    struct node *q = p->next;
    while(p->data != nd && p->next != NULL)
    {
        p = p->next;
        q = p->next;
    }
    if(p->next == NULL)
    {
        printf("Element not found!!\n");
    }
    else
    {
        p->next = q->next;
        free(q);
    }
    return ptr;
}


int main()
{
    int choice;
    struct htptr *ht = (struct htptr *)malloc(sizeof(struct htptr));
    ht->head = ht->tail = NULL;
    int entry, pos, key, ans;
    while(1){
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
            ht = create(ht);
            break;
        case 2:
            printf("enter the value:\n");
            scanf("%d",&entry);
            insertAtBeginning(ht,entry);
            display(ht);
            break;
        case 3:
            printf("enter the value and node\n");
            scanf("%d %d",&entry,&pos);
            insertBefore(ht,pos,entry);
            display(ht);
            break;
        case 4:
            printf("enter the value and node\n");
            scanf("%d %d",&entry,&pos);
            insertAfter(ht,pos,entry);
            display(ht);
            break;
        case 5:
            printf("enter the value\n");
            scanf("%d",&entry);
            insertAtEnd(ht,entry);
            display(ht);
            break;
        case 6:
            deleteAtBeginning(ht);
            display(ht);
            break;
        case 7:
            printf("enter the node\n");
            scanf("%d",&pos);
            deleteBefore(ht,pos);
            display(ht);
            break;
        case 8:
            printf("enter the node\n");
            scanf("%d",&pos);
            deleteAfter(ht,pos);
            display(ht);
            break;
        case 9:
            deleteAtEnd(ht);
            display(ht);
            break;
        case 10:
            printf("enter the element to be searched\n");
            scanf("%d",&key);
            int ans = search(ht,key);
            if(ans == -1)
            {
                printf("Element not found!!\n");
            }
            else{
                printf("the element is at node %d\n",ans);
            }
            break;
        case 11:
            reverse(ht);
            printf("linked list after reversal:\n");
            display(ht);
            break;
        case 12:
            display(ht);
            break;
        case 0:
            return 0;               
        default:
            printf("invalid choice\n");
        }
    }
    return 0;
}