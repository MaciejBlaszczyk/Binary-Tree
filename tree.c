#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define SIZE 20
#define SIZET 5

typedef struct data
{
    char firstname [SIZE];
    char lastname [SIZE];
    unsigned int counter;
    unsigned long telnumber [SIZET];
}data;

typedef struct node
{
    struct node *right;
    struct node *left;
    data person;
}node;

void word (void)
{
    printf ("\nPress any key to continue ...");
    getch ();
    system ("cls");
}

void show (node * root)
{
    int i;
    printf ("\nFirst Name : %s", root->person.firstname);
    printf ("\nLast Name : %s", root->person.lastname);
    printf ("\nTelephon Numbers :  ");
    for (i = 0; i < root->person.counter; i++)
        printf ("%ld  ", root->person.telnumber[i]);
}

void insert_node (node **root, node *new_element)
{
    new_element->right = NULL;
    new_element->left = NULL;
    node *temp;
    temp = *root;
    if (temp == NULL)
        *root = new_element;
    else
        while (temp)
        {
            if (strcmp (temp->person.lastname, new_element->person.lastname) == -1)
            {
                if (temp->right == NULL)
                {
                    temp->right = new_element;
                    break;
                }
                    else
                        temp = temp->right;
            }
            else
            {
                if (temp->left == NULL)
                {
                    temp->left = new_element;
                    break;
                }
                    else
                        temp = temp->left;
            }
        }
}

void load_data (node **root)
{
    node *temp;
    int i;

    temp = malloc (sizeof (node));
    if (temp == NULL)
    {
        printf ("Memory error");
        free (temp);
        temp = NULL;
        return;
    }

    printf ("\nWrite first name : ");
    scanf ("%s", temp->person.firstname);
    printf ("Write last name : ");
    scanf ("%s", temp->person.lastname);
    printf ("How much telephon numbers does person have? ");
    scanf ("%d", &temp->person.counter);
    printf ("Write telephone numbers : ");
    for (i = 0; i < temp->person.counter; i++)
        scanf ("%ld", &temp->person.telnumber[i]);

    insert_node (root, temp);

    printf ("\nNode has been added.");
    word();
}

void in_order_show (node *root)
{
    if (root != NULL)
    {
        in_order_show (root->left);
        show (root);
        in_order_show (root->right);
    }
}

void del_tree (node *root)
{
    if (root != NULL)
    {
        del_tree (root->left);
        del_tree (root->right);
        free (root);
        root = NULL;
    }
}

node * search_min (node * root)
{
    if (root->left != NULL)
        return search_min (root->left);
    return root;
}

node * search_max (node * root)
{
    if (root->right != NULL)
        return search_max (root->right);
    return root;
}

void count_nodes (node * root, unsigned int *counter)
{
    if (root != NULL)
    {
        count_nodes (root->left, counter);
        (*counter)++;
        count_nodes (root->right, counter);
    }
}

void search_person (node * root)
{
    char key [SIZE];
    printf ("Write surname :");
    scanf ("%s", key);
    while(root)
    {
        if (strcmp (root->person.lastname, key) == 0)
            break;
        else if (strcmp (root->person.lastname, key) == -1)
            root = root->right;
        else
            root = root->left;
    }
    if (root)
        show (root);
    else
        printf("Person does not exist");
}
