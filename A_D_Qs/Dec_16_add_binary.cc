class Solution {
public:
    string addBinary(string a, string b) {
        string str = "";
        int i = a.length()-1, j = b.length()-1, carry = 0;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int A = i >= 0 ? a[i]-'0' : 0;
            int B = j >= 0 ? b[j]-'0' : 0;
            str += (A ^ B ^ carry) + '0';
            carry = (A&B) || (A&carry) || (B&carry);
            i--,j--;
        }
        std::reverse(str.begin(), str.end());
        return str;
    }
};
