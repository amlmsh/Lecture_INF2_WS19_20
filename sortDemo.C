#include "SortDemo.H"

#include <wx/wx.h>


class MyApp : public wxApp
{
public:
	bool OnInit()
	{
		DrawWindow *win = new DrawWindow(wxT("Sort View"),
					new DataArraySelectionSort(100));

	    win->Show();
	    return true;
	}


};

wxIMPLEMENT_APP(MyApp);

