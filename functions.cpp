#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

struct player{

	int money;

} paul;


void lose (){

	std::cout << "\nDu hast kein Geld mehr! Deswegen hast du verloren!\n\n";
	paul.money = 100;
	std::cout << "Du besitzt wieder 100 Euro\n";
}

void score(){
	std::cout << "Du besitzt [" << paul.money << "] Euro\n";
}

void getnwrite (){
	char answer;
	std::string s;
	std::ifstream read; //Input filestream
	read.open("highscore.txt");

	if(read.is_open()){ //Test ob Datei vorhanden ist --> Datei ist vorhanden:
		while (std::getline(read, s)){ //Zeilen lesen
			std::cout << "Derzeitiger gespeicherter Highscore: " << s; //Lesen der Datei + Ausgabe des aktuellen gespeicherten highscores/ Das was in dr Textdatei steht
		}

	read.close(); //Schließen der Datei;
	}
	else{ //Falls Datei noch nicht vorhanden
		std::cout << "Oeffnen der Datei nicht moeglich!\nBitte wiederholen!\n";
		std::ofstream f;
		f.open("highscore.txt");
		f << "0"; //Highscore auf null
		f.close();
	}
	std::cout << "\nDein highscore (Der Betrag deines Geldes) liegt bei [" << paul.money << "]\nWillst du den gespeicherten highscore \nueberschreiben? [J/N]\n"; //Wie groß ist der Highscore im Spiel?
	std::cin >> answer;
		std::ofstream file; //Output filestream

	switch (answer){

	case 'J':
	case'j':
		
		file.open("highscore.txt"); //oeffnen
		file << paul.money;
		std::cout << "Der Spielstand wurde gespeichert!\n";
		file.close(); //File wieder schließen

	break;
	case 'n':
	case 'N':
		std::cout << "\nDer Spielstand wird nicht gespeichert!\n";
		break;

	default:
		std::cout << "\nSpeichern durch falsche eingabe abgebrochen!\n";
		break;
	}
	

}

void lucky_number(){ //Game Lucky Number (Drei Zahlen 1-3 werden generiert und geschaut ob sie gleich sind)

	if (paul.money >= 20){ //Wenn er so viel Geld hat - Anfang

		std::cout << "\n\n\t\t\t    --- Lucky number +++\n\t\tDrei Zahlen, alle gleich --> Gewinn!\nDieses Spiel kostet dich 20 Euro!\n";
		paul.money -= 20;

		int first = rand() % 3 + 1, second = rand() % 3 + 1, third = rand() % 3 + 1;

		if (first == second && second == third && first == third){
			std::cout << "Die drei Zahlen sind gleich! [" <<first<< "]\n\nDu verdienst 60 Euro!\n\n" ;
			paul.money += 60;
		}
		else {
			std::cout << "Die drei Zahlen sind nicht gleich! [" << first << "," << second << "," <<third << "]\n";
		}
		//Verlieren

		if (paul.money <= 0){
			lose();
		}

	} //Wenn er so viel Geld hat - Ende
	else{
		std::cout << "Du scheinst daf\x81r kein Geld zu haben!\n";
	}
}

void guess_before_pc(){ //Guess before pc Spiel

	int choice, winning, pc;

	winning = rand() % 20 + 1;
	pc = rand() % 20 + 1;

	//Hauptmenü


	if (paul.money >= 10){ //Wenn er so viel Geld hat - Anfang
		paul.money -= 10;
		std::cout << "\n\n\t\t\t    +++ Guess before pc +++\n\t\tErrate eine Zufallszahl vor dem Computer!\n\nDieses Spiel kostet dich 10 Euro!\n\n";
		std::cout << "\n\nDeine Zahl (Zwischen 1 und 20): ";

		std::cin >> choice; //Eingabe

		if (choice == winning && winning == pc){
			std::cout << "Du und der Computer liegen richtig!\nDu verdienst 10 Euro!\n";
			paul.money += 10;
		}

		if (choice == winning && winning != pc){
			std::cout << "Nur du liegst richtig!\nDu verdienst 40 Euro!\n";
			paul.money += 40;
		}

		if (choice != winning && winning != pc){
			std::cout << "Beide liegen falsch [" << winning << "]\n";
		}
		if (choice != winning && winning == pc){
			std::cout << "Du liegst falsch, der Computer liegt richtig [" << winning << "]\nDadurch verlierst du nochmals 10 Euro!\n";
			paul.money -= 10;
		}

		//	std::cout << "winning: " << winning << "\npc: " << pc; // beweis für Ungleichheit
		//Verlieren

		if (paul.money <= 0){
			lose();
		}

	} //Wenn er so viel Geld hat - Ende
	else {
		std::cout << "Du scheinst daf\x81r kein Geld zu haben!\n";
	}


}

void guess_the_number(){ //Guess the Number Spiel

	int choice, winning;
	winning = rand() % 20 + 1;
	if (paul.money >= 10){ //Wenn er so viel Geld hat - Anfang
		std::cout << "\n\n\t\t\t    +++ Guess the number +++\n\nDieses Spiel kostet dich 10 Euro!\n";
		paul.money -= 10;
		std::cout << "\t\tErrate die Zahl zwischen 1 und 20!\n\t\tDein Tipp: "; //Zahl von 1 - 20 eingeben

		std::cin >> choice; //Eingabe

		//Auswertung

		if (choice == winning){
			std::cout << "Du hast gewonnen!\n\nDu verdienst 20 Euro!\n\n";
			paul.money += 20;
		}
		else
			std::cout << "Schade! Du hast die Zahl [" << winning << "] nicht erraten!\n\n";

		//Verlieren

		if (paul.money <= 0){
			lose();
		}

	} //Wenn er so viel Geld hat - Ende
	else {
		std::cout << "Du scheinst daf\x81r kein Geld zu haben!\n";
	}

}

void setzero(){
	paul.money = 0;
}

void refill(){
	paul.money = 100;
	std::cout << "Du hast nun wieder 100 Euro\n";

}
