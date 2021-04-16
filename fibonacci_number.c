// source: https://leetcode.com/problems/fibonacci-number/

#include <stdlib.h>
#include <stdio.h>

int greedy(int n, int *memo)
{
    if (n <= 1)
        return n;

    if (memo[n] != 0)
        return memo[n];

    int fib = greedy(n - 1, memo) + greedy(n - 2, memo);
    memo[n] = fib;

    return fib;
}

int fib(int n)
{
    int *memo = (int *)calloc(n + 1, sizeof(int));
    return greedy(n, memo);
}

void main(void)
{
    // Test1
    int n = 30;
    int res = fib(n);
    printf("fib(%d) = %d\n", n, res);
}