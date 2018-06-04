#include <iostream>
#include <string>
#include <fstream>
#include "Tokenizer.h"
#include "Parser.h"

int main()
{
	std::ifstream assemblyFile;

	assemblyFile.open("testfile.asm");
	if (assemblyFile.is_open())
	{
		Parser parser(assemblyFile);
		parser.Parse();
	}
	else
		std::cout << "Error opening file." << std::endl;

	int x;
	std::cin >> x;

	return 0;
}
