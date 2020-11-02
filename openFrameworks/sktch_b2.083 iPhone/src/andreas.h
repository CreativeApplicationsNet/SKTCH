/*
 *  andreas.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _ANDREAS_H
#define _ANDREAS_H

#include "ofMain.h"

class Andreas
{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	vector < ofPoint > pts;
	
	float squareAlpha;
	
	float r;
	float g;
	float b;
	
	float x;
	float y;
	
	float t;
	float n;
	float scl;
	
	float xmanval;
	float ymanval;
	float zmanval;
	
	string text;
	
	
	int lastDrawnPoint;
	int textIndex;
    
    //ofTrueTypeFont  myFont;
	
	
};

#endif