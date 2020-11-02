/*
 *  confirm.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 30/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "confirm.h"

void Confirm::setup(){
	bVisible = false;
	
	squareAlpha = 255.0f;
	
	
}

void Confirm::update(){
	
}

void Confirm::draw(){
	if (bVisible){
		
		
		squareAlpha -= 7.5f; 
		if( squareAlpha < 0.0f ) squareAlpha = 255.0f;
		if( squareAlpha == 0.0f ) bVisible = false;
		
		
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(r-20,g-20,b-20, (int)squareAlpha );
		ofRect((ofGetWidth()-ofGetWidth()/2-50), (ofGetHeight()-ofGetHeight()/2-15), 100, 40);
		ofTriangle(x, y, x, y-20, x-20, y-10);
		
		ofEnableAlphaBlending();
		ofSetColor(255-r,255-g,255-b,  (int)squareAlpha );
		ofDrawBitmapString(text, (ofGetWidth()-ofGetWidth()/2-35), (ofGetHeight()-ofGetHeight()/2+2));
		
	}
	
	
	
	
	
}