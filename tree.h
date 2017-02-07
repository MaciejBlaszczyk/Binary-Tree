#ifndef BINARYTREE
#define BINARYTREE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>

#define SIZE 20
#define SIZET 5

typedef struct data
{
    char firstName[SIZE];
    char lastName[SIZE];
    unsigned int counter;
    long telnumber[] ;
}data;

typedef struct node
{
    struct node *right;
    struct node *left;
    data person;
}node;

void show(node *);
void word(void);
void insertNode(node **, node *);
void loadData(node **);
void inOrderShow(node *);
void deleteTree(node *);
node * searchMin(node *);
node * searchMax(node *);
void countNodes(node *, unsigned int *);
void searchPerson(node *);

#endif // BINARYTREE

