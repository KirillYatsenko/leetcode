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
            push(st, idx, count);
            count = 1;
            idx = i;
            continue;
        }

        if (count == k)
        {
            strncpy((s + idx), (s + i + 1), slen - i - 1);
            slen -= count;

            if (st.empty())
                break;

            StackElem prev = st.top();
            st.pop();

            i = idx - 1;
            idx = prev.idx;
            count = prev.count;
        }
    }

    s[slen] = '\0';
    return s;
}

int main(void)
{
    char strA[] = "pioois";
    removeDuplicates(strA, 2);
    printf("strA = %s\n", strA);

    char strB[] = "piooaais";
    removeDuplicates(strB, 2);
    printf("strB = %s\n", strB);

    char strC[] = "a";
    removeDuplicates(strC, 2);
    printf("strC = %s\n", strC);

    char strD[] = "aa";
    removeDuplicates(strD, 2);
    printf("strD = %s\n", strD);

    char strE[] = "eee";
    removeDuplicates(strE, 2);
    printf("strE = %s\n", strE);

    char str0[] = "aaab";
    removeDuplicates(str0, 2);
    printf("str0 = %s\n", str0);

    char str[] = "deeedbbcccbdaa";
    removeDuplicates(str, 3);
    printf("str = %s\n", str);

    char str1[] = "abcd";
    removeDuplicates(str1, 2);
    printf("str1 = %s\n", str1);

    char str2[] = "pbbcggttciiippooaais";
    removeDuplicates(str2, 2);
    printf("str2 = %s\n", str2);

    return 0;
}