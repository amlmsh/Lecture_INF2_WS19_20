/*
 * PrakAufg03.C
 *
 *  Created on: 17.04.2018
 *      Author: aml
 */

#include <iostream>
#include <sstream>
#include <fstream>




#include "PrakAufg03.H"





namespace SemesterProgramming{



GameOfLife::GameOfLife(int dimX, int dimY){
	field_.init(dimX, dimY);
}



GameOfLife::~GameOfLife(){
	// destroys frees the whole field
	field_.clear();
}




void GameOfLife::initBoard(){

	/**
	 *
	 * set all cell dead
	 *
	 */
	for(int x=0; x < field_.width(); x++){
		for(int y=0; y < field_.height(); y++){
				field_.set(x,y,0);
		}
	}



	for(int x=0; x < field_.width(); x++){
		for(int y=0; y < field_.height(); y++){
			if( (rand() / (float)RAND_MAX) < 0.25 ){
				field_.set(x,y, 1);
			}else{
				field_.set(x,y,0);
			}
		}
	}



	/*
	field_.set(50,50,1);
	field_.set(50,51,1);
	field_.set(50,52,1);
	field_.set(49,51,1);
	field_.set(51,50,1);
	*/

	return;
}

short GameOfLife::updateRule(short cell, short N, short NE, short E, short SE, short S, short SW, short W, short NW){


	short sum = N + NE + E + SE + S + SW + W + NW;

	if(!cell && (sum == 3)){
		return true;  // cell gets alive
	}

	if(cell && (sum  < 2)){
		return false;  // cell gets dies
	}

	if(cell && ( (sum == 2) || (sum == 3) )){
		return true;  // cell stays alive
	}

	if(cell && (sum > 3)){
		return false;  // cell dies
	}

	return cell;
}


void GameOfLife::update(){
	GenDataField<short> tmpField;
	int dimX = field_.width();
	int dimY = field_.height();

	short currentValue, n, ne, e, se, s, sw, w, nw;
	tmpField.init(dimX, dimY );

	// write new data into tmpField
	for(int x=0; x < dimX; x++){
		for(int y=0; y < dimY; y++){
			field_.get(x,y,currentValue);


			currentValue = updateRule(currentValue,
					getN(x,y),getNE(x,y),getE(x,y),getSE(x,y),
					getS(x,y),getSW(x,y),getW(x,y),getNW(x,y));


			tmpField.set(x,y,currentValue);
		}
	}

	// write new state from tmpField back to the board
	for(int x=0; x < dimX; x++){
		for(int y=0; y < dimY; y++){
			tmpField.get(x,y,currentValue);
			field_.set(x,y,currentValue);
		}
	}

	tmpField.clear();

	return;
}


short GameOfLife::getN(int x, int y){
	int dimY = field_.height();
	short value;
	int tmpX, tmpY;

	tmpX = x;
	tmpY = y - 1;
	if(tmpY < 0 )
		tmpY = dimY - 1;

	field_.get(tmpX,tmpY,value);

	return value;
}

short GameOfLife::getNE(int x, int y){
	int dimX = field_.width();
	int dimY = field_.height();
	short value;
	int tmpX, tmpY;
	tmpX = x + 1;
	tmpY = y - 1;
	if(tmpX > (dimX - 1)) tmpX = 0;
	if(tmpY < 0         ) tmpY = dimY - 1;
	field_.get(tmpX,tmpY,value);
	return value;
}

short GameOfLife::getE(int x, int y){
	int dimX = field_.width();
	short value;
	if(x >= (dimX - 1)){
		field_.get(0,y,value);
	}else{
		field_.get(x+1,y,value);
	}
	return value;
}

short GameOfLife::getSE(int x, int y){
	int dimX = field_.width();
	int dimY = field_.height();
	short value;

	int tmpX, tmpY;

	tmpX = x + 1;
	tmpY = y + 1;
	if(tmpX > (dimX-1)) tmpX = 0;
	if(tmpY > (dimY-1)) tmpY = 0;

	field_.get(tmpX,tmpY,value);

	return value;
}

short GameOfLife::getS(int x, int y){
	int dimY = field_.height();
	short value;
	if(y >= (dimY - 1) ){
		field_.get(x,0,value);
	}else{
		field_.get(x,y+1,value);
	}
	return value;
}

short GameOfLife::getSW(int x, int y){
	int dimX = field_.width();
	int dimY = field_.height();
	short value;

	int tmpX, tmpY;

	tmpX = x - 1;
	tmpY = y + 1;
	if(tmpX < 0)          tmpX = dimX - 1;
	if(tmpY > (dimY - 1)) tmpY = 0;

	field_.get(tmpX,tmpY,value);

	return value;
}

short GameOfLife::getW(int x, int y){
	int dimX = field_.width();
	short value;
	if(x == 0){
		field_.get(dimX-1,y,value);
	}else{
		field_.get(x-1,y,value);
	}
	return value;
}

short GameOfLife::getNW(int x, int y){
	int dimX = field_.width();
	int dimY = field_.height();
	short value;

	int tmpX, tmpY;

	tmpX = x - 1;
	tmpY = y - 1;
	if(tmpX < 0) tmpX = dimX - 1;
	if(tmpY < 0) tmpY = dimY - 1;

	field_.get(tmpX,tmpY,value);

	return value;
}


void GameOfLife::writeXmlToFile(std::string fileName){
	return;
}

short GameOfLife::getCell(int x, int y){
	short tmp;
	field_.get(x,y,tmp);
	return tmp;
}

int GameOfLife::getDimX(){
	return field_.width();
}
int GameOfLife::getDimY(){
	return field_.height();
}



ViewPanelGameOfLife::ViewPanelGameOfLife(wxFrame * parent) :
		wxPanel(parent) {
	gL_ = NULL;

	dc_ = NULL;


	Centre();

	this->Connect(wxEVT_PAINT,
			wxPaintEventHandler(ViewPanelGameOfLife::onRightClick));
	this->Connect(wxEVT_RIGHT_DOWN,
			wxPaintEventHandler(ViewPanelGameOfLife::onRightClick));
	this->Connect(wxEVT_LEFT_DOWN,
			wxMouseEventHandler(ViewPanelGameOfLife::onLeftClick));
}

void ViewPanelGameOfLife::setGame(GameOfLife *dA) {
	gL_ = dA;
}

void ViewPanelGameOfLife::onPaint(wxPaintEvent & event) {
	if (gL_ != NULL) {
		this->update(0);
	}
}

void ViewPanelGameOfLife::onRightClick(wxPaintEvent & event) {
		if (gL_ != NULL) {
			this->update(0);
		}
}

void ViewPanelGameOfLife::onLeftClick(wxMouseEvent& event) {
	if (gL_ != NULL) {
		this->update(0);
	}
}

void ViewPanelGameOfLife::drawPoints(wxClientDC *dc) {
	wxBufferedDC *buffer = new wxBufferedDC(dc);

	buffer->SetUserScale(5,5);
	buffer->Clear();
	buffer->DrawRectangle(4,4,102,102);
	wxCoord x = 0;
	wxCoord y = 0;

	// paint the game board here
	buffer->SetBrush(*wxBLACK_BRUSH);
	for(int xG = 0; xG < gL_->getDimX(); xG++){
		for(int yG = 0; yG < gL_->getDimY(); yG++){
			x = xG;
			y = yG;
			if(gL_->getCell(x,y)){
				buffer->DrawRectangle(x + 5, y + 5,1,1);
			}
		}
	}
	buffer->SetBrush(*wxWHITE_BRUSH);

	delete buffer;
}


void ViewPanelGameOfLife::update(int n){
	if(n < 0){
		n = 0;
	}

	if (gL_ != NULL) {
		// update the game
		for(int i = 0; i < n; i++){
			gL_->update();
		}
		// update the view
		if(dc_ == NULL){
			dc_ = new wxClientDC(this);
		}
		drawPoints(dc_);
	}
}


DrawWindow::DrawWindow(const wxString& winTitle, GameOfLife *da)
	: wxFrame((wxFrame *)NULL, -1,  winTitle, wxPoint(-1,-1), wxSize(630,550)){

	view_ = new ViewPanelGameOfLife(this);

    gL_ = da;
	view_->setGame(gL_);


	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);



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
	gL_->initBoard();
	view_->update(0);
}




DrawWindowThread::DrawWindowThread(const wxString& winTitle, GameOfLife *da) : DrawWindow(winTitle, da){
	;;
}

void DrawWindowThread::onStepButton(wxCommandEvent & event){
	while(1){
		view_->update(1);
	}
}







template<typename T>
GenDataField<T>::GenDataField() {
	 ptrDataField_ = nullptr;
	 wDim_ = 0;
	 hDim_ = 0;
}

template<typename T>
GenDataField<T>::~GenDataField() {
	clear();
}

template<typename T>
void GenDataField<T>::init(int wDim, int hDim) throw(std::invalid_argument,std::runtime_error){
	std::stringstream msg;

	if(wDim < 1){
		msg << "Dimension parameters must be positive integer larger 0, ";
		msg << "but first parameter is " << wDim  << ".";
		throw std::invalid_argument(msg.str());
	}
	if(hDim < 1){
		msg << "Dimension parameters must be positive integer larger 0, ";
		msg << "but second parameter is " << hDim  << ".";
		throw std::invalid_argument(msg.str());
	}

	wDim_ = wDim;
	hDim_ = hDim;
	try {
		// allocate memory and initializing
		ptrDataField_ = new T[wDim_*hDim_]();
	} catch(...) {
		msg << "Can not allocate memory (required memory size: ";
		msg << wDim << "x" << hDim << "=" << (wDim*hDim) << sizeof(T) << " byte.";
		throw std::runtime_error(msg.str());
	}
}

template<typename T>
void GenDataField<T>::clear() {
	if(ptrDataField_ != nullptr){
		wDim_ = 0;
		hDim_ = 0;
		delete [] ptrDataField_;
		ptrDataField_ = nullptr;
	}
}


template<typename T>
int GenDataField<T>::width() {
	return wDim_;
}

template<typename T>
int GenDataField<T>::height() {
	return hDim_;
}

template<typename T>
int GenDataField<T>::glbIndex(int w, int h) throw (std::runtime_error){
	return ((w*hDim_) + h);
}

template<typename T>
void GenDataField<T>::checkRange(int w, int h)throw (std::out_of_range){
	std::stringstream msg;

	if((w < 0) || (w > (wDim_-1))){
		msg << "Index parameters w must be in the range [0, " << (wDim_-1) << "] ";
		msg << "but w parameter is " << w  << ".";
		throw std::out_of_range(msg.str());
	}
	if((h < 0) || (h > (hDim_-1))){
		msg << "Index parameters h must be in the range [0, " << (hDim_-1) << "] ";
		msg << "but w parameter is " << h << ".";
		throw std::out_of_range(msg.str());
	}
}

template<typename T>
void GenDataField<T>::set(int w, int h, const T& dataItem) throw (std::out_of_range){
	try{
		checkRange(w,h);
	}catch(std::out_of_range &e){
		throw e;
	}catch(...){
		throw std::exception();
	}
	ptrDataField_[glbIndex(w,h)] = dataItem;
	return;
}

template<typename T>
void GenDataField<T>::get(int w, int h, T &dataItem) throw (std::out_of_range){
	try{
		checkRange(w,h);
	}catch(std::out_of_range &e){
		throw e;
	}catch(...){
		throw std::exception();
	}
	dataItem = ptrDataField_[glbIndex(w,h)];
	return;
}





template<typename T>
GenDataFieldIO<T>::GenDataFieldIO() : GenDataField<T>() { }

template<typename T>
GenDataFieldIO<T>::~GenDataFieldIO() { }



template<typename T>
void GenDataFieldIO<T>::readFromFile(std::string sourceFileName) throw (std::runtime_error){
	T dataItem;
	std::ifstream sourceFile(sourceFileName);
	int wDim, hDim, size;
	int counter = 0;
	std::string line;


	// read header
	std::getline(sourceFile,line);
	sscanf( line.c_str(), "wDim=%d",&wDim );
	std::getline(sourceFile,line);
	sscanf( line.c_str(), "hDim=%d",&hDim );
	this->clear();
	this->init(wDim,hDim);
	size = (this->width() *  this->height());

	// read data
	if(!sourceFile.is_open()){
		throw std::runtime_error("Cannot open input file.");
	}

	while(( sourceFile >> dataItem) && (counter < size )){
		(this->ptrDataField_)[counter]  = dataItem;
		counter++;
	}

	sourceFile.close();
	return;
}

template<typename T>
void GenDataFieldIO<T>::writeToFile(std::string fileName) throw (std::runtime_error){
	std::ofstream sinkFile(fileName);
	int size = this->width()*this->height();
	if(!sinkFile.is_open()){
		throw std::runtime_error("Cannot open output file.");
	}
	// write header
	sinkFile << "wDim=" << this->wDim_ << std::endl;
	sinkFile << "hDim=" << this->hDim_ << std::endl;
	//write data
	for(int i = 0; i < size; i++){
		sinkFile <<  this->ptrDataField_[i] << std::endl;
	}
	sinkFile.close();
	return;
}

} // end namespace SemesterProgramming

