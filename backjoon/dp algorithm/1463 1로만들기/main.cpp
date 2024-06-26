#include<iostream>

using namespace std;

int N;
int i, j;
int cnt;
int max_answer = 0;
int dp[1000001];

int min(int a, int b)
{
    if(a < b)
        return a;

    else if(a == b)
        return a;
    else
        return b;
}

void solve()
{
    dp[0] = 0;
    dp[1] = 0;

    cin >> N;

    for(int i=2; i<=N; i++)
    {
        dp[i] = dp[i-1] + 1;
        if(i%2 == 0)dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3 == 0)dp[i] = min(dp[i], dp[i/3]+1);
    }

    cout << dp[N];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();
    


    return 0;
}