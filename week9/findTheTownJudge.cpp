class Solution {
public:
    //time complexity : O(N+E)
    //space complexity : O(N+E)
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<bool>hasOutdegree;
        vector<int>indegree;
        
        hasOutdegree.resize(N+1,false);
        indegree.resize(N+1,0);
        
        for(vector<int> adj:trust){
            hasOutdegree[adj[0]]=true;
            indegree[adj[1]]++;
        }
        
        for(int i=1;i<=N;i++){
            if(!hasOutdegree[i] && indegree[i]==N-1)
                return i;
        }
        return -1;
    }
};
