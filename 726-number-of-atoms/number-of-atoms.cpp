class Solution {
public:
    string countOfAtoms(string s) {
        int n = s.size();
        stack<map<string, int>> st;
        map<string, int> current;
        
        for (int i = 0; i < n;) {
            if (s[i] == '(') {
                st.push(current);
                current.clear();
                i++;
            } else if (s[i] == ')') {
                int j = i + 1;
                while (j < n && isdigit(s[j])) j++;
                int multiplicity = (j == i + 1) ? 1 : stoi(s.substr(i + 1, j - i - 1));
                i = j;

                if (!st.empty()) {
                    auto temp = current;
                    current = st.top();
                    st.pop();
                    for (auto& p : temp) {
                        current[p.first] += p.second * multiplicity;
                    }
                }
            } else {
                int j = i + 1;
                while (j < n && islower(s[j])) j++;
                string name = s.substr(i, j - i);
                i = j;
                while (j < n && isdigit(s[j])) j++;
                int multiplicity = (j == i) ? 1 : stoi(s.substr(i, j - i));
                i = j;
                current[name] += multiplicity;
            }
        }
        
        string result;
        for (auto& p : current) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        return result;
    }
};

