#include <iostream>
#include <vector>
using namespace std;

// source: https://leetcode.com/problems/beautiful-arrangement-ii

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> result(n);
        vector<bool> taken(n);

        // set first elem
        result[0] = 1;
        taken[0] = true;

        for (int i = 1; i < n; i++)
        {
            if (k == 0)
            {
                result[i] = i + 1;
                continue;
            }

            int val = result[i - 1] - k;
            if (val < 1 || taken[val - 1])
                val = result[i - 1] + k;

            k--;
            result[i] = val;
            taken[val - 1] = true;
        }

        return result;
    }
};

int main(void)
{
    Solution sol;
    vector<int> res = sol.constructArray(20, 10);

    printf("\n");
    for (size_t i = 0; i < res.size(); i++)
        printf("%d ", res[i]);

    printf("\n");

    return 0;
}
