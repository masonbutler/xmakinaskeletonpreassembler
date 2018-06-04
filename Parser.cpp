#include "Parser.h"
#include "Instruction.h"
#include <algorithm>

Instruction instructions[] =
{
	{ "ADC", "ADDC #0, *" },
	{ "CALL", "BL" },
	{ "NOP", "MOV R6, R6" },
	{ "JUMP", "MOV *, R7" },
	{ "RLC", "ADDC *, *" },
};

Parser::Parser(std::ifstream &file)
{
	inputFile = &file;
	inputFile->clear();
	inputFile->seekg(0, std::ios::beg);
}

void Parser::Parse()
{
	while (getline((*inputFile), currentRecord))
	{
		std::string token, newInstruction;
		tokenizer.SetRecord(currentRecord);

		while (!(token = tokenizer.GetNextToken()).empty())
		{
			int index = SearchTable(token);

			if (index != -1)
			{
				// found in table,  process
			}
		}
	}
}

int Parser::SearchTable(std::string &str)
{
	std::string upper = str;
	std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
	for (int i = 0; i < 5; i++)
	{
		if (upper == instructions[i].emulatedInstruction)
			return i;
	}

	return -1;
}
