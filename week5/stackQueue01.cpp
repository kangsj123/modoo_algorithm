class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int sz=T.size();
        stack<int>st;
        
        for(int i=0;i<sz;i++){
            while(!st.empty() && T[st.top()]<T[i]){
                int top_index=st.top();
                T[top_index]=i-top_index;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            T[st.top()]=0;
            st.pop();
        }
        return T;
    }
};
