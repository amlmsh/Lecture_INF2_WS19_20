/*
 * V00.C
 *
 *  Created on: 17.04.2018
 *      Author: aml
 */

#include <iostream>
#include <string>
#include <map>


#include "V00.H"

void demoV00(){



	std::map<std::string,int> tbl;

	tbl["a"] = tbl["a"] + 1;

	std::cout << "a: " << tbl["a"] << " " << sizeof(unsigned char)<< std::endl;

	//TAML();
	//A2L();

}


void A2L(){
	int A,B,C,D,E,F,G,H,I,J,K,L;
	float sA,sB,sC,sD,sE,sF,sG,sH,sI,sJ,sK,sL;
	sA = sB = sC = sD = sE = sF = sG = sH = sI = sJ = sK = sL = 0;

	int count = 0;

	// Ausgabe Wahrheitswerte
	std::cout << " \t\tA\t\tB\t\tC\t\tD\t\tE\t\tF\t\tG\t\tH\t\tI\t\tJ\t\tK\t\tL\n\n";

	for(A=0; A < 2; A++){
		for(B=0; B < 2; B++){
			for(C=0; C < 2; C++){
				for(D=0; D < 2; D++){
					for(D=0; D < 2; D++){
						for(E=0; E < 2; E++){
							for(F=0; F < 2; F++){
								for(G=0; G < 2; G++){
									for(H=0; H < 2; H++){
										for(I=0; I < 2; I++){
											for(J=0; J < 2; J++){
												for(K=0; K < 2; K++){
													for(L=0; L < 2; L++){



														// Ausgabe Ergebnis
														if (A2Leval(A,B,C,D,E,F,G,H,I,J,K,L)) {

															// Ausgabe Wahrheitswerte
															std::cout << ++count << "\t\t";
															std::cout << A << "\t\t";
															std::cout << B << "\t\t";
															std::cout << C << "\t\t";
															std::cout << D << "\t\t";
															std::cout << E << "\t\t";
															std::cout << F << "\t\t";
															std::cout << G << "\t\t";
															std::cout << H << "\t\t";
															std::cout << I << "\t\t";
															std::cout << J << "\t\t";
															std::cout << K << "\t\t";
															std::cout << L << "\t\t";

															std::cout << "   erfüllende Belegung    ";

															std::cout << A+B+C+D+E+F+G+H+I+J+K+L;

															std::cout <<  std::endl;

															sA = sA + A;
															sB = sB + B;
															sC = sC + C;
															sD = sD + D;
															sE = sE + E;
															sF = sF + F;
															sG = sG + G;
															sH = sH + H;
															sI = sI + I;
															sJ = sJ + J;
															sK = sK + K;
															sL = sL + L;

														}else{
															// std::cout << std::endl;
														}


													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


	// Ausgabe Wahrheitswerte
	std::cout.precision(1);
	std::cout << "\n  " << "\t\t";
	std::cout << sA/count << "\t\t";
	std::cout << sB/count << "\t\t";
	std::cout << sC/count << "\t\t";
	std::cout << sD/count << "\t\t";
	std::cout << sE/count << "\t\t";
	std::cout << sF/count << "\t\t";
	std::cout << sG/count << "\t\t";
	std::cout << sH/count << "\t\t";
	std::cout << sI/count << "\t\t";
	std::cout << sJ/count << "\t\t";
	std::cout << sK/count << "\t\t";
	std::cout << sL/count << std::endl;

	return;
}


int  A2Leval(int A, int B, int C, int D, int E, int F, int G, int H, int I, int J, int K, int L){
	int result = 1;

	result = result && implies(F, B && L);  // 1
	result = result && implies(!D  && !I, A); // 2
	result = result && implies(K || D, !B); // 3
	result = result && implies(J,!C && !K); // 4
	result = result && implies(!J && !G, H); //5
	result = result && implies(!(C && E),!I); //6
	result = result && implies(G,I && (!K)); // 7
	result = result && implies(H,C && (!A)); // 8
	result = result && implies(!F && !I, !H); // 9
	result = result && implies(I, !E); // 10
	result = result && ((A + B + C + D + E + F + I + L) > (G + H + J + K)) ;

	return result;
}

int implies(int A, int B){
	return (!(A && !B));
}

int logEq(int A, int B){
	return (implies(A,B) && implies(B,A));
}


void TAML() {

	int T, A, M, L;

	std::cout << "T   A   M   L" << std::endl;


	for (T = 0; T < 2; T++) {
		for (A = 0; A < 2; A++) {
			for (M = 0; M < 2; M++) {
				for (L = 0; L < 2; L++) {

					// Ausgabe Wahrheitswerte
					std::cout << T << "   " << A << "   " << M << "   " << L;

					// Ausgabe Ergebnis
					if (TAMLeval2(T, A, M, L)) {
						std::cout << "   erfüllende Belegung" << std::endl;
					}else{
						std::cout << std::endl;
					}
				}

			}
		}
	}

}

/*
 *
 * Umsetzung mittels vollstaendiger Fallunterscheidung
 *
 *
 */
int TAMLeval1(int T, int A, int M, int L){
	int result  = 1;
	int rT, rA, rM, rL;



	// T: genau zwei sagen die Wahrheit
	rT =
			( T  &&  A && !M && !L) ||
			( T  && !A &&  M && !L) ||
			( T  && !A && !M &&  L) ||
			(!T  &&  A &&  M &&  L) ||
			(!T  &&  A && !M && !L) ||
			(!T  && !A &&  M && !L) ||
			(!T  && !A && !M &&  L) ||
			(!T  && !A && !M && !L);



	// A: mindestens zwei sagen nicht die Wahrheit
	rA =
			( T  &&  A && !M && !L) ||
			( T  && !A &&  M &&  L) ||
			(!T  &&  A &&  M && !L) ||
			(!T  &&  A && !M &&  L) ||
			(!T  &&  A && !M && !L);



	// M: A luegt
	rM =
			( T  &&  A && !M &&  L) ||
			( T  &&  A && !M && !L) ||
			( T  && !A &&  M &&  L) ||
			( T  && !A &&  M && !L) ||
			(!T  &&  A && !M &&  L) ||
			(!T  &&  A && !M && !L) ||
			(!T  && !A &&  M &&  L) ||
			(!T  && !A &&  M && !L);


	// L:  hoechstens einer sagt die Wahrheit
	rL =
			( T  &&  A &&  M && !L) ||
			( T  &&  A && !M && !L) ||
			( T  && !A &&  M && !L) ||
			(!T  &&  A &&  M && !L) ||
			(!T  && !A && !M &&  L);




	return (rT && rA && rM && rL);

}


/*
 *
 * Umsetzung mittels "genau dann, wenn"
 *
 *
 */
int TAMLeval2(int T, int A, int M, int L){
	int result  = 1;
	int rT, rA, rM, rL, X;



	// T: genau zwei sagen die Wahrheit
	X =
			( A  && !M && !L) ||
			(!A  &&  M && !L) ||
			(!A  && !M &&  L);
	rT = !(T && !X);
	rT = rT && (!(!T && X));



	// A: mindestens zwei sagen nicht die Wahrheit
	X =
			( T  && !M && !L) ||
			(!T  &&  M && !L) ||
			(!T  && !M &&  L) ||
			(!T  && !M && !L);
	rA = !(A && !X);

	rA = rA && (!(!A && X));


	// M: A luegt
	X =
			!A;
	rM = !(M && !X);
	rM = rM && (!(!M && X));


	// L:  hoechstens einer sagt die Wahrheit
	X =
			(!T  && !A && !M);
	rL = !(L && !X);
	rL = rL && (!(!L && X));

	return (rT && rA && rM && rL);

}


/*
 *
 * Umsetzung mittels "genau dann, wenn" mittels logEq.
 *
 *
 */
int TAMLeval3(int T, int A, int M, int L){
	int result  = 1;
	int rT, rA, rM, rL, X;



	// T: genau zwei sagen die Wahrheit
	X =
			( A  && !M && !L) ||
			(!A  &&  M && !L) ||
			(!A  && !M &&  L);
	rT = logEq(T,X);



	// A: mindestens zwei sagen nicht die Wahrheit
	X =
			( T  && !M && !L) ||
			(!T  &&  M && !L) ||
			(!T  && !M &&  L) ||
			(!T  && !M && !L);
	rA = logEq(A,X);


	// M: A luegt
	X =
			!A;
	rM = logEq(M,X);



	// L:  hoechstens einer sagt die Wahrheit
	X =
			(!T  && !A && !M);
	rL = logEq(L,X);


	return (rT && rA && rM && rL);

}

