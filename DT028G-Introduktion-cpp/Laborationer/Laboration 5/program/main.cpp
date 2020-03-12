#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	string currentWord;
	string wordSentenceBuild;
	string devider = "=============================";

	//Illegal characters
	static string ILLEGAL_CHARS = ".,*^!#\\/:?|;+-'¨\"";

	//Integer for the user input
	int numberOfWords;

	//Word map
	map<string, int> wordMap;

	//Word vector
	vector<pair<string, int> > wordVector;

	//File path
	string filePath = "hitchhikersguide.txt";

	//Open file stream
	ifstream readFile;
	readFile.open(filePath);

	//Read through the file
	while ( !readFile.eof() )
	{
		readFile >> currentWord;

		//Remove all illegal characters
		for(char symbol : ILLEGAL_CHARS) {
			if(currentWord.find(symbol) != string::npos) {
				currentWord.erase(std::remove(currentWord.begin(), currentWord.end(), symbol), currentWord.end());
			}
		}

		//Control if the current is bigger than 0
		//To prevent empty words in the result
		if(currentWord.length() <= 0) {
			continue;
		}

		//Transform the current word to lover case only
		transform(currentWord.begin(), currentWord.end(), currentWord.begin(), ::tolower);

		//Increase the value of the current word in the map
		wordMap[currentWord]++;
	}

	//Copy the word map to a vector called vectorMap
	copy(wordMap.begin(), wordMap.end(), back_inserter < vector< pair< string, int > > > ( wordVector ) );

	//Sorting of the vector from the second value (the map's value) instead of the first value (the map's key)
	auto cmp = []( pair<string, int> a, pair<string, int> b )
	{
		if( a.second > b.second )
		{
			return true;
		}

		return false;
	};

	sort( wordVector.begin(), wordVector.end(), cmp );

	//Printout's
	cout << "There is a total of " << wordVector.size() << " words in the file " << filePath << endl;
	cout << "How many top words do you want to display? : ";

	//User input for the amount of words to be displayed
	cin >> numberOfWords;

	//If the the user imput is bigger than the total amount of word in the file
	if ( numberOfWords > wordVector.size() )
	{
		cout << endl << "There is less than " << numberOfWords << " words in " << filePath << endl;
		cout << "The total amout of " << wordVector.size() << " words printed." << endl << endl;
		numberOfWords = wordVector.size();
	}

	//If the user input is equal to one, declare the string "wordSencenceBuild" to "word"
	if ( numberOfWords == 1 )
	{
		wordSentenceBuild = "word";
	}

	//Else, declare the string as "words"
	else
	{
		wordSentenceBuild = "words";
	}

	//Print of the result
	cout << endl << "Top " << numberOfWords << " " << wordSentenceBuild << endl;
	cout << devider << endl << endl;

	//Loop through the vector for the given amount of times
	for ( int i = 0; i < numberOfWords; ++i )
	{
    	cout << wordVector[i].first << ": " << wordVector[i].second << " times" << endl << endl;
  	}

  	cout << devider << endl << endl;

  	//Close file stream
	readFile.close();

	return 0;
}