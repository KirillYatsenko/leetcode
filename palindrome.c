// source: https://leetcode.com/problems/palindrome-linked-list/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode *head);
size_t getLength(struct ListNode *head, size_t length);
void convertToString(struct ListNode *head, size_t current_elem, char *str);

void main(void)
{
    struct ListNode head;
    struct ListNode second;
    struct ListNode third;
    struct ListNode fourth;
    struct ListNode fifth;

    // TEST #1: 9
    head.val = 9;
    head.next = NULL;

    printf("TEST #1: 1. Is palidrome: %d\n", isPalindrome(&head));


    // TEST #1: 1 - 2 - 3 - 2 - 1
    head.val = 2;
    second.val = 3;
    third.val = 2;

    head.next = &second;
    second.next = &third;
    third.next = NULL;

    printf("TEST #1: 1 - 2 - 3 - 2 - 1. Is palidrome: %d\n", isPalindrome(&head));

    // TEST #2: 1 - 2 - 4
    head.val = 2;
    second.val = 3;
    third.val = 4;

    head.next = &second;
    second.next = &third;
    third.next = NULL;

    printf("TEST #2: 1 - 2 - 4. Is palidrome: %d\n", isPalindrome(&head));

    // TEST #2: 1 - 2 - 2 - 1
    head.val = 1;
    second.val = 2;
    third.val = 2;
    fourth.val = 1;

    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = NULL;

    printf("TEST #3: 1 - 2 - 2 - 1. Is palidrome: %d\n", isPalindrome(&head));


    // TEST #2: 1 - 2 - 3 - 2 - 1
    head.val = 1;
    second.val = 2;
    third.val = 3;
    fourth.val = 2;
    fifth.val = 1;

    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;
    fifth.next = NULL;

    printf("TEST #4: 1 - 2 - 3 - 2 - 1. Is palidrome: %d\n", isPalindrome(&head));

    // TEST #2: 1 - 2 - 3 - 2 - 2
    head.val = 1;
    second.val = 2;
    third.val = 3;
    fourth.val = 2;
    fifth.val = 2;

    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;
    fifth.next = NULL;

    printf("TEST #4: 1 - 2 - 3 - 2 - 2. Is palidrome: %d\n", isPalindrome(&head));
}

// should have this signature for Leetcode compatibility
bool isPalindrome(struct ListNode *head)
{
    size_t list_length = getLength(head, 0);
    char *str = (char *)malloc(list_length * sizeof(char));
    convertToString(head, 0, str);

    char *end = (str + list_length - sizeof(char));

    int str_idx = 0;
    while (str_idx++ <= list_length / 2)
        if (*(str++) != *(end--))
            return false;

    return true;
}

void convertToString(struct ListNode *head, size_t current_elem, char *str)
{
    if (head == NULL)
        return;

    str[current_elem] = 0 + head->val;

    return convertToString(head->next, ++current_elem, str);
}

size_t getLength(struct ListNode *head, size_t length)
{
    if (head == NULL)
        return length;

    return getLength(head->next, ++length);
}