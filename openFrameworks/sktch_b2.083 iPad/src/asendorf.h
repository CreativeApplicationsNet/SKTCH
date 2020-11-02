/*
 *  asendorf.h
 *  SKTCHiPhone
 *
 *  Created by Kim Asendorf on 01.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _ASENDORF_H
#define _ASENDORF_H

#include "ofMain.h"

class Asendorf {
	
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
	
	bool bmp[100];
};

#endif