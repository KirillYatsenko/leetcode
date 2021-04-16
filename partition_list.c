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
    int pivot_set = 0;

    while (current)
    {
        // set pivot
        if (!pivot_set && current->val >= x)
        {
            pivot = prev;
            pivot_set = 1;
        }

        // insert current and change pivot
        if (pivot_set && current->val < x)
        {
            struct ListNode *current_next = current->next; // save current next before overriding

            // if pivot is before head
            if (!pivot)
            {
                struct ListNode *old_head = head; // save old head before overriding

                pivot = current;
                head = current;         // set new head
                pivot->next = old_head; // set new head->next to old head
            }
            else
            {
                struct ListNode *pivot_next = pivot->next; // save old pivot->next before overriding
                pivot->next = current;                     // save new pivot->next
                pivot = current;
                pivot->next = pivot_next; // setting NEW pivot->next to OLD pivot->next
            }

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
    size = 3;
    int arr2[] = {1, 2, 1};
    head = list_convert(arr2, size);
    newHead = partition(head, 2);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d,", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");

    // Test #3
    size = 2;
    int arr3[] = {2, 1};
    head = list_convert(arr3, size);
    newHead = partition(head, 2);

    for (size_t i = 0; i < size; i++)
    {
        printf("%d,", newHead->val);
        newHead = newHead->next;
    }
    printf("\n");
}