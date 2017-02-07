#include "tree.h"

#define SIZE 20
#define SIZET 5

void word()
{
    printf("\nPress any key to continue ...");
    getch();
    system("cls");
}

void show(node *root)
{
    int i;
    printf("\nFirst Name : %s", root->person.firstName);
    printf("\nLast Name : %s", root->person.lastName);
    printf("\nTelephon Numbers :  ");
    for(i = 0; i < root->person.counter; i++)
        printf("%lud  ", root->person.telnumber[i]);
}

void insertNode(node **root, node *newElement)
{
    newElement->right = NULL;
    newElement->left = NULL;
    node *temp;
    temp = *root;
    if(temp == NULL)
        *root = newElement;
    else
        while(temp)
        {
            if(strcmp(temp->person.lastName, newElement->person.lastName) == -1)
            {
                if(temp->right == NULL)
                {
                    temp->right = newElement;
                    break;
                }
                    else
                        temp = temp->right;
            }
            else
            {
                if(temp->left == NULL)
                {
                    temp->left = newElement;
                    break;
                }
                    else
                        temp = temp->left;
            }
        }
}

void loadData(node **root)
{
    node *temp;
    unsigned int i;

    temp = malloc(sizeof(node));
    if(temp == NULL)
    {
        printf("Memory error");
        free(temp);
        temp = NULL;
        return;
    }

    printf("\nWrite first name : ");
    scanf("%s", temp->person.firstName);
    printf("Write last name : ");
    scanf("%s", temp->person.lastName);
    printf("How much telephon numbers does person have? ");
    scanf("%d", &temp->person.counter);
    printf("Write telephone numbers : ");
    for(i = 0; i < temp->person.counter; i++)
        scanf("%ld", &temp->person.telnumber[i]);


    insertNode(root, temp);

    printf("\nNode has been added.");
    word();
}

void inOrderShow(node *root)
{
    if(root != NULL)
    {
        inOrderShow(root->left);
        show(root);
        inOrderShow(root->right);
    }
}

void deleteTree(node *root)
{
    if(root != NULL)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
        root = NULL;
    }
}

node *searchMin(node *root)
{
    if(root->left != NULL)
        return searchMin(root->left);
    return root;
}

node *searchMax(node *root)
{
    if(root->right != NULL)
        return searchMax(root->right);
    return root;
}

void countNodes(node *root, unsigned int *counter)
{
    if(root != NULL)
    {
        countNodes(root->left, counter);
       (*counter)++;
        countNodes(root->right, counter);
    }
}

void searchPerson(node *root)
{
    char key [SIZE];
    printf("Write surname :");
    scanf("%s", key);
    while(root)
    {
        if(strcmp(root->person.lastName, key) == 0)
            break;
        else if(strcmp(root->person.lastName, key) == -1)
            root = root->right;
        else
            root = root->left;
    }
    if(root)
        show(root);
    else
        printf("Person does not exist");
}
