/*
Programmer: Trinity Herbst
Project: Final - Interactive Fiction
Class: CSC125
Instructor: Juan Rodriguez
*/

//Pre-processor directives
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "story_functions.h"

//Namespaces
using namespace std;


//Main function
int main(int argc, char** argv)
{
	
	int Set[] = { 7, 7, 7 }; //Default Colors
	char counter = 2;
	char key;

	goToCoord(10, 3);
	cout << "NEUROTIC DREAM";

	// Loop to set menu items 
	for (int i = 0;;) {

		
		goToCoord(10, 5);
		color(Set[0]);
		cout << "Play ";

		goToCoord(10, 6);
		color(Set[1]);
		cout << "Credits ";


		key = _getch();

		// Detects key press. 72 is for the 'Up Arrow', 73 for 'Down Arrow'
		if (key == 72 && (counter >= 2 && counter <= 3))
		{
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 2))
		{
			counter++;
		}
		// If statement to detect if user presses ENTER
		if (key == '\r')
		{
			if (counter == 1)
			{
				system("CLS");
				cout << "\n\n\n";
				cout << "      ";

				showLoadingScreen();

				cout << "\n\n\n";

				//Clear console window
				system("CLS");

				greetUser();
				getUserName();

				//Create instance of the classes
				thePills p;
				cars c;

				//Initialize string objects from the classes
				p.bluePill = "You have taken the blue pill.";
				p.redPill = "You have taken the red pill.";
				c.mustang = "Mustang";
				c.corvette = "Corvette";


				// Output to console
				cout << "There's a knock on the door. Answer it? 'Y' or 'N'" << endl;

				//Get user input
				char answerDoor;
				cin >> answerDoor;

				//If/Else statements that rely on user input
				if (answerDoor == 'Y')
				{
					cout << "There is nobody there, just a package laying on the floor. Open the package? 'Y' or 'N'" << endl;
					//Declare character variable for user input
					char openPackage;
					// Initialize user input
					cin >> openPackage;
					if (openPackage == 'Y') {
						cout << "Inside of the package are two pills, a blue pill and a red pill. Which one will you take? 'BLUE' or 'RED'" << endl;
						//Declare character variable for user input
						string whichPill;
						// Initialize user input
						cin >> whichPill;
						if (whichPill == "BLUE")
						{
							// Output object from pills class
							cout << p.bluePill << endl;
							cout << "'Mmm, it tastes like blueberry,' you say out loud. You wake up in bed thinking to yourself " << endl;
							cout << "'What a strange dream.'" << endl;
						}
						else if (whichPill == "RED")
						{
							// Output object from pills class
							cout << p.redPill << endl;
							cout << "'Eww, that was the worst thing I've ever tasted in my life!' you yell as you try to spit the taste from your mouth." << endl << endl;
							cout << "'That's because the truth is bitter,' said an unknown voice. " << endl << endl;
							cout << "'Who are you? WHERE are you? How did you get into my apartment?' you ask." << endl << endl;
							cout << "'I\'m talking to you from your computer screen. I hacked into your computer. What do you think this is? The Matrix?' said the voice." << endl << endl;
							cout << "'What? What is the mat--'" << endl << endl;
							cout << " A hand comes through your monitor and presses it's finger to your lips." << endl << endl;
							cout << "'Shhh! You'll have time for questions later. For now, let's play a game.'" << endl << endl;

							// Create and initialize boolean for testing game loop
							bool gameState = true;
							// While gameState is equal to true, run loop
							while (gameState)
							{
								cout << "What is 2 + 2?" << endl;
								int answer;
								cin >> answer;
								if (answer == 4)
								{
									cout << "That was too easy, wasn't it?" << endl << endl;
									// Break out of loop
									break;
								}
								else
								{
									cout << "Really? Really? We expected more from 'The One.'" << endl;
									// Change gameState to false and end loop
									gameState = false;
								}
							}

							cout << "'What model of car was stolen from John Wick? asked the stranger. 'MUSTANG' or 'CORVETTE' " << endl << endl;
							string carModel;
							cin >> carModel;

							if (carModel == "MUSTANG")
							{
								// Output object from cars class
								cout << "Yes, it was a " << c.mustang << "." << endl;
							}
							else if (carModel == "CORVETTE")
							{
								// Output object from cars class
								cout << "No, it was not a " << c.corvette << "." << endl;
							}


							cout << "'Okay, I played your dumb games. Time to answer my questions. Who are you?' you ask." << endl << endl;
							cout << "The stranger replies: 'My name is....'" << endl << endl;
							// Call function, insert parameter, and output statements from function
							strangerName("Morpheus");
							cout << "End of transmission" << endl << endl;
							// Declare variable for rating
							int rating;
							// Declare pointer that points to the address of rating
							int* ptrRating;
							// Initialize pointer to variable's address
							ptrRating = &rating;

							cout << "How would you rate this program from 1-10?" << endl;
							cin >> rating;
							// Output string and dereference pointer to get the variable which the pointer addresses
							cout << "You rated this program a " << *ptrRating << " out of 10." << endl;
						}
						else {
							cout << "You're really indecisive, aren't you?? Definitely not 'The One.'" << endl;
						}
					}
					else
					{
						cout << "You are not the one we are looking for." << endl;
					}
				}
				else
				{
					cout << "It is clear that you are not 'The One.'" << endl;
				}
				break;
			}

			// If user presses enter on 'CREDITS'
			if (counter == 2)
			{
				//Clear console window
				system("CLS");
				credits();
				break;
			}

		}
		Set[0] = 7;
		Set[1] = 7;

		if (counter == 1)
		{
			Set[0] = 12;
		}

		if (counter == 2)
		{
			Set[1] = 12;
		}
	}

	return 0;
}