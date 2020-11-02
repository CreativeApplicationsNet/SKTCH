/*
 *  jocabola2.h
 *  SKTCHiPhone
 *
 *  Created by Eduard Prats Molner on 15/4/10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _JOCABOLA2_H
#define _JOCABOLA2_H

#include "ofMain.h"

class Jocabola2 {
	
public: 
	
	void setup();
	void update();
	void draw();
	void editPoint(int index, float x, float y);
	bool bVisible;
	
	vector < ofPoint > pts;
//	vector <FireFly> particles;
	
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