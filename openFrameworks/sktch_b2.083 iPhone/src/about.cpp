/*
 *  about.cpp
 *  ptcleiPhone
 *
 *  Created by Filip Visnjic on 28/02/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved.
 */

#include "about.h"
#include "ofxiPhone.h"


void About::setup(){
	bVisible = false;
	
	info.loadImage("info.png");
	infox2.loadImage("infox@2x.png");

}


void About::draw(){
	
	
	if (bVisible){
		ofPushStyle();
		ofSetColor(255,255,255);
		if (ofGetWidth() > 320) {
			infox2.draw(0.1, 0.1);
		}
		else {
			info.draw(0.1, 0.1);
		}
		ofPopStyle();
		
	ofPopStyle();	
	
	
}
}

