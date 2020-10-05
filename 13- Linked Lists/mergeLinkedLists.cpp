#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = NULL, *last = NULL, *second = NULL;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count = 0;

void display(Node *p)
{
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;
        count++;
    }
    cout << endl;
}

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

Node *merge(Node *p, Node *q)
{
    Node *s = NULL, *head = NULL;
    if (p == NULL)
        return q;
    if (q == NULL)
        return p;
    if (p->data <= q->data)
    {
        s = p;
        p = p->next;
    }
    else
    {
        s = q;
        q = q->next;
    }
    head = s;
    while (p && q)
    {
        if (p->data <= q->data)
        {
            s->next = p;
            s = p;
            p = p->next;
        }
        else
        {
            s->next = q;
            s = q;
            q = q->next;
        }
    }
    if (p)
        s->next = p;
    if (q)
        s->next = q;
    return head;
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30};
    create(A, 5);
    create2(B, 4);
    Node *head = merge(first, second);
    display(head);
}
