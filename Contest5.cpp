#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long power(long long base, long long exp) {
    long long res = 1;
    long long mod = 1e9 + 7;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
long long modInverse(long long n) {
    return power(n, 1e9 + 7 - 2);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    string s;
    cin >> s;
    int n = s.length();
    long long mod = 1e9 + 7;
    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'a']++;
    }
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    long long ans = fact[n];
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 1) {
            ans = (ans * modInverse(fact[counts[i]])) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}