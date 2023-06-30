// THIS IS INTENDED TO GENERATE A PASSPHRASE/PASSWORD TO BE ENTERED MANUALLY

/* Java program to create a secure pass-phrase that is also personalized and easy to remember.
There is an option to generate a secure password that is not personalized but definitely secure.*/

import java.util.Scanner;
import java.util.Random;

class Generate{
	public static void main(String[] args){

			//Initialization of scanner object to be used for obtaining user input
			Scanner userInput = new Scanner(System.in);

			//These three lines are used to get the choice of whether to create a familiar passphrase or randomly generate password
			System.out.println("\nWould you like to create a familiar passphrase or a randomly generated password?");
			System.out.println("(Type 'phrase' or 'word' to choose and press enter.)\n");
			String ans = userInput.nextLine();

			//Check that the input is valid
			if((!ans.equals("phrase")) && (!ans.equals("word"))){

				System.out.print("Correct usage is typing <word> or <phrase>, exiting program");
				System.exit(0);
		
			}

			//If creating a familiar passphrase is chosen:
			//    Get the components of the passphrase as user input
			//    Secure the user inputs and add them to the passphrase
			//    Print the new secure passphrase
			if(ans.equals("phrase")){

				String s1, s2, i1, p1;
				String passphrase = "";
				
				System.out.println("\nYou have chosen to create a personalized passphrase.");
				System.out.println("To create a passphrase, you will use memorable information.");

				System.out.println("\nType a memorable 5+ letter word.");
				s1 = userInput.nextLine();
				System.out.println("Type a memorable number.(of any length)");
				i1 = userInput.nextLine();
				System.out.println("Type a memorable 5+ letter word.");
				s2 = userInput.nextLine();
				System.out.println("Type a memorable phrase.(without spaces)");
				p1 = userInput.nextLine();

				passphrase += secureItem(s1);
				passphrase += i1;
				passphrase += secureItem(s2);
				passphrase += secureItem(p1);

				System.out.println("\nYour passphrase is: " + passphrase + "\n");	
			}

			//If creating a generated password is chosen:
			//    Initialize the random number, random seed, password length, and password string
			//    Recommend a proper password length and get the length as user input
			//    Create a password of that length using the ASCII table, specifically characters available for user input
			//    Print the new password
			if(ans.equals("word")){
				
				Random rand = new Random();
				long seed = rand.nextLong();
				rand.setSeed(seed);
				int passLength;
				String password = "";

				System.out.println("\nYou have chosen to have a password generated for you.");
				System.out.println("How long would you like your password to be?");
				System.out.println("(it is recommended at leat 10 characters in length)\n");
				passLength = userInput.nextInt();

				// This loop loops for the password length and randomly selects a keyboard inputtable ASCII table characer, adding it to the password
				for(int i = 0; i < passLength; i++){

					int randNum = rand.nextInt(95)+32;
					password += (char)randNum;

				}
				System.out.println("\nYour password is: " + password); 
			}
	}

	//This function takes a word or phrase without spaces as a parameter and returns a new, similar version of that word or phrase that has it letters replaced with capital letters, numbers, or symbols.
	//Special note on the fact that these replacement characters are chosen to still look similar to the original word or phrase to keep its familiarity.
	//Requires: The input of a String. 
	//Assignable: NONE
	//Ensures: The return of a String that is similar version of the original character array that has been secured.
	public static String secureItem(String item){

				//Inititialization of: passphrase to be returned,,,index to keep track of substring location,,,random number,,,random seed to ensure different number every time program is used
				String passphrase = "";
				int index = 0;
				Random rand = new Random();
				long seed = rand.nextLong();
				rand.setSeed(seed);

				//This loop iterates through the input string, changing each character to either the same character, a capatilized character, a similar number, or a similar symbol
				for(int i = 0; i < item.length(); i++){
					
					String letter = item.substring(index, i+1);
					int randNum = rand.nextInt(2);

					if(randNum == 0){
	                                	if(letter.equals("s")) {
                                        		passphrase += "$";                              
                                		}else if(letter.equals("i")){
                                        		passphrase += "!";
                                		}else if(letter.equals("b")){
                                        		passphrase += "8";
                                		}else if(letter.equals("e")){
                                		        passphrase += "3";
                                		}else{
                                	        	passphrase += letter.toUpperCase();
                                		}
                        		}
                        		if(randNum == 1){
                                		passphrase += letter;
                        		}
                        		if(randNum == 2){
                        		        if(letter.equals("i")){
                        		                passphrase += "1";
                        		        }else if(letter.equals("s")){
                        		                passphrase += "5";
                        		        }else if(letter.equals("p")){
                        		                passphrase += "9";
                        		        }else if(letter.equals("e")){
                        		                passphrase += "=";
                                		}else if(letter.equals("o")){
                                		        passphrase += "0";
                                		}else if(letter.equals("l")){
                               			         passphrase += "1";
                                		}else if(letter.equals("b")){
                                		        passphrase += "8";
                                		}else{
                                		        passphrase += letter.toUpperCase();
                                		}
                        		}
					index++;
				}
			return passphrase;
	}	
}
