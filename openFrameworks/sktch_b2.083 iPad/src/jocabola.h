/*
 *  jocabola.h
 *  SKTCHiPhone
 *
 *  Created by Eduard Prats Molner on 15/4/10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _JOCABOLA_H
#define _JOCABOLA_H

#include "ofMain.h"

class Jocabola {
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	vector < ofPoint > pts;
	
	//float squareAlpha;
	
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
	
	//bool bmp[100];
};

#endif