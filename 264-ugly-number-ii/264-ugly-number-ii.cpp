class Solution {
public:
    int nthUglyNumber(int n) {
        set<uint64_t> st;
        st.emplace(1);
        
        while (n > 0) {
            n--;
            uint64_t x = *st.begin();
            st.erase(st.begin());
            
            if (n == 0)
                return x;
            
            for (auto &p : {2, 3, 5})
                st.emplace(x * p);
        }
        
        assert(false);
    }
};