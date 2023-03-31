#include "Source.h"
#include <string>

std::string encrypt(std::string text, int key) {
	std::string result;

	result = "";
	for (int j = 0; j < text.length(); ++j)
	{
		if (isupper(text[j])){
			result += (text[j] + key - 65) % 26 + 65;
		}
		else if (islower(text[j])){
			result+= (text[j] + key - 97) % 26 + 97;
		}
		else
			result += text[j];
	}
	return result;
}

std::string decrypt(std::string text,int key)
{
	std::string result;
	
    result = "";
    for (int j = 0; j <text.length(); ++j)
	{
		if (isupper(text[j]))
		{
			if ((text[j] - key - 65) < 0)
				result += 91 + (text[j] - key - 65);
			else
				result += (text[j] - key - 65) % 26 + 65;
		}
		else if (islower(text[j]))
		{
			if ((text[j] - key - 97) < 0)
				result += 123 + (text[j] - key - 97);
			else
				result += (text[j] - key - 97) % 26 + 97;
		}
		else
			result += text[j];
	}
	return result;
}

int main() {
	cout << "\t\tCesar Cypher\n\n";
	
	int key;
	std::string text;

	cout << "Enter text to encrypt: ";
	getline(cin, text);

	cout << "Enter the key:"; cin >> key;
	cout << "\n\nText before encrypt: " << text;
	text = encrypt(text, key);
	cout << "\n\n Text after encrypt: " << text;


	cout << "\n=========================================================\n";
    text = decrypt(text,key);
	cout << "Text decrypted: " << text;
	
	return 0;
}