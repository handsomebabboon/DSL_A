
#include <stdio.h>
#include<stdlib.h>
typedef struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
}tnode;

struct tnode *CreateBST(struct tnode *root, int item)
{
    if(root == NULL)
    {
        root = (struct tnode *)malloc(sizeof(struct tnode));
        root->left = root->right = NULL;
        root->data = item;
        return root;
    }
    else
    {
        if(item < root->data )
            root->left = CreateBST(root->left,item);
        else if(item > root->data )
            root->right = CreateBST(root->right,item);
        else
            printf(" Duplicate Element !! Not Allowed !!!");
        
        return(root);
    }
}

void display(struct tnode * root,int i)
{
    int j;
    
    if(root!=NULL)
    {
        display(root->right,i+1);
        for(j=1;j<=i;j++) printf("\t");
        printf("%d( %d: %d)\n",root->data, i,j);
        display(root->left,i+1);
        
    }
    
}//end display




void Inorder(struct tnode *root)
{
    if( root != NULL)
    {
        Inorder(root->left);
        printf(" %d ",root->data);
        Inorder(root->right);
    }
}

void Preorder(struct tnode *root)
{
    if( root != NULL)
    {
        printf(" %d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

void Postorder(struct tnode *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" %d ",root->data);
    }
}

int main()
{
    struct tnode *root1 = NULL;
    int choice, item, n, i;
    while(1)
    {
        printf("\n\nBinary Search Tree Operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5. Display\n");
		printf("\n6. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            
            printf("\n\nBST for How Many Nodes ? ");
            scanf("%d",&n);
            for(i = 1; i <= n; i++)
            {
                printf("\nEnter data for node %d : ", i);
                scanf("%d",&item);
                root1 = CreateBST(root1,item);
            }
            printf("\nBST with %d nodes is ready to Use!!\n", n);
            break;
        case 2:
            printf("\nBST Traversal in INORDER \n");
            Inorder(root1);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            Preorder(root1);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            Postorder(root1);
            break;
        case 5:
            printf("\n\n Displaying the BST \n\n");
			display(root1, 1); 
            break;
		case 6: 
			printf("\n\n Terminating  \n\n");
			exit(0); 
            break;
        default:
            printf("\n\nIgnvalid Option !!! Try Again !! \n\n");
            break;
        }
    };
    return 0;
}
