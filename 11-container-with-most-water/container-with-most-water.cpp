class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int i=0,j=height.size()-1;
        while(i<height.size()&&i<=j&&j>=0){
            int temp=(j-i)*min(height[i],height[j]);
            if(height[i]<height[j])
            i++;
            else 
            j--;
            if(temp>area)
            area=temp;
        }
        return area;
    }
};