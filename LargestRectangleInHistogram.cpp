int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st;
    st.push(-1);
    int i, n = A.size(), ans = -1, l, r;
    if(n == 0) return 0;
    if(n == 1) return A[0];
    for(i = 0; i<n; ++i) {
        while(st.top() >= 0 && A[st.top()]>A[i]) {
            r = st.top();
            st.pop();
            l = i-st.top()-1;
            ans = max(ans, l*A[r]);
        }
        st.push(i);
    }
    while(st.top() >= 0) {
        r = st.top();
        st.pop();
        l = i-st.top()-1;
        ans = max(ans, l*A[r]);
    }
    return ans;
}

