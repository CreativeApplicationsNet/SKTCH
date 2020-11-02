/*
 *  mesh.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "mesh.h"

void Mesh::setup(){
	bVisible = false;
	
	
	
	
}

void Mesh::update(){
	
	
}

void Mesh::draw(){
	if (bVisible){
		
		ofPushStyle();
		
		ofNoFill();
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		ofSetColor(255-r,255-g,255-b,t);
		ofSetLineWidth(scl/3);
		
		
		for (int i = 0; i < pts.size(); i++){
			
			if (i > n){
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			ofTriangle(pts[i].x, pts[i].y, pts[i-n].x, pts[i-n].y, pts[i-2*n].x, pts[i-2*n].y);
			}
		}	
		
		ofPopStyle();
	}
	
	
	
	
	
}