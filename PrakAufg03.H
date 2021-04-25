/*
 * PrakAufg03.H
 *
 *  Created on: 17.04.2018
 *      Author: aml
 *
 *
 *      SW-Framework fuer Praktikumsaufgabe 3
 *
 *      Implementiert werden soll das sog.  "Game of Life".
 *
 *      Die Dimensionen des Feldes sollen parametrisiert sein.
 *      Die Regeln des Spiels soll durch Vererbung einfach
 *      veraenderbar sein.
 *      Der Stand einer Simulation als XML Datei abgespeichert
 *      werden koennen.
 *
 *
 */

#ifndef PRAKAUFG03_H_
#define PRAKAUFG03_H_

#include <stdexcept>
#include <string>

#include <wx/wx.h>
#include <wx/dcbuffer.h>


#include <pthread.h>

// On Linux, you must compile with the -D_REENTRANT option.  This tells
// the C/C++ libraries that the functions must be thread-safe
//#ifndef _REENTRANT
//#error ACK! You need to compile with _REENTRANT defined since this uses threads
//#endif



namespace SemesterProgramming{



/**
 *
 * \file PrakAufg03.H
 *
 * \brief Contains all the class definitions used
 * for the Game of Life demo.

 * It contains of class GenDataField and its
 * derived class GenDataFieldIO used to represent
 * the Game of Life world.
 * It also contains the GameOfLife class the wxWidget
 * classes implementing the GUI.
 *
 */





/**
 *
 *  \class GenDataField
 *  \@param T Type
 *  \brief     A template class definition. The class
 *  implements generic data container of a 2-dimensional
 *  data field - a container of arbitrary data types.
 *
 *
 *  \author Martin Huelse, mhuelse@fh-bielefeld.de
 *
 *  \date    03.02.2017
 *
 */
template<typename T>
class GenDataField {
public:
	/**
	 *
	 * \brief Constructor
	 */
	        GenDataField();


	    	/**
	    	 *
	    	 * \brief Destructor
	    	 *
	    	 */
   virtual ~GenDataField();

	/**
	 * \brief Gives the currently defined width-dimension.
	 *
	 * \return int width-dimension size of the 2-dimensional data field
	 *
	 */
   int      width();



	/**
	 * \brief Gives the currently defined height-dimension.
	 *
	 * \return int width-dimension size of the 2-dimensional data field
	 *
	 */
   int      height();

	/**
	 *
	 * \brief Initialisation of the 2-dimensional data field
	 *
	 * \param wDim  width-dimension of the 2-dimensional data field
	 * \param hDim  height-dimension of the 2-dimensional data field
	 * \throws std::invalid_argument or std::runtime_error if one dimension parameters is
	 *         smaller 1 or memory allocation fails.
	 *
	 */
   void     init(int wDim, int hDim) throw (std::invalid_argument,std::runtime_error);

	  /**
	   *
	   *
	   * \brief Clearing of the data field. It deletes all current data and
	   * frees the allocated memory.
	   *
	   * @return void
	   *
	   */
   void     clear();

	/**
	 *
	 * \brief Assigns the data item of the 2-dimensional data field for the given index
	 *
	 * \param w  width-dimension index of the 2-dimensional data field
	 * \param h  height-dimension index of the 2-dimensional data field
	 * \param dataItem  OODataItem data item contains the data to be assigned
	 * \throws std::out_of_range if one index parameter is out of range of the given 2-dimensional data field.
	 *
	 */
   void     set(int w, int h, T const &dataItem) throw (std::out_of_range);

	/**
	 *
	 * \brief Returns the value of the 2-dimensional data field for the given index
	 *
	 * \param w  width-dimension index of the 2-dimensional data field
	 * \param h  height-dimension index of the 2-dimensional data field
	 * \param dataItem  OODataItem data item contains the data of the given index
	 *
	 * \throws std::out_of_range if one dimension parameters is smaller 1.
	 *
	 * \throws std::out_of_range if one index parameter is out of range of the given 2-dimensional data field
	 *
	 */
   void     get(int w, int h, T &dataItem)       throw (std::out_of_range);

protected:
   // helper methods

	  /**
	   *
	   * Returns the index of the 1-dimensional array derived from the (w,h)-parameter of the
	   * 2-dimensional data field.
	   *
	   * \return int global index
	   */
   int          glbIndex(int w, int h)  throw (std::runtime_error);

	  /**
	   *
	   * Throws and exception if  the given (w,h)-parameter is out of range of the currently
	   * initialized data field.
	   *
	   * @return int global index
	   */
   void         checkRange(int w, int h)throw (std::out_of_range);

   // data

	  /**
	   *
	   * \brief Pointer to the 1-dimensional array storing all data items of the
	   * 2-dimensional data field.
	   */
   T *ptrDataField_;

	  /**
	   *
	   * \brief width-dimension size of the 2-dimensional data field
	   * (positive number larger one)
	   *
	   */
   int wDim_;

	  /**
	   *
	   * \brief height-dimension size of the 2-dimensional data field
	   * (positive number larger one)
	   *
	   */
   int hDim_;
};


/**
 *
 *  \class GenDataFieldIO
 *  \@param T Type
 *  \brief     A template class derived from GenDataField. The class
 *  implements reading from and write to file the data of the 2-dimensional
 *  data field.
 *
 *
 *  \author Martin Huelse, mhuelse@fh-bielefeld.de
 *
 *  \date    03.02.2017
 *
 */
template<typename T>
class GenDataFieldIO : public GenDataField<T> {

public:

	/**
	 *
	 * \brief Constructor
	 */
	        GenDataFieldIO();

	    	/**
	    	 *
	    	 * \brief Destructor
	    	 *
	    	 */
   virtual ~GenDataFieldIO();


	/**
	 *
	 * \brief Reads data of the field data from file.
	 *
	 * @param sourceFileName  std::string file name of the data file
	 *
	 * \throws std::runtime_error if error occurs during reading
	 *
	 */
   void     readFromFile(std::string sourceFileName) throw (std::runtime_error);

	/**
	 *
	 * \brief Write data of the field data to file.
	 *
	 * @param sinkFileName  std::string file name of the data file
	 *
	 * \throws std::runtime_error if error occurs during writing
	 *
	 */
   void     writeToFile(std::string sinkFileName) throw (std::runtime_error);


};

/**
 *
 *  \class GameOfLife
 *  \@param T Type
 *  \brief     Class implementing basic functionality of the
 *  		Game of Life. This includes initialisation of the
 *  		world (dimension, initial state) and the update rules.
 *
 *
 *  \author Martin Huelse, mhuelse@fh-bielefeld.de
 *
 *  \date    Apr. 2018
 *
 */
class GameOfLife{
public:

	/**
	 *
	 * \brief Constructor
	 *
	 * The constructior initialises the whole data structre
	 *
	 */
	GameOfLife(int dimX = 100, int dimY=100);

	/**
	 *
	 * \brief Destructor
	 */
	~GameOfLife();


	/**
	 *
	 * \brief initialisation of the game field
	 *	This method initialises the world with a
	 *	particular pattern (it can be randomized
	 *	as well as pre-defined patterns).
	 *
	 *
	 *
	 */
	void initBoard();


	/**
	 *
	 * \brief Applies the update rule once.
	 *
	 */
	void update();

	/**
	 *
	 * \brief Writes the current state of the world
	 * into a xml-file.
	 *
	 * \@param String  name (incl. path) of the xml-file
	 *
	 */
	void writeXmlToFile(std::string fileName);

	/**
	 *
	 *	\brief Returns the value of a particular cell
	 *
	 *	\param  int x  index of the dimension X
	 *	\param  int y  index of the dimension Y
	 *
	 *	if x or y are out of range the corresponding
	 *	indices are calculated interpreting the grid
	 *	as an torso (meaning cossing one end leads to
	 *	the entering of the world again on the other
	 *	end).
	 *
	 *	Comment: This calculation saves a lot of
	 *	thinking when implementing the updates rules
	 *	including the handling of the edges of the world.
	 *
	 * \return short current state of the cell
	 */
	short getCell(int x, int y);

	/**
	 *	\brief Returns the X dimension of the game of life world
	 *
	 *  \return int  X dimension of the game of life world
	 */
	int getDimX();

	/**
	 *	\brief Returns the Y dimension of the game of life world
	 *
	 *  \return int  Y dimension of the game of life world
	 */
	int getDimY();

protected:


	/**
	 * \brief Implements the update rule to a particular cell
	 * and its neighbors. The state of the cell and the neighbors
	 * is given.
	 *
	 * \param short cell: state of the cell, the rule is applied to
	 *
	 * \param short N:  state of the N-neighbor
	 * \param short S:  state of the N-neighbor
	 * \param short E:  state of the N-neighbor
	 * \param short W:  state of the N-neighbor
	 * \param short NE: state of the N-neighbor
	 * \param short SE: state of the N-neighbor
	 * \param short SW: state of the N-neighbor
	 * \param short NW: state of the N-neighbor
	 *
	 * \return short new state of  the cell
	 *
	 */
	short updateRule(short cell, short N, short NE, short E, short SE, short S, short SW, short W, short NW);


	/**
	 *
	 * \brief returns the state of the N-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the N-neighbor of the cell
	 *
	 */
	short getN(int x, int y);

	/**
	 * \brief returns the state of the N-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the N-neighbor of the cell
	 *
	 */
	short getNE(int x, int y);

	/**
	 * \brief returns the state of the NE-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the NE-neighbor of the cell
	 *
	 */
	short getE(int x, int y);

	/**
	 * \brief returns the state of the E-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the E-neighbor of the cell
	 *
	 */
	short getSE(int x, int y);

	/**
	 * \brief returns the state of the SE-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the SE-neighbor of the cell
	 *
	 */
	short getS(int x, int y);

	/**
	 * \brief returns the state of the SW-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the SW-neighbor of the cell
	 *
	 */
	short getSW(int x, int y);

	/**
	 * \brief returns the state of the W-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the W-neighbor of the cell
	 *
	 */
	short getW(int x, int y);

	/**
	 * \brief returns the state of the NW-neighbors of
	 * the cell given by the coordinates x and y
	 *
	 * \@param int x  index of the cell
	 * \@param int y  index of the cell
	 *
	 * \return int state of the NW-neighbor of the cell
	 *
	 */
	short getNW(int x, int y);



	/**
	 *
	 * \brief Data structure representing the
	 * state of the game of life world.
	 * The single cell states are stored are
	 * data items of type short
	 *
	 */
	GenDataFieldIO<short> field_;

};



/**
 *
 *  \class ViewPanelGameOfLife
 *  \brief     View panel for the drawing of the game of life grid. The class
 *  implements the call-back functions used by the GUI in order.
 *
 *
 *  \author Martin Huelse, mhuelse@fh-bielefeld.de
 *
 *  \date    Apr. 2018
 *
 */
class ViewPanelGameOfLife: public wxPanel {
public:

	/**
	 *
	 *  \brief constructor
	 *
	 */
	ViewPanelGameOfLife(wxFrame * parent);

	/**
	 *
	 * \brief initialises the view with a particular
	 * instance of the  GameOfLife object
	 *
	 * \@param *GameOfLife  object of the class
	 */
	void setGame(GameOfLife *gL);

	/**
	 *
	 * \brief Update of the Game of Life world.
	 * It applies the Game of Life update rule n-times.
	 *
	 * \@param int n number of times the update rule is applied
	 *               (if n < 0 then n is set to 0, no update)
	 *
	 */
	void update(int n);

protected:

	/**
	 *
	 * \brief call-back function for catching GUI events
	 *
	 *	\@param *wxPaintEvent  event, wxWidget event
	 */
	void onRightClick(wxPaintEvent & event);

	/**
	 *
	 * \brief call-back function for catching GUI events
	 *
	 *	\@param *wxPaintEvent  event, wxWidget event
	 */

	void onLeftClick(wxMouseEvent& event);

	/**
	 *
	 * \brief call-back function for catching GUI events
	 *
	 *	\@param *wxPaintEvent  event, wxWidget event
	 */

	void onPaint(wxPaintEvent & event);

	/**
	 *
	 * \brief specific draw function of the wxWidget framework
	 *
	 *	\@param *wxClientDC  dc, wxWidget drawing panel
	 */
	void drawPoints(wxClientDC *dc);



	/**
	 *
	 * \brief reference to the GameOfLife object
	 *
	 */
	GameOfLife *gL_= NULL;


	/**
	 *
	 * \brief reference to the drawing object
	 *
	 */
	wxClientDC *dc_ = NULL;
	//wxBufferedDC *dc_ = NULL;

	/**
	 *
	 * \brief offSetX for plotting the data
	 *
	 */
	const int offSetX_ = 5;

	/**
	 *
	 * \brief offSetY for plotting the data
	 *
	 */
	const int offSetY_ = 5;


};



/**
 *
 *  \class DrawWindow
 *  \brief     GUI window of game of life. The class
 *  implements buttons and the drawing area for
 *  displaying and running the Game Of Life.
 *
 *
 *  \author Martin Huelse, mhuelse@fh-bielefeld.de
 *
 *  \date    Apr. 2018
 *
 */
class DrawWindow: public wxFrame {
public:

	/**
	 *
	 * \brief constructor
	 *
	 * Definition of the GUI and binding GUI elements (buttons etc.)
	 * with the call-back functions of the drawing panel.
	 *
	 */
	DrawWindow(const wxString& winTitle, GameOfLife *da);

	/**
	 *
	 *  \brief call-back function for button 1-Step
	 *
	 *	\@param wxCommandEvent event  wxWidget event
	 */
	virtual void onStepButton(wxCommandEvent & event);

	/**
	 *
	 *  \brief call-back function for button 10-Step
	 *
	 *	\@param wxCommandEvent event  wxWidget event
	 */
	virtual void onStep10Button(wxCommandEvent & event);

	/**
	 *
	 *  \brief call-back function for button 50-Step
	 *
	 *	\@param wxCommandEvent event  wxWidget event
	 */
	virtual void onStep50Button(wxCommandEvent & event);

	/**
	 *
	 *  \brief call-back function for button Reset
	 *
	 *	\@param wxCommandEvent event  wxWidget event
	 */
	virtual void onResetButton(wxCommandEvent & event);

protected:

	/**
	 *
	 * \brief reference to wxWidget drawing panel
	 *
	 */
	ViewPanelGameOfLife *view_;

	/**
	 *
	 * \brief reference to the GameOfLife object
	 *
	 */
	GameOfLife *gL_;
};



class DrawWindowThread: public DrawWindow {

public:
	DrawWindowThread(const wxString& winTitle, GameOfLife *da);
	void onStepButton(wxCommandEvent & event);
};

} // end namespace SemesterProgramming


#endif /* PRAKAUFG03_H_ */
