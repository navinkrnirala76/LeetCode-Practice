class Solution {
bool isIntDec(string s, bool integer = true) {
if(s.length() && (s[0]=='+'||s[0]=='-')) s = s.substr(1); // begins with sign; skip that
return s.length()>0 && // empty not OK
s.find_first_not_of(integer ? "0123456789" : ".0123456789") == string::npos // contains only numbers and optionally a dot
&& (integer || count(s.begin(), s.end(), '.')<2 && s != "."); // if not integer, contains at most 1 dot and is not only a dot
}
public:
bool isNumber(string s) {
size_t e = s.find_first_of("eE"); // split the string at e or E
string mantissa = s.substr(0, e);
bool mantissa_ok = isIntDec(mantissa) || isIntDec(mantissa, false); // mantissa is either integer or decimal
bool exponent_ok = e == string::npos || isIntDec(s.substr(e+1)); // either no exponent or it has to be an integer
return mantissa_ok && exponent_ok;
}
};
