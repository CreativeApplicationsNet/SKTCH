/*
 *  jocabola.cpp
 *  SKTCHiPhone
 *
 *  Created by Eduard Prats Molner on 15/4/10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "jocabola.h"

void Jocabola::setup(){
	bVisible = false;
}

void Jocabola::update(){
	if (bVisible){
		
				
	}
}

void Jocabola::draw(){
	if (bVisible){
		
		
		ofPushStyle();
		
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		//ofSetColor(r,g,b,t);
		//ofSetLineWidth(scl);
		
		//cout << "scl" << scl << endl;
		//cout << "bmp: " << bmp[1] << endl;
		
		if(pts.size() > 1){
			for (int i = 0; i < pts.size()-1; i++){
				
				ofRotateX(xmanval);
				ofRotateY(ymanval);
				ofRotateZ(zmanval);
				
				ofPoint a = pts[i];
				ofPoint c = pts[i+1];
				
				float dx = c.x - a.x;
				float dy = c.y - a.y;
				
				float d = sqrt(dx*dx + dy*dy);
				//float angle = atan2(dy, dx);
				
				dx /= d;
				dy /= d;
				
				float N = d + scl*10;
				
				ofPoint mid;
				ofPoint origin;
				ofPoint dest;
				mid.x = a.x + dx/2;
				mid.y = a.y + dy/2;
				
				ofSetCircleResolution(n*2);
				
				ofSetColor(255-r, 255-g, 255-b, t*5);
				ofNoFill();
				ofCircle(mid.x, mid.y, N);
				
				ofSetColor(255-r, 255-g, 255-b, t-10);
				ofFill();
				ofCircle(mid.x, mid.y, N);
			}
		}
		
		ofPopStyle();
	}
}