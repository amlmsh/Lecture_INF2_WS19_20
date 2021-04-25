/*
 * SortDemo.C
 *
 *  Created on: Feb 26, 2018
 *      Author: aml
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "SortDemo.H"

/*
void demoSort(){
	DataArrayToSort *da = new DataArrayBubbleSort(20);
	DataArrayAsciiOutput *output = new DataArrayAsciiOutput(da);


	std::cout << output->outputH() << std::endl;
	std::string i;

	while(!da->sortArray()){

		std::cout << output->outputH() << std::endl << std::endl << std::endl;
		usleep(80000);
	}
}
*/

DataArrayToSort::DataArrayToSort(int size) {
	srand((unsigned) time(0));
	size_ = size;
	dataArray_ = new int[size_];
	for (int i = 0; i < size_; i++) {
		dataArray_[i] = i;
	}
	// swap
	int idx;
	for (int i = 0; i < size_; i++) {
		idx = rand() % size_;
		swapElements(i, idx);
	}
}

int DataArrayToSort::getSize() {
	return size_;
}

int DataArrayToSort::getElementAt(int idx) {
	if (idx < 0)
		return dataArray_[0];
	else if (idx > (size_ - 1))
		return dataArray_[size_ - 1];
	else
		return dataArray_[idx];
}

void DataArrayToSort::out() {
	std::cout << "[ ";
	for (int i = 0; i < (size_- 1); i++){
		std::cout << dataArray_[i] << ", ";
	}
	std::cout << dataArray_[size_ - 1] << "]\n";

}

void DataArrayToSort::swapElements(int idxA, int idxB) {
	int tmp = dataArray_[idxA];
	dataArray_[idxA] = dataArray_[idxB];
	dataArray_[idxB] = tmp;
}


void DataArrayToSort::init(){
	int idx;
	for(int i=0; i < size_; i++){
		idx = rand() % size_;
		swapElements(i,idx);
	}
	return;
}

int DataArrayToSort::getIndex(int value){
	int idx;
	for(int i=0; i < size_; i++){
		if(value == dataArray_[i]){
			return i;
		}
	}
	return -1;
}

/*
DataArrayAsciiOutput::DataArrayAsciiOutput(DataArrayToSort *da){
	da_ = da;
}

std::string DataArrayAsciiOutput::outputV(){
	if(da_ == nullptr) return std::string("");

	int i, size;
	std::string result("");
	std::string tmp;
	size = da_->getSize();

	for(i = 0; i < size; i++){
		tmp = std::string(da_->getElementAt(i)+1, '#');
		tmp.append("\n");
		result.append(tmp);
	}
	return result;
}


std::string DataArrayAsciiOutput::outputH(){
	if(da_ == nullptr) return std::string("");

	int i, size;
	std::stringstream ss;
	std::string result("");
	std::string tmp;
	size = da_->getSize();


	result.append(std::string(size, '-'));
	result.append("\n");
	for(i = size-1; i > -1; i--){
		ss << std::setw(5)  << i;
		tmp = ss.str();
		ss.str(std::string());
		ss.clear();
		tmp.append(":");
		tmp.append(std::string(da_->getIndex(i), ' '));
		tmp.append("o\n");
		result.append(tmp);
	}
	result.append(std::string(size, '-'));
	result.append("\n");
	return result;
}
*/

ViewPanelDataArray::ViewPanelDataArray(wxFrame * parent) :
		wxPanel(parent) {
	dA_ = NULL;
	offSetX_ = 5;
	offSetY_ = 5;

	Centre();

	this->Connect(wxEVT_PAINT,
			wxPaintEventHandler(ViewPanelDataArray::onRightClick));
	this->Connect(wxEVT_RIGHT_DOWN,
			wxPaintEventHandler(ViewPanelDataArray::onRightClick));
	this->Connect(wxEVT_LEFT_DOWN,
			wxMouseEventHandler(ViewPanelDataArray::onLeftClick));
}

void ViewPanelDataArray::setDataArray(DataArrayToSort *dA) {
	dA_ = dA;
}

void ViewPanelDataArray::onPaint(wxPaintEvent & event) {
	this->update(1);
}

void ViewPanelDataArray::onRightClick(wxPaintEvent & event) {
		if (dA_ != NULL) {
			dA_->init();
			drawPoints(new wxPaintDC(this));
		}
}

void ViewPanelDataArray::onLeftClick(wxMouseEvent& event) {
	this->update(1);
}

void ViewPanelDataArray::drawPoints(wxPaintDC *dc) {

	dc->SetUserScale(3,3);
	dc->Clear();
	dc->DrawRectangle(4,4,102,102);
	wxCoord x = 0;
	wxCoord y = 0;

	for (int i = 0; i < dA_->getSize(); i++) {
		x = i;
		y = dA_->getElementAt(i);
		dc->SetBrush(*wxBLACK_BRUSH);
		dc->DrawCircle(x + 5, 110 - y - 5, 1);
		dc->SetBrush(*wxWHITE_BRUSH);
	}

	delete dc;
}


void ViewPanelDataArray::update(int n){
	if(n < 0){
		n = 0;
	}

	if (dA_ != NULL) {
		for(int i = 0; i < n; i++){
			dA_->sortArray();
		}
		drawPoints(new wxPaintDC(this));
		dA_->out();
	}
}


DrawWindow::DrawWindow(const wxString& winTitle, DataArrayToSort *da)
	: wxFrame((wxFrame *)NULL, -1,  winTitle, wxPoint(-1,-1), wxSize(430,330)){

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);


	view_ = new ViewPanelDataArray(this);
    sizer->Add(view_, 1, wxEXPAND);

    wxButton *step   = new wxButton(this,1,wxT("Step"));
    wxButton *step10 = new wxButton(this,1,wxT("Step + 10"));
    wxButton *step50 = new wxButton(this,1,wxT("Step + 50"));
    wxButton *reset  = new wxButton(this,1,wxT("Reset"));

    buttonSizer->Add(step, wxALIGN_TOP,1);
    buttonSizer->Add(step10, wxALIGN_TOP,1);
    buttonSizer->Add(step50, wxALIGN_TOP,1);
    buttonSizer->Add(reset, wxALIGN_TOP,1);

    sizer->Add(buttonSizer, 0, 0);

    this->SetSizer(sizer);
    this->SetAutoLayout(true);

    da_ = da;
	view_->setDataArray(da_);


	step->Bind(wxEVT_BUTTON, &DrawWindow::onStepButton, this);
	step10->Bind(wxEVT_BUTTON, &DrawWindow::onStep10Button, this);
	step50->Bind(wxEVT_BUTTON, &DrawWindow::onStep50Button, this);
	reset->Bind(wxEVT_BUTTON, &DrawWindow::onResetButton, this);

	return;
}

void DrawWindow::onStepButton(wxCommandEvent & event){
	view_->update(1);
}

void DrawWindow::onStep10Button(wxCommandEvent & event){
	view_->update(10);
}

void DrawWindow::onStep50Button(wxCommandEvent & event){
	view_->update(50);
}

void DrawWindow::onResetButton(wxCommandEvent & event){
	da_->init();
	view_->update(0);
}

DataArraySelectionSort::DataArraySelectionSort(int i) : DataArrayToSort(i){
	;;
};


bool DataArraySelectionSort::sortArray(){
	bool swaped = false;
	int minPos;
	for(int i = 0; i < (size_ - 1); i++){
		minPos = i;

		for(int j = (i + 1); j < size_; j++){
			if(dataArray_[j] < dataArray_[minPos]){
				minPos = j;
				swaped = true;
			}
		}
		if(swaped){
			swapElements(minPos,i);
			return false; // return after one step
		}

	}
	return true;
}




DataArrayInsertionSort::DataArrayInsertionSort(int i) : DataArrayToSort(i){
	;;
};


bool DataArrayInsertionSort::sortArray(){
	int value;
	int i;
	for(int k = 1; k <= size_; k++){
		if(dataArray_[k] < dataArray_[k-1]){
			value = dataArray_[k];
			for(i = k; (i>0) && (dataArray_[i-1]>value); i--){
				dataArray_[i] = dataArray_[i-1];
			}
			dataArray_[i] = value;
			return false; // return after one step
		}
	}
	return true;
}



DataArrayBubbleSort::DataArrayBubbleSort(int i) : DataArrayToSort(i){
	;;
};


bool DataArrayBubbleSort::sortArray(){
	bool swaped = false;
	while(true){
		for(int i=0; i < (size_-1); i++){
			if(dataArray_[i] > dataArray_[i+1]){
				swapElements(i,i+1);
				swaped = true;
			}

		}
		return !swaped;
	}
}


