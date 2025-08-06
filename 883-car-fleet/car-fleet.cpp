class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars(position.size());
        stack<double> fleets;
        for(int i=0;i<position.size();i++){
            cars[i].first=position[i];
            cars[i].second=double(target-position[i])/(speed[i]);
        }
        sort(cars.rbegin(),cars.rend());

        for(int i=0;i<position.size();i++){
            if(fleets.empty()||fleets.top()<cars[i].second){
                fleets.push(cars[i].second);
            }

        }
        return fleets.size();
    }
};