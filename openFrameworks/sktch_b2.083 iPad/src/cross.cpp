/*
 *  cross.cpp
 *  SKTCHiPhone
 *
 *  Created by Martin Fuchs on 19.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "cross.h"

void Cross::setup(){
	bVisible = false;
}

void Cross::update(){
	
}

void Cross::draw(){
	if (bVisible){
		
		float maxsize = scl*20;
		float weight = n*2;
		float size;
		
		for (int i = 1; i < pts.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			size = maxsize - ofDist(pts[i-1].x, pts[i-1].y, pts[i].x, pts[i].y)*1.6;
			weight =  n*2;
			if(size <1){
				size = ofDist(pts[i-1].x, pts[i-1].y, pts[i].x, pts[i].y)/maxsize;
				weight = 20-n*2;
			}
			drawCross(pts[i-1],size,weight,cos(floor(pts[i-1].x*pts[i-1].y/8000))*45);
		}	
	}
}

void Cross::drawCross(ofPoint p, float size, float weight, float rot){
	weight /=2;
	size /=2;
	
	float col = rot-10;
	
	ofPushStyle();
	ofFill();
	ofEnableSmoothing();
	ofEnableAlphaBlending();
	ofSetColor(255-r-col,255-g-col,255-b-col,t+20);
	
	ofPushMatrix();
	ofTranslate(p.x, p.y);
	ofRotate(rot);
	ofBeginShape();
	ofVertex(-size, -weight);
	ofVertex(-size, weight);
	ofVertex(-weight, weight);
	ofVertex(-weight, size);
	ofVertex(weight, size);
	ofVertex(weight, weight);
	ofVertex(size, weight);
	ofVertex(size, -weight);
	ofVertex(weight, -weight);
	ofVertex(weight, -size);
	ofVertex(-weight, -size);
	ofVertex(-weight, -weight);
	ofEndShape(true);
	ofPopMatrix();
	ofPopStyle();
}