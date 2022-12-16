#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	system("chcp 1251>null");

	string userMessage = "viktarovich iryna";

	vector<size_t> oBufferKeys;
	vector<char> oBufferSymbol;

	oBufferKeys.push_back(1);
	oBufferSymbol.push_back(userMessage[0]);
	for (size_t i = 1; i < userMessage.size(); i++)
	{
		auto iterator = find(oBufferSymbol.begin(), oBufferSymbol.end(), userMessage[i]);

		if (iterator != oBufferSymbol.end())
		{
			++oBufferKeys[distance(oBufferSymbol.begin(), iterator)];
		}
		else
		{
			oBufferKeys.push_back(1);
			oBufferSymbol.push_back(userMessage[i]);
		}
	}

	vector<pair<size_t, string>> indexStrSymbols;
	for (size_t i = 0; i < oBufferKeys.size(); i++)
	{
		indexStrSymbols.emplace_back(oBufferKeys[i], *(new string(1, oBufferSymbol[i])));
	}

	sort(indexStrSymbols.begin(), indexStrSymbols.end());

	vector<pair<char, string>> symbolCipher;
	for (size_t i = 0; i < oBufferKeys.size(); i++)
	{
		symbolCipher.emplace_back(oBufferSymbol[i], "");
	}

	struct compareFirst
	{
		compareFirst(char symbol)
		{
			_symbol = symbol;
		}

		bool operator() (pair<char, string> const& p)
		{
			return (p.first == _symbol);
		}

		char _symbol;
	};

	auto EncryptSymbols = [&](const string& symbolsNull, const string& symbolsOne)
	{
		for (size_t i = 0; i < symbolsNull.size(); i++)
		{
			size_t index = distance(symbolCipher.begin(), find_if(symbolCipher.begin(), symbolCipher.end(), compareFirst(symbolsNull[i])));

			symbolCipher[index].second = "0" + symbolCipher[index].second;
		}

		for (size_t i = 0; i < symbolsOne.size(); i++)
		{
			size_t index = distance(symbolCipher.begin(), find_if(symbolCipher.begin(), symbolCipher.end(), compareFirst(symbolsOne[i])));

			symbolCipher[index].second = "1" + symbolCipher[index].second;
		}
	};

	auto MySort = [&](pair<size_t, string> temp)
	{
		for (auto i = indexStrSymbols.begin(); i != indexStrSymbols.end(); i++)
		{
			if (temp.first > (*i).first) continue;
			else
			{
				indexStrSymbols.insert(indexStrSymbols.begin() + distance(indexStrSymbols.begin(), i), temp);
				return;
			}
		}

		indexStrSymbols.push_back(temp);
	};

	while (indexStrSymbols.size() != 1)
	{
		EncryptSymbols(indexStrSymbols[0].second, indexStrSymbols[1].second);

		auto temp = *(new pair<size_t, string>(indexStrSymbols[0].first + indexStrSymbols[1].first,
			indexStrSymbols[0].second + indexStrSymbols[1].second));

		indexStrSymbols.erase(indexStrSymbols.begin(), indexStrSymbols.begin() + 2);

		MySort(temp);
	}
 
	indexStrSymbols.clear();
	for (size_t i = 0; i < oBufferKeys.size(); i++)
	{
		indexStrSymbols.emplace_back(oBufferKeys[i], *(new string(1, oBufferSymbol[i])));
	}

	sort(indexStrSymbols.begin(), indexStrSymbols.end());

	string EncryptString;
	for (size_t i = 0; i < userMessage.size(); i++)
	{
		EncryptString.append((*find_if(symbolCipher.begin(), symbolCipher.end(), compareFirst(userMessage[i]))).second);
	}

	for (size_t i = 0; i < indexStrSymbols.size(); i++)
	{
		cout << "( " << indexStrSymbols[i].second << " - " << indexStrSymbols[i].first << " )" << endl;
	}

	cout << endl << endl << "Symbols with their code:" << endl;
	for (size_t i = 0; i < symbolCipher.size(); i++)
	{
		cout << "( " << symbolCipher[i].first << " - " << symbolCipher[i].second << " )" << endl;
	}

	cout << endl << endl << "Result:" << endl;
	cout << EncryptString << endl << endl;

	/*cout << "Расшифровка:";
	struct compareSecond
	{
		compareSecond(string str)
		{
			_str = str;
		}

		bool operator() (pair<char, string> const& p)
		{
			return (p.second == _str);
		}

		string _str;
	};

	string decryptedString;
	string temp;
	for (size_t i = 0; i < EncryptString.size(); i++)
	{
		temp.push_back(EncryptString[i]);

		auto it = find_if(symbolCipher.begin(), symbolCipher.end(), compareSecond(temp));

		if (it != symbolCipher.end())
		{
			decryptedString.push_back((*it).first);
			temp = "";
		}
	}

	cout << decryptedString;*/
}