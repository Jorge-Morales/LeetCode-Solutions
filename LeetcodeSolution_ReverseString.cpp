#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class Solution
{
public:
	void reverseWords(std::string &stringToReverse)
	{
		std::stack<std::string> reverse;
		std::ostringstream oss;

		bool onlySpace = true;

		char* stringAsChar = const_cast<char*>(stringToReverse.c_str());

		for (int i = 0; i < stringToReverse.size(); ++i)
		{

			// If the current character is a SPACE, we store the previous word and clear the buffer
			if (stringAsChar[i] == 0x20)
			{
				reverse.push(oss.str());
				oss.str("");
			}
			else // Char is not SPACE, keep on storing
			{
				oss << stringAsChar[i];
				onlySpace = false;
			}
		}

		// We need to store the last word because the loop above doesn't do it
		if (stringToReverse.size() && !onlySpace)
		{
			reverse.push(oss.str());
		}

		// Clear the buffer
		oss.str("");

		while (!reverse.empty() && onlySpace == false)
		{
			oss << reverse.top();

			// Remove the previous entry
			reverse.pop();

			if (!reverse.empty())
			{
				oss << " ";
			}
		}

		stringToReverse = oss.str();
	}
};