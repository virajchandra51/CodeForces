#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        // taking input

        sort(s.begin(), s.end()); // O(nlogn)

        vector<char> answerCharacters(n);
        int left = 0;
        int right = n - 1;

        for (int i = 0; i < n; i += 2) // ~ O(n)
        {
            if (i == n - 1)
            {
                answerCharacters[left] = s[i];
            }
            else if (s[i] == s[i + 1])
            {
                answerCharacters[left] = s[i];
                answerCharacters[right] = s[i];
                left++;
                right--;
            }
            else
            {
                if (s[i + 1] == s[n - 1])
                {
                    int len = n - i - 1;
                    int firstHalf = ceil(len / 2.0);
                    int secondHalf = len - firstHalf;
                    while (firstHalf--)
                    {
                        answerCharacters[left] = s[i + 1];
                        left++;
                    }
                    answerCharacters[left] = s[i];
                    while (secondHalf--)
                    {
                        answerCharacters[right] = s[i + 1];
                        right--;
                    }
                    break;
                }
                else
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        answerCharacters[left] = s[j];
                        left++;
                    }
                    answerCharacters[right] = s[i];
                    break;
                }
            }
        }
        string answer = "";
        for (auto it : answerCharacters)
            answer += it;
        cout << answer << endl;
    }
    return 0;
}

// TC - O(nlogn+n) ~ O(nlogn)
// SC - O(n)