class Solution {
public:
    
    vector<string> generate(int n) {
        if(n == 1) return {"0", "1"};
        
        vector<string> binary = generate(n - 1);
        vector<string> result = {};
        int len = binary.size();
        
        for(int i = 0; i < len ; i++) {
            result.push_back("0" + binary[i]);
        }
        for(int i = len -1; i >= 0; i--) {
            result.push_back("1" + binary[i]);
        }
        return result;
    }
    
    vector<int> grayCode(int n) {
        if(n == 1) return {0, 1};
        
        vector<string> store = generate(n);
        vector<int> result = {};
        
        for(auto s : store)
            result.push_back(stoi(s, 0, 2));
    
        return result;
    }
};