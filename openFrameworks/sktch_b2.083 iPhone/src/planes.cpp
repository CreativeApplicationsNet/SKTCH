/*
 *  box.cpp
 *  SKTCHiOS4
 *
 *  Created by Filip Visnjic on 17/08/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#include "planes.h"

void Planes::setup(){
	bVisible = false;
	
	
	
}

void Planes::update(){
	
	
}

void Planes::draw(){
	if (bVisible){
		
		ofEnableSmoothing();
		
		for (int i = 1; i < pts.size(); i++){
			//ofRectangle(pts[i].x, pts[i].y, 100, 100 );
			
			//ofSetColor(((pts[i].y)*r/250), ((pts[i].y)*g/250), b);
			
			//ofPushMatrix();
			ofSetLineWidth(1);
			ofEnableAlphaBlending();
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			ofNoFill();
			ofSetColor(255-r, 255-g, 255-b, t);
			ofRect(pts[i].x, pts[i].y, (pts[i].y)*scl/20, (pts[i].y)*scl/20);
			
			
			ofFill();
			ofEnableAlphaBlending();
			ofSetColor(255-r-pts[i].y, 255-g, 255-b, t+150-pts[i].y);
			ofRect(pts[i].x, pts[i].y, (pts[i].y)*scl/20, (pts[i].y)*scl/20);
			
			ofFill();
			ofEnableAlphaBlending();
			ofSetColor(255-r, 255-g, 255-b, t-pts[i].y);
			ofRect(pts[i].x, pts[i].y, (pts[i].y)*scl/20, (pts[i].y)*scl/20);
			
			
			//ofCircle(pts[i].x, pts[i].y, (pts[i].y)*n/20);
			//ofPopMatrix();
			ofNoFill();
		}
		
		
		
	}
	
	
}