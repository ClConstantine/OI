// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        
        vector<int> ans;
        
        ans.push_back(1);
        
        for(int i = 2;i <= N;++i){
            int l = 0,r = i - 2,mid;
            
            while(l < r){
                mid = (l + r) >> 1;
                
                if(compare(i,ans[mid]) ){
                    r = mid;
                }
                else  l = mid + 1;
            }
            ans.insert(ans.begin() + r,i);
            
            if(!compare(i,ans[r + 1])){
                  swap(ans[r],ans[r + 1]);
            }
            
        }
        
        return ans;
    }
};