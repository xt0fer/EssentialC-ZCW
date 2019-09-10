#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct list *start, *end;

void add(struct list **head, struct list **list, int data);
int delete (struct list *head, struct list *tail);

int main(void)
{
    start = end = NULL;
    add(&start, &end, 2);
    add(&start, &end, 3);
    printf("First element: % d\n", delete (start, end));
    printf("Second element: % d\n", delete (start, end));
}

void add(struct list **head, struct list **tail, int data)
{
    if ((*tail) == NULL)
    {
        (*head) = (*tail) = (struct list *)malloc(sizeof(struct list));
        (*head)->data = data;
        (*head)->next = NULL;
    }
    else
    {
        (*tail)->next = (struct list *)malloc(sizeof(struct list));
        (*tail) = (*tail)->next;
        (*tail)->data = data;
        (*tail)->next = NULL;
    }
}

int delete (struct list *head, struct list *tail)
{
    struct list *temp;
    int result = -1;
    if (head != NULL)
    {
        result = head->data;
    }
    if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        temp = head->next;
        free(head);
        head = temp;
    }
    return result;
}
