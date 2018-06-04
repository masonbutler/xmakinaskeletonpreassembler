#pragma once
#include <iostream>
#include <string>

class Tokenizer
{
public:
	Tokenizer();
	void SetRecord(std::string &str);
	std::string GetNextToken();
private:
	std::string buffer, token, delimiters;
	std::string::const_iterator currentPosition;
};
