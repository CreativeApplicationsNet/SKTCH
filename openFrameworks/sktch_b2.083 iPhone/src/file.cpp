ofDrawBitmapString/*
 *  file.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 04/08/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#include "file.h"

void File::setup(){
	bVisible = false;
	
	
}

void File::update(){
	
}

void File::draw(){
	if (bVisible){
		
		ofPushStyle();
		ofFill();
		ofSetColor(r-20,g-20,b-20);
		ofRect(0, ofGetHeight()-160, 55, 130);
		ofPopStyle();
		
		
		
		ofPushStyle();
		ofSetColor(255-r,255-g,255-b);
		
		ofDrawBitmapString("EDIT", 15,ofGetHeight()-65+18);
		ofDrawBitmapString("SAVE", 15,ofGetHeight()-95+18);
		ofDrawBitmapString("OPEN", 15,ofGetHeight()-125+18);
		ofDrawBitmapString("3D", 15,ofGetHeight()-155+18);
		ofPopStyle();
		
		
	}
	
	
}