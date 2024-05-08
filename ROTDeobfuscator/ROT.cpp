#include <iostream>
#include <string>
#include "ROT.h"

char LiteralIntToChar(int i)
{
	return i + '0';
}
int CharToLiteralInt(char c)
{
	return c - '0';
}

std::string DeobfuscateRot5(std::string encryptedInt)
{
	std::string deobfuscatedString;
	for (int i = 0; i < encryptedInt.size(); i++)
	{
		char c = encryptedInt[i];
		int newRotated = (CharToLiteralInt(c) + 5) % 10;
		deobfuscatedString += LiteralIntToChar(newRotated);
	}
	return deobfuscatedString;
}

char AlphabetIntToChar(int i, char c)
{
	if (islower(c))
	{
		return i + (int)'a';
	}
	else
	{
		return i + (int)'A';
	}
}
int AlphabetCharToInt(char c)
{
	if (islower(c))
	{
		return c - 'a';
	}
	else
	{
		return c - 'A';
	}
}

std::string DeobfuscateRot13(std::string obfuscatedStr)
{
	std::string deobfuscatedString;
	for (int i = 0; i < obfuscatedStr.size(); i++)
	{
		char c = obfuscatedStr[i];
		if (c == ' ') { deobfuscatedString += " ";	continue; }
		if (!isalpha(c)) continue;
		int newRotatedInt = (AlphabetCharToInt(c) + 13) % 26;
		deobfuscatedString += AlphabetIntToChar(newRotatedInt, c);
	}
	return deobfuscatedString;
}

std::string DeobfuscateRotCustom(std::string obfuscatedStr, int customRot)
{
	std::string deobfuscatedString;
	for (int i = 0; i < obfuscatedStr.size(); i++)
	{
		char c = obfuscatedStr[i];
		if (c == ' ') { deobfuscatedString += " ";	continue; }
		if (!isalpha(c)) continue;
		int newRotatedInt = (AlphabetCharToInt(c) + customRot) % 26;
		deobfuscatedString += AlphabetIntToChar(newRotatedInt, c);
	}
	return deobfuscatedString;
}

void ProcessInput(std::string inputMode)
{
	std::string obfuscatedInput;
	std::string rotCountInput;
	std::string rotCountInputEnd;

	switch (std::stoi(inputMode))
	{
	case 1:
		printf_s("ROT5 string : ");
		std::getline(std::cin, obfuscatedInput);
		printf_s("%s", DeobfuscateRot5(obfuscatedInput).c_str());

		break;
	case 2:
		printf_s("ROT13 string : ");
		std::getline(std::cin, obfuscatedInput);
		printf_s("%s", DeobfuscateRot13(obfuscatedInput).c_str());

		break;
	case 3:
		printf_s("ROT47 string : ");
		std::getline(std::cin, obfuscatedInput);
		//printf_s("%s", DeobfuscateRot47(input).c_str());

		break;
	case 4:
		printf_s("ROTCUSTOM string : ");
		std::getline(std::cin, obfuscatedInput);
		//
		printf_s("ROTCUSTOM Count : ");
		std::getline(std::cin, rotCountInput);
		printf_s("%s", DeobfuscateRotCustom(obfuscatedInput, stoi(rotCountInput)).c_str());

		break;
	case 5:
		printf_s("ROTCUSTOM string : ");
		std::getline(std::cin, obfuscatedInput);
		printf_s("From X Rot : ");
		std::getline(std::cin, rotCountInput);
		//
		printf_s("Until X Rot : ");
		std::getline(std::cin,rotCountInputEnd);

		LoopUntilLastRotCount(stoi(rotCountInputEnd), obfuscatedInput, rotCountInput);

		break;

	default:
		printf_s("CONSOLE : Undefined input");

		break;
	}
	rotCountInput.clear();
}

void LoopUntilLastRotCount(int rotCountInputMax, std::string& obfuscatedInput, std::string& rotCountInput)
{
	for (int i = 0; i < rotCountInputMax; i++)
	{
		printf_s("%s", DeobfuscateRotCustom(obfuscatedInput, stoi(rotCountInput) + i).c_str());
		std::cout << std::endl;
	}
}

int main() //Implement to website
{
	std::string modeInput;
	while (true)
	{
		std::cout << "Rot type :" << std::endl;
		std::cout << "============================" << std::endl;
		std::cout << "[1] : ROT5 (Numerical )" << std::endl;
		std::cout << "[2] : ROT13 (Alpha)" << std::endl;
		std::cout << "[3] : ROT47 (AlphaNum)" << std::endl;
		std::cout << "[4] : ROT CUSTOM (Alpha)" << std::endl;
		std::cout << "[5] : TRY MULTIPLE ROT (Alpha)" << std::endl;
		std::cout << "============================" << std::endl;
		std::getline(std::cin, modeInput);
		std::cout << std::endl;


		ProcessInput(modeInput);
		std::cout << std::endl << std::endl;
		modeInput.clear();
	}
}

