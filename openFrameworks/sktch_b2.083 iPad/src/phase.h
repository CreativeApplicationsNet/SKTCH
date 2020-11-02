/*
 *  phase.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 22/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _PHASE_H
#define _PHASE_H

#include "ofMain.h"

class Phase {
	
public: 
	
	void setup();
	void update();
	void draw();
	
	bool bVisible;
	int time;
	
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
	void offset(int i,float phase);
	
	vector < ofPoint > ptr;
	vector < ofPoint > pr;
};

#endif