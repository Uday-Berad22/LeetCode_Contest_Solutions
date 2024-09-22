class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& wt) {
            priority_queue <pair<long long,long long > , vector<pair<long long,long long>  >, greater<pair<long long,long long > > > pq;
            for(auto num: wt) {
                pq.push({num,1});
            }
            long long ans=0;
            while(mountainHeight>0){
                long long tp= pq.top().first;
                long long  tt=pq.top().second;
                ans=tp;
                pq.pop();
                mountainHeight--;
                long long sum=(tt*(tt+1))/2;
                long long ori=tp/sum;
                tt++;
                long long nsum=(tt*(tt+1))/2;
                pq.push({ori*nsum,tt});
                
            }
            return ans;
    }
};