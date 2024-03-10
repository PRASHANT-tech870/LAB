/*
p = leader, q = follower

p,q points initially to root

deviate q left or right until it becomes null
(if not null then bring p also to that node only where q is pointing)
according to greater(right) or smaller(left)

if q is null then create a new node there
*/

#include <stdio.h>
#include <stdlib.h> //for dma

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *getnode(int ele)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->lchild = temp->rchild = NULL;

    return temp;
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

void createRoot(struct node **root)
{
    struct node *temp;
    int key;
    printf("\n Entr key of the root node");
    scanf("%d", &key);
    *root = getnode(key);
}

void createTree(struct node **root, int ele)
{
    struct node *p, *q, *temp;
    p = q = *root;
    while (ele != p->data && q != NULL)
    {
        p = q;
        if (ele > p->data)
        {
            q = p->rchild;
        }
        else
        {
            q = p->lchild;
        }
    }
    if (ele == p->data)
        {
            printf("\nDuplicate");
        }
        else if (ele < p->data)
        {
            temp = getnode(ele);
            p->lchild = temp;
        }
        else
        {
            temp = getnode(ele);
            p->rchild = temp;
        }
}







int main()
{
    struct node *root;
    root = NULL;
    // createTree(&root);
    int choice;
    int ele;
    createRoot(&root);
    while (1)
    {
        printf("\n1.Insert , 2.Traversal, 3.Treesort");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("\nEnter element");
        scanf("%d",&ele);
            createTree(&root, ele);
            break;
        case 2:
            printf("\nInorder traversal: ");
            inorder(root);

            printf("\npreorder traversal: ");
            preorder(root);

            printf("\npostorder traversal: ");
            postorder(root);
            break;

        case 3:
            printf("\nTRee sort:");
            inorder(root);
            break;

        default:
            return 0;
        }
    }
}