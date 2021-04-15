#include "linkedlist.h"

struct ListNode *list_convert(int *array, size_t size)
{
    if (!size)
        return NULL;

    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *current = head;
    current->val = array[0];

    for (size_t i = 1; i < size; i++)
    {
        struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
        next->val = array[i];

        current->next = next;
        current = current->next;
    }

    current->next = NULL;
    return head;
}