// source: https://leetcode.com/problems/deepest-leaves-sum/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "treenode/treenode.h"

static struct TreeNode *tree_convert_helper(int *array, size_t array_size, size_t idx);
struct TreeNode *tree_convert(int *array, size_t size);

int deepestLeavesSum(struct TreeNode *root);
int helper(struct TreeNode *root, int *depth);

void main(void)
{
    // // Test #1
    // int test1[] = {1, 2, 1};
    // struct TreeNode *head = tree_convert(test1, sizeof(test1)/ sizeof(test1[0]));
    // int res = deepestLeavesSum(head);
    // printf("Test #1 | Correct: 3 | Actual: %d\n", res);

    // // Test #2
    // int test2[] = {2, 3, 4, 5, 6, 7, 0};
    // struct TreeNode *head2 = tree_convert(test2, sizeof(test2)/ sizeof(test2[0]));
    // int res2 = deepestLeavesSum(head2);
    // printf("Test #2 | Correct: 18 | Actual: %d\n", res2);

    // Test From Leetcode.com #1
    int testL1[] = {1, 2, 3, 4, 5, 0, 6, 7, 0, 0, 0, 0, 8};
    struct TreeNode *headL1 = tree_convert(testL1, sizeof(testL1) / sizeof(testL1[0]));
    int resL1 = deepestLeavesSum(headL1);
    printf("Test From Leetcode.com #1 | Correct: 15 | Actual: %d\n", resL1);
}

// should have this signature for Leetcode compatibility
int deepestLeavesSum(struct TreeNode *root)
{
    int i = 0;
    return helper(root, &i);
}

int helper(struct TreeNode *root, int *depth)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return root->val;

    int leftDepth = *depth + 1;
    int rightDepth = *depth + 1;

    int leftSum = helper(root->left, &leftDepth);
    int rightSum = helper(root->right, &rightDepth);

    if (leftDepth == rightDepth)
    {
        // can be set to rightSum, no difference since these values are equal
        *depth = leftDepth;
        return leftSum + rightSum;
    }
    else if (leftDepth > rightDepth)
    {
        *depth = leftDepth;
        return leftSum;
    }
    else
    {
        *depth = rightDepth;
        return rightSum;
    }
}

struct TreeNode *tree_convert(int *array, size_t size)
{
    return tree_convert_helper(array, size, 0);
}

static struct TreeNode *tree_convert_helper(int *array, size_t array_size, size_t idx)
{
    // 0 converted to NULL
    if (idx >= array_size || array[idx] == 0)
        return NULL;

    struct TreeNode *head = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    head->val = array[idx];
    head->left = tree_convert_helper(array, array_size, 2 * idx + 1);
    head->right = tree_convert_helper(array, array_size, 2 * idx + 2);

    return head;
}