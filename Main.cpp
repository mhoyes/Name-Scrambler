#include <iostream>
#include <string>
#include <algorithm> // For transform()
using namespace std;

int Random(int lowerLimit, int upperLimit);
std::string ScrambleName(std::string name);

int main()
{
	string name;

	// Get the initial input
	cout << "Enter a name: " << endl;
	getline(cin, name);

	bool done = name.empty();

	while (!done)
	{
		std::string newName = ScrambleName(name);
		
		// Verify the user is happy with the scrambled name
		cout << endl << "Your new name is: " << newName << endl << endl;
		cout << "Happy with it? (Y/N)" << endl << endl;
		cout << "Answer: ";

		string yesNo;
		cin >> yesNo;

		transform(yesNo.begin(), yesNo.end(), yesNo.begin(), toupper);

		// If satisfied, do-while loop ends by assigning "done" to true.
		if (yesNo == "Y" || yesNo == "YES")
		{
			done = true;
		}
		else
		{
			system("CLS");
			cout << "Okay, re-scrambling the name now..." << endl;

		}
	}

	system("CLS");

	if (!name.empty())
	{
		cout << "Good to hear!" << endl << endl;
	}
	
	cout << "Bye Bye" << endl;
}

// My own Random Method
// lowerLimit - Inclusive
// upperLimit - Inclusive
// Ex. Random(0, 5)....0,1,2,3,4,5
int Random(int lowerLimit, int upperLimit) {

	//returns a random number within the given boundary
	return rand() % (upperLimit - lowerLimit + 1);
}

std::string ScrambleName(std::string name)
{
	std::string strToConvert = name;
	std::string newName = "";
	int strLength = name.length();

	// Assign the name mask
	strToConvert = name;

	// iterate the number of characters in the mask name
	for (int i = 0; i < strLength; i++)
	{
		// find an index to select a random character within the mask
		int index = Random(0, strToConvert.length() - 1);

		// append that character to the existing value of newName
		newName += strToConvert[index];

		// assign the value of mask to a temp string and clear the mask
		string temp = strToConvert;
		strToConvert = "";

		// iterate through all characters in temp
		// assign the character to mask, excluding the
		// index character which we assigned to newName earlier
		for (int j = 0; j < temp.length(); j++)
		{
			if (j != index)
			{
				strToConvert += temp[j];
			}
		}
	}

	return newName;
}

