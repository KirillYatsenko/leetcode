// source: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

#include <stdio.h>
#include <stack>
#include <string.h>

using namespace std;

class StackElem
{
public:
    int idx;
    int count;
};

void push(stack<StackElem> &st, int idx, int count)
{
    StackElem elem;
    elem.idx = idx;
    elem.count = count;

    st.push(elem);
}

char *removeDuplicates(char *s, int k)
{
    stack<StackElem> st;
    int slen = strlen(s);

    int count = 0;
    int idx = 0;

    for (size_t i = 0; i < slen; i++)
    {
        if (s[i] == s[idx])
        {
            count++;
        }
        else
        {
            if (count >= k)
            {
                strncpy((s + idx), (s + i), slen - i);
                slen -= count;

                if (st.empty())
                    break;

                StackElem prev = st.top();
                st.pop();

                i = idx - 1;
                idx = prev.idx;
                count = prev.count;
            }
            else
            {
                push(st, idx, count);
                count = 1;
                idx = i;
            }
        }
    }

    s[slen] = '\0';
    return s;
}

int main(void)
{
    char str[] = "deeedbbcccbdaa";
    removeDuplicates(str, 3);
    printf("%s\n", str);

    char str1[] = "abcd";
    removeDuplicates(str1, 2);
    printf("%s\n", str1);

    char str2[] = "pbbcggttciiippooaais";
    removeDuplicates(str2, 2);
    printf("%s\n", str2);

    return 0;
}