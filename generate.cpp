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

int main() {

        string ans;
        cout << "\nWould you like to create a familiar passphrase or a randomly generated password?\nType 'phrase' or 'word' to choose and press enter.\n";
        cin >> ans;

        if(ans != "phrase" && ans != "word") {
                cout << "\nCorrect usage is typing <word> or <phrase>, exiting program\n";
                exit(0);
        }

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

                srand(time(0));
                for(int i = 0; i < strlen(s1); i++){

                        char letter = s1[i];
                        int rand = (std::rand())%2;

                        if(rand == 0) {
                                if(letter == 's') {
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

                passphrase += i1;

                for(int i = 0; i < strlen(p1); i++){

                        char letter = p1[i];
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

                for(int i = 0; i < strlen(s2); i++){

                        char letter = s2[i];
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

                cout << "Your passphrase is: " << passphrase << endl;
        }

        if(ans == "word"){

                int pass_length;
                string password;

                cout << "You have chosen to have a password generated for you." << endl;
                cout << "How long would you like your password to be?(it is recommended at least 10 characters in length)" << endl;
                cin >> pass_length;

                srand(time(0));
                for(int i = 0; i < pass_length; i++){
                        int rand = (std::rand()%(95)) + 32;
                        password += char(rand);
                }

                cout << "Your password is: " << password << endl;
        }
}
