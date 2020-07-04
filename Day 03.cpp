// Prison Cells After N Days

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        map<string, int> mp;
        vector<string> v;
        string curr;
        
        for(int i = 0; i < 256; i++) {
            curr = "";
            for(int x : cells) {
                curr += to_string(x);
            }
            
            if(mp.find(curr) != mp.end()) {
                break;
            } else {
                mp[curr] = i;
                v.push_back(curr);
            }
            vector<int> temp(8, 0);
            
            for(int i = 1; i < 7; i++) {
                if(cells[i - 1] == cells[i + 1])
                    temp[i] = 1;
            }
            cells = temp;
            if(i == n - 1)
                return cells;
        }
        
        int si = mp[curr];
        int ei = v.size();
        
        n -= si;
        int diff = ei - si;
        string ans = v[si + (n % diff)];
        
        for(int i = 0; i < 8; i++) {
            if(ans[i] == '1')
                cells[i] = 1;
            else
                cells[i] = 0;
        }
        
        return cells;
    }
};