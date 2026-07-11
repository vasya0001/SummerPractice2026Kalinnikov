#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
 
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
 
    vector<int> left(n), right(n);
    stack<int> s;
 
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && b[s.top()] <= b[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
 
    while (!s.empty()) s.pop();
 
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && b[s.top()] < b[i]) s.pop();
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        long long l_dist = i - left[i];
        long long r_dist = right[i] - i;
        count += b[i] * l_dist * r_dist;
    }
    cout << count << endl;
 
    return 0;
}
