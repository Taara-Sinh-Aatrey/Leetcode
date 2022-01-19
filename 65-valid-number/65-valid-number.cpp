class Solution {
public:
    bool isNumber(string s) {
        
        // an integer or a decimal can't be empty
        if (s.empty())
            return false;
        
        int ce = count(s.begin(), s.end(), 'e');
        int cE = count(s.begin(), s.end(), 'E');
        
        string first = s, last = "";
        
        if (ce + cE == 1) {
            int p = find(s.begin(), s.end(), ce == 1 ? 'e' : 'E') - s.begin();
            first = s.substr(0, p);
            last = s.substr(p + 1);
        }
        
        if (!first.empty() && (first.front() == '+' || first.front() == '-'))
            first = first.substr(1);
        
        if (!last.empty() && (last.front() == '+' || last.front() == '-'))
            last = last.substr(1);
        
        int cdot = count(first.begin(), first.end(), '.');
        if (cdot > 1 or first == ".") {
            return false;
        }
        
        if (first.empty() || (ce + cE == 1 && last.empty())) {
            return false;
        }
        
        for (char ch : first) {
            if ((ch < '0' || ch > '9') && ch != '.') {
                return false;
            }
        }
        
        for (char ch : last) {
            if ((ch < '0' || ch > '9')) {
                return false;
            }
        }
        
        return true;
    }
};