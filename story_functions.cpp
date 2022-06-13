//Pre-processor directives
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "story_functions.h"


//Namespaces
using namespace std;

const int BLACK = 0;
const int WHITE = 15;
const int DEFAULT = 12;

// Backspace text to simulate animation
void clearScreen(int CharacterLength) 
{
	for (int i = 0; i < CharacterLength; i++)
	{
		cout << "\b";
	}
}

// Change color of text for loading screen
void changeColor(int txtColor) 
{
	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, txtColor);
}

//Display a loading screen
void showLoadingScreen() 
{
	string closed = "L O A D I N G", open = ". . . . . . .";
	int txtColor[] = { BLACK, DEFAULT };
	
	cout << closed;
	cout << open;

	for (int i = 0; i < 2; i++)
	{
		Sleep(1000);

		clearScreen(13);
		changeColor(txtColor[i]);

		cout << open;

		Sleep(1000);

		clearScreen(13);
		changeColor(WHITE);

		cout << open;
	}

	clearScreen(13);
	changeColor(WHITE);
}

// Set color of menu text
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

// Display text at specific coordinates
void goToCoord(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


// Initialize functions
void greetUser()
{
	cout << "Greetings, adventurer. You are about to embark on a timeless journey." << endl;
	cout << "This program is an interactive fiction story, in which you, the user, dictates the outcome." << endl << endl;
}


// Get user's name
string getUserName()
{
	// Function statements
	string userName;
	// Create and initialize reference to userName
	string& refUser = userName;
	cout << "What is your name?" << endl;
	// Get user input and initialize userName
	cin >> userName;
	// Reference userName
	cout << "Hello, " << refUser << ". You've fallen down the rabbit hole. Let your journey begin." << endl << endl;
	cout << "You wake up suddenly. You're sitting at your computer. You realize that you must have fallen asleep." << endl;
	cout << "You have been working pretty hard, after all." << endl;
	cout << "The screen on your monitor goes black, and a message is presented to you." << endl;
	// Reference userName
	cout << "It states: 'Wake up, " << refUser << ".'" << endl;
	return userName;
}

// Initialize function
void strangerName(string name)
{
	// Function statements
	cout << name << endl;
}

void credits() {
	cout << "Written by: Trinity Herbst\n";
}







