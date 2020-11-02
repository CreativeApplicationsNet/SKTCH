/*
 *  slider.cpp
 *  prtcliPhone
 *
 *  Created by Filip Visnjic on 14/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "button.h"



void Button::setup() {
	
	bVisible = false;
	
	squareAlpha = 255.0f;

}

void Button::update() {
	
}

void Button::draw() {
	
	if (bVisible){
		
		squareAlpha -= 255.0f; 
		if( squareAlpha < 0.0f ) squareAlpha = 255.0f;
		if( squareAlpha == 0.0f ) bVisible = false;
		
		
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(255,0,0, (int)squareAlpha );
		ofRect(x, y, 120, 20);
		
	}
	

}








