class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans (n+1,0);
        int lstpw=1;
        for(int i =1;i<=n;i++){
            if(lstpw==i-lstpw){
                ans[i]=1;
                lstpw=i;
            }
            else{
            ans[i]=1+ans[i-lstpw];                
            }
        }
        return ans;
    }
};