#include <stdlib.h>
#include "treenode.h"

static struct TreeNode *tree_convert_helper(int *array, size_t array_size, size_t idx);

struct TreeNode *tree_convert(int *array)
{
    size_t array_size = sizeof(array) / sizeof(array);
    return tree_convert_helper(array, array_size, 0);
}

static struct TreeNode *tree_convert_helper(int *array, size_t array_size, size_t idx)
{
    // 0 converted to NULL
    if (idx >= array_size || array[idx] == 0)
        return NULL;

    struct TreeNode* head = (struct TreeNode*) malloc(sizeof(struct TreeNode));

    head->val = array[idx];
    head->left = tree_convert_helper(array, array_size, 2 * idx + 1);
    head->right = tree_convert_helper(array, array_size, 2 * idx + 2);

    return head;
}