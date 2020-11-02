/*
 *  orbit.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 22/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "orbit.h"

void Orbit::setup(){
	bVisible = false;
}

void Orbit::update(){
	
	
	
	if (bVisible){
		if (pts.size() == 0) {
			ptr.clear();
			pr.clear();
		}
		for (int i=ptr.size(); i<pts.size(); i++) {
			ofPoint p1;
			p1.x = pts[i].x;
			p1.y = pts[i].y;
			ptr.push_back(p1);
			
		}
	} 
	
	
}

void Orbit::offset(int i,float phase){
	if(i < 1) return;
	
	
//	float multScale = .1f;
	float multDist = 0.5f;
	ofPoint p;
//	float rnd;
	float dist = ofDist(pts[i].x,pts[i].y,pts[i-1].x,pts[i-1].y);
	dist *= n; //filip changed into n
	ofSetColor(255-r,255-g,255-b, t+100); //filip changed t
	
	if(dist > 50.0f) dist = 50.0f;
	
	p.x = pts[i].x + sin((float(i)/100.0) + phase ) * dist * multDist;
	p.y = pts[i].y + cos((float(i)/100.0) + phase ) * dist * multDist;
	ofCircle(p.x, p.y, scl);	 //filip changed scl	
	
	
	
}

void Orbit::draw(){
	if (bVisible){
		
		ofPoint off1, off2;
		
		//cout << "scl" << scl << endl;
		//cout << "bmp: " << bmp[1] << endl;
		
		for (int i = 0; i < pts.size(); i++){
			
			if (1<=i) {
				
				ofRotateX(xmanval);
				ofRotateY(ymanval);
				ofRotateZ(zmanval);
				
				ofPushStyle();
				ofFill();
				//ofSetCircleResolution(3);
				ofEnableSmoothing();
				ofEnableAlphaBlending();
				ofSetLineWidth(scl/4);
				
				ofSetColor(127-r,127-g,127-b,t);
				//ofLine(ptr[i].x, ptr[i].y, ptr[i-1].x, ptr[i-1].y);
				
				offset(i,0.0f);
				offset(i,1.0f);
				offset(i,2.0f);
				offset(i,3.0f);
				offset(i,4.0f);
				offset(i,5.0f);
				
				ofPopStyle();
			}
			//
//			ofPushStyle();
//			ofFill();
//			ofEnableSmoothing();
//			ofEnableAlphaBlending();
//			ofSetLineWidth(scl);
//			
//			
//			ofSetColor(255-r,255-g,255-b,t);
//			
//			
//			ofPopStyle();
		}	
		
	}
}