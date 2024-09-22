class Solution {
public:
    long long validSubstringCount(string s, string t) {
        int n = s.size();
        vector<int> m(26, 0);  
        vector<int> window_freq(26, 0); 

        for (char c : t) {
            m[c - 'a']++;
        }
        
        int left = 0;  
        long long count = 0; 
        int needed_chars = t.size();  

        for (int right = 0; right < n; ++right) {
            
            char current_char = s[right];
            window_freq[current_char - 'a']++;

            if (window_freq[current_char - 'a'] <= m[current_char - 'a']) {
                needed_chars--;
            }

            while (needed_chars == 0) {
                count += (n - right);  

                char left_char = s[left];
                window_freq[left_char - 'a']--;
                
                if (window_freq[left_char - 'a'] < m[left_char - 'a']) {
                    needed_chars++;
                }
                
                left++;  
            }
        }
        
        return count;
    }
};
