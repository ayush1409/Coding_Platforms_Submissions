/*
    Problem : We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string s.  Return a list of strings representing all possibilities for what our original coordinates could have been.
    Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".
    The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)

    Example 1:
    Input: s = "(123)"
    Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]

    Example 2:
    Input: s = "(00011)"
    Output:  ["(0.001, 1)", "(0, 0.011)"]
    Explanation: 
    0.0, 00, 0001 or 00.01 are not allowed.
    
    Example 3:
    Input: s = "(0123)"
    Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
    
    Example 4:
    Input: s = "(100)"
    Output: [(10, 0)]
    Explanation: 
    1.0 is not allowed.

    Note:
    4 <= s.length <= 12.
    s[0] = "(", s[s.length - 1] = ")", and the other elements in s are digits.
*/
class Solution {
public:
    vector<string> result, xPoss;
    
    void parseString(string str, int xy) {
        if (str.size() == 1 || str.front() != '0')
            processString(str, xy);
        if (str.size() > 1 && str.back() != '0')
            processString(str.substr(0,1) + "." + str.substr(1), xy);
        if (str.size() > 2 && str.front() != '0' && str.back() != '0')
            for (int i = 2; i < str.size(); i++)
                processString(str.substr(0,i) + "." + str.substr(i), xy);
    }
    
    void processString(string str, int xy) {
        if (xy != 0)
            for (auto x : xPoss)
                result.push_back("(" + x + ", " + str + ")");
        else xPoss.push_back(str);
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> temp(S.size(), "0") ;
        
        for (int i = 2; i < S.size() - 1; i++) {
            string strs[2] = {S.substr(1,i-1), S.substr(i,S.size()-i-1)};
            xPoss.clear();
            for (int j = 0; j < 2; j++)
                if (xPoss.size() || !j) parseString(strs[j], j);
        }
        return result;
    }
    
};