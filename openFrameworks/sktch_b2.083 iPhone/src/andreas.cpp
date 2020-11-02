/*
 *  andreas.cpp
 *  SKTCHiPhone
 *
 *  Created by Filip Visnjic on 26/03/2010.
 *  Copyright 2010 CreativeApplications.Net. All rights reserved. *
 */

#include "andreas.h"


//-------------------------------------------------------------------------------------------------------------------------------------
//
void Andreas::setup()
{	
	lastDrawnPoint = 0;
	textIndex = 0;
	bVisible = false;
	
	//text = "Aged 68 and almost half a century past the zenith of his angry, protest-song youth, Bob Dylan must almost have forgotten what it was like to be deemed a threat to society. But it seems at least one place still sees him as a dangerous radical.";
	text = "You cannot do much about the length of your life, but you can do a lot about its depth and width. ";
    
    //myFont.loadFont( "frabk.ttf", 12, true, false, false );
	
}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Andreas::update()
{

}

//-------------------------------------------------------------------------------------------------------------------------------------
//
void Andreas::draw()
{
	if( pts.size() < 2 ) return;
	
	if (bVisible)
	{
		ofPushStyle();
		
		ofEnableSmoothing();
		
		ofSetColor(220-r,220-g,220-b);
		
		float p1x = 0.0f;
		float p1y = 0.0f;
		
		float p2x = 0.0f;
		float p2y = 0.0f;	
		
		float tmpa = 0.0f;
		float tmpb = 0.0f;
		
		float tmpStepX = 0.0f;
		float tmpStepY = 0.0f;
		
		float spacingBetweenLetters = (n/10)*10.0f;
		
		textIndex = 0;
		
		for (int i = 0; i < pts.size()-1; i++)			
		{
			
			ofRotateX(xmanval);
			ofRotateY(ymanval);
			ofRotateZ(zmanval);
            
            //ofScale(scl, scl);
			
			p1x = pts[i].x;
			p1y = pts[i].y;
			
			p2x = pts[i+1].x;
			p2y = pts[i+1].y;			
			
			tmpa = (p1x - p2x);
			tmpb = (p1y - p2y);
			
			float tmpLength = sqrtf( tmpa*tmpa + tmpb*tmpb );
			
			float tmpAng = ofRadToDeg( atan2( tmpb, tmpa) ) - 180.0f;
			
			/*
			 textIndex = i % (text.size()-1); 
			 string tmpStr = text.substr(textIndex, 1);
			 
			 glPushMatrix();
			 glTranslatef( pts[i].x, pts[i].y, 0.0f );
			 glRotatef( tmpAng, 0.0f, 0.0f, 1.0f );
			 myFont->drawString( tmpStr, 0.0f, 0.0f );
			 glPopMatrix();
			 */
			
			int tmpSteps = (int)roundf(tmpLength / spacingBetweenLetters);
			
			//cout << tmpSteps << "  " << tmpLength << endl;
			
			tmpStepX = -(tmpa / tmpSteps);
			tmpStepY = -(tmpb / tmpSteps);
			
			for( int j = 0; j < tmpSteps; j++ )
			{
				string tmpStr = text.substr(textIndex, 1);
				
				
				glPushMatrix();
				glTranslatef( p1x + (j*tmpStepX), p1y + (j*tmpStepY), 0.0f );
				glRotatef( tmpAng, 0.0f, 0.0f, 1.0f );
				ofDrawBitmapString( tmpStr, 0.0f, 0.0f );
				//myFont.drawString( tmpStr, 0.0f, 0.0f );
				glPopMatrix();
				
				textIndex++;
				textIndex %= (text.size()-1); 
			}
			
		}
		
		
		
		ofPopStyle();
		
		lastDrawnPoint = pts.size() - 1;
		
	}
	
}
