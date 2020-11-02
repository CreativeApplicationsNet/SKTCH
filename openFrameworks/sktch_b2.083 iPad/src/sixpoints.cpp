/*
 *  sixpoints.cpp
 *  SKTCHiPhone
 *
 *  Created by Kim Asendorf on 03.04.10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "sixpoints.h"

void SixPoints::setup(){
	bVisible = false;
}

void SixPoints::update(){
	
	
	
	if (bVisible){
		if (pts.size() == 0) {
			ptr.clear();
			pr.clear();
			pbr.clear();
			pbl.clear();
			pl.clear();
			ptl.clear();
		}
		for (int i=ptr.size(); i<pts.size(); i++) {
			ofPoint p1;
			p1.x = pts[i].x+2*n;
			p1.y = pts[i].y-4*n;
			ptr.push_back(p1);
			
			ofPoint p2;
			p2.x = pts[i].x+4*n;
			p2.y = pts[i].y;
			pr.push_back(p2);
			
			ofPoint p3;
			p3.x = pts[i].x+2*n;
			p3.y = pts[i].y+4*n;
			pbr.push_back(p3);
			
			ofPoint p4;
			p4.x = pts[i].x-2*n;
			p4.y = pts[i].y+4*n;
			pbl.push_back(p4);
			
			ofPoint p5;
			p5.x = pts[i].x-4*n;
			p5.y = pts[i].y;
			pl.push_back(p5);
			
			ofPoint p6;
			p6.x = pts[i].x-2*n;
			p6.y = pts[i].y-4*n;
			ptl.push_back(p6);
		}
	}
	
	
}

void SixPoints::draw(){
	if (bVisible){
		
		
		
		//cout << "scl" << scl << endl;
		//cout << "bmp: " << bmp[1] << endl;
		
		for (int i = 0; i < pts.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			if (1<=i) {
				
				ofPushStyle();
				ofFill();
				ofEnableSmoothing();
				ofEnableAlphaBlending();
				ofSetLineWidth(scl/4);
				
				ofSetColor(220-r,220-g,220-b,t);
				ofLine(ptr[i].x, ptr[i].y, ptr[i-1].x, ptr[i-1].y);
				ofLine(pr[i].x, pr[i].y, pr[i-1].x, pr[i-1].y);
				ofLine(pbr[i].x, pbr[i].y, pbr[i-1].x, pbr[i-1].y);
				ofLine(pbl[i].x, pbl[i].y, pbl[i-1].x, pbl[i-1].y);
				ofLine(pl[i].x, pl[i].y, pl[i-1].x, pl[i-1].y);
				ofLine(ptl[i].x, ptl[i].y, ptl[i-1].x, ptl[i-1].y);
				
				ofPopStyle();
			}
			
			ofPushStyle();
			ofFill();
			ofEnableSmoothing();
			ofEnableAlphaBlending();
			ofSetLineWidth(scl);
	
			
			ofSetColor(255-r,255-g,255-b,t);
			ofRect(ptr[i].x-scl, ptr[i].y-scl, scl*4, scl*4);
			ofRect(pr[i].x-scl, pr[i].y-scl, scl*4, scl*4);
			ofRect(pbr[i].x-scl, pbr[i].y-scl, scl*4, scl*4);
			ofRect(pbl[i].x-scl, pbl[i].y-scl, scl*4, scl*4);
			ofRect(pl[i].x-scl, pl[i].y-scl, scl*4, scl*4);
			ofRect(ptl[i].x-scl, ptl[i].y-scl, scl*4, scl*4);
			
			ofPopStyle();
		}	
		
	}
}