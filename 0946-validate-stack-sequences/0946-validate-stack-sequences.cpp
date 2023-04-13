class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int ptr = 0;
        for(int i:pushed)
        {
            st.push(i);
            while(st.size() && st.top() == popped[ptr])
            {
                st.pop();
                ptr++;
            }
        }
        
        return st.size()==0;
    }
};