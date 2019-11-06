//Using Stack (O(N)/O(N))
class Solution {
public:
    int largestRectangleArea2(vector<int>& heights) {        
        int ans=0;
        int sz=heights.size();
        stack<pair<int,int>>st;

        heights.push_back(0);
        
        for(int i=0;i<=sz;i++){
            int h=heights[i];
            int h_indx=i;
            
            while(!st.empty() && st.top().first>h){                
                int top_val=st.top().first;
                int top_indx=st.top().second;
                int rec=top_val*(i-top_indx);
                if(rec>ans)
                    ans=rec;
                
                h_indx=top_indx;
		st.pop();
            }
            st.push(make_pair(heights[i],h_indx));
        }
        return ans;
    }
};



//Using SegmentTree (O(NlogN)/O(N))
#define mid ((begin+end)>>1)
#define l_node (node<<1)
#define r_node (l_node+1)
#define INF 0x7fffffff
class Solution {
public:
    vector<int> tree;
    int largestRectangleArea1(vector<int>& heights) {
        
        int sz=heights.size();
        tree.resize(sz<<2);
        
        if(sz==0)return 0;
        
        init(1,0,sz-1,heights);
        
        queue<pair<int,int>> qu;
        qu.push(make_pair(0,sz-1));
        
        int max=0;
        while(!qu.empty()){
            int st=qu.front().first;
            int end=qu.front().second;
            qu.pop();
            
            int indx=query(1,0,sz-1,st,end,heights);
            int area=(end-st+1)*heights[indx];
            if(area>max)
                max=area;
            if(st<=indx-1)
                qu.push(make_pair(st,indx-1));
            if(indx+1<=end)
                qu.push(make_pair(indx+1,end));    
        }
        return max;
    }
    
    int init(int node, int begin, int end,vector<int>&arr) {
        if (begin == end) return tree[node] = begin;
        int l = init(l_node, begin, mid,arr);
        int r = init(r_node, mid+1, end,arr);
        
        if(l == INF)return r;
        if(r == INF)return l;
        return tree[node] = arr[l]<arr[r]?l:r;
    }
    
    int query(int node, int begin, int end, int l_pos, int r_pos,vector<int>&arr) {
        if (r_pos < begin || end < l_pos) return INF;
        if (l_pos <= begin && end <= r_pos) return tree[node];
        int l = query(l_node, begin, mid, l_pos, r_pos,arr);
        int r = query(r_node, mid+1, end, l_pos, r_pos,arr);
        
        if(l == INF)return r;
        if(r == INF)return l;
        return arr[l]<arr[r]?l:r;
    }
};
