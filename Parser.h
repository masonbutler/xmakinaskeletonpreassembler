#pragma once
#include <fstream>
#include "Tokenizer.h"

class Parser
{
public:
	Parser(std::ifstream &file);
	void Parse();

	int SearchTable(std::string &str);

private:
	std::ifstream *inputFile;
	//std::ofstream &outputFile;
	std::string currentRecord;

	Tokenizer tokenizer;
};
