/*
 *  sixpoints.h
 *  SKTCHiPhone
 *
 *  Created by Kim Asendorf on 03.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _SIXPOINTS_H
#define _SIXPOINTS_H

#include "ofMain.h"

class SixPoints {
	
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

	
private:
	
	vector < ofPoint > ptr;
	vector < ofPoint > pr;
	vector < ofPoint > pbr;
	vector < ofPoint > pbl;
	vector < ofPoint > pl;
	vector < ofPoint > ptl;
};

#endif