/*
 *  network.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 31/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "network.h"

void Network::setup(){
	bVisible = false;
	
	
	
	
}

void Network::update(){
	
	
	
}

void Network::draw(){
	if (bVisible){
		

			for (int i = 0; i < pts.size(); i++){
				
				if (i > 0){
					
					float dist;
					dist = ofDist(pts[i].x, pts[i].y, pts[i-1].x, pts[i-1].y);
					
					if ( dist > 1){
						
						
						ofPushMatrix();
						ofPushStyle();
						ofFill();
						ofEnableSmoothing();
						ofEnableAlphaBlending();
						ofSetColor(255-r,255-g,255-b,t);
						ofSetLineWidth(1);
						ofSetCircleResolution(32);
						ofTranslate(0, 0, dist*zmanval*3);
						ofCircle(pts[i].x, pts[i].y, (scl/3)*dist);
						ofPopStyle();
						ofPopMatrix();

						ofPushMatrix();
						ofPushStyle();
						ofFill();
						ofSetColor(r-20,g-20,b-20,t);
						ofSetLineWidth(1);
						ofTranslate(0, 0, dist*zmanval*3);
						ofLine(pts[i].x, pts[i].y, pts[i-1].x, pts[i-1].y);	
						ofSetCircleResolution(32);
						ofCircle(pts[i].x, pts[i].y, n);	
						ofPopStyle();
						ofPopMatrix();
						
						ofPushMatrix();
						ofPushStyle();
						ofNoFill();
						ofEnableAlphaBlending();
						ofSetColor(r,g,b,t);
						ofSetLineWidth(1);
						ofSetCircleResolution(32);
						ofTranslate(0, 0, dist*zmanval*3);
						ofCircle(pts[i].x, pts[i].y, (scl/3)*dist);	
						ofPopStyle();
						ofPopMatrix();

					}
					
					
				}
				
			}	
		
		
		
		
	}
	
	
	
	
	
}