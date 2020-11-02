/*
 *  phase.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 22/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "phase.h"

void Phase::setup(){
	bVisible = false;
}

void Phase::update(){
	
	
	
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

void Phase::offset(int i,float phase){
	if(i < 2) return;
	
	float multDist = 0.5f;
	ofPoint p, p2, p3, p4;
	float dist = ofDist(pts[i].x,pts[i].y,pts[i-1].x,pts[i-1].y);
	
	if(dist > 50.0f) return;
	
	
//	dist = 20.0f;
	dist = scl*10.0f;
	ofSetColor(255-r,255-g,255-b, t+100);
//	ofSetColor(255-r,255-g,255-b,255 * .5f);
	
	
	p.x = pts[i].x + sin( phase )  * multDist * dist * sin( phase );
	p.y = pts[i].y + cos( phase )  * multDist * dist * cos( phase );
	p2.x = pts[i-1].x + sin( phase - 0.2f ) * multDist * dist * sin( phase - 0.2f );
	p2.y = pts[i-1].y + cos( phase - 0.2f ) * multDist * dist * cos( phase - 0.2f );
	
	ofLine(p.x,p.y,p2.x,p2.y);	
	//ofCircle(p.x, p.y, dist * multScale);	
	
}
void Phase::draw(){
	if (bVisible){
		
		ofPushStyle();
		ofFill();
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		
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
				ofSetLineWidth(1);
				
				ofSetColor(127-r,127-g,127-b,t+100);
				//ofLine(ptr[i].x, ptr[i].y, ptr[i-1].x, ptr[i-1].y);
				
				offset(i,float(i) * .2f + PI*.25f);
				offset(i,float(i) * .2f + PI*.5f);
				offset(i,float(i) * .2f + PI*1.5f);
				offset(i,float(i) * .2f + PI);
				//offset(i,float(i) * .1f + 3.0f);
				ofPopStyle();
			}
			
			
			
			ofPopStyle();
		}	
		
	}
}

