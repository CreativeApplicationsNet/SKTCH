/*
 *  intro.h
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 05/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#ifndef _SAVE_H
#define _SAVE_H

#include "ofMain.h"


class Save{
	
public: 
	
	void setup();
	void update();
	void draw();
	bool bVisible;
	
	float r;
	float g;
	float b;
	
	float buttondown;
		
};

#endif