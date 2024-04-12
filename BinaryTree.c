#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ", root->data);
    }
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

struct node *createBT()
{

    int choice;
    printf("\nEnter 1 to create a new node or 0 to return");
    scanf("%d", &choice);
    if (choice == 0)
    {
        return NULL;
    }
    else
    {

        int ele;
        printf("\nEnter the key:");
        scanf("%d", &ele);
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = ele;
        printf("\n cretating left sub tree for node %d", temp->data);
        temp->lchild = createBT();
        printf("\n cretating right sub tree for node %d", temp->data);
        temp->rchild = createBT();
        return temp;
    }
}

int countNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + countNodes(root->lchild) + countNodes(root->rchild);
    }
}

int countLeafNodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if ((root->lchild == NULL && root->rchild == NULL))
    {
        return 1;
    }

    else
    {
        return countLeafNodes(root->lchild) + countLeafNodes(root->rchild);
    }
}
int main()
{
    struct node *root;
    root = NULL;
    root = createBT();
    printf("\nInorder traversal: ");
    inorder(root);

    printf("\npreorder traversal: ");
    preorder(root);

    printf("\npostorder traversal: ");
    postorder(root);

    printf("\n Total number of nodes = %d", countNodes(root));
    printf("\n Total number of Leaf nodes = %d", countLeafNodes(root));
}
