/*
 *  tooltip.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 18/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "tooltip.h"

void Tooltip::setup(){
	bVisible = false;
	
	
	squareAlpha = 255.0f;
	y = 420;
	
	
}

void Tooltip::update(){
	
		//if( squareAlpha = 0.0f ) bVisible = false;
		
}

void Tooltip::draw(){
	if (bVisible){
		
		
		squareAlpha -= 7.5f; 
		if( squareAlpha < 0.0f ) squareAlpha = 255.0f;
		if( squareAlpha == 0.0f ) bVisible = false;
		
		
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(r-20,g-20,b-20, (int)squareAlpha );
		ofRect((ofGetWidth()-ofGetWidth()/2-50), (ofGetHeight()-ofGetHeight()/2-15), 110, 30);
		//ofTriangle(x+70, y+20, x+80, y+20, x+75, y+25);
		
		ofEnableAlphaBlending();
		ofSetColor(255-r,255-g,255-b,  (int)squareAlpha );
		ofDrawBitmapString(text, (ofGetWidth()-ofGetWidth()/2-35), (ofGetHeight()-ofGetHeight()/2+2));
		
		
		
		}
	
	
	
		
	
	}
	
	