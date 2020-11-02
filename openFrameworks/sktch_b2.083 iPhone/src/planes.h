/*
 *  planes.h
 *  SKTCHiOS4
 *
 *  Created by Filip Visnjic on 18/08/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#ifndef _PLANES_H
#define _PLANES_H

#include "ofMain.h"

class Planes{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	vector < ofPoint > pts;
	
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
	
};

#endif