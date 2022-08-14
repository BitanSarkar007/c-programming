#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int search(struct node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (key == root->data)
    {
        return 1;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

void create(struct node **root, int val)
{
    struct node *n = (struct node *)(malloc(sizeof(struct node)));
    n->left = NULL;
    n->right = NULL;
    n->data = val;
    if (*root == NULL)
    {
        *root = n;
        return;
    }
    if (search(*root, val) == 0)
    {
        if ((*root)->data > val)
            create(&(*root)->left, val);
        else
            create(&(*root)->right, val);
        return;
    }
    printf("Element already exists in the tree \n");
    return;
}

void preoder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preoder(root->left);
        preoder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *successor(struct node *root, int key)
{
    struct node *n = NULL;
    if (root == NULL)
        return NULL;

    while (root != NULL)
    {
        if (root->data == key)
        {
            if (root->right)
            {
                n = root->right;
                while (n->left)
                {
                    n = n->left;
                }
            }
            return n;
        }

        else if (root->data < key)
        {
            root = root->right;
        }

        else
        {
            n = root;
            root = root->left;
        }
    }
    return NULL;
}

struct node *predecessor(struct node *root, int key)
{
    struct node *n = NULL;
    if (root == NULL)
        return NULL;

    while (root != NULL)
    {
        if (root->data == key)
        {
            if (root->left)
            {
                n = root->left;
                while (n->right)
                {
                    n = n->right;
                }
            }
            return n;
        }

        else if (root->data < key)
        {
            n = root;
            root = root->right;
        }

        else
        {
            root = root->left;
        }
    }
    return NULL;
}

struct node *minimum(struct node *node)
{
    struct node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *delete (struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete (root->left, key);

    else if (key > root->data)
        root->right = delete (root->right, key);

    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minimum(root->right);

        root->data = temp->data;

        root->right = delete (root->right, temp->data);
    }
    return root;
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return -1; // height based on number of edges
    }
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
        {
            return (l + 1);
        }
        else
        {
            return (r + 1);
        }
    }
}
int main()
{
    struct node *root = NULL;
    struct node *pre = NULL;
    struct node *suc = NULL;
    int ch, data;

    while (ch != -1)
    {
        printf("**** Options ***** \n");
        printf("1.Search \n");
        printf("2.Insert \n");
        printf("3.Display \n");
        printf("4.Delete \n");
        printf("5. Predecessor and succesor of a node \n");
        printf("6. Height of your BST \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value for searching : \n");
            scanf("%d", &data);
            printf("%d\n", root->data);
            if (search(root, data))
            {
                printf("Element found \n");
            }
            else
            {
                printf("Element not found \n");
            }
            break;
        case 2:
            printf("Enter your value : \n");
            scanf("%d", &data);
            create(&root, data);
            break;
        case 3:
            printf("Displaying the tree : \n");
            printf("Displaying in-order \n");
            inorder(root);
            printf("\nDisplaying post-order\n");
            postorder(root);
            printf("\nDisplaying pre-order\n");
            preoder(root);
            break;
        case 4:
            printf("Enter key: \n");
            scanf("%d", &data);
            delete (root, data);
            break;
        case 5:
            printf("Enter your value : \n");
            scanf("%d", &data);
            suc = successor(root, data);
            pre = predecessor(root, data);
            if (suc != NULL)
                printf("Successor is : %d\n", suc->data);
            else
                printf("NULL successor \n");

            if (pre != NULL)
                printf("Predecessor is : %d\n", pre->data);
            else
                printf("NULL predecessor \n");
            break;
        case 6:
            printf("Height of your BST is %d\n", height(root));
            break;
        default:
            printf("Invalid choice \n");
        }
        printf("\n");
    }
    return 0;
}