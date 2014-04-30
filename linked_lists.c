#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    char data;
} Node;


Node* initnode(Node *before, char data)
{
    Node* new = (Node*) malloc(sizeof(Node));
    before->next = new;
    new->data = data;

    return new;
}


void initlist(Node *list)
{
    char letter, i;
    for(i = 3; i; --i)
        for(letter = 'a'; letter <= 'h'; letter++)
            list = initnode(list, letter);
}


void deletelist(Node *list)
{
    Node *temp, *curr;

    while(list->next)
    {
        temp = list->next;
        free(list);
        list = temp;
    }
}
void rdeletelist(Node *list)
{
    if(!list) return;

    deletelist(list->next);
    free(list);
}

void printlist(Node *list)
{
    if(!list) return;

    while(list = list->next)
        printf("%c%s", list->data, list->next ? "->" : "");

    printf("\n");
}


void invertlist(Node *p)
{
    Node *a, *b;

    while((a = p->next) && (b = a->next))
    {
        p -> next = b;
        a -> next = b -> next;
        b -> next = a;

        p = p -> next -> next;
    }
}


void rinvertlist(Node *p)
{
    Node *a = p -> next;
    if(!a) return;

    Node *b = a -> next;
    if(!b) return;

    p -> next = b;
    a -> next = b -> next;
    b -> next = a;

    rinvertlist(a);
}


void removeduplicates(Node *list)
{
    Node *prev = list;
    char letter, set[26];

    for(letter = 'a'; letter <= 'z'; letter++)
        set[letter - 'a'] = 0;

    while(list = prev->next)
        if(set[list->data - 'a']++)
        {
            prev -> next = list -> next;
            free(list);
        }
        else
            prev = prev -> next;
}


void _rremoveduplicates(Node *list, char *set)
{
    Node *curr = list->next;
    if(!curr) return;

    if(set[curr->data - 'a']++)
    {
        list -> next = curr -> next;
        free(curr);
        _rremoveduplicates(list, set);
    }
    else
        _rremoveduplicates(list->next, set);
}


void rremoveduplicates(Node *list)
{
    char letter, set[26];

    for(letter = 'a'; letter <= 'z'; letter++)
        set[letter - 'a'] = 0;

    _rremoveduplicates(list, set);
}


int main()
{
    Node *list = (Node*) malloc(sizeof(Node));

    initlist(list);
    printlist(list);

    rinvertlist(list);
    //printlist(list);

    //rremoveduplicates(list);
    printlist(list);

    deletelist(list);
    printlist(list);

    return 0;
}
