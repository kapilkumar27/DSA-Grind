class Solution {
public:
    long long getSum(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }

        vector<long long> pf(n+1,0);
        for(int p=0;p<n;++p){
            pf[p+1]=pf[p]+nums[p];
        }

        vector<int> P(2*n+1,0);
        for(int q=0;q<n;++q){
            P[2*q+1]=nums[q];
        }

        int m=P.size();
        vector<int> Q(m,0);
        int c=0;
        int r=0;
        long long mx_sm=0;

        for(int p=0;p<m;++p){
            int i_m=2*c-p;
            if(r>p){
                Q[p]=min(r-p,Q[i_m]);
            }
            else{
                Q[p]=0;
            }

            while(p-1-Q[p]>=0 && p+1+Q[p]<m && P[p-1-Q[p]]==P[p+1+Q[p]]){
                Q[p]++;
            }

            if(p+Q[p]>r){
                c=p;
                r=p+Q[p];
            }

            int lin=p-Q[p];
            int rin=p+Q[p];

            int l_A=(lin%2==0)?lin+1:lin;
            int r_A=(rin%2==0)?rin-1:rin;

            if(l_A<=r_A){
                int L=(l_A-1)/2;
                int R=(r_A-1)/2;

                long long c_sum=pf[R+1]-pf[L];
                mx_sm=max(mx_sm,c_sum);
            }
        }
        return mx_sm;
    }
};