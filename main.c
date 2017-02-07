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
            case 1 :loadData(&root);
            break;
            case 2 :inOrderShow(root); word();
            break;
            case 3 :show(searchMin(root)); word();
            break;
            case 4 :show(searchMax(root)); word();
            break;
            case 5 :counter = 0; countNodes(root, &counter); printf("%d", counter); word();
            break;
            case 6 :searchPerson(root); word();
            break;
            case 9 :deleteTree(root); return 1;
        }
    }
    deleteTree(root);
    return 0;
}
