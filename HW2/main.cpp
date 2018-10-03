/*
File name: main.cpp
Authors: Eric Oropezaelwood and Chiu Tsang
Date: 10/3/2018
Description: Organizations of the whole program.
*/

#include <iostream>
#include "Store.h"
#include "TextUI.h"

using namespace std;

int main(){

	Store s("store.txt");
	TextUI tui;
	string str_choice;

	do{
		str_choice = tui.MainMenu();
		tui.RouteChoice(s, str_choice);
	}while(str_choice != "Leave");

}
