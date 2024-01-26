#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count;
    cin >> count;
    queue<string> que;

    while (count)
    {
        int inp;
        cin >> inp;
        if (inp == 0)
        {
            string str;
            cin >> str;
            que.push(str);
        }
        else
        {
            if (!que.empty())
            {
                cout << que.front();
                que.pop();
            }
            else
            {
                cout << "Invalid";
            }
            cout << endl;
        }
        count--;
    }

    return 0;
}