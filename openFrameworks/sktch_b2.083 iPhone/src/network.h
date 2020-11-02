/*
 *  network.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 31/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _NETWORK_H
#define _NETWORK_H

#include "ofMain.h"

class Network{
	
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
	
	string text;
	
	float xmanval;
	float ymanval;
	float zmanval;
	
};

#endif