/* C++ program to create a secure pass-phrase that is also personalized and easy to
remember. There is an option to generate a secure password that is not
personalized but definitely secure.*/

#include <iostream>
#include <cstdlib>

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

                string s1, s2, i1, p1, passphrase;

                cout << "\nType a memorable 5+ letter word.\n";
                cin >> s1;
                cout << "\nType a memorable number.(of any length)\n";
                cin >> i1;
                cout << "\nType a memorable 5+ letter word.\n";
                cin >> s2;
                cout << "\nType a memorable phrase.(without spaces)\n";
                cin >> p1;

        }
}
