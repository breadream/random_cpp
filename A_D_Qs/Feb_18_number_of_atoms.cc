class Solution {
public:
string countOfAtoms(string formula) {
    // local, global factors(outside the parentheses) , and we start from the end of the input string
    int local = 1, global = 1, i = formula.length()-1;
        stack<int> s; // contain a local factor
        map<string, int> m;
        string temp = "", ans;
        while (i >= 0) {
            if (isupper(formula[i])) { // if we encouter a uppercase character, we have a complete part 
                temp = formula[i] + temp;
                m[temp] += local * global;
                temp = "";
                local = 1;
                i--;                
            }
            else if (islower(formula[i])) { 
                temp = formula[i] + temp;
                while (islower(formula[--i])) // to find uppercase character
                    temp = formula[i] + temp;
            }
            else if (isdigit(formula[i])) { 
                local *= (formula[i] - '0');
                int j = 1;
                while (isdigit(formula[--i])) // to find a complete number
                    local += (formula[i] - '0') * std::pow(10, j++); 
            }
            else if (formula[i] == ')') { // going one level deeper 
                s.push(local); 
                global *= local; 
                local = 1;
                i--;
                cout << global << endl;
            }
            else if (formula[i] == '(') { 
                global /= s.top(); // reset the global factor
                s.pop();
                i--;
            }
        }
        for (auto & e : m) 
        {
            ans +=  e.first;
            if (e.second > 1)
                ans += to_string(e.second);
        }
        return ans;
}
};
