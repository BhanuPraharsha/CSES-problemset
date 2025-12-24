#include<bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    long long x;
    cin >> n >> x;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    vector<tuple<long long, int, int>> b;
    b.reserve((long long)n * (n - 1) / 2);
    
    for(int j=0; j<n; j++) {
        for(int k=j+1; k<n; k++) {
            b.emplace_back((long long)a[j] + a[k], j, k);
        }
    }
    
    sort(b.begin(), b.end());
    
    int left=0;
    int right=b.size()-1;
    
    while(left<right) {
        long long csum = get<0>(b[left]) + get<0>(b[right]);
        
        if(csum < x) {
            left++;
        } else if(csum > x) {
            right--;
        } else {
            int temp_right = right;
            while (temp_right > left && get<0>(b[temp_right]) == get<0>(b[right])) {
                int i1 = get<1>(b[left]);
                int i2 = get<2>(b[left]);
                int i3 = get<1>(b[temp_right]);
                int i4 = get<2>(b[temp_right]);
 
                if (i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4) {
                    cout << i1 + 1 << " " << i2 + 1 << " " << i3 + 1 << " " << i4 + 1 << endl;
                    return 0;
                }
                temp_right--; 
            }
 
            left++;
        }
    }
    
    cout << "IMPOSSIBLE\n";
 
    return 0;
}
