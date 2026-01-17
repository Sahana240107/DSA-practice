/*Intersection of unsorted arrays*/
vector<int> intersection(vector<int>& a, vector<int>& b) {
    unordered_set<int> st(a.begin(), a.end());
    vector<int> ans;

    for (int x : b) {
        if (st.find(x) != st.end()) {
            ans.push_back(x);
            st.erase(x); // avoid duplicates
        }
    }

    return ans;
}
