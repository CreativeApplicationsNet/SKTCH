/*
 *  button.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 21/07/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */


#ifndef _BUTTON_H
#define _BUTTON_H


#include "ofMain.h"

class Button{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	float squareAlpha;
	
	float x;
	float y;
	
	
};

#endif