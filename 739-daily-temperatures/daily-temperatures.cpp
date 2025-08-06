class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector <int> temps(temperatures.size(),0);
        stack <int> indices;
        for(int i=0;i<temps.size();i++){
            while(!indices.empty()&&temperatures[i]>temperatures[indices.top()]){
                int finalIndex=i-indices.top();
                temps[indices.top()]=finalIndex;
                indices.pop();                

            }
            indices.push(i);
        }
        return temps;
    }
};