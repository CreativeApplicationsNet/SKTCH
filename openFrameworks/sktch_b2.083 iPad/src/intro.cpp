/*
 *  intro.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 05/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "intro.h"

void Intro::setup(){
	bVisible = false;

    help.loadImage("help.png");
}


void Intro::draw(){
	if (bVisible){
		
		
		
        if (bVisible){
            ofPushStyle();
            ofSetColor(255,255,255);
                help.draw(0.1, 0.1);
            ofPopStyle();

		
	}
	
	
}
}