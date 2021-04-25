/*
 * gameOfLifeMain.C
 *
 *  Created on: 17.04.2018
 *      Author: aml
 */

#include "PrakAufg03.H"

#include <wx/wx.h>




using namespace SemesterProgramming;



class MyApp : public wxApp
{
public:
	bool OnInit()
	{
		GameOfLife *g = new GameOfLife(100,100);

		//DrawWindow *win = new DrawWindow(wxT("Game of Life"),g);
		DrawWindowThread *win = new DrawWindowThread(wxT("Game of Life Thread"),g);

	    win->Show();

	    return true;
	}


};

wxIMPLEMENT_APP(MyApp);



