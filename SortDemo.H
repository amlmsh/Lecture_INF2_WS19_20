/*
 * SortDemo.H
 *
 *  Created on: Feb 26, 2018
 *      Author: aml
 */

#ifndef SORTDEMO_H_
#define SORTDEMO_H_

#include <string>

#include <wx/wx.h>


void demoSort();

class DataArrayToSort{
public:
	DataArrayToSort(int size = 100);
	int getSize();
	int getElementAt(int idx);
	int getIndex(int value);
	void out();
	virtual void init();
	/**
	 *
	 * Is intended to be a step-wise sorting routine.
	 * If called it processes only one sorting-step and
	 * returns TRUE if array is sorted otherwise FALSE.
	 * If FALSE the method has to be called again and
	 * again until return value is TRUE.
	 *
	 * It is up to the concrete implementation what
	 * a single sorting-step is.
	 *
	 */
	virtual bool sortArray() = 0;

protected:
	void swapElements(int idxA, int idxB);
	int size_;
	int *dataArray_;
};


class DataArraySelectionSort : public DataArrayToSort{
public:
	DataArraySelectionSort(int i = 100);
	bool sortArray();

};


class DataArrayBubbleSort : public DataArrayToSort{
public:
	DataArrayBubbleSort(int i = 100);
	bool sortArray();

};


class DataArrayInsertionSort : public DataArrayToSort{
public:
	DataArrayInsertionSort(int i = 100);
	bool sortArray();

};

/*
class DataArrayAsciiOutput{
public:
	DataArrayAsciiOutput(DataArrayToSort *da = nullptr);
	std::string outputH();
	std::string outputV();

protected:
	DataArrayToSort *da_;
};
*/


class ViewPanelDataArray : public wxPanel{
public:
	ViewPanelDataArray(wxFrame * parent);
	void setDataArray(DataArrayToSort *dA);
    void update(int n);

protected:
	void onRightClick(wxPaintEvent & event);
	void onLeftClick(wxMouseEvent& event);
	void onPaint(wxPaintEvent & event);
	void drawPoints(wxPaintDC *dc);
	DataArrayToSort *dA_;
	int offSetX_;
	int offSetY_;

};


class DrawWindow : public wxFrame{
public:
	DrawWindow(const wxString& winTitle, DataArrayToSort *da);
	void onStepButton(wxCommandEvent & event);
	void onStep10Button(wxCommandEvent & event);
	void onStep50Button(wxCommandEvent & event);
	void onResetButton(wxCommandEvent & event);

protected:
	ViewPanelDataArray *view_;
	DataArrayToSort *da_;
};



#endif /* SORTDEMO_H_ */
