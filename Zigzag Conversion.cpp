class Solution {
public:
    string convert(string s, int numRows) {
    if (numRows == 1 || s.length() <= numRows) {
        return s;
    }

    vector<string> rows(numRows, "");
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;

        if (curRow == 0 || curRow == numRows - 1) {
            goingDown = !goingDown;
        }

        curRow += goingDown ? 1 : -1;
    }

    string result;
    for (string row : rows) {
        result += row;
    }

    return result;
}

int main() {
    string s = "PAYPALISHIRING";
    int numRows = 3;

    string converted = convert(s, numRows);

    cout << "Converted string: " << converted << endl;

    return 0;

        
    }
};
