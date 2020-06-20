#include "bits/stdc++.h"
using namespace std;
#define N 600
int J, K, n, s[N], e = 500, maxJedi, ans;
int jedi(int x)
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
        if ((s[i] >= K && jedi(s[i]) - jedi(s[i] - K) > maxJedi))
        {
            e = i;
            maxJedi = jedi(s[i]) - jedi(s[i] - K);
        }
    }
    if (e == 500)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] > s[e])
            {
                e = i;
            }
        }
    }
    s[e] = max(0, s[e] - K);
    for (int i = 0; i < n; i++)
    {
        ans += jedi(s[i]);
    }
    cout << ans << endl;
    return 0;
}