﻿#include <iostream>
#include <stdlib.h>
using namespace std;
const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };

char mass[9];
void fillMassive();
void printField();
void usersStep(int number);
void computersStep();
bool IsVictory(char symbol);
bool IsDraw();
bool ifMayWinAnyone(int index, char symbol);

int main()
{    	
	int choice;	
	fillMassive();	
	while (true)
	{		
		system("cls");
		printField();
		cout << endl << "Make your choice: ";
		cin >> choice;
		if (choice < 1 || choice > 9)
		{
			cout << "Error! You enter wrong number (only from 1 to 9)." << endl;
			return 1;
		}
		usersStep(choice);
		computersStep();
		if (IsVictory('X'))
		{
			system("cls");
			printField();
			cout << "USER WIN!";
			break;
		}
		else if (IsVictory('0'))
		{
			system("cls");
			printField();
			cout << "Computer WIN!";
			break;
		}

		if (IsDraw())
		{
			system("cls");
			printField();
			cout << "Draw!";
			break;
		}
		
	}
	
	return 0;
}

void fillMassive()
{
	for (int i = 0; i < 9; i++)
	{
		mass[i] = ' ';		
	}
}

void printField()
{
	cout << "  CROSS-ZERO GAME" << endl;
	cout << "###################" << endl;
	cout << "#  "<< mass[6] <<"  #  " << mass[7] << "  #  " << mass[8] << "  #" << endl;
	cout << "###################" << endl;
	cout << "#  " << mass[3] << "  #  " << mass[4] << "  #  " << mass[5] << "  #" << endl;
	cout << "###################" << endl;
	cout << "#  " << mass[0]<< "  #  " << mass[1] << "  #  " << mass[2] << "  #" << endl;
	cout << "###################" << endl;
}

void usersStep(int number)
{
	mass[number - 1] = 'X';
}
	

void computersStep()
{	
	bool stepDone = false;
	bool computerWin = false;
	for (int i = 0; i < 9; i++)
	{
		if (mass[i] == ' ' && ifMayWinAnyone(i, '0'))
		{			
			mass[i] = '0';
			stepDone = true;
			computerWin = true;
			break;					
			
		}
	}
	if (!computerWin)
	{
		for (int i = 0; i < 9; i++)
		{
			if (mass[i] == ' ' && ifMayWinAnyone(i, 'X'))
			{
				mass[i] = '0';
				stepDone = true;
				break;
			}
		}
	}	
	if (!stepDone)
	{
		for (int i = 0; i < 9; i++)
		{
			if (mass[BEST_MOVES[i]] == ' ')
			{
				mass[BEST_MOVES[i]] = '0';
				break;
			}
		}
	}		
}

bool ifMayWinAnyone(int index, char symbol)
{
	mass[index] = symbol;
	if (IsVictory(symbol))
	{
		return true;
	}	
	else
	{
		mass[index] = ' ';
	}
	return false;
}


bool IsVictory(char symbol)
{	
	if (mass[0] == symbol && mass[1] == symbol && mass[2] == symbol)
	{
		return true;
	}
	else if (mass[3] == symbol && mass[4] == symbol && mass[5] == symbol)
	{
		return true;
	}
	else if (mass[6] == symbol && mass[7] == symbol && mass[8] == symbol)
	{
		return true;
	}
	else if (mass[0] == symbol && mass[3] == symbol && mass[6] == symbol)
	{
		return true;
	}
	else if (mass[1] == symbol && mass[4] == symbol && mass[7] == symbol)
	{
		return true;
	}
	else if (mass[2] == symbol && mass[5] == symbol && mass[8] == symbol)
	{
		return true;
	}
	else if (mass[6] == symbol && mass[4] == symbol && mass[2] == symbol)
	{
		return true;
	}
	else if (mass[0] == symbol && mass[4] == symbol && mass[8] == symbol)
	{
		return true;
	}
	return false;
}

bool IsDraw()
{	
	for (int i = 0; i < 9; i++)
	{
		if (mass[i] == ' ')
		{
			return false;
		}
	}
	return true;
}