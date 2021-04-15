#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *list_convert(int *array, size_t size);

#endif