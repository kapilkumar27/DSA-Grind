class Solution {
public:
    string helper(const string &s){
        int n=s.size();
        if(n<=1){
            return s;
        }
        string temp=s+s;
        int p=0;
        int q=1;
        int r=0;
        while(p<n && q<n && r<n){
            if(temp[p+r]==temp[q+r]){
                r++;
            }
            else if(temp[p+r]>temp[q+r]){
                p=p+r+1;
                if(p<=q){
                    p=q+1;
                }
                r=0;
            }
            else{
                q=q+r+1;
                if(q<=p){
                    q=p+1;
                }
                r=0;
            }
        }
        int st=min(p,q);
        return temp.substr(st,n);
    }
    
    int minimumGroups(vector<string>& words) {
        unordered_set<string> set1;
        for(string &a:words){
            string tempE="";
            string tempO="";
            for(int i=0;i<a.size();i++){
                if(i%2==0){
                    tempE+=a[i];
                }
                else{
                    tempO+=a[i];
                }
            }
            string ans=helper(tempE)+"#"+helper(tempO);
            set1.insert(ans);
        }
        return set1.size();
    }
};