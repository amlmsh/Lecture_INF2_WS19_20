/*
 * V01.H
 *
 *  Created on: 16.04.2018
 *      Author: aml
 */

#ifndef V01_H_
#define V01_H_

/*
 * Aufruf der Demos
 *
 */
void demoV01_komplexeZahlen();
void demoV01_Rechteck();



/*
 * Deklarationen fuer den Datentyp Komplexe Zahlen
 *
 */

namespace V01{

// Datentyp
typedef struct {
	float re = 0.0;
	float im = 0.0;
}complexNmb;

// Operatoren
void       out(complexNmb a);
complexNmb con(complexNmb a);
complexNmb add(complexNmb a, complexNmb b);
complexNmb sub(complexNmb a, complexNmb b);
complexNmb mul(complexNmb a, complexNmb b);
complexNmb div(complexNmb a, complexNmb b);








/*
 * Deklarationen fuer die Datentypen Punkt und
 * Rechteck
 *
 */

// Datentypen
typedef struct {
	int X = 0;
	int Y = 0;
}Point2D;

typedef struct {
	Point2D P1;
	Point2D P2;
	int     AREA;
}Rectangle;



// Operatoren
void       out(Point2D    p);
void       out(Rectangle  r);
int       area(Rectangle  r);
int    optArea(Rectangle  r);
void       set(Rectangle *r, Point2D p1, Point2D p2);


} // end namespace V01

#endif /* V01_H_ */
