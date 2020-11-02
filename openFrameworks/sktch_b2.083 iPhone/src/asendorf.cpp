/*
 *  asendorf.cpp
 *  SKTCHiPhone
 *
 *  Created by Kim Asendorf on 01.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "asendorf.h"

void Asendorf::setup(){
	bVisible = false;
	
	
}

void Asendorf::update(){
	if (bVisible){
		
		for (int i=0; i<100; i++) {
			int val = fmod(i, n);
			//cout << "val: " << val << endl;
				
			if (val==1) {
				bmp[i] = true;
			} else {
				bmp[i] = false;
			}
		}		
	}
}

void Asendorf::draw(){
	if (bVisible){
		
		
		ofPushStyle();
		ofFill();
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		ofSetColor(r,g,b,t);
		ofSetLineWidth(scl);
		
		//cout << "scl" << scl << endl;
		//cout << "bmp: " << bmp[1] << endl;
		
		for (int i = 0; i < pts.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			float ax = pts[i].x - 5*scl;
			float ay = pts[i].y - 5*scl;
				
			for (int j = 0; j < 100; j++) {
					
				//float xoff = fmod(j, 10)*1.5*scl;
                float xoff = j/10*1.5*scl;
				float yoff = j/10*1.5*scl;
				
//				float xoff = 10;
//				float yoff = 10;
					
				if (!bmp[j]) {
					ofSetColor(r,g,b,t);
				} else {
					ofSetColor(255-r,255-g,255-b,t);
				}
				
				ofRect(ax+xoff, ay+yoff, 1.5*scl, 1.5*scl);
			}
		}	
		ofPopStyle();
	}
}