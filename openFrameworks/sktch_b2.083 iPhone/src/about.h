/*
 *  about.h
 *  ptcleiPhone
 *
 *  Created by Filip Visnjic on 28/02/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved.
 */

#ifndef _ABOUT_H
#define _ABOUT_H

#include "ofMain.h"


class About{
	
public: 
	
	void setup();
	void draw();
	bool bVisible;

	ofImage info;
	ofImage infox2;
	
};

#endif