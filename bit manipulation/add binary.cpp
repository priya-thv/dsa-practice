class Solution {
public:
    string addBinary(string a, string b) {
        string r="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }
            carry = sum / 2; // Calculate carry for next step
            r.push_back(sum % 2 + '0'); // Append the current bit to result
        }
        reverse(r.begin(),r.end());
        return r;
    }
};
