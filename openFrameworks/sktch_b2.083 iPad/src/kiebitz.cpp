/*
 *  kiebitz.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 21/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "kiebitz.h"


void Kiebitz::setup(){
	bVisible = false;
	lastIndex = 0;
	lastRecurse = 0;
}

void Kiebitz::update(){
	
}

void Kiebitz::draw(){
	
	ofPushStyle();
	
	
	if (bVisible){
		
		ofEnableSmoothing();
		if(pts.size()==0)
			nodes.clear();
		while(pts.size()>nodes.size()){
			node n;
			n.p = pts[nodes.size()];
			if(nodes.size()>1){
				//if(ofDistSquared(nodes[nodes.size()-1].p.x, nodes[nodes.size()-1].p.y, n.p.x, n.p.y)>DIST*DIST){//ofRandom(0, 1)>.3&&
				lastRecurse = nodes.size();
				n.doRecurs = true;
				//}
			}
			nodes.push_back(n);
		}
		float lastAngl = 0;
		//tex.begin();
		for(int i=lastIndex;i<nodes.size();i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			curAlpha = ofMap(i, lastIndex, nodes.size(), t/255.f, 1);
			ofEnableAlphaBlending();
			//ofSetColor(r, g, b, 4);
			//ofRect(0, 0, ofGetWidth(), ofGetHeight());
			ofSetColor(255-r,255-g,255-b, 255);
			
			ofPoint p = nodes[i].p;
			float angl = 0;
			if(i>0){
				ofPoint pp = nodes[i-1].p-p;
				//ofPoint pp(ofGetWidth()*ofNoise(p.x),ofGetHeight()*ofNoise(p.y));
				angl = atan2f(pp.y, pp.x);
				//if (ofDist(nodes[i-1].p.x, nodes[i-1].p.y, p.x, p.y)<60) {
				//ofLine(nodes[i-1].p.x, nodes[i-1].p.y, p.x, p.y);
				//ofRect(nodes[i].p.x, nodes[i].p.y, 5, 5);
				//}
			}
			if(nodes[i].doRecurs){
				
				if(nodes.size()-i<TAIL){
					if(i==0)
						lastAngl = angl;
					else
						lastAngl+=(angl-lastAngl)*n/7.;
					recurse(p, lastAngl);
				}else{
					//ofEllipse(nodes[i].p.x, nodes[i].p.y, 5, 5);
				}
			}
			ofDisableAlphaBlending();
			//lastIndex = i;
		}
		//cout << lastIndex << endl;
		//tex.end();
		//tex.draw(0, 0);
	}
	
	ofPopStyle();
}

void Kiebitz::recurse(ofPoint p, float angl, int depth){
	
	ofPushStyle();
	
	
	if(depth>=MAX_DEPTH)
		return;
	float fac = ofMap(depth, MAX_DEPTH, 0, .1, .6, true)*ofNoise(p.x/ofGetWidth());
	float s = fac*scl*90+ofNoise(p.x/ofGetWidth(), p.y/ofGetHeight())*30;
	int branches = 1;
	if(depth>0)
		branches = roundf(ofNoise(p.x/ofGetWidth(), p.y/ofGetHeight())+.1)+1;
	ofSetColor(255-r,255-g,255-b, ofMap(depth, 0, MAX_DEPTH-1, 250, 90)*curAlpha);
	for(int i=0;i<branches;i++){
		
		ofRotateX(xmanval);
		ofRotateY(ymanval);
		ofRotateZ(zmanval);
		
		float ang = ofMap(i, 0, branches, angl+HALF_PI, angl-HALF_PI);
		ang += ofNoise(p.x/ofGetWidth()*0.01, p.y/ofGetHeight()*0.01, ang*.3)-1;
		//float ang = angl;
		ofPoint p2(cosf(ang)*s, sinf(ang)*s);
		p2 += p;
		ofLine(p.x, p.y, p2.x, p2.y);
		recurse(p2, ang, depth+1);
	}
	
	ofPopStyle();
}