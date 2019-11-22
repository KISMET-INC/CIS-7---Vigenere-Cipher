#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>

using namespace std;

//Cosmetic Divider
const string DIVIDER = "***************************************************";

//Array Size For Vigenere Square
const int ARRAYSIZE = 26;

//Color Handler
HANDLE  hConsole; int k = 7;

//DECLARED FUNCTIONS

void setColor(int);

void nextLetterInAlphabet(char &);

void createVigenereSquare(char array[ARRAYSIZE][ARRAYSIZE], int);

void printArray(char array[ARRAYSIZE][ARRAYSIZE], int);

string addNextLetter_Key(string, string);

string createMatchingKey(string, string);

string convertCharToString(char);

string stringToAllUppercase(string);

void indexViewer();

string generateEncodedCipher(string, string, char array[ARRAYSIZE][ARRAYSIZE]);

string generateEncodedCipher2(string, string);

string decryptCipher(string, string, char array[ARRAYSIZE][ARRAYSIZE]);

bool dataValidation(string &, string);

void header();

void menu();

void results(string, string, string, string, char);

void cin_ToUpperCase(char &);


//LETS BEGIN...

int main()
{
	//VARIABLES
	string readableText; //plain text [either user input or generated]
	string key; // user input key
	string matchingKey; //key generated to match user input
	string cipher; // coded message [either user input or generated]

	bool bypass = false; //used to bypass ask to restart questions
	bool validText; //variable to determine if text is a valid entry
	char menuChoice; //variable to hold menu choice
	char vigenereArray[ARRAYSIZE][ARRAYSIZE]; //array to hold vigenere square data

	


	//SETUP
	//Fill 2D Array with Vigenere Data.
	createVigenereSquare(vigenereArray, ARRAYSIZE);


	//BEGIN PROGRAM

	//Display app name and author
	header();

	cout << endl;
	cout << " War begins in 5...4...3...2...1...";

	//Pause for Drama Lol!
	cin.get();

	//Display Menu
	menu();
	cin_ToUpperCase(menuChoice);

	
	//Beginning of While Loop
	do {
		cin.ignore();

		switch (menuChoice) {
		
		case '1': // INPUT TEXT FOR ENCRYPTION

			setColor(5);
			cout << "  ENCRYPTION:  "; setColor(7); cout << "Enter a TEXT." << endl;
			cout << "  ~ Letters and Spaces only ~ ";
			getline(cin, readableText);
			validText = dataValidation(readableText, "text");

			//Data Validation
			while (validText == false) {
				cout << endl;
				cout << " ~ Your code can only contain letters and spaces ~ " << endl;

				setColor(5);
				cout << "  ENCRYPTION:  "; setColor(7); cout << "Enter  a TEXT." << endl;
				cout << "  ~ Letters and Spaces only ~ ";
				getline(cin, readableText);
				//Reevaluate Input
				validText = dataValidation(readableText, "text");
			}

			cout << endl;

			// CREATE A CIPHER KEY
			setColor(5);
			cout << "  ENCRYPTION:  "; setColor(7); cout << "Enter a KEY." << endl;
			cout << "  ~ Letters only ~ ";
			getline(cin, key);
			validText = dataValidation(key, "key");

			//Data Validation
			while (validText == false) {
				cout << endl;
				cout << " ~ Your code can only contain letters ~ " << endl;
				setColor(5);
				cout << "  ENCRYPTION:  "; setColor(7); cout << "Enter a KEY." << endl;
				cout << "  ~ Letters only ~ ";
				getline(cin, key);
				//Reevaluate Input
				validText = dataValidation(key, "key");
			}

			cout << endl;
			//Create a Key to Match Input
			matchingKey = createMatchingKey(key, readableText);

			//Generate Cipher From Input
			cipher = generateEncodedCipher2(readableText, matchingKey);

			//Print Results
			results(readableText, key, matchingKey, cipher,'E');

			cout << DIVIDER << endl;
			break;


		case '2': //INPUT CODE FOR DECRYPTION
			cout << endl;
			setColor(9);
			cout << "  DECRYPTION:  "; setColor(7); cout << "Enter an ENCRYPTED CODE." << endl;
			cout << "  ~ Letters and Spaces only ~ ";
			getline(cin, cipher);

			validText = dataValidation(cipher, "text");

			//Data Validiation
			while (validText == false) {
				cout << endl;
				cout << " ~ Your code can only contain letters and spaces.~ " << endl;
				setColor(9);
				cout << "  DECRYPTION:  "; setColor(7); cout << "Enter an ENCRYPTED CODE." << endl;
				cout << "  ~ Letters and Spaces only ~ ";
				getline(cin, cipher);
				//Reevaluate Text
				validText = dataValidation(cipher, "text");

			}

			// CREATE A CYPER KEY
			cout << endl;
			setColor(9);
			cout << "  DECRYPTION:  "; setColor(7); cout << "Enter a KEY." << endl;
			cout << "  ~ Letters only ~ ";
			getline(cin, key);
			validText = dataValidation(key, "key");

			//Data Validation
			while (validText == false) {
				cout << endl;
				cout << " ~ Your code can only contain letters ~ " << endl;
				setColor(9);
				cout << "  DECRYPTION:  "; setColor(7); cout << "Enter a KEY." << endl;
				cout << "  ~ Letters only ~ ";
				getline(cin, key);
				//Reevaluate Text
				validText = dataValidation(key, "key");

			}
			cout << endl;

			//Create a Key to Match ENCRYPTED CODE
			matchingKey = createMatchingKey(key, cipher);
			//Decrypt CODE into readable text
			readableText = decryptCipher(cipher, matchingKey, vigenereArray);
			//Display Results
			results(readableText, key, matchingKey, cipher,'D');
			cout << DIVIDER << endl;

			break;

			
		case '3': //PRINT VIGENERE SQUARE
			indexViewer();
			printArray(vigenereArray, ARRAYSIZE);
			cout << endl << endl;
			cout << DIVIDER << endl;
			break;

		case 'Q': //QUIT
		case '4':
			menuChoice == 'Q';
			//Bypass Restart Questions
			bypass = true;
			break;

		case 'M': //DISPLAY MENU [pass through]
		default:
			menu(); 

		case 'Y': // RESTART WHILE LOOP WITHOUT PRINTING MENU [pass through again]
			setColor(8);
			cout << "\t~ Enter your menu choice ~ ";
			setColor(7);
			cin_ToUpperCase(menuChoice);
			//Bypass Restart Questions
			bypass = true;		
		}
		
		//Bypass Section if Restart Already Confirmed
		if ((menuChoice == '1' || menuChoice == '2' || menuChoice == '3')&& bypass == false){
			//RESTART QUESTIONS
			cout << "\t\tARE WE STILL AT WAR?" << endl;
			cout << "\tY to CONTINUE. M to see the MENU." << endl;
			cout << "\t\t Q to QUIT. " << endl << endl;
			cin_ToUpperCase(menuChoice);
		}

		//If Restart Questions Previously Bipassed, Reset So Questions Not Bypassed Forever
		bypass = false;
	
	} while (menuChoice !='Q' && menuChoice != '4');


	//SIGN OFF MESSAGE
	cout << DIVIDER << endl;

	setColor(12);
	cout << "\t  WE ARE AT PEACE...For now." << endl;
	cout << "\t  by K!smet Industries" << endl;
	setColor(7);

	cout << DIVIDER << endl;

	return 0;
}

//Function List

// Chars cannot be added to strings without first 
//being converted to single character strings.



//****************************************************************
// setColor()                                                   //
// Fast way to change text color                                //
//****************************************************************
void setColor(int color)
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	k = color;
	SetConsoleTextAttribute(hConsole, k);
}

//****************************************************************
// addLetterToVigenereTable()									//
// Produces the next letter in the alphabet every time it is    //
// called, after Z it loops back around again to produce A      //
//****************************************************************
void nextLetterInAlphabet(char& total) {

	if (total > 89)
	{
		//if the total is an ascii value greater than Z, it loops back
		//around to A

		total = total - 25;
	}
	else
		//if ascii value not greater than Z it produces the ascii value
		//of the next letter in the sequence.
		total = total + 1;
}

//****************************************************************
// createVigenereSquare()                                       //
// Creates the Vigenere Square by pulling letter from the       //
// addLettertoVignereTable function and fillng all the			//
// indexes with the next letter.                                //
//****************************************************************
void createVigenereSquare(char array[ARRAYSIZE][ARRAYSIZE], int ARRAYSIZE) {

	//Letters start at ascii 64 which is A -1
	static char total = 64;

	for (int i = 0; i < ARRAYSIZE; i++) //rows
	{
		//Makes every row after first row start with one higher letter
		if (i != 0) {
			total = total + 1;
		}

		for (int j = 0; j < ARRAYSIZE; j++) { // columns

			//Value of the first column and begins to add successive letters to 
			//the table till it gets to the end of the row. Then starts over.
			nextLetterInAlphabet(total);
			array[i][j] = total;

		}

	}
}

//****************************************************************
// printArray()                                                 //
// Cycles through and prints out the Vigenere Square Array      //
//****************************************************************
void printArray(char array[ARRAYSIZE][ARRAYSIZE], int ARRAYSIZE) {
	
	//Cycles through array and prints values at each index
	setColor(12);
	for (int i = 0; i <= ARRAYSIZE - 1; i++)
	{
		for (int j = 0; j <= ARRAYSIZE - 1; j++) {

			//If value of J is a factor of the ARRAYSIZE+1 (to account for index 0)
			//It must be the end of the row so a end line is added.
			if ((j % (ARRAYSIZE + 1) == 0))
			{
				cout << endl;


			}
			//Spaces between the column values
			cout << array[i][j] << " ";

		}
	}
	setColor(7);

}

//****************************************************************
// addNextLetter_Key()                                          //
// Takes in a key string and every time it is called it			//
// produces the next letter in the string then loops around     //
// when it gets to the last letter. Produces the letters as     //
// strings so they can be appended to a full string later.      //
//****************************************************************
string addNextLetter_Key(string key, string reset) {
	static int i;
	string stringLetter;

	//If the next letter location called is greater than the length of the 
	//key, we look back at the character at location[0] of the key.
	//Essentially a loop.
	if (i > key.length() - 1)
	{
		i = 0;
	}

	//Takes 1 letter from the key string at a changing pointer location [i]
	string letter(1, key[i]);

	//Appends this letter to a longer string
	stringLetter.append(letter);

	//Prepares to find the next letter in the key
	i++;

	//To reset the pointer for use again later for a different key
	if (reset == "reset") {
		i = 0;

	}

	return stringLetter;
}

//****************************************************************
// createMatchingKey()                                          //
// Takes in both the key and the text and using					//
// addNextLetter_key it keeps putting letters down until it     //
// reaches the end of the user input text.                      //
//****************************************************************
string createMatchingKey(string key, string text) {

	int startChar = key[0];
	int keylength = key.length();
	int textlength = text.length();
//	int letters = 0;

	//holder for the new key that will match the length of the user input value
	string matchingKey;


	for (int i = 0; i < textlength; i++) {

		//If the user input string contains a space, add this space to the
		//matching key.
		if (text[i] == 32) {
			matchingKey.append(" ");

		}
		else {
			//Otherwise pull the next looping characters from the  key
			//to the extended matchingkey string
			matchingKey.append(addNextLetter_Key(key, ""));
		}

	}
	return matchingKey;

}

//****************************************************************
// convertCharToString()                                        //
// Takes in a character and converts it to a string and retuns  //
// the string.                                                  //
//****************************************************************
string convertCharToString(char character) {

	//Convert character to string
	string letter(1, character);

	return letter;

}

//****************************************************************
// stringToAllUppercase()                                       //
// Takes in a string and converts it into all uppercase then    //
// returns a new string.                                        //
//****************************************************************
string stringToAllUppercase(string String) {
	int i = 0;
	char c;
	string upperCaseString;

	//While there is a value in the [i] location of the string
	while (String[i]) {
		//Assign the character in this location to the variable c
		c = String[i];
		//Convert this character to an uppercase
		char newChar(toupper(c));

		//One by one add these uppercase letters to a string
		//that consists of only upper case letters
		upperCaseString.append(convertCharToString(newChar));
		i++;

	}

	return upperCaseString;
}

//****************************************************************
// indexViewer()                                                //
// Prints out a row of numbers to represent the index for		//
// the Vigenere Square                                          //
//****************************************************************
void indexViewer() {

	setColor(12);
	cout << DIVIDER << endl << endl;
	setColor(4);
	cout << "\t     ~ VIGENERE'S SQUARE ~" << endl << endl;
	setColor(12);
	cout << DIVIDER << endl << endl;
	setColor(7);
	cout << "0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 " << endl;

}

//ORIGINAL FUNCTION USING VIGENERE SQUARE
//****************************************************************
// generateEncodedCipher()                                      //
// Takes in he user input text, the long key and the Vigenere   //
// Square array. Searches the Vigenere Square and produces a    //
// string with the encoded message.								//
//****************************************************************
string generateEncodedCipher(string text, string longKey, char array[ARRAYSIZE][ARRAYSIZE]) {
	int length = text.length();
	//the new encrypted code
	string cipher;


	//Generates index locations (for Vigenere Square) of corresponding letters in 
	//corresponding locations of the user input key and the matching length key.
	for (int i = 0; i < length; i++) {

		int column = text[i] - 65;
		int row = longKey[i] - 65;

		//If in the text there is a space, add a space to the cipher
		if (text[i] == 32) {
			cipher.append(" ");
		}
		else
		{
			//Using the index values generated above find the character in 
			//that location on the Vigenere Square
			string tempCharHolder(1, array[row][column]);

			//Add this found character to the cipher string
			cipher.append(tempCharHolder);

		}

	}

	return cipher;
}

//****************************************************************
// generateEncodedCipher2()                                     //
// Easier implementation without Vignere Table					//
// Takes in the user input text, and the long key, finds the	//
//	0-25 value of these then the sum mod 26 is the number of the//
//	encoded letter												//
//****************************************************************
string generateEncodedCipher2(string text, string longKey) {
	int length = text.length();
	//the new encrypted code
	string cipher;


	//Generates index locations (for Vigenere Square) of corresponding letters in 
	//corresponding locations of the user input key and the matching length key.
	for (int i = 0; i < length; i++) {

		int column = text[i];
		int row = longKey[i];
		
		//If in the text there is a space, add a space to the cipher
		if (text[i] == 32) {
			cipher.append(" ");
		}
		else
		{
			
			//Using the ascii values above this adds them together to find the appropriate letter in the ascii table
			// mod 6 to loop the characters in intervals of 26 to represent alphabet letters
			// and + 65 to find the ascii value.

			char columnRow = ((column + row) % 26)+65;
			//cout << columnRow << endl;
			string tempCharHolder (1, columnRow);

			//Add this found character to the cipher string
			cipher.append(tempCharHolder);

		}

	}

	return cipher;
}
//****************************************************************
// decryptCipher()                                              //
// Takes in the encrypted text, the long key and the Vigenere   //
// Square to decrypt the code. Uses the subtraction method.     //
//****************************************************************
string decryptCipher(string encrypted, string longKey, char array[ARRAYSIZE][ARRAYSIZE]) {
	int length = encrypted.length();

	//Once text is decrypted it goes in this variable
	string readableText;

	char decodedLetter;

	//Convert inputs into uppercase
	encrypted = stringToAllUppercase(encrypted);
	longKey = stringToAllUppercase(longKey);

	for (int i = 0; i < length; i++) {
		//Convert letters of encrypted text and key into corresponding
		//ascii values
		int column = encrypted[i] - 65;
		int row = longKey[i] - 65;

		//Using subtraction of ascii values this represents
		//the index location of the character we want.
		int subtract = column - row;
		

		//If the value is a space, add a space to the decoded string
		if (encrypted[i] == 32) {
			readableText.append(" ");

		}
		else {
			//if the subtract value is a negative number add the Z+1 ascii value to 
			//reset and loop to find appropriate letter

			if (subtract < 0) {
				decodedLetter = subtract + 91;
			}

			else {

				//Turn the Ascii value of the letter into a character variable
				decodedLetter = column - row + 65;
			}

			//turn this character into a single string value to append to longer string
			string charToString(1, decodedLetter);

			//Append this single letter string into the full string of decoded readable text
			readableText.append(charToString);

		}
	}

	return readableText;
}

//****************************************************************
// dataValidation()                                             //
// Checks it the string input is only alphabet characters and   //
// returns a bool of true or false.								//
//***************************************************************
bool dataValidation(string& String, string type) {
	//Edit string input and convert it to uppercase
	String = stringToAllUppercase(String);

	for (int i = 0; i < String.length(); i++) {
		//Search the string, if it has a space...
		if ((String[i] == ' ')) {
			// and if the type of validation is not for the text (it is being validated for the key)
			//return false (no spaces allowed in key)
			if (type != "text") {
				return false;
			}

		}

		else
			//All characters must be between A and Z
			if (String[i] < 'A')
				return false;

			else

				if (String[i] > 'Z')
					return false;
	}
	//No red flags, return true
	return true;
}


//****************************************************************
// header()                                                     //
// Displays the header with the app welcome title and the       //
// author                                                       //
//****************************************************************
void header() {
	cout << DIVIDER << endl << endl;
	cout << "\tWelcome to the VIGINERE CIPHER" << endl;
	cout << "\t    by K!smet Industries" << endl << endl;

	cout << DIVIDER << endl;
	setColor(12);
	cout << "\t    ~ ATTACK AT DAWN ~" << endl << endl;
	setColor(7);

}

//****************************************************************
// menu()                                                       //
// Displays a menu of choices                                   //
//****************************************************************
void menu() {
	cout << DIVIDER << endl << endl;
	setColor(8);
	cout << "\t ~ WHAT ARE YOUR ORDERS ~" << endl << endl;
	setColor(7);
	cout << "\t1. Encrypt a Code.\n"
		<< "\t2. Decrypt a Code.\n"
		<< "\t3. View Vigenere Square (with index)\n"
		<< "\t4. Stand Down (Quit)" << endl << endl;

	cout << DIVIDER << endl;

}

//****************************************************************
// results()                                                    //
// Displays the results of the encryption or decryption			//
//****************************************************************
void results(string plaintext, string key, string longkey, string cipher, char t) { 
	
	//char t = type of result to be produced

	cout << DIVIDER << endl;
	cout << "\t\t~ RESULTS ~" << endl << endl;
	if (t == 'D') // For Decryption, Highlights important result by changing color
		setColor(9);
	cout << "\tPlain text\t: " << plaintext << endl;

	setColor(7);
	cout << "\tMatching Key\t: " << longkey << endl;
	cout << endl;
	cout << "\tOriginal Key\t: " << key << endl;

	if (t == 'E') // For Decryption, Highlights important result by changing color
		setColor(5);

	cout << "\tCipher\t\t: " << cipher << endl;

	setColor(7);

	//Reset pointer to 0 for new key in next iteration of program
	addNextLetter_Key(key, "reset");

	cout << endl;
}

//****************************************************************
// cin_ToUpperCase()                                            //
// Takes in a input character and immediately converts it to    //
// uppercase                                                    //
//****************************************************************
void cin_ToUpperCase(char& input) {
	cin >> input;
	input = toupper(input);
}

//Limits, 
//key is accepting numbers
//menu and yes keys dont work when continuing
