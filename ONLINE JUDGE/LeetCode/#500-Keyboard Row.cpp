class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    vector<string> key = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
	vector<string> vec;
	for (auto word : words)
		for (auto row : key)
			if (word.find_first_not_of(row) == string::npos)   // STL Function for finding the word that are not present in the Keyboard
				vec.push_back(word);
	return vec;
    }
};
