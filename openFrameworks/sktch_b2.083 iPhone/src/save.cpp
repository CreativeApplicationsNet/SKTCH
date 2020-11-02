/*
 *  about.cpp
 *  ptcleiPhone
 *
 *  Created by Filip Visnjic on 28/02/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved.
 */

#include "save.h"




void Save::setup(){
	bVisible = false;
	
	buttondown = 0;
	
}

void Save::update(){
	
}


void Save::draw(){
	
	
	
	if (bVisible){
		
		ofPushStyle();
		ofFill();
		ofEnableAlphaBlending();
		ofSetColor(r-20,g-20,b-20, 255);
		ofRect(10, 10, 300, 245);
		ofPopStyle();
		
		
		ofPushStyle();
		ofSetColor(255-r,255-g,255-b);
		ofFill();
		//// buttons
		ofRect(30, 57, 120, 20); // save screenshot
		ofRect(170, 57, 120, 20); // send to desktop
		ofRect(170, 137, 120, 20); // CANCEL
		ofRect(30, 187, 120, 20); // save settings
//		ofRect(170, 187, 120, 20); // facebook
		ofPopStyle();
		
		ofPushStyle();
		ofFill();
		ofSetColor(255,0,0);
		ofRect(30, 137, 120, 20); // save
		ofPopStyle();
		
	
		/// BUTTON TEXT
		ofPushStyle();
		ofSetColor(r,g,b);
		ofDrawBitmapString("SAVE SCREENSHOT", 38,70);
		ofDrawBitmapString("SEND TO DESKTOP", 176,70);
		ofDrawBitmapString("SAVE FILE", 38,150);
		ofDrawBitmapString("CANCEL", 176,150);
		ofDrawBitmapString("SAVE SETTINGS", 38,200);
//		ofDrawBitmapString("FACEBOOK", 176,200);
		ofPopStyle();
		
		
		ofPushStyle();
		ofSetColor(0,0,0);
		ofDrawBitmapString("SAVE FILE", 38,150);
		ofPopStyle();
		
		
		
	}
	
	
}

