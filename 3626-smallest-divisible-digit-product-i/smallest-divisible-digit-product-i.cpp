class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int temp=n;
            int p=1;
            while(temp>0){
                int rem=temp%10;
                p*=rem;
                temp=temp/10;
            }
            if(p%t==0){
                return n;
            }
            n++;
        }
        return -1;
    }
};