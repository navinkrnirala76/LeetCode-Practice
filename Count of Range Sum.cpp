#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// #define int long long
#define pi pair<int , int>
#define ppi pair<pi ,int>

// int INF = INT64_MAX;
int mod = 1e9+7;

typedef tree<long long,null_type,less_equal<long long> ,rb_tree_tag,tree_order_statistics_node_update> pbds;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int l, int r) {
        long long n = nums.size();
        vector<long long> pref(n+1, 0);
        for(int i=0;i<n;i++)pref[i+1] = pref[i] + nums[i];
        pbds p1;
        long long ans = 0;
        map<long long , int> mp;
        for(int i=n-1;i>=0;i--)
        {
            p1.insert(pref[i+1]);
            mp[pref[i+1]]++;
            long long updt_l = (long long)pref[i] + l , updt_r = (long long)pref[i] + r;
            long long less1 = (long long)p1.order_of_key(updt_l);
            long long less2 = (long long)p1.order_of_key(updt_r);
            ans += (mp[updt_r] + less2 - less1);
        }
        return ans;
    }
};
