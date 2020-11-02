/*
 *  menu.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 18/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _MENU_H
#define _MENU_H

#include "ofMain.h"


class Menu{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	bool bSlide;
	
	float squareAlpha;
	
//	ofTrueTypeFont  someFont;
//	ofTrueTypeFont  titleFont;
	
	
	float r;
	float g;
	float b;
	
	float x;
	float y;
	
};

#endif