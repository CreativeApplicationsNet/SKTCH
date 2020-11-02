/*
 *  cross.h
 *  SKTCHiPhone
 *
 *  Created by Martin Fuchs on 19.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _CROSS_H
#define _CROSS_H

#include "ofMain.h"

class Cross{
	
public: 
	
	void setup();
	void update();
	void draw();
	void drawCross(ofPoint p, float size, float weight, float rot);
	
	
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
	
	ofPoint tempP;
};

#endif