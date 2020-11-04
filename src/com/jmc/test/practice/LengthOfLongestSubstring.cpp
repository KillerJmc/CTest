#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * example:
 *     01234567
 *     dvdfdvdf
 *
 *     [dv][vdf][fdv][vdf]
 *      0x  12x  34x  567
 *
 *      x stands for the repeated elements.
 *
 * @param s
 * @return lengthOfLongestSubstring
 */
static int lengthOfLongestSubstring(string s) {
    vector<char> v;
    int maxLen = 0;
    int count = 0;
    int idx = 0;

    for (int t = 0; t < s.length(); t++)
    {
        auto it = find(v.begin(), v.end(), s[t]);

        // 如果找不到
        if (it == v.end())
        {
            count++;
            v.push_back(s[t]);
            printf("找不到元素%c，放入，maxLen = %d t = %d\n", s[t], maxLen, t);
            if (t == s.length() - 1)
            {
                maxLen = max(count, maxLen);
                printf("最后maxLen = %d\n", maxLen);
            }
        }
        else
        {
            maxLen = max(count, maxLen);
            t = (int) (it - v.begin()) + idx;
            idx += (int) (it - v.begin()) + 1;
            v.clear();
            printf("找到元素%c，maxLen = %d，t = %d，idx = %d\n", s[t], maxLen, t, idx);
            count = 0;
        }
        printf("\n---------------------------------------------------\n");
    }
    return maxLen;
}

