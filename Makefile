INCLDIR=.

LIBDIR1=.
LIBDIR2=.


WX_CONFIG=/usr/bin/wx-config


WXCFLAGS=$(shell wx-config --cppflags)  -std=c++11  -std=c++0x
WXLIBFLAGS=$(shell wx-config --libs std)


CFLAGS=$(WXCFLAGS) -I$(INCLDIR) -I.

LIBS=$(WXLIBFLAGS) -L$(LIBDIR1) -L$(LIBDIR2)  -lm 


all:	main sortDemo prakAufg01Main prakAufg02Main prakAufg03Main prakAufg04Main
	doxygen Doxyfile

main:	main.o SortDemo.o V00.o V01.o V02.o V03.o V04.o V05.o V06.o V07.o V08.o V09.o
	g++ -o main main.o SortDemo.o V00.o V01.o V02.o V03.o V04.o V05.o V06.o V07.o V08.o V09.o $(LIBS)
	
main.o:	main.C
	g++ -c $(CFLAGS) main.C

sortDemo:	sortDemo.o SortDemo.o
	g++ -o sortDemo sortDemo.o SortDemo.o $(LIBS)



	
prakAufg01Main:	prakAufg01Main.o PrakAufg01.o
	g++ -o prakAufg01Main prakAufg01Main.o PrakAufg01.o $(LIBS)	
	
prakAufg02Main:	prakAufg02Main.o PrakAufg02.o
	g++ -o prakAufg02Main prakAufg02Main.o PrakAufg02.o $(LIBS)		

prakAufg03Main:	prakAufg03Main.o PrakAufg03.o
	g++ -o prakAufg03Main prakAufg03Main.o PrakAufg03.o $(LIBS)

prakAufg04Main:	prakAufg04Main.o PrakAufg04.o
	g++ -o prakAufg04Main prakAufg04Main.o PrakAufg04.o $(LIBS)

praktMain:	praktMain.o Prak_P1.o Prak_P2.o Prak_P3.o
	g++ -o praktMain praktMain.o Prak_P1.o Prak_P2.o Prak_P3.o $(LIBS)

sortDemo.o:	sortDemo.C
	g++ -c $(CFLAGS) sortDemo.C

SortDemo.o:	SortDemo.C  SortDemo.C
	g++ -c $(CFLAGS) SortDemo.C
	
prakAufg01Main.o:	prakAufg01Main.C
	g++ -c $(CFLAGS) prakAufg01Main.C	
	
prakAufg03Main.o:	prakAufg03Main.C
	g++ -c $(CFLAGS) -DUNIX -D_REENTRANT  prakAufg03Main.C

prakAufg04Main.o:	prakAufg04Main.C
	g++ -c $(CFLAGS)   prakAufg04Main.C	


PrakAufg01.o:	PrakAufg01.H PrakAufg01.C	
	g++ -c $(CFLAGS) PrakAufg01.C	
	
PrakAufg02.o:	PrakAufg02.H PrakAufg02.C	
	g++ -c $(CFLAGS) PrakAufg02.C	

PrakAufg03.o:	PrakAufg03.H PrakAufg03.C	
	g++ -c $(CFLAGS) -DUNIX -D_REENTRANT PrakAufg03.C
	
PrakAufg04.o:	PrakAufg04.H PrakAufg04.C	
	g++ -c $(CFLAGS) -std=c++11 PrakAufg04.C	
	
praktMain.o:	praktMain.C
	g++ -c $(CFLAGS) praktMain.C
	
Prak_P1.o:	Prak_P1.H Prak_P1.C
	g++ -c $(CFLAGS) Prak_P1.C

Prak_P2.o:	Prak_P2.H Prak_P2.C
	g++ -c $(CFLAGS) Prak_P2.C
	
Prak_P3.o:	Prak_P3.H Prak_P3.C
	g++ -c $(CFLAGS) Prak_P3.C

V00.o:	V00.C V01.H
	g++ -c $(CFLAGS) V00.C
	
V01.o:	V01.C V01.H
	g++ -c $(CFLAGS) V01.C
	
V02.o:	V02.C V02.H
	g++ -c $(CFLAGS) V02.C

V03.o:	V03.C V03.H
	g++ -c $(CFLAGS) V03.C
	
V04.o:	V04.C V04.H
	g++ -c $(CFLAGS) V04.C
	
V05.o:	V05.C V05.H
	g++ -c $(CFLAGS) V05.C	
	
V06.o:	V06.C V06.H
	g++ -c $(CFLAGS) V06.C		
	
V07.o:	V07.C V07.H
	g++ -c $(CFLAGS) V07.C			
	
V08.o:	V08.C V08.H
	g++ -c $(CFLAGS) V08.C				
	
	
V09.o:	V09.C V09.H
	g++ -c $(CFLAGS) V09.C				
		
runMain:	main
	./main
	

doc:
	doxygen Doxyfile 

clean:
	rm  -r *.o  DOXYGENDOC main wxWidgetMain gameOfLifeMain prakAufg01Main prakAufg02Main prakAufg03Main prakAufg04Main praktMain sortDemo
	
