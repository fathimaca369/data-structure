#include <stdio.h>
#include <stdlib.h>


typedef struct rep rep;
typedef struct node node;
typedef struct nodaddr nodaddr;

struct node {
    int value;
    rep *repptr;
    node *next;
};

struct rep {
    node *head;
    node *tail;
};

struct nodaddr {
    int key;
    node *obj_node_ptr;
    nodaddr *next;
};

nodaddr *ndr = NULL;


void makeset(int a)
{
    nodaddr *t = (nodaddr*)malloc(sizeof(nodaddr));
    rep *newset = (rep*)malloc(sizeof(rep));
    node *n = (node*)malloc(sizeof(node));

    n->value = a;
    n->repptr = newset;
    n->next = NULL;

    newset->head = newset->tail = n;

    t->obj_node_ptr = n;
    t->key = a;
    t->next = ndr;
    ndr = t;
}

rep *findset(int x)
{
    nodaddr *t = ndr;

    while (t != NULL) {
        if (t->key == x)
            return t->obj_node_ptr->repptr;
        t = t->next;
    }

    return NULL;   
}
void unionset(int key1, int key2)
{
    rep *set1 = findset(key1);
    rep *set2 = findset(key2);

    if (set1 == NULL || set2 == NULL) {
        printf("One or both elements not found.\n");
        return;
    }

    if (set1 == set2) {
        printf("\n %d and %d already belong to same set\n", key1, key2);
        return;
    }

    node *t = set2->head;
    while (t != NULL) {
        t->repptr = set1;
        t = t->next;
    }

    set1->tail->next = set2->head;
    set1->tail = set2->tail;

    free(set2);
}

void display(int a)
{
    rep *r = findset(a);
    if (r == NULL) {
        printf("Element not found.\n");
        return;
    }

    node *t = r->head;
    printf("\nSet members containing %d :", a);

    while (t != NULL) {
        printf(" %d", t->value);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    int data, data1, data2, opt;

    while (1) {
        printf("\n1. Makeset");
        printf("\n2. Findset");
        printf("\n3. Unionset");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter option: ");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            makeset(data);
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d", &data);
            printf("Reference: %p\n", (void*)findset(data));
            break;

        case 3:
            printf("Enter first element: ");
            scanf("%d", &data1);
            printf("Enter second element: ");
            scanf("%d", &data2);
            unionset(data1, data2);
            break;

        case 4:
            printf("Enter element: ");
            scanf("%d", &data);
            display(data);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }
    return 0;
}

