/*
 *  meta.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 02/04/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "triangle.h"

class Particle {
	
public:
	
	ofPoint pos;
	ofPoint vel;
	int life;
	int creationMillis;
	float size;
	

	Particle(){
		creationMillis = ofGetElapsedTimeMillis();
	}
	
	
	void update(){
		
		
		//		pos.x += vel.x;
		//		pos.y += vel.y;
		//		vel.x *= 5.0;
		//		vel.y *= 5.0;
		
		
		life++;  // zachs code
	
		
	}
	
	float getOffset(){
		//modify for other size
		//size = 25;
		return ofMap(ofGetElapsedTimeMillis()-creationMillis, 0, 200, size, 0, true);
	}
	
	void draw(){
		
		life=0;
		
		//	ofFill();
		//	ofSetColor((ofRandom(0, 255)), (ofRandom(0, 255)), (ofRandom(0, 255)), 50);
		//ofCircle(pos.x, pos.y, 5);
	
		
	}
};


//--------------------------------------------------------------

Particle particle;
vector <Particle> particles;


void Triangle::setup(){
	bVisible = false;
	p = 5.0;
	
	
}

void Triangle::update(){
	
	

}

void Triangle::draw(){
	if (bVisible){
		
		ofPushStyle();
		ofFill();
		ofEnableAlphaBlending();
		ofEnableSmoothing();
		ofSetColor(255-r, 255-g, 255-b, t-10);
		ofSetLineWidth(1);
		
		
		
		
		//ofBeginShape();
		for (int i = 3; i < particles.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			ofTriangle(particles[i].pos.x, particles[i].pos.y, particles[i-1].pos.x, particles[i-1].pos.y, particles[i-2].pos.x, particles[i-2].pos.y);
			particles[i].size = n*4;
		}
		
		ofPushStyle();
		
		//ofEndShape();
		
		ofPushStyle();

		ofNoFill();
		ofEnableAlphaBlending();
		ofSetColor(255-r, 255-g, 255-b, 3*t);
		ofSetLineWidth(1);
		
		//ofBeginShape();
		for (int i = 3; i < particles.size(); i++){
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
			
			ofTriangle(particles[i].pos.x, particles[i].pos.y, particles[i-1].pos.x, particles[i-1].pos.y, particles[i-2].pos.x, particles[i-2].pos.y);
			//ofCircle(particles[i].pos.x, particles[i].pos.y, 10);
			
		}
		
		//ofEndShape();
		
		ofPushStyle();
		
		p += 0.005f; 
		//if( p > 1.0f ) p = 1.0f;
		
		
			for (int i = 0; i < particles.size(); i++){
			
				
				ofRotateX(xmanval);
				ofRotateY(ymanval);
				ofRotateZ(zmanval);
				
				float v= particles[i].getOffset();
				particles[i].pos.x += ofRandom(-v, v);
				particles[i].pos.y += ofRandom(-v, v);
				
				
				
				//particle.size = n;
			}
			
		
		
		
		
		
	}
	
	
}

void Triangle::touchDown(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	particles.clear();
}

void Triangle::touchMoved(float x, float y, int touchId, ofxMultiTouchCustomData *data) {
	
	for (int i = 0; i < 3; i++){
		Particle tempParticle;
		tempParticle.pos.set(x, y);
		tempParticle.vel.set( ofRandom(-1,1), ofRandom(-1,1));
		//tempParticle.vel.set( 80.0, 80.0);
		
		particles.push_back(tempParticle);
	}
	
}
