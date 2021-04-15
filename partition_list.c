// source: https://leetcode.com/problems/partition-list/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist/linkedlist.h"

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

struct ListNode *partition(struct ListNode *head, int x)
{
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *pivot = NULL;

    while (current)
    {
        // set pivot
        if (pivot == NULL && current->val >= x)
            pivot = prev;

        // insert current and change pivot
        if (pivot && current->val < x)
        {
            struct ListNode *pivot_next = pivot->next;
            struct ListNode *current_next = current->next;

            pivot->next = current;
            pivot = current;
            pivot->next = pivot_next;

            prev->next = current_next;
            current = current_next;
        }
        else
        {
            // iterate and keep previous position
            prev = current;
            current = current->next;
        }
    }

    return head;
}

void main(void)
{
    // Test #1
    int size = 6;
    int arr[] = {1, 4, 3, 2, 5, 2};
    struct ListNode *head = list_convert(arr, size);
    struct ListNode *newHead = partition(head, 3);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d,", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");

    // Test #2
    size = 2;
    int arr2[] = {2, 1};
    head = list_convert(arr2, size);
    newHead = partition(head, 2);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d,", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");
}