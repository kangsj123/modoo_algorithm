class Solution {
// time complexity : O(N+E)
// space complexity : O(N)
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int sz=rooms.size();

        vector<bool>visit;
        visit.resize(sz,false);
        
        queue<int>qu;
        qu.push(0);
        visit[0]=true;
        
        while(!qu.empty()){
            int node=qu.front();
            qu.pop();
            
            for(int i:rooms[node]){
                if(!visit[i]){
                    qu.push(i);
                    visit[i]=true;
                }
            }
        }
        
        for(int i=0;i<sz;i++){
            if(!visit[i])
                return false;
        }
        
        return true;
    }
};
