#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
};

class GT
{
    node *root;

public:
    GT()
    {
        root = NULL;
    }

    void create_tree();
    void display();
};

void GT::create_tree()
{
    int tchapers, i, j;
    root = new node;

    cout << "\nEnter name of book: ";
    cin >> root->label;

    cout << "\nEnter no. of chapters in book: ";
    cin >> tchapers;

    root->ch_count = tchapers;

    for (i = 0; i < tchapers; i++)
    {
        root->child[i] = new node;

        cout << "\nEnter Chapter name: ";
        cin >> root->child[i]->label;

        cout << "Enter no. of sections in Chapter " 
             << root->child[i]->label << ": ";
        cin >> root->child[i]->ch_count;

        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;

            cout << "Enter Section " << j + 1 << " name: ";
            cin >> root->child[i]->child[j]->label;

            /* ✅ MISSING LINE (NOW ADDED) */
            root->child[i]->child[j]->ch_count = 0;
        }
    }
}

void GT::display()
{
    int i, j, tchapers;

    cout << "\n----- Book Hierarchy -----";
    cout << "\nBook Title: " << root->label;

    tchapers = root->ch_count;

    for (i = 0; i < tchapers; i++)
    {
        cout << "\n\tChapter " << i + 1 << ": "
             << root->child[i]->label;

        cout << "\n\t\tSections:";
        for (j = 0; j < root->child[i]->ch_count; j++)
        {
            cout << "\n\t\t -> "
                 << root->child[i]->child[j]->label;
        }
    }
}

int main()
{
    int choice;
    GT gt;

    while (1)
    {
        cout << "\n--------------------";
        cout << "\nBook Tree Creation";
        cout << "\n1. Create";
        cout << "\n2. Display";
        cout << "\n3. Quit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            gt.create_tree();
            break;

        case 2:
            gt.display();
            break;

        case 3:
            exit(0);

        default:
            cout << "Wrong choice";
        }
    }

    return 0;
}
