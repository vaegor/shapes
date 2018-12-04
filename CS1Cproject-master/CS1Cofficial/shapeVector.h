#ifndef SHAPEVECTOR
#define SHAPEVECTOR

#include "vector.h"
#include "shape.h"

#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "shape.h"
#include "text.h"

class shapeVector{

public:
	  //*************//
	 // Constructor //
	//*************//
	shapeVector();

	  //***********************//
	 // Program Functionality //
	//***********************//	
	void addShape();
	void deleteShape();
		/* Add other options here */

private:
	  //*********//
	 // Purpose //
	//*********//
	void ParseData();	
	void dimmensionParser(string& dimmensionString, int Array[]);
	
	int ColorEnumConverter(string Color);
	int BrushStyleEnum(string Style);
	int PenStyleEnum(string Style);

	//vector<shape*> Storage;

};

/********************************************************************************
*																				*
*	Function name: PenStyleEnum(string Style) 					 				*
*																				*
*	-Functionality: Created to convert string style to enum equivalent 			*
*																				*
*	-Variables																	*
*																				*
*	Name			Data Type		Value										*
*	------------	------------	--------------------						*
*	enumVal			int 			2 (default) 								*
*	Style 			string 			passed paramter								*
*																				*
*	-Process: Switch statement accepts string and returns its equivalent 		*
*																				*
*	-Output: return enum equivalent to be called in constructor 				*
*															  	  				*
********************************************************************************/
int PenStyleEnum(string Style){
	
	int enumVal = 1;

	if(Style == "NoPen"){
		enumVal = 0;
	}
	if(Style == "SolidLine"){
		enumVal = 1;
	}
	if(Style == "DashLine"){
		enumVal = 2;
	}
	if(Style == "DotLine"){
		enumVal = 3;
	}
	if(Style == "DashDotLine"){
		enumVal = 4;
	}
	if(Style == "DashDotDotLine"){
		enumVal = 5;
	}

	return enumVal;
}


/********************************************************************************
*																				*
*	Function name: BrushStyleEnum(string Style) 					 			*
*																				*
*	-Functionality: Created to convert string style to enum equivalent 			*
*																				*
*	-Variables																	*
*																				*
*	Name			Data Type		Value										*
*	------------	------------	--------------------						*
*	enumVal			int 			2 (default) 								*
*	Style 			string 			passed paramter								*
*																				*
*	-Process: Switch statement accepts string and returns its equivalent 		*
*																				*
*	-Output: return enum equivalent to be called in constructor 				*
*															  	  				*
********************************************************************************/
int shapeVector::BrushStyleEnum(string Style){
	
	int enumVal = 1;

	if(Style == "NoBrush"){
		enumVal = 0;
	}
	if(Style == "SolidPattern"){
		enumVal = 1;
	}
	if(Style == "HorPattern"){
		enumVal = 9;
	}
	if(Style == "VerPattern"){
		enumVal = 10;
	}	

	return enumVal;

}

/*
special enum values

int shapeVector::PenCapEnum(string Style){
	
	int enumVal = 1;

	if(Style == "NoPen"){
		enumVal = 0;
	}
	if(Style == "SolidLine"){
		enumVal = 1;
	}
	if(Style == "DashLine"){
		enumVal = 2;
	}

	return enumVal

}
*/

/********************************************************************************
*																				*
*	Function name: ColorEnumConverter(string Color) 					 		*
*																				*
*	-Functionality: Created to convert string color to enum equivalent 			*
*																				*
*	-Variables																	*
*																				*
*	Name			Data Type		Value										*
*	------------	------------	--------------------						*
*	enumVal			int 			2 (default) 								*
*	Color 			string 			passed paramter								*
*																				*
*	-Process: Switch statement accepts string and returns its equivalent 		*
*																				*
*	-Output: return enum equivalent to be called in constructor 				*
*															  	  				*
********************************************************************************/
int shapeVector::ColorEnumConverter(string Color){
	int enumVal = 2;

	if(Color == "white"){
		enumVal = 3;
	}
	if(Color == "black"){
		enumVal = 2;
	}
	if(Color == "red"){
		enumVal = 7;
	}
	if(Color == "green"){
		enumVal = 8;
	}
	if(Color == "blue"){
		enumVal = 9;
	}
	if(Color == "cyan"){
		enumVal = 10;
	}
	if(Color == "magenta"){
		enumVal = 11;
	}
	if(Color == "yellow"){
		enumVal = 12;
	}
	if(Color == "gray"){
		enumVal = 5;
	}
	return enumVal;
}

/********************************************************************************
*	PRE-CONDITION: Array of int's needed and SET TO THE CORRECT CAPACITY		*
*																				*
*	Function name: dimmensionParser(string& dimmensionString, int Array[]) 		*
*																				*
*	-Functionality: function accepts string, return's int[] of dimmensions 		*
*		ready to be passed to the corresponding shapes constructor. 			*
*		(dimmensions accepted in order from text file)							*
*																				*
*	-Variables																	*
*																				*
*	Name			Data Type	 Value											*
*	------------	------------ --------------------							*
*	dimmensionSTR 	string 														*
*	ArrPosition		int 		 0 		(Purpose: indexing value)				*
*	set 			bool 		 false 	(Purpose: flag when number's complete)	*
*																				*
*	-Process: 																	*
*		1) for loop to go through the entire string 							*
*			2) if number is found, it will check to see if the next character 	*
*				is a number														*
*				3) if number is found it will check to see if the next character*
*					is a number 												*
*			4) moves up i value to start from the newest point 					*
*		5) Saves number as a string 											*
*		6) flag triggered - casts to int - saves value to array 				*
*	-Output: Array is filled with seperate values to be assigned to Shape 		*
*																	constructer	*
*	-POST-CONDITION: Array is filled with dimmension's as intergers			 	*
*															  	  				*
********************************************************************************/
void shapeVector::dimmensionParser(string& dimmensionString, int Array[]){

	string dimmensionSTR;
	int ArrPosition = 0;

	for(int i = 0; i < dimmensionString.length(); i++){

		bool set = false;

		string startingCharacter = dimmensionString.substr(i,1); //checking first value

		int INTcharacterOver = i + 1;
		string characterOver = dimmensionString.substr(INTcharacterOver, 1);

		int INTcharacterOverNext = INTcharacterOver + 1;
		string characterOverNext = dimmensionString.substr(INTcharacterOverNext, 1);
		
		if(startingCharacter == "1" || startingCharacter == "2" || startingCharacter == "3" 
			|| startingCharacter == "4" || startingCharacter == "5" || startingCharacter == "6" 
			|| startingCharacter == "7" || startingCharacter == "8" || startingCharacter == "9" 
			|| startingCharacter == "0"){

			dimmensionSTR = startingCharacter;

			if(characterOver == "1" || characterOver == "2" || characterOver == "3" 
				|| characterOver == "4" || characterOver == "5" || characterOver == "6" 
				|| characterOver == "7" || characterOver == "8" || characterOver == "9" || characterOver == "0"){
			
				dimmensionSTR += characterOver;

				if(characterOverNext == "1" || characterOverNext == "2" || characterOverNext == "3" 
					|| characterOverNext == "4" || characterOverNext == "5" || characterOverNext == "6" 
					|| characterOverNext == "7" || characterOverNext == "8" || characterOverNext == "9" 
					|| characterOverNext == "0"){

					dimmensionSTR += characterOverNext;
				}
				i += 1;
			}
			i += 1;
			set = true;
		}

		if(set){
			int dimmension = stoi(dimmensionSTR);

			Array[ArrPosition] = dimmension;
			ArrPosition++;
		}
	}
}

/********************************************************************************
*	PRE-CONDITION:                                                              *
*                                                                               *
*	Function name: ParseData()                                            		*
*                                                                               *
*	-Functionality: Designed to open data base and fill vector with data        *
*                                                                               *
*	-Variables                                                                  *
*                                                                               *
*	Name			Data Type		Value                                       *
*	------------	------------	--------------------                        *
*	-Process:                                                                   *
*        1) Open File                                                           *
*        2) Loop to gather data until the file closes                           *
*            3) Save shape ID since all shapes share                            *
*            4) ShapeType value will save as string first,                      *
*                    then be assigned an enum                                   *
*            5) switch statement for enum to finish gathering the rest of the   *
*                   data specfic to the shape                                   *
*	-Output: Vector filled with data                                			*
*                                                                           	*
*	-POST-CONDITION: Vector filled with shapes                                  *
*                                                                               *
********************************************************************************/

void shapeVector::ParseData(){

    enum ShapeType { Line, PolyLine, Polygon, Rectangle, Square, Ellipse, Circle, Text};
    ShapeType enumVal;

    ifstream& dataBase
    dataBase.open("shapes.txt");

    //
	string target = "ShapeId: ";
	string line; 

	//General Shape Characteristics
	int ShapeId;
	string ShapeType;			//	NOTE: I could switch to enum if depending on constructors 
	string ShapeDimensions; 	// dimmensionSTR as an entire string, but will slice into individual int's
	string Color;

	int PenWidth;
	string PenStyle;
	string PenCapStyle;
	string PenJoinStyle;

	string BrushStyle;

	//Characteristics for just Text
	string TextString;
	string TextAlignment;
	string TextPointSize;
	string TextFontFamily;
	string TextFontStyle;
	string TextFontWeight;

	while(!(dataBase.eof())){	

		getline(dataBase, input);

		if(input.find(target) != std::string::npos){ //target would be found at this point 
			
			ShapeId = stoi(input.substr(9));
			getline(dataBase, shapeType);
			shapeType = shapeType.substr(11);

			getline(dataBase, ShapeDimensions);				

			if(shapeType == "Text"){

				int textDimmensions[4]; 

				getline(dataBase, TextString);
				TextString = TextString.substr(12);


				getline(dataBase, Color);
				Color = Color.substr(11);

				getline(dataBase, TextAlignment);
				TextAlignment = TextAlignment.substr(15);

				getline(dataBase, TextPointSize);
				TextPointSize = TextPointSize.substr(15);

				getline(dataBase, TextFontFamily);
				TextFontFamily = TextFontFamily.substr(16);

				getline(dataBase, TextFontStyle);
				TextFontStyle = TextFontStyle.substr(15);

				getline(dataBase, TextFontWeight);
				TextFontWeight = TextFontWeight.substr(16);

				dimmensionParser(ShapeDimensions, textDimmensions);

				// ---> ****** array is fille with int dimmenstions here ****** <---

				/*
					Convert Data here to match data for constructor

					--> call the dimmension parser 

					--> save data to vector before the leaving the scope
				*/


			}
			else{

				getline(dataBase, Color);
				Color = Color.substr(10);

				getline(dataBase, PenWidth);
				PenWidth = PenWidth.substr(10); //Needs casting
				

				getline(dataBase, PenStyle);
				PenStyle = PenStyle.substr(10);

				getline(dataBase, PenCapStyle);
				PenCapStyle = PenCapStyle.substr(13);

				getline(dataBase, PenJoinStyle);
				PenJoinStyle = PenJoinStyle.substr(14);

				if( (ShapeType != "Line") || (ShapeType != "Polyline")){
					getline(dataBase, Color);
					Color = Color.substr(12);

					getline(dataBase, BrushStyle);
					BrushStyle = BrushStyle.substr(12);

					/*
						----> *** Switch statment to create array's for the correct shape

					*/

				}

				/*
					---> ***** create code that will handle if he parse data will be for a 
						polyline OR for line

						- create object and save to vector.
				*/
			}
		}
	}
    dataBase.close();

}


shapeVector::shapeVector(){
	/*
		fill vector in this function 
	*/

	ParseData();

}


#endif

