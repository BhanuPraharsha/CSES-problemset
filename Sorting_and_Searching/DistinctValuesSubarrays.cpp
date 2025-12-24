#include<bits/stdc++.h>
using namespace std;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // Robust mixing function can avoid tle from O(n) due to bad hashing in default unordered set
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        // A random seed to avoid collisions
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
 
    size_t operator()(int x) const {
        return (*this)(static_cast<uint64_t>(x));
    }
 
    size_t operator()(long long x) const {
        return (*this)(static_cast<uint64_t>(x));
    }
};
 
 
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
 
	for(int i=0;i<1;i++)
	{
		int n;
		cin>>n;
		
		vector<int> a(n);
		unordered_set<int, custom_hash> hset;
		
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		
//		hset[a[0]]=1;
		
		int left=0;
		long long int ans=0LL;
		
		for(int right=0;right<n && left<=right;)
		{
			if(hset.find(a[right])==hset.end())
			{
				ans+=(long long int)(right-left+1);
				hset.insert(a[right]);
				right++;
			}
			else{
				while(a[left]!=a[right] && left<=right)
				{
					hset.erase(a[left]);
					left++;
				}
				
				hset.erase(a[left]);
				left++;
			}
			
		}
		
		cout<<ans<<endl;	
	}	
	return 0;
}

