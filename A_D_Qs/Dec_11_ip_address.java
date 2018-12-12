class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList();
        helper(result, "", s, 0);
        return result;    
    }
    private void helper (List<String> result, String ip, String s, int count) {
        if (s.isEmpty() || count == 4){
            if (s.isEmpty() && count == 4)
                result.add(ip);  
            return;
        }
        for (int i = 1; i <= (s.charAt(0) == '0' ? 1 : 3) && i <= s.length(); i++) { // eliminate leading 0
            String part = s.substring(0, i); // begin(inclusive), end(exclusive)
            if (Integer.valueOf(part) <= 255)
                helper(result, ip + ((count == 0) ? "" : ".") + part, s.substring(i), count+1);
        }
    }
}
