/*
 * Prak_P1.C
 *
 *  Created on: 19.04.2018
 *      Author: aml
 */

#include "Prak_P1.H"

#include <iostream>
#include <fstream>
#include <string>

namespace P1{

void P1A00(){
	std::cout << "012345789012345678901234567890" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "**                          **" << std::endl;
	std::cout << "**       Hello World!       **" << std::endl;
	std::cout << "**                          **" << std::endl;
	std::cout << "******************************" << std::endl;
	std::cout << "ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜẞ" << std::endl;
}

void P1A01(){
	int n, i;
	std::string  s, d;

	std::cout << "Eingabe n:";
	std::cin >> n;

	std::cout << "Eingabe string:";
	std::cin >> s;

	d = std::string("");
	for(i = 0; i < n; i++){
		std::cout << d << s  << std::endl;
		d = d + " ";
	}

	return;
}

void P1A02(){
	std::string name, familyName;
	int i, c;

	std::ofstream file("out.xml");
	file << "<data>\n";

	std::cout << "Anzahl der Namen: ";
	std::cin >> i;

	if(i < 1){
		std::cout << "Schreibe leere Datei.\n";
	}else{
		c = 1;
		while(c <= i){
			std::cout << c << ". Vorname:";
			std::cin >> name;
			std::cout << c << ". Familienname:";
			std::cin >> familyName;
			c++;

			file << "  <Name>\n";
			file << "    <Vorname>\n";
			file << "      " << name << std::endl;
			file << "    </Vorname>\n";
			file << "    <Nachname>\n";
			file << "      " << familyName << std::endl;
			file << "    </Nachname>\n";
			file << "  </Name>\n";
		}
	}

	file << "</data>\n";
	file.close();
	return;
}

void P1A03(){
	unsigned short a, b;

	std::cout << "a   b    a->b" << std::endl;
	std::cout << "-------------" << std::endl;
	for(a = 0; a < 2; a++){
		for(b = 0; b < 2; b++ ){
			std::cout << a << "   ";
			std::cout << b << "      ";
			std::cout << implies(a,b) << std::endl;
		}
	}

	return;
}

void P1A04(){
	unsigned short a, b;

	std::cout << "a   b    a <-> b" << std::endl;
	std::cout << "----------------" << std::endl;
	for(a = 0; a < 2; a++){
		for(b = 0; b < 2; b++ ){
			std::cout << a << "   ";
			std::cout << b << "       ";
			std::cout << logEq(a,b) << std::endl;
		}
	}

	return;
}

void P1A05(){
	int n, i, idx, tmp;
	std::string strL("");

	std::cout << "Eingabe n: ";
	std::cin >> n;

	int l[n];

	for(i = 0; i < n; i++){
		l[i] = i+1;
	}

	// bringe Liste durcheinander
	for(i = 0; i < n; i++){
		idx = rand() % n;
		tmp = l[idx];
		l[idx] = l[i];
		l[i]   = tmp;
	}

	// Ausgabe Liste
	std::cout << "Ausgabe:   [";
	for(i = 0; i < n; i++){
		std::cout << l[i];
		if(i != (n-1)){
			std::cout << ",";
		}
	}
	std::cout << "]" << std::endl;
}

void P1A06(){


	unsigned short bValues;

	// Ausgabe Wahrheistwerttabelle
	std::cout << "\tA B C D E F G H I J K L  Wert " << std::endl;

	unsigned short counter = 1;

	for(bValues = 0; bValues < 4096; bValues++){

		if (termValue(bValues)) {
			std::cout << counter++  << "\t";
			std::cout << getBinValue(bValues, 'A') << " ";
			std::cout << getBinValue(bValues, 'B') << " ";
			std::cout << getBinValue(bValues, 'C') << " ";
			std::cout << getBinValue(bValues, 'D') << " ";
			std::cout << getBinValue(bValues, 'E') << " ";
			std::cout << getBinValue(bValues, 'F') << " ";
			std::cout << getBinValue(bValues, 'G') << " ";
			std::cout << getBinValue(bValues, 'H') << " ";
			std::cout << getBinValue(bValues, 'I') << " ";
			std::cout << getBinValue(bValues, 'J') << " ";
			std::cout << getBinValue(bValues, 'K') << " ";
			std::cout << getBinValue(bValues, 'L') << "  1" << std::endl;
		}
	}
}

unsigned short getBinValue(unsigned short v, char c){
	unsigned short bitValue;
	switch(c){
		case 'A': bitValue = v & 0b100000000000 ? 1 : 0;
			break;
		case 'B': bitValue = v & 0b010000000000 ? 1 : 0;
			break;
		case 'C': bitValue = v & 0b001000000000 ? 1 : 0;
			break;
		case 'D': bitValue = v & 0b000100000000 ? 1 : 0;
			break;
		case 'E': bitValue = v & 0b000010000000 ? 1 : 0;
			break;
		case 'F': bitValue = v & 0b000001000000 ? 1 : 0;
			break;
		case 'G': bitValue = v & 0b000000100000 ? 1 : 0;
			break;
		case 'H': bitValue = v & 0b000000010000 ? 1 : 0;
			break;
		case 'I': bitValue = v & 0b000000001000 ? 1 : 0;
			break;
		case 'J': bitValue = v & 0b000000000100 ? 1 : 0;
			break;
		case 'K': bitValue = v & 0b000000000010 ? 1 : 0;
			break;
		case 'L': bitValue = v & 0b000000000001 ? 1 : 0;
			break;
		default: bitValue = 2;
	}
	return bitValue;
}



unsigned short termValue(unsigned short bits){
	unsigned short value = 1;

	unsigned short A = getBinValue(bits, 'A');
	unsigned short B = getBinValue(bits, 'B');
	unsigned short C = getBinValue(bits, 'C');
	unsigned short D = getBinValue(bits, 'D');
	unsigned short E = getBinValue(bits, 'E');
	unsigned short F = getBinValue(bits, 'F');
	unsigned short G = getBinValue(bits, 'G');
	unsigned short H = getBinValue(bits, 'H');
	unsigned short I = getBinValue(bits, 'I');
	unsigned short J = getBinValue(bits, 'J');
	unsigned short K = getBinValue(bits, 'K');
	unsigned short L = getBinValue(bits, 'L');

	value = value && implies(F, B && L);  // 1
	value = value && implies(!D  && !I, A); // 2
	value = value && implies(K || D, !B); // 3
	value = value && implies(J,!C && !K); // 4
	value = value && implies(!J && !G, H); //5
	value = value && implies(!(C && E),!I); //6
	value = value && implies(G,I && (!K)); // 7
	value = value && implies(H,C && (!A)); // 8
	value = value && implies(!F && !I, !H); // 9
	value = value && implies(I, !E); // 10
	value = value && ((A + B + C + D + E + F + I + L) > (G + H + J + K)) ;

	return value;
}


unsigned short implies(unsigned short A, unsigned short B){
	return (!(A && !B));
}

unsigned short logEq(unsigned short A, unsigned short B){
	return (implies(A,B) && implies(B,A));
}


} // end namespace P1
