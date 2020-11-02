/*
 *  meta.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 02/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "ofMain.h"
#include "ofxiPhone.h"


class Triangle{
	
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
	
	float h;
	float p;
	
	float xmanval;
	float ymanval;
	float zmanval;
	
	string text;
	

	float size;	
	
};

#endif