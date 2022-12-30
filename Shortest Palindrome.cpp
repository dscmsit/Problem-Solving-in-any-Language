// Shortest Pallindrome Brute Force

bool isPal(string s)
{
    string p = s;
    reverse(p.begin(), p.end());
    if (s == p)
        return true;
    return false;
}
string shortestPalindrome(string s)
{
    if (isPal(s))
        return s;
    int n = s.size();
    int k = 0, maxIdx = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isPal(s.substr(k, i)))
            maxIdx = i - 1;
    }
    string r = "";
    for (int i = maxIdx + 1; i < n; i++)
        r += s[i];
    reverse(r.begin(), r.end());
    s = r + s;
    return s;
}