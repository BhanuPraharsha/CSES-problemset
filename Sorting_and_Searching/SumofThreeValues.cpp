#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    long long x;
    cin >> n >> x;
 
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; 
    }
 
    sort(a.begin(), a.end());
 
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            
            long long target_value = x - a[i].first - a[j].first;
 
            auto it = lower_bound(a.begin() + j + 1, a.end(), make_pair((int)target_value, 0));
 
            if (it != a.end() && it->first == target_value) {
                
                cout << a[i].second << " " << a[j].second << " " << it->second << endl;
                return 0; 
            }
        }
    }
 
    cout << "IMPOSSIBLE\n";
 
    return 0;
}
