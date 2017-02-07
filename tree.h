#ifndef gra
#define gra
#define SIZE 20
#define SIZET 5

typedef struct data
{
    char firstname [SIZE];
    char lastname [SIZE];
    unsigned int counter;
    unsigned long *telnumber ;
}data;

typedef struct node
{
    struct node *right;
    struct node *left;
    data person;
}node;

void show (node *);

void word (void);

void insert_node (node **, node *);

void load_data (node **);

void in_order_show(node *);

void del_tree(node *);

node * search_min (node *);

node * search_max (node *);

void count_nodes (node *, unsigned int *);

void search_person (node *);

#endif // tree

