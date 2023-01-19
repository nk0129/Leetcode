class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k){ 
        int res=0;
    unordered_map<int,int> mp;
    
    mp[0]=1;
    int sum=0;
    int rem=0;
    
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
        rem=sum%k;
        
        if(rem<0)
            rem+=k;
        
        if(mp.find(rem)!=mp.end())
        {
            res+=mp[rem];
            //mp[rem]+=1;
        }
      //  else
            mp[rem]++;
    }
    return res;
}
};