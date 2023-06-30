// THIS IS INTENDED TO GENERATE A PASSPHRASE/PASSWORD TO BE MANUALLY ENTERED 

/* C++ program to create a secure pass-phrase that is also personalized and easy to
remember. There is an option to generate a secure password that is not
personalized but definitely secure.*/

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

//Initialization of function that will mutate the familiar words or phrase.
string secure_item(char item[]);

int main() {

	//Initialize and accept, as user input, the choice of whether to create a familiar passphrase or a randomly generated password.
        string ans;
        cout << "\nWould you like to create a familiar passphrase or a randomly generated password?\nType 'phrase' or 'word' to choose and press enter.\n";
        cin >> ans;

	//Check that the input is valid.
        if(ans != "phrase" && ans != "word") {
                cout << "\nCorrect usage is typing <word> or <phrase>, exiting program\n";
                exit(0);
        }

	//If creating a familiar passphrase is chosen:
	//    Get the components of the passphrase as user input
	//    Secure the user inputs and add them to the passphrase
	//    Print the new secure passphrase
        if(ans == "phrase") {

                cout << "\nYou have chosen to create a personalized passphrase.\n";
                cout << "To create a passphrase, you will use memorable information.\n";

                char s1[64], s2[64], i1[64], p1[64];
                string passphrase;
                
                cout << "\nType a memorable 5+ letter word.\n";
                cin >> s1;
                cout << "\nType a memorable number.(of any length)\n";
                cin >> i1;
                cout << "\nType a memorable 5+ letter word.\n";
                cin >> s2;
                cout << "\nType a memorable phrase.(without spaces)\n";
                cin >> p1;

		passphrase += secure_item(s1);
		passphrase += i1;
		passphrase += secure_item(p1);
		passphrase += secure_item(s2);

                cout << "\nYour passphrase is: " << passphrase << endl;
        }

	//If creating a generated password is chosen:
	//    Recommend a proper passowrd length, initialize that length, and get the length as user input
	//    Create a password of that length using the ASCII table, specifically characters available for user input
	//    Print the new password
        if(ans == "word"){

                int pass_length;
                string password;

                cout << "\nYou have chosen to have a password generated for you." << endl;
                cout << "How long would you like your password to be?(it is recommended at least 10 characters in length)\n" << endl;
                cin >> pass_length;

		//Create random seed to ensure new numbers each time the program is executed
                srand(time(0));
		//This loop loops for the password length number and randomly selects a keyboard inputtable ASCII table character, adding it to the password 
                for(int i = 0; i < pass_length; i++){
                        int rand = (std::rand()%(95)) + 32;
                        password += char(rand);
                }

                cout << "\nYour password is: " << password << endl;
        }
}

//This function takes a word or phrase without spaces as a parameter and returns a new, similar version of that word or phrase that has each of its letters replaced with capital letters, numbers, or symbols.
//Special note on the fact that these replacement characters are chosen to still look similar to the original word or phrase to keep its familiarity.
//Requires: The input of a character array. 
//Assignable: NONE
//Ensures: The return of a character array that is a similar version of the original character array that has been secured.
string secure_item(char item[]){

		//Initialization of: passphrase to be returned,,,random seed to ensure a new random number each time the program is executed
		string passphrase;
		srand(time(0));

		//This loop iterates through the input character array, changing each character to either the same character, a capitalzied character, a similar number, or a similar symbol.
                for(int i = 0; i < strlen(item); i++){

                        char letter = item[i];
                        int rand = (std::rand())%3;

                        if(rand == 0){
                                if(letter == 's'){
                                        passphrase += '$';
                                }else if(letter == 'i'){
                                        passphrase += '!';
                                }else if(letter == 'b'){
                                        passphrase += '8';
                                }else if(letter == 'e'){
                                        passphrase += '3';
                                }else{
                                        passphrase += toupper(letter);
                                }
                        }
                        if(rand == 1){
                                passphrase += letter;
                        }
                        if(rand == 2){
                                if(letter == 'i'){
                                        passphrase += '1';
                                }else if(letter == 's'){
                                        passphrase += '5';
                                }else if(letter == 'p'){
                                        passphrase += '9';
                                }else if(letter == 'e'){
                                        passphrase += '=';
                                }else if(letter == 'o'){
                                        passphrase += '0';
                                }else if(letter == 'l'){
                                        passphrase += '1';
                                }else if(letter == 'b'){
                                        passphrase += '8';
                                }else{
                                        passphrase += toupper(letter);
                                }
                        }
                }
		return passphrase;
}
