/*
 *  meta.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 02/04/2010.
 *  Copyright 2010 University for the Creative Arts. All rights reserved.
 *
 */

#include "spline.h"

class Spoint {
	
public:
	
	ofPoint pos;

	
	void update(){

	}
	
	void draw(){
		
		
		ofCircle(pos.x, pos.y, 5);
		
	}
};


//--------------------------------------------------------------

Spoint spoint;
vector <Spoint> spoints;


void Spline::setup(){
	bVisible = false;
	
}

void Spline::update(){
	
	if (bVisible){

		
	}
	
}

void Spline::draw(){
	if (bVisible){
		
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		
        ofRotateX(xmanval);
        ofRotateY(ymanval);
        ofRotateZ(zmanval);
        
		
		ofPushStyle();
		ofNoFill();
		ofSetColor(205-r, 205-g, 205-b, t);
		ofBeginShape();
		ofSetLineWidth(1);
		
		for (int i = 1; i < spoints.size(); i++){
			
			ofVertex(spoints[i].pos.x, spoints[i].pos.y);
		}
		ofEndShape();
		
		ofBeginShape();
		for (int i = 1; i < spoints.size(); i++){
            
			float dist;
			dist = ofDist(spoints[i].pos.x, spoints[i].pos.y, spoints[i-1].pos.x, spoints[i-1].pos.y);
			
			if ( dist > scl*35){
				ofSetColor(255-r, 225-g, 255-b);
			ofCurveVertex(spoints[i].pos.x+n/2, spoints[i].pos.y-n/2);
			}
		}
		ofEndShape();
		
		
		
//		ofBeginShape();
//		for (int i = 1; i < spoints.size(); i++){
//			
//			float dist;
//			dist = ofDist(spoints[i].pos.x, spoints[i].pos.y, spoints[i-1].pos.x, spoints[i-1].pos.y);
//			
//			if ( dist > scl*45){
//				ofSetColor(205-r, 255-g, 205-b);
//				ofCurveVertex(spoints[i].pos.x+n/2, spoints[i].pos.y-n/2);
//			}
//		}
//		ofEndShape();
		
		
		
//		ofBeginShape();
//		for (int i = 1; i < spoints.size(); i++){
//			ofCurveVertex(spoints[i].pos.x-n/2, spoints[i].pos.y+n/2);
//		}
//		ofEndShape();
		
		ofPopStyle();
		
		
		
		ofPushStyle();
		ofSetColor(255-r, 255-g, 255-b, t);
		ofSetLineWidth(1);
		for (int i = 3; i < spoints.size(); i++){
			ofFill();
			ofCircle(spoints[i].pos.x, spoints[i].pos.y, 1);
		}
		ofPopStyle();
		
		
//		ofNoFill();
//		ofBeginShape();
//		ofEnableSmoothing();
//		//ofSetColor(r-100, g-100, b-100);
//		for (int i = 0; i < pts.size(); i++){
//			ofVertex(pts[i].x, pts[i].y);
//		}
//		
//		ofEndShape();
		
		
		
	}
	
	
}

void Spline::touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	spoints.clear();
}

void Spline::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	
	for (int i = 0; i < 2; i++){
		Spoint tempSpoint;
		tempSpoint.pos.set(ofRandom(x-scl*20,x+scl*20), ofRandom(y-scl*20,y+scl*20));
		spoints.push_back(tempSpoint);
	}
	
}
