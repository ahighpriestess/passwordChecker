#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

bool passwordValidation(string);


int main()
{
	string validPassword;
	do
	{
		cout << "Create password: " << endl;
		cout << endl;

		const int COL1 = 35;
		const int COL2 = 40;
		cout << left << setw(COL1) << "Requirement 1: " << right << setw(COL2) << "No Spaces" << endl;
		cout << left << setw(COL1) << "Requirement 2: " << right << setw(COL2) << "Uppercase Letter" << endl;
		cout << left << setw(COL1) << "Requirement 3: " << right << setw(COL2) << "Lowercase Letter" << endl;
		cout << left << setw(COL1) << "Requirement 4: " << right << setw(COL2) << "Numeric Digit" << endl;
		cout << left << setw(COL1) << "Requirement 5: " << right << setw(COL2) << "Special Symbol" << endl;
		cout << endl;

		getline(cin, validPassword);

	} while (passwordValidation(validPassword));

	cout << "Your password has been processed successfully." << endl;
	return 0;

}


bool passwordValidation(string forPassword)
{
	bool passwordValidation;
	int uppercaseLetter, lowercaseLetter, theNumber, includesSpace, specialSymbols, length;


	uppercaseLetter = 0;
	lowercaseLetter = 0;
	theNumber = 0;
	includesSpace = 0;
	specialSymbols = 0;

	passwordValidation = false;
	length = forPassword.length() - 1;


	for (int theValidation = 0; theValidation <= length; theValidation++)
	{

		if (isdigit(forPassword[theValidation]))
			theNumber++;
		if (islower(forPassword[theValidation]))
			lowercaseLetter++;
		if (isupper(forPassword[theValidation]))
			uppercaseLetter++;
		if (!isalnum(forPassword[theValidation]) && !isspace(forPassword[theValidation]))
			specialSymbols++;
		if (isspace(forPassword[theValidation]))
			includesSpace++;
	}



	if (!uppercaseLetter || length < 11 || !lowercaseLetter || !theNumber || includesSpace || !specialSymbols) {

		cout << endl;
		cout << "Invalid entry. " << endl;
		cout << endl;

	}

	if (!theNumber)
	{
		cout << "You have not entered a number." << endl;
		passwordValidation = true;

	}

	if (!lowercaseLetter)
	{
		cout << "You have not entered a lowercase letter. " << endl;
		passwordValidation = true;
	}

	if (!uppercaseLetter)
	{
		cout << "You have not entered an uppercase letter. " << endl;
		passwordValidation = true;
	}

	if (length < 11)
	{
		cout << "You have entered less than 12 characters. " << endl;
		passwordValidation = true;
	}

	if (!specialSymbols)
	{
		cout << "You have not entered special symbols. " << endl;
		passwordValidation = true;
	}

	if (includesSpace)
	{
		cout << "You have entered spaces. " << endl;
		passwordValidation = true;
	}

	cout << endl;


	return passwordValidation;

}