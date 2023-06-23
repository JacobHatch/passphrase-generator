// THIS IS INTENDED TO GENERATE A PASSPHRASE/PASSWORD TO BE ENTERED MANUALLY

/* Java program to create a secure pass-phrase that is also personalized and easy to remember.
There is an option to generate a secure password that is not personalized but definitely secure.*/

import java.util.Scanner;
import java.util.Random;

class Generate{
	public static void main(String[] args){

			Scanner userInput = new Scanner(System.in);

			System.out.println("\nWould you like to create a familiar passphrase or a randomly generated password?");
			System.out.println("(Type 'phrase' or 'word' to choose and press enter.)\n");
			
			String ans = userInput.nextLine();
			
			if((!ans.equals("phrase")) && (!ans.equals("word"))){

				System.out.print("Correct usage is typing <word> or <phrase>, exiting program");
				System.exit(0);
		
			}

			if(ans.equals("phrase")){

				String s1, s2, i1, p1;
				String passphrase = "";
				Random rand = new Random();
				long seed = rand.nextLong();
				rand.setSeed(seed);
				
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

				for(int i = 0; i < passLength; i++){

					int randNum = rand.nextInt(95)+32;
					password += (char)randNum;

				}
				System.out.println("\nYour password is: " + password); 
			}
	}

	public static String secureItem(String item){

				String passphrase = "";
				int index = 0;
				Random rand = new Random();
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
