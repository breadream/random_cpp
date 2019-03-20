    string addStrings(string num1, string num2) {
        int carry = 0;
        size_t i = 0;
        size_t j = 0;
        string res;
        while (i < num1.size() || j < num2.size() || carry)
        {
            int temp = carry;
            if (i < num1.size())
                temp += (num1[num1.size()-1 - i++] - '0');
            if (j < num2.size())
                temp += (num2[num2.size()-1 - j++] - '0');
            
            res = std::to_string(temp % 10) + res;
            carry = temp / 10;
        }
        
        return res;
    }
