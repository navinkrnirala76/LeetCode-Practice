class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int n = words.size();
		vector<string> ans;
		int i = 0;
		while (i < n) {
			int j = i, numOfWord = 0, spaceBetween = 0;
			while (j < n && maxWidth >= (numOfWord + spaceBetween + words[j].size())) {
				numOfWord += words[j].size();
				spaceBetween++;
				j++;
			}
			spaceBetween--;
			string res = "";
			int rem = maxWidth - numOfWord;
			int numOfSpace = spaceBetween <= 0 ? 0 : rem / spaceBetween;
			int extraSpace = spaceBetween <= 0 ? 0 : rem % spaceBetween;
			if (j == n) {
				numOfSpace = 1;
				extraSpace = 0;
			}
			while (i < n && i < j) {
				res += words[i];
				int k = 0;
				while (spaceBetween > 0 && k < numOfSpace) {
					res += " ";
					k++;
				}
				spaceBetween--;
				if (extraSpace > 0) {
					res += " ";
					extraSpace--;
				}
				i++;
			}
			while (res.size() != maxWidth) res += " ";
			ans.push_back(res);
		}
		return ans;
	}
};
