#include <string>
#include <iostream>
using namespace std;

int main() {
    string ans =
        "ABCBCCABCBDBDCC"
        "FTTFDA"
        "TTTTDA"
        "FTTFBD"
        "CBBAC"
        "DBDBC";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ans =
        "ABCBACABCBDBACD"
        "FTTTBA"
        "FFTTAA"
        "FFFTCC"
        "CDDAC"
        "CBDCB";
    int no;
    cin >> no;
    cout << ans[no - 1];
    return 0;
}
*/