class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int sz=asteroids.size();
        vector<int>st;
        
        for(int i=0;i<sz;i++){
            int ast=asteroids[i];
            
            if(ast>0){
                st.push_back(ast);
            }
            else{
                while(!st.empty() && ast<0 && st.back()>0){
                    int top_ast=st.back();
                    st.pop_back();
                    
                    if(-ast<top_ast)
                        ast=top_ast;
                    else if(-ast==top_ast)
                        ast=0;
                }
                if(ast!=0)
                    st.push_back(ast);
            }
        }
        return st;
    }
};
