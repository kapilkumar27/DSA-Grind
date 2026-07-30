class Solution {
public:
    vector<int> prevSmall(vector<int>& heights, int &n){
        vector<int> prev(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        return prev;
    }
    vector<int> nextSmall(vector<int>& heights, int &n){
        vector<int> next(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }
            st.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> prev(n);
        vector<int> next(n);
        prev=prevSmall(heights,n);
        next=nextSmall(heights,n);
        int maxA=0;
        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            int area=width*heights[i];
            maxA=max(maxA,area);
        }
        return maxA;
    }
};