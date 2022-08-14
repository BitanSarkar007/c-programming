struct htptr *insertBefore(struct htptr *ptr)
{
    struct node *p = ptr->head;
    struct node *q = ptr->head;
    struct node *newNode;
    int key, val;
    printf("Enter the key before which you want the value to be inserted\n");
    scanf("%d", &key);
    while (p->data != key && p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    if (p->next == NULL && p->data!= key )
    {
        printf("Element not found!!\n");
    }
    else
    {
        printf("Enter the value of the new node: \n");
        scanf("%d", &val);
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = val;
        newNode->prev = q;
        newNode->next = q->next;
        q->next = newNode;
    }
    return ptr;
}
