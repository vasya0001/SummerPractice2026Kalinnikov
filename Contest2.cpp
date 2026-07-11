#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    if (!(std::cin >> n)) return 0;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    long long count = 0;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int sum = a[i] + a[j];
            
            auto it = std::lower_bound(a.begin() + j + 1, a.end(), sum);
            
            count += (std::distance(a.begin() + j + 1, it));
        }
    }
 
    std::cout << count << std::endl;
 
    return 0;
}