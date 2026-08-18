class Solution {
public:
    long long fuel;
    int car(vector<vector<int>>& adj, int i, int parent, int& seats){
        int cars = 1;
        for(int ele: adj[i]){
            if(ele==parent) continue;
            cars += car(adj, ele, i, seats);
        }
        fuel += ceil((double)cars/seats);
        return cars;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        fuel = 0;
        vector<vector<int>> adj(n);
        for(auto ele: roads){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        for(int ele: adj[0]){
            car(adj, ele, 0, seats);
        }
        return fuel;

    }
};