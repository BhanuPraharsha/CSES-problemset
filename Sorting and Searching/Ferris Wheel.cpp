#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    // int t;
    // cin>>t;
 
    for(int i=0;i<1;i++)
    {
        long int n,x;
        cin>>n>>x;
        vector<long int> a(n);
        
        for(long int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        
        sort(a.begin(), a.end());
        
        long int count=0;
        long int start=0;
        long int end=n-1;
        
 
        while(start<n)
        {
 
            if(start==end)
            {
                if(a[start]<=x)
                {
                    count++;
                }
                break;
            }
 
 
 
                auto it=upper_bound(a.begin()+start, a.begin()+end+1, x-a[start]);
                if(it==a.begin()+start)
                {
                    count+=end-start+1;
                    break;
                }
                else {
                    it--;
                    long long idx=it-a.begin();
 
                    count++;
                    
                    count+=end-idx;
 
                    start++;
                    end=idx-1;    
                }
        }
                    
        cout<<count<<endl;
    }
                
    return 0;
}

