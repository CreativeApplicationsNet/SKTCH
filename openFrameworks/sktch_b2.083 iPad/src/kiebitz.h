/*
 *  rectangle.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _KIEBITZ_H
#define _KIEBITZ_H
#define MAX_DEPTH 2.

#define TAIL 260
#define DIST 3

#include "ofMain.h"

struct node {
	node(){
		doRecurs = false;
	}
	ofPoint p;
	bool doRecurs;
};

class Kiebitz{
	
public: 
	
	void setup();
	void update();
	void draw();
	void recurse(ofPoint p, float angl, int depth=0);
	bool bVisible;
	
	vector < ofPoint > pts;
	vector < node > nodes;
	
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
	
	int lastIndex;
	int lastRecurse;
	float curAlpha;
};

#endif