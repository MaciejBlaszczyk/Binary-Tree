#include<stdio.h>
#include"tree.h"

int main()
{
    node *root = NULL;
    unsigned int number;
    unsigned int counter;
    while (1)
    {
        printf ("Welcome in phone book !\n"
                "If you want to add a new record, press 1\n"
                "If you want to show all records, press 2\n"
                "If you want to search minimum, press 3\n"
                "If you want to search maximum, press 4\n"
                "If you want to count nodes, press 5\n"
                "If you want to search someone, press 6\n"
                "If you want to exit phone book, press 9\n");
        scanf ("%d", &number);
        switch (number)
        {
            case 1 :load_data (&root);
            break;
            case 2 :in_order_show (root); word ();
            break;
            case 3 :show (search_min (root)); word ();
            break;
            case 4 :show (search_max (root)); word ();
            break;
            case 5 :counter = 0; count_nodes (root, &counter); printf("%d", counter); word ();
            break;
            case 6 :search_person (root); word ();
            break;
            case 9 :goto Jump;
        }
    }
    Jump:
    del_tree (root);
    return 0;
}
