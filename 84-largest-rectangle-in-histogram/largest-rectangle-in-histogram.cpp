class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        stack<int> indices;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!indices.empty()&&heights[i]<heights[indices.top()]){
                int height=heights[indices.top()];
                indices.pop();
                if(indices.empty()&&maxArea<height*(i))
                   maxArea=height*(i);
                else if(!indices.empty()&&maxArea<height*(i-indices.top()-1))             
                    maxArea=height*(i-indices.top()-1);
            }
        
            indices.push(i);

        }
        return maxArea;
    }
};