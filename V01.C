/*
 * V01.C
 *
 *  Created on: 16.04.2018
 *      Author: aml
 */

#include <stdio.h>
#include "V01.H"

using namespace V01;

void demoV01_komplexeZahlen(){
	complexNmb a, b;

	// 1. Ausgabe
	printf("\n\n 1.Ausgabe a: ");
	out(a);

	// 2. Veraendere Daten und Ausgabe
	a.re = -2.12;
	printf("\n 2.Ausgabe a: ");
	out(a);

	// 3. Veraendere Daten und Ausgabe
	a.im = 32.12;
	a.re = -2.12;
	printf("\n 3. Ausgabe a: ");
	out(a);

	// 4. Berechne konjungation
	printf("\n 4. Ausgabe: a conj =  ");
	out(con(a));

	b.re = 2.1;
	b.im = 9.9;

	// 5. Ausgabe
	printf("\n 5.Ausgabe b: ");
	out(b);

	// 6. Ausgabe
	printf("\n a + b: ");
	out(add(a,b));


}


void demoV01_Rechteck(){

	Point2D p1, p2;

	Rectangle r;

	printf("\n\n p1: "); out(p1);
	printf("\n p2: ");   out(p2);


	r.P1 = p1;
	r.P2 = p2;


	printf("\n\n Output Rectangle: ");  out(r);
	printf("\n area (units): %i \n", area(r));


	p1.X = 0;
	p1.Y = 0;
	p2.X = 12;
	p2.Y = 4;

	r.P1 = p1;
	r.P2 = p2;


	printf("\n\n Output Rectangle: "); out(r);
	printf("\n area (units): %i \n", area(r));


	printf("\n area (units): %i \n\n\n", optArea(r));



	Point2D p3;
	p3.X = -12;
	p3.Y = -4;

	set(&r, p2, p3);

	printf("\n\n Output Rectangle 2\n");
	out(r);
	printf("\n area (units): %i \n", area(r));

	printf("\n area (units): %i \n\n\n", optArea(r));

	r.P1 = p1;
	printf("\n\n Output Rectangle 3\n");out(r);

	printf("\n area (units): %i \n", area(r));

	printf("\n area (units): %i \n\n\n", optArea(r));

}


namespace V01{

void out(complexNmb a){
	if(a.im < 0){
		printf("( %.2f - %.2fi)", a.re, -a.im);
	}else{
		printf("( %.2f + %.2fi)", a.re,  a.im);
	}
}

complexNmb con(complexNmb a){
	complexNmb b;
	b = a;
	b.im = - a.im;
	return b;
}

complexNmb add(complexNmb a, complexNmb b){
	complexNmb c;
	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return c;
}

complexNmb sub(complexNmb a, complexNmb b){
	complexNmb c;
	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return c;
}

complexNmb mul(complexNmb a, complexNmb b){
	complexNmb c;
	c.re = (a.re * b.re) - (a.im * b.im);
	c.im = (a.re * b.im) + (a.im * b.re);
	return c;
}


complexNmb div(complexNmb a, complexNmb b){
	complexNmb c;
	float norm = (b.re * b.re) + (b.im * b.im);
	c.re = ( (a.re * b.re) - (a.im * b.im) ) / norm;
	c.im = ( (a.im * b.re) + (a.re * b.im) ) / norm;
	return c;
}




void out(Point2D f){
	printf("< %i; %i >", f.X, f.Y);
}



void out(Rectangle f){
	printf("{ ");
	V01::out(f.P1);
	printf("; ");
	V01::out(f.P2);
	printf(" }");
}


int       area(Rectangle r){
	int diffX = r.P1.X - r.P2.X;
	int diffY = r.P1.Y - r.P2.Y;
	int res   = diffX*diffY;

	if(res < 0){
		return -res;
	}else{
		return res;
	}
}



int    optArea(Rectangle r){
	return r.AREA;
}

void   set(Rectangle *r, Point2D p1, Point2D p2){
	r->P1 = p1;
	r->P2 = p2;
	int diffX = r->P1.X - r->P2.X;
	int diffY = r->P1.Y - r->P2.Y;
	int res   = diffX*diffY;

	if(res < 0){
		r->AREA =  -res;
	}else{
		r->AREA = res;
	}
}


} // end namespace V01
