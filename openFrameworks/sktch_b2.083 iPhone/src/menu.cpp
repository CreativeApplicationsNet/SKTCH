/*
 *  menu.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 18/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "menu.h"




void Menu::setup(){
	bVisible = true;

	x = 0;
	
	y = 480;
	
}

void Menu::update(){
	
	
}

void Menu::draw(){
	
	if (bVisible){
	
		ofPushStyle();
		ofFill();
		ofSetColor(r-20,g-20,b-20);
		ofRect(0, ofGetHeight()-30, 260, 30);
		
		ofPopStyle();


		///clear back
		
		ofPushStyle();
		ofFill();
		ofSetColor(r-20,g-20,b-20);
		ofRect(ofGetWidth()-85, ofGetHeight()-30, 85, 30);
		ofPopStyle();
		
		///UI TEXT
		ofPushStyle();
		ofSetColor(255-r,255-g,255-b);
		
		
		ofDrawBitmapString("FILE", x+15,ofGetHeight()-30+18);
		ofDrawBitmapString("SETTINGS", x+65,ofGetHeight()-30+18);
		ofDrawBitmapString("PRESETS", x+135,ofGetHeight()-30+18);
		ofDrawBitmapString("RANDOM", x+200,ofGetHeight()-30+18);
		
		
		///CLEAR BUTTON
		ofDrawBitmapString("CLEAR", ofGetWidth()-65,ofGetHeight()-30+18);

		
		ofLine(ofGetWidth()+0-25, ofGetHeight()-30+10, ofGetWidth()+10-25, ofGetHeight()-30+20);
		ofLine(ofGetWidth()+10-25, ofGetHeight()-30+10, ofGetWidth()+0-25, ofGetHeight()-30+20);

		
		ofPopStyle();

		
	}
	

	
	
	
}