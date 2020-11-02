/*
 *  jocabola.cpp
 *  SKTCHiPhone
 *
 *  Created by Eduard Prats Molner on 15/4/10.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "jocabola2.h"

class FireFly {
	
public:
	
	ofPoint pos;
	float x;
	float y;
	float vx;
	float vy;
	float size;
	
	vector <ofPoint> points;
	
	//	FireFly(){}
	
	
	void setup(ofPoint _pos, float siz){
		vx = ofRandom(-4, 4);
		vy = ofRandom(-4, 4);
		
		pos = _pos;
		points.push_back(pos);
		size = siz;
		
		x = pos.x;
		y = pos.y;
	}
	
	void update(){
		if((fabs(vx) > 0)&&(fabs(vy) > 0)){
			pos.x += vx;
			pos.y += vy;
			
			vx *= 0.75;
			vy *= 0.75;
			points.push_back(pos);
			
			if(fabs(vx) < 0.1){
				vx = 0;
			}
			
			if(fabs(vy) < 0.1){
				vy = 0;
			}
		}
	}
	
	void draw(){
		
		for(int i=0; i<points.size(); i++){
		
			
			ofCircle(points[i].x, points[i].y, size);
		}
		
	}
	
	void reset(float x, float y){
		points.clear();
		
		vx = ofRandom(-4, 4);
		vy = ofRandom(-4, 4);
		
		pos = ofPoint(x, y);
		points.push_back(pos);
		
		x = pos.x;
		y = pos.y;
	}
};




//--------------------------------------------------------------

FireFly prticle;
vector <FireFly> prticles;


void Jocabola2::setup(){
	bVisible = false;
}

void Jocabola2::update(){
	int i;
	
	if (bVisible){
		float scale = (scl - 0.5)/4.1;
		
		if(pts.size() < prticles.size()){
			prticles.clear();
		}
		
		for(i=prticles.size(); i<pts.size();i++){
			FireFly ff;
			ff.setup(pts[i], scale*10);
			prticles.push_back(ff);
		}
		
		for(i=1;i<prticles.size();i++){
			prticles[i].update();
		}
	}
}

void Jocabola2::draw(){
	if (bVisible){
		
		
		ofPushStyle();
		
		ofEnableSmoothing();
		ofEnableAlphaBlending();
		ofSetCurveResolution(10);
		ofSetCircleResolution(10);
		
		float displacement = ((n - 1.5))/12.5;
		float alpha = t-10;
		float scale = (scl - 0.5)/4.1;
		
		ofSetCircleResolution(displacement*8 + 4);
		
		ofSetColor(255-r, 255-g, 255-b, alpha + 5);
		ofFill();
		
		if(prticles.size() > 1){
			prticles[0].size = scale*10;
			prticles[0].draw();
		}
		
		for(int i=1;i<prticles.size();i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			//ofSetColor(255-r, 255-g, 255-b, alpha + 20);
			ofSetColor(r/255 + g, g/255 + b, b/255 + r, alpha);
			ofNoFill();
			prticles[i].size = scale*10;
			prticles[i].draw();
			//ofSetColor(r/255 + g, g/255 + b, b/255 + r, alpha);
			ofSetColor(255-r, 255-g, 255-b, alpha);
			ofFill();
			prticles[i].draw();
			
			ofSetColor(r/255 + g, g/255 + b, b/255 + r, alpha + 20);
			//ofSetColor(255-r, 255-g, 255-b, alpha + 20);
			ofNoFill();
			ofLine(prticles[i-1].x, prticles[i-1].y, prticles[i].x, prticles[i].y);
		}
		
		ofPopStyle();
	}
}

void Jocabola2::editPoint(int index, float x, float y){
	if(index < prticles.size()){
		prticles[index].reset(x, y);
	}
}