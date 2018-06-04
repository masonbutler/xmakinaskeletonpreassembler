#include "Tokenizer.h"

Tokenizer::Tokenizer()
{
	delimiters = "\t ";
}

void Tokenizer::SetRecord(std::string &str)
{
	buffer = str;
	currentPosition = buffer.begin();
}

std::string Tokenizer::GetNextToken()
{
	if (buffer.size() > 0)
	{
		token.clear();
		while (currentPosition != buffer.end() && (delimiters.find(*currentPosition) != std::string::npos))
			currentPosition++;

		while (currentPosition != buffer.end())
		{
			if (!(delimiters.find(*currentPosition) != std::string::npos))
			{
				token += *currentPosition;
				currentPosition++;
			}
			else
				break;
		}
		return token;
	}

	return std::string();
}
