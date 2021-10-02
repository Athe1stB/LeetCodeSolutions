#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,x;
    cin>>t;
    while(t--)
    {
        cin>>x;
        if(x==0)
        {
            cout<<1<<endl;
            continue;
        }
        int ans=-1;
        for(int i=31;i>=0;i--)
        {
            if(((1<<i)&x) == x)
            {
                ans=x;
                break;
            }
            if((1<<i)==x+1)
            {
                ans=x+1;
                break;
            }
        }
        if(ans==-1)
            for(int i=31;i>=0;i--)
                if(((1<<i)&x) >0)
                {
                    ans=(1<<i);
                    break;
                }
        cout<<ans<<endl;
    }
}
