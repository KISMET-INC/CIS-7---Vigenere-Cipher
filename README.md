# Changes in Patch 1
Although the Vigenere Square is still available for viewing within the program, the encoding function no longer uses this 2D array to encode messages, instead it uses the addition method similar to the way the decoding uses the subtraction method.

# Vigenere-Cipher- Readme

Designed in a sort of game format, this program allows the user to encrypt and decrypt codes using the standard Vigenere Square Ciper.

# How the Vigenere Cipher works :
The user inputs a string of letters and spaces they want encoded. They also enter a unique key that will be used as its complement on the table.

Each letter in each location in the user input and its corresponding letter in the key are compared on the Vigenere Square. The text input letters are searched for in the columns and the key input letters are searched for in the rows. Where the rows and columns meet on the table is the corresponding letter to the newly encrypted cipher. This process is repeated for every letter in the user input text and the cipher is built. (Note: The letters in the key are recycled as many times as necessary to match the length of the user input text) 

# Getting Started
 - Start the program. 
 - You will be shown the title of the project and prompted with "War Begins in 5...4...3...2...1..." Press any key to continue.
 - You will be shown a menu of options. Choose an option to begin. Press Q to quit


# Message Inputs (to encode or decode)
Only letters and spaces can be used (upper or lowercase)The program automatically converts all inputs to uppercase. Numbers and symbols will not be allowed.

# Key Inputs
Key inputs must be one single line (Does not allow spaces, numbers or symbols)

# Maintenance and Contributers
If you need help with this project, or have any questions about it, Kristen can be reached at kmoreland909@gmail.com


