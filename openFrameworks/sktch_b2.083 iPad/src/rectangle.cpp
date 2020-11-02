/*
 *  rectangle.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "rectangle.h"

void Rectangle::setup(){
	bVisible = false;
	

	
	
}

void Rectangle::update(){
	

	
}

void Rectangle::draw(){
	if (bVisible){
		
		
		ofPushStyle();
		ofFill();
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		ofSetColor(100-r,100-g,100-b,t);
		ofSetLineWidth(1);
		ofBeginShape();
		for (int i = 0; i < pts.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			if (i > 0){
				ofSetColor(255-r,255-g,255-b,t);
				ofRect(pts[i].x-scl*10, pts[i].y-scl*10, scl*20, scl*20);
			}
		}	
		ofEndShape();
		ofPopStyle();
		
		
//		ofPushStyle();
//		ofFill();
//		ofEnableSmoothing();
//		ofEnableAlphaBlending();
//		ofSetLineWidth(1);
//		ofBeginShape();
//		for (int i = 0; i < pts.size(); i++){
//			
//			if (i > 0){
//				ofSetColor(200-r,200-g,200-b,t);
//				ofLine(pts[i].x-scl*10, pts[i].y-scl*10, pts[i].x-scl*10+scl*20, pts[i].x-scl*10+scl*20);
//			}
//		}	
//		ofEndShape();
//		ofPopStyle();
		

		
	}
	
	
	
	
}

