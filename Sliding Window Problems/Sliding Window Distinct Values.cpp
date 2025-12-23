#include<bits/stdc++.h>
using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin>>arr[i];

    map<int, int> freq;
    int ans = 0;

    for (int i = 0; i < k; i++) {
        if (freq[arr[i]] == 0) ans++;
        freq[arr[i]]++;
    }
    cout<<ans;

    for (int i = k; i < n; i++) {
        int out_val = arr[i - k];
        freq[out_val]--;
        if (freq[out_val] == 0) {
            ans--;
        }

        int in_val = arr[i];
        if (freq[in_val] == 0) ans++;
        freq[in_val]++;

        cout<<" "<<ans;
    }
    cout<<"\n";

    return 0;
}
