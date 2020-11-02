/*
 *  slider.cpp
 *  prtcliPhone
 *
 *  Created by Filip Visnjic on 14/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "slider.h"



void Slider::setup() {
	mVisible = false;	
	pos.set(30, 245, 0);
	
	r = 220;
	g = 220;
	b = 220;
}

void Slider::update() {
	
	if(pos.x > 270) {
		pos.x = 270;
	}
	
	if(pos.x < 30) {
		pos.x = 30;
	}
}


void Slider::draw() {
	
//	if (mVisible){
//	
//
//		
//		
//	}
}


void Slider::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	pos.set(x, y, 0);
}








