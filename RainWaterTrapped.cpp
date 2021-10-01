int Solution::trap(const vector<int> &A) {
    stack<int> st;
    int i, n = A.size(), ans = 0, k;
    for(i = 0; i < n; ++i) {
        while(st.size() > 1 && A[st.top()] < A[i]) {
            k = st.top();
            st.pop();
            ans += (min(A[i], A[st.top()]) - A[k]) * (i - st.top() - 1);
        }
        if(st.size() == 0 || A[st.top()] >= A[i]) 
            st.push(i);
        else {
            st.pop();
            st.push(i);
        }
    }
    return ans;
}

