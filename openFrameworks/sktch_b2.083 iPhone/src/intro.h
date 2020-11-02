/*
 *  intro.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 05/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _INTRO_H
#define _INTRO_H

#include "ofMain.h"

class Intro{
	
public: 
	
	void setup();
	void draw();
	bool bVisible;

	
	ofImage help;
	ofImage helpx2;
};

#endif