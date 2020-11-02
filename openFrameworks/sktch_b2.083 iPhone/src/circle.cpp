/*
 *  circle.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "circle.h"

void Circle::setup(){
	bVisible = false;
	
	
	
	
}

void Circle::update(){
	
	
	
}

void Circle::draw(){
	if (bVisible){
		
		
		ofSetCircleResolution(32);
		for (int i = 0; i < pts.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			if (i > 0){
				
				ofPushStyle();
				ofFill();
				ofEnableAlphaBlending();
				ofEnableSmoothing();
				ofSetColor(255-r,255-g,255-b,t);
				ofCircle(pts[i].x, pts[i].y, scl*10);
				
				ofSetColor(50-r,50-g,50-b,t);
				ofCircle(pts[i].x, pts[i].y, scl);
				
				ofPopStyle();
				
				ofPushStyle();
				ofNoFill();
				ofEnableSmoothing();
				ofSetLineWidth(1);
				ofSetColor(255-r,255-g,255-b);
				ofCircle(pts[i].x, pts[i].y, scl*10);
				ofPopStyle();
			}
		}	
		
		
		
		
	
	}
	
	
	
	
	
}