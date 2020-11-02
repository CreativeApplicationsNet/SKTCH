/*
 *  spline.h
 *  SKTCHiOS4
 *
 *  Created by Filip Visnjic on 04/12/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#ifndef _SPLINE_H
#define _SPLINE_H

#include "ofMain.h"
#include "ofxiPhone.h"

class Spline{
	
public: 
	
	void setup();
	void update();
	void draw();
	void touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	void touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data = NULL);
	
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
	float radius;
	float scale;
	
	float h;
	float p;
	
	float xmanval;
	float ymanval;
	float zmanval;
		
};

#endif