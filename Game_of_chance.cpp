#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include "functions.hpp" //functions.hpp mit den Funktionen


//Spieler definition

/**
Umlaute in cpp:

Zeichen     Hex    Okt
========================
'Ä'       8E     216
'ä'       84     204
'Ö'       99     231
'ö'       94     224
'Ü'       9A     232
'ü'       81     201
'ß'       E1     341

**/

//Funktionen sind in functions.hpp deklariert


int main(){

	setzero(); //Highscore 0 setzen

	int game = 0; //Auswahl Zahl für Hauptmenü
	bool end = false; //Ende Wahrheitswert für Schleife (Hauptmenü)
	while (end != true){ //Test auf end = false

		srand(time(0)); //initialisierung des Zufallsgenerators

		//Hauptmenu

		std::cout << "\n\t\t\t    ### Game of chance ###\n";
		std::cout << "\t\t\t   -1- Guess the number -1-\n";
		std::cout << "\t\t\t   -2- Guess before pc -2-\n";
		std::cout << "\t\t\t   -3- Lucky Number -3-\n";
		std::cout << "\t\t\t   -4- Money show -4-\n";
		std::cout << "\t\t\t   -5- Money refill -5-\n";
		std::cout << "\t\t\t   -6- Highscore Update -6-\n";
		std::cout << "\t\t\t         -7- Ende -7-\n";

		std::cin >> game; // Spielmodus Wahl

		//Auswertung

		if (game == 1){
			guess_the_number(); //Guess The Number wird gespielt
		}
		if (game == 2){

			guess_before_pc(); //Guess before pc wird gespielt

		}
		if (game == 3){
			lucky_number(); //Lucky Number wird gespielt
		}
		if (game == 4){ //Der Score / Das Geld wird angezeigt
			score();
		}
		if (game == 5){ //Der Score / Das Geld wird auf 100 aufgefüllt
			refill();
		}
		if (game == 6){ //Der Score wird gespeichert (Highscore.txt)
			getnwrite();
		}
		if(game == 7){ //Beenden
			end = true; //Wahrheitswert end wird auf true gesetzt --> Ende
			std::cout << "Bye!\n\n"; //Schluss funktion
		}
		if (game > 7 || game < 1){ //Falls eine ungültige Zahl eingegeben wurde!
			std::cout << "\n6Bitte gebe eine Zahl von 1 - 6 ein!\n";
		}
	} //Schleifenende

	system("pause"); // Verhinderung des sofortigen Beendens
	return 0;
}
