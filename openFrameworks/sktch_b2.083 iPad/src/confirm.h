/*
 *  confirm.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 30/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _CONFIRM_H
#define _CONFIRM_H

#include "ofMain.h"

class Confirm{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	float squareAlpha;

	
	float r;
	float g;
	float b;
	
	float x;
	float y;
	
	string text;
	
};

#endif