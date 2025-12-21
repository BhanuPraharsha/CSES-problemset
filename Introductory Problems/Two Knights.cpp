#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin>>n;
 
    for (long long k = 1; k <= n; ++k) {
        long long k_s = k * k;
 
        long long tot = k_s * (k_s - 1) / 2;
 
        long long a_w = 4 * (k - 1) * (k - 2);
 
        long long n_aw = tot - a_w;
 
        cout << n_aw <<endl;
    }
 
    return 0;

