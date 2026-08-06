class Solution {
public:
    bool search(vector<int>& arr, int tar) {
        int st=0, end=arr.size()-1;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(arr[mid]==tar){
                return true;
            }

            if (arr[st] == arr[mid] && arr[mid] == arr[end]) {
                st++;
                end--;
                continue;
            }
            if(arr[st]<=arr[mid]){
                if( arr[st]<= tar && tar <= arr[mid]){
                    end=mid-1;
                }
                else{
                    st=mid+1;
                }
            }
            else {
                if(arr[mid]<= tar && tar <= arr[end]){
                    st=mid+1;
                }
                else{
                    end= mid-1;
                }
            }
        }
        return false;
    }
};