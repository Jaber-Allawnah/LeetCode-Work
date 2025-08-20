class Solution {
public:

    int maxRepeating(string sequence, string word) {
        int L=word.length();
        int n = sequence.length();
        int ans=0;
        for(int i=0;i<n;i++){
        int count=0;
            
            while(i+(count+1)*L<=n&&sequence.compare(i+count*L,L,word)==0)
            {
                count++;
            }
            if(count>ans){
                ans=count;
            }
        }
        return ans;
    }
};