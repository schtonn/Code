#include "bits/stdc++.h"
using namespace std;
#define N 121
int J, K, n, s[N], e = -1, maxMuck, ans;
int muck(int x)
{
    return x / J + (x % J ? 1 : 0);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    cin >> K >> J;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= K) && (muck(s[i]) - muck(s[i] - K) > maxMuck))
        {
            e = i;
            maxMuck = muck(s[i]) - muck(s[i] - K);
        }
    }
    if (e == -1)
    {
        e = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] >= s[e])
            {
                e = i;
            }
        }
    }
    // s[e] = max(0, s[e] - K);
    for (int i = 0; i < n; i++)
    {
        ans += muck(s[i]);
    }
    cout << ans - maxMuck << endl;
    return 0;
}
/*

*/