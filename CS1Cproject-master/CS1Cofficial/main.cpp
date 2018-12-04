
/********************************************************************************
*	Filename: main.cpp                                              			*
*	Project name: 2D Shape Render                                           	*
*-------------------------------------------------------------------------------*
*	Creator name's and email's:                                                 *
*       -mybanez0@saddleback.edu                                                *
*       -
*       -
*       -
*       -
*       -
*       -
*	Course-Section: CS 1C                                                       *
*	Creation Date: XX/XX/XX                                                     *
*	Date of Last Modification: XX/XX/XX                                         *
*-------------------------------------------------------------------------------*
*	Description: The modeler will demonstrate the capabilities of 2D Graphics   *
*       Modeler Inc.’s graphics engine. Potential customers will be looking for *
*       a 2D graphics rendering library which can be integrated into their own  *
*       software suite.                                                         *
*-------------------------------------------------------------------------------*
*	Algorithm:								*
*		1)								*
*-------------------------------------------------------------------------------*
*				Data Dictionary                                                 *
*	#Constants                                                                  *
*                                                                               *
*	Name            Data Type       Value                                       *
*	-----------     -----------     --------------------                        *
*										*
*										*
*	#Variables                                                                  *
*                                                                               *
*	Name            Data Type       Value                                       *
*	------------	------------	--------------------                        *
*										*
********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>


#include "mainwindow.h"
/*
#include "shape.h"
#include "ellipse.h"
#include "line.h"
#include "polygon.h"
#include "polyline.h"
#include "rectangle.h"
#include "shape.h"
#include "text.h"
*/
#include <QApplication>
#include "drawwt.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
