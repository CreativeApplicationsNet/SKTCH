#include "testApp.h"
#include "ofxiPhoneExtras.h"
#include "MyGuiView.h"

MyGuiView * myGuiViewController;


#define ACCELEROMETER_FORCE		0.2

//--------------------------------------------------------------

void testApp::setup(){	

	
	// register touch events
	ofRegisterTouchEvents(this);
	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//iPhoneAlerts will be sent to this.
	ofxiPhoneAlerts.addListener(this);
	
	
	//If you want a landscape oreintation 
	
	iPhoneSetOrientation(OFXIPHONE_ORIENTATION_PORTRAIT);
	
	

	displayMode = 0;
	
	CGSize s = [[[UIApplication sharedApplication] keyWindow] bounds].size;
	screenW = ofGetScreenWidth();
	screenH = ofGetScreenHeight();
	
	
	///// NEW

	///old app
	lengthRatio	= 0.5;
	numPoints	= 5;
	bFill		= true;
	
	//Our Gui setup
	myGuiViewController	= [[MyGuiView alloc] initWithNibName:@"MyGuiView" bundle:nil];
	// I have to first view and then can change to any subView
	[ofxiPhoneGetUIWindow() addSubview:myGuiViewController.view];
	[myGuiViewController.view removeFromSuperview];
	// add subview desire
    
    [ofxiPhoneGetUIWindow() addSubview:myGuiViewController.viewPresets];
	myGuiViewController.viewPresets.hidden = YES;
    
	[ofxiPhoneGetUIWindow() addSubview:myGuiViewController.viewSettings];
	myGuiViewController.viewSettings.hidden = YES;
	
	[ofxiPhoneGetUIWindow() addSubview:myGuiViewController.viewMain];
	myGuiViewController.viewMain.hidden = NO;
	
	
	
	//ofBackground(r, g, b);
    
	
	
	//IMAGE PICKER
	
	
	cameraPixels = NULL; 
	camera = new ofxiPhoneImagePicker();
	camera->setMaxDimension(ofGetWidth()); //otherwise we will have enormous images
//	imgPos.x=width/2;
//	imgPos.y=height/2;
	
	
	//UI
	intro.setup();
	save.setup();
	hello.setup();
	line.setup();
	tline.setup();
	scale.setup();
	
	colourr.setup();
	colourg.setup();
	colourb.setup();
	
	vx = 10;
	vy = 10;
	l = 150;
	
	
	scale.pos.x = 180;
	
	
	
	//TOOLTIPS
	
	tooltip.setup();
	button.setup();
	confirm.setup();
	
	menu.setup();
	
	
	// EFFECTS
	rectangle.setup();
	mesh.setup();
	andreas.setup();
	network.setup();
	triangle.setup();
	asendorf.setup();
	sixpoints.setup();
	jocabola.setup();
	jocabola2.setup();
	cross.setup();
	kiebitz.setup();
	phase.setup();
	orbit.setup();
	planes.setup();
	spline.setup();

	
	//------------------------------
	
	
	shouldITakeScreenshot=false;
	canDelete=false;
	showGrid=true;
	tdmenu=true;
	

	//launch values
	rectangle.bVisible = !rectangle.bVisible;
    
//  line.pos.x = 150;
//	tline.pos.x = 200;
//	scale.pos.x = 100;
    
    
    //load xml / load settings
    
    /// FIRST TIME USER OR NOT
    loadFile();
    if (u == 1){
		intro.bVisible = !intro.bVisible;
		r = 20;
		g = 20;
		b = 20;
	}
}

//--------------------------------------------------------------
void testApp :: initTrackball ()
{
	gTrackBallRotation[ 0 ] = 0.0f;
	gTrackBallRotation[ 1 ] = 0.0f;
	gTrackBallRotation[ 2 ] = 0.0f;
	gTrackBallRotation[ 3 ] = 0.0f;
	gWorldRotation[ 0 ]	= 0.0f;
	gWorldRotation[ 1 ]	= 0.0f;
	gWorldRotation[ 2 ]	= 0.0f;
	gWorldRotation[ 3 ]	= 0.0f;
	gTrackBall = false;
}

void testApp :: mouseTrackballDown( int x, int y )
{
	startTrackball( x, y, 0, 0, ofGetWidth(), ofGetHeight() );
	gTrackBall = true;
}

void testApp :: mouseTrackballUp( int x, int y )
{
	gTrackBall = false;
	rollToTrackball( x, y, gTrackBallRotation );
	if( gTrackBallRotation[0] != 0.0 )
	{
		addToRotationTrackball( gTrackBallRotation, gWorldRotation );
	}
	gTrackBallRotation[ 0 ] = gTrackBallRotation[ 1 ] = gTrackBallRotation[ 2 ] = gTrackBallRotation[ 3 ] = 0.0f;
}

void testApp :: mouseTrackballMove( int x, int y )
{
	if (gTrackBall)
	{
		rollToTrackball( x, y, gTrackBallRotation );
	}
}

//--------------------------------------------------------------
void testApp::update(){


	
	ofBackground(r, g, b);

			
	xmanval = (xman.pos.x/100)-0.3;
	ymanval = (yman.pos.x/100)-0.3;
	zmanval = (zman.pos.x/100)-0.3;



	
	menu.r = r;
	menu.g = g;
	menu.b = b;
	

	tooltip.r = r;
	tooltip.g = g;
	tooltip.b = b;
	
	menu.update();
	
	line.update();
	tline.update();
	scale.update();
	
	colourr.update();
	colourg.update();
	colourb.update();
	
	xman.update();
	yman.update();
	zman.update();
	
	
	/// EFFECTS

	
	save.r = r;
	save.g = g;
	save.b = b;
	

	
	confirm.r = r;
	confirm.g = g;
	confirm.b = b;	
	
	rectangle.r = r;
	rectangle.g = g;
	rectangle.b = b;
	rectangle.t = t;
	rectangle.pts = pts;
	rectangle.scl = scl;
	rectangle.n = n;
	
	mesh.r = r;
	mesh.g = g;
	mesh.b = b;
	mesh.t = t;
	mesh.pts = pts;
	mesh.scl = scl;
	mesh.n = n;
	
	circle.r = r;
	circle.g = g;
	circle.b = b;
	circle.t = t;
	circle.pts = pts;
	circle.scl = scl;
	circle.n = n;
	
	andreas.r = r;
	andreas.g = g;
	andreas.b = b;
	andreas.t = t;
	andreas.pts = pts;
	andreas.scl = scl;
	andreas.n = n;
	
	network.r = r;
	network.g = g;
	network.b = b;
	network.t = t;
	network.pts = pts;
	network.scl = scl;
	network.n = n;

	
	triangle.r = r;
	triangle.g = g;
	triangle.b = b;
	triangle.t = t;
	triangle.pts = pts;
	triangle.scl = scl;
	triangle.n = n;
	
	asendorf.r = r;
	asendorf.g = g;
	asendorf.b = b;
	asendorf.t = t;
	asendorf.pts = pts;
	asendorf.scl = scl;
	asendorf.n = n;
	
	sixpoints.r = r;
	sixpoints.g = g;
	sixpoints.b = b;
	sixpoints.t = t;
	sixpoints.pts = pts;
	sixpoints.scl = scl;
	sixpoints.n = n;
	
	jocabola.r = r;
	jocabola.g = g;
	jocabola.b = b;
	jocabola.t = t;
	jocabola.pts = pts;
	jocabola.scl = scl;
	jocabola.n = n;
	
	jocabola2.r = r;
	jocabola2.g = g;
	jocabola2.b = b;
	jocabola2.t = t;
	jocabola2.pts = pts;
	jocabola2.scl = scl;
	jocabola2.n = n;
	
	cross.r = r;
	cross.g = g;
	cross.b = b;
	cross.t = t;
	cross.pts = pts;
	cross.scl = scl;
	cross.n = n;
	
	kiebitz.r = r;
	kiebitz.g = g;
	kiebitz.b = b;
	kiebitz.t = t;
	kiebitz.pts = pts;
	kiebitz.scl = scl;
	kiebitz.n = n;
	
	phase.r = r;
	phase.g = g;
	phase.b = b;
	phase.t = t;
	phase.pts = pts;
	phase.scl = scl;
	phase.n = n;
	
	orbit.r = r;
	orbit.g = g;
	orbit.b = b;
	orbit.t = t;
	orbit.pts = pts;
	orbit.scl = scl;
	orbit.n = n;


	
	planes.r = r;
	planes.g = g;
	planes.b = b;
	planes.t = t;
	planes.pts = pts;
	planes.scl = scl;
	planes.n = n;
	
	
	spline.r = r;
	spline.g = g;
	spline.b = b;
	spline.t = t;
	spline.pts = pts;
	spline.scl = scl;
	spline.n = n;
	
	
	//3D Values
	
	if(displayMode == 2){
		
	mesh.xmanval = xmanval;
	mesh.ymanval = ymanval;
	mesh.zmanval = zmanval;
	
	network.xmanval = xmanval;
	network.ymanval = ymanval;
	network.zmanval = zmanval;
	
	kiebitz.xmanval = xmanval;
	kiebitz.ymanval = ymanval;
	kiebitz.zmanval = zmanval;
	
	orbit.xmanval = xmanval;
	orbit.ymanval = ymanval;
	orbit.zmanval = zmanval;

	planes.xmanval = xmanval;
	planes.ymanval = ymanval;
	planes.zmanval = zmanval;

	phase.xmanval = xmanval;
	phase.ymanval = ymanval;
	phase.zmanval = zmanval;
	
	cross.xmanval = xmanval;
	cross.ymanval = ymanval;
	cross.zmanval = zmanval;
	
	jocabola2.xmanval = xmanval;
	jocabola2.ymanval = ymanval;
	jocabola2.zmanval = zmanval;
	
	jocabola.xmanval = xmanval;
	jocabola.ymanval = ymanval;
	jocabola.zmanval = zmanval;
	
	sixpoints.xmanval = xmanval;
	sixpoints.ymanval = ymanval;
	sixpoints.zmanval = zmanval;
	
	asendorf.xmanval = xmanval;
	asendorf.ymanval = ymanval;
	asendorf.zmanval = zmanval;
	
	triangle.xmanval = xmanval;
	triangle.ymanval = ymanval;
	triangle.zmanval = zmanval;
	
	andreas.xmanval = xmanval;
	andreas.ymanval = ymanval;
	andreas.zmanval = zmanval;
	
	circle.xmanval = xmanval;
	circle.ymanval = ymanval;
	circle.zmanval = zmanval;
	
	rectangle.xmanval = xmanval;
	rectangle.ymanval = ymanval;
	rectangle.zmanval = zmanval;
	
	spline.xmanval = xmanval;
	spline.ymanval = ymanval;
	spline.zmanval = zmanval;
		
		
	}
	
	else {
	mesh.xmanval = 0;
	mesh.ymanval = 0;
	mesh.zmanval = 0;
	
	network.xmanval = 0;
	network.ymanval = 0;
	network.zmanval = 0;
	
	kiebitz.xmanval = 0;
	kiebitz.ymanval = 0;
	kiebitz.zmanval = 0;
	
	orbit.xmanval = 0;
	orbit.ymanval = 0;
	orbit.zmanval = 0;

	
	phase.xmanval = 0;
	phase.ymanval = 0;
	phase.zmanval = 0;
	
	planes.xmanval = 0;
	planes.ymanval = 0;
	planes.zmanval = 0;
	
	cross.xmanval = 0;
	cross.ymanval = 0;
	cross.zmanval = 0;
	
	jocabola2.xmanval = 0;
	jocabola2.ymanval = 0;
	jocabola2.zmanval = 0;
	
	jocabola.xmanval = 0;
	jocabola.ymanval = 0;
	jocabola.zmanval = 0;
	
	sixpoints.xmanval = 0;
	sixpoints.ymanval = 0;
	sixpoints.zmanval = 0;
	
	asendorf.xmanval = 0;
	asendorf.ymanval = 0;
	asendorf.zmanval = 0;
	
	triangle.xmanval = 0;
	triangle.ymanval = 0;
	triangle.zmanval = 0;
	
	andreas.xmanval = 0;
	andreas.ymanval = 0;
	andreas.zmanval = 0;
	
	circle.xmanval = 0;
	circle.ymanval = 0;
	circle.zmanval = 0;
	
	rectangle.xmanval = 0;
	rectangle.ymanval = 0;
	rectangle.zmanval = 0;
	
	spline.xmanval = 0;
	spline.ymanval = 0;
	spline.zmanval = 0;
	}

	
	
	
	// EFFECTS
    
	rectangle.update();
	mesh.update();
	circle.update();
	andreas.update();
	network.update();
	triangle.update();
	asendorf.update();
	sixpoints.update();
	jocabola.update();
	jocabola2.update();
	cross.update();
	kiebitz.update();
	phase.update();
	orbit.update();
	planes.update();
	spline.update();
	
	save.update();
	
	
	
	// IMAGE PICKER
	
	if(camera->imageUpdated){
		
		if (cameraPixels == NULL){
			cameraPixels = new unsigned char [camera->width * camera->height*4];
		}
		for (int i = 0; i < camera->height; i++){
			memcpy(cameraPixels+(camera->height-i-1)*camera->width*4, camera->pixels+i*camera->width*4, camera->width*4);
		}
		photo.setFromPixels(cameraPixels,camera->width, camera->height, OF_IMAGE_COLOR_ALPHA);
		
		imgPos.x=ofGetWidth()/2;
		imgPos.y=ofGetHeight()/2;
		camera->imageUpdated=false;

	}
	

	r = colourr.pos.x;
	g = colourg.pos.x;
	b = colourb.pos.x;
	
	n = line.pos.x/20;
	
	t = 290-tline.pos.x;
	
	scl = scale.pos.x/60;
    
    [[UIApplication sharedApplication] setStatusBarHidden:YES];
}

//--------------------------------------------------------------
void testApp::draw(){
	
	if(displayMode == 0){
		// do normal stuff
		drawNormalMode();
	}
	
	
	if(displayMode == 2){
		// edit points mode
		draw3DMode();
	}
}
//--------------------------------------------------------------
void testApp::drawNormalMode(){
	
	
	ofBackground(r, g, b);
	
	// IMAGE PICKER
	ofPushStyle();
	ofDisableAlphaBlending();
	ofSetColor(r,g,b);
	photo.draw(imgPos.x-photo.width/2,imgPos.y-photo.height/2);
	ofPopStyle();
	
	
	glPushMatrix();
	
	// PRESETS DRAW
	
	rectangle.draw();
	circle.draw();
	network.draw();
	asendorf.draw();
	mesh.draw();
	triangle.draw();
	sixpoints.draw();
	andreas.draw();
	jocabola.draw();
	jocabola2.draw();
	cross.draw();
	kiebitz.draw();
	phase.draw();
	orbit.draw();
	planes.draw();
	spline.draw();
	ofPopStyle();
	
	glPopMatrix();

	
	if(shouldITakeScreenshot){
		ofxiPhoneAppDelegate * delegate = ofxiPhoneGetAppDelegate();
		ofxiPhoneScreenGrab(delegate);
	}
	shouldITakeScreenshot=false;
    
    hello.draw();
    intro.draw();

	
}
//--------------------------------------------------------------
void testApp::draw3DMode(){
	
	
	ofPushStyle();
	ofDisableAlphaBlending();
	ofSetColor(r,g,b);
	photo.draw(imgPos.x-photo.width/2,imgPos.y-photo.height/2);
	ofPopStyle();
	
	
	
	//glClear(GL_DEPTH_BUFFER_BIT);
	//glEnable( GL_DEPTH_TEST );
	
	
	//glEnable(GL_BLEND);	
	glPushMatrix();
	glTranslatef( ofGetWidth() * 0.5, ofGetHeight() * 0.5, -ofGetHeight() );
	glScalef( 2, 2, 2 );
	glRotatef( gTrackBallRotation[ 0 ], gTrackBallRotation[ 1 ], gTrackBallRotation[ 2 ], gTrackBallRotation[ 3 ] );
	glRotatef( gWorldRotation[ 0 ], gWorldRotation[ 1 ], gWorldRotation[ 2 ], gWorldRotation[ 3 ] );
	
	ofTranslate(0, 0, -100);
	
	//// DRAW HERE
	
	if(showGrid){
		
		///GRID
		ofPushStyle();
		//	ofRotateX(90);
		ofSetColor(r-20, g-20, b-20);
		ofNoFill();
		ofSetLineWidth(1);
		ofRect(-300, -300, 600, 600);
		
		for(int i=0; i<10; i++) {
			ofLine(-30*i, -300, -30*i, 300);
			ofLine(30*i, -300, 30*i, 300);
			ofLine(-300, -30*i, 300, -30*i);
			ofLine(-300, 30*i, 300, 30*i);
		}
		ofPopStyle();
		
	}
	
		
	glTranslatef(-200,-200,0); // iPhone

	
	// PRESETS DRAW
	
	rectangle.draw();
	circle.draw();
	network.draw();
	asendorf.draw();
	mesh.draw();
	triangle.draw();
	sixpoints.draw();
	andreas.draw();
	jocabola.draw();
	jocabola2.draw();
	cross.draw();
	kiebitz.draw();
	phase.draw();
	orbit.draw();
	//box.draw();
	planes.draw();
	spline.draw();
	ofPopStyle();
	
	//glDisable(GL_BLEND);
	glPopMatrix();
	
	
	if(shouldITakeScreenshot){
		
		ofxiPhoneAppDelegate * delegate = ofxiPhoneGetAppDelegate();
		ofxiPhoneScreenGrab(delegate);
	}
	
	shouldITakeScreenshot=false;
	
	
	hello.draw();
	intro.draw();
	
}


//--------------------------------------------------------------
void testApp::exit(){
		
	saveFile();
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
	
	
	if(displayMode == 0){
		touchDownNormal(touch);
	}
	
	if(displayMode == 2){
		touchDown3DMode(touch);
	}
	
}

//--------------------------------------------------------------
void testApp::touchDownNormal(ofTouchEventArgs &touch){
	
	
}	

//--------------------------------------------------------------
void testApp::touchDown3DMode(ofTouchEventArgs &touch){
	

		if(touch.x>0 && touch.x<ofGetWidth() && touch.y>0 && touch.y<ofGetHeight()-30){
	mouseTrackballDown( touch.x*(ofxAccelerometer.getForce().x)*10, touch.y*(ofxAccelerometer.getForce().y)*10 );
		}

	if (shouldITakeScreenshot==false){
		if(touch.x>0 && touch.x<ofGetWidth() && touch.y>0 && touch.y<ofGetHeight()-30){
	mouseTrackballDown( touch.x, touch.y );
		}
	}
			
	

		
//		if (touch.x>30 && touch.x<30+120 && touch.y>50 && touch.y<50+40){
//		
//			showGrid = !showGrid;
//		}
	
	
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
	
	if(displayMode == 0){
		touchMovedNormal(touch);
	}
	
	
	if(displayMode == 2){
		touchMoved3DMode(touch);
	}
	
	
	

	
}

//--------------------------------------------------------------
void testApp::touchMovedNormal(ofTouchEventArgs &touch){
	
	///// DRAWING
	if(displayMode == 0){
									
			ofPoint myPt;
			myPt.x = touch.x;
			myPt.y = touch.y;
			pts.push_back(myPt);
			
			triangle.touchMoved(touch.x, touch.y, 0);
			spline.touchMoved(touch.x, touch.y, 0);
			
			
			////SAVING POINTS TO XML AS YOU DRAW THEM
//			
//			if(pointCount < NUM_PTS -1){
//				pts[pointCount].set(touch.x, touch.y);
//			}
		}	
}


//--------------------------------------------------------------
void testApp::touchMoved3DMode(ofTouchEventArgs &touch){
	
	if(touch.x>0 && touch.x<ofGetWidth() && touch.y>0 && touch.y<ofGetHeight()-30){
	mouseTrackballMove( touch.x, touch.y );
	
	}
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	
	
	if(displayMode == 2){
		touchUp3DMode(touch);
	}
	
	
	
}
//--------------------------------------------------------------

void testApp::touchUpNormal(ofTouchEventArgs &touch){
	
		
}
//--------------------------------------------------------------

void testApp::touchUp3DMode(ofTouchEventArgs &touch){
	if(touch.x>0 && touch.x<ofGetWidth() && touch.y>0 && touch.y<ofGetHeight()-30){
        mouseTrackballUp( touch.x, touch.y );
	}
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){
	
	[ofxiPhoneGetUIWindow() addSubview:myGuiViewController.viewMain];
	myGuiViewController.viewMain.hidden = NO;
	
}

//--------------------------------------------------------------
void testApp::lostFocus(){
	
}

//--------------------------------------------------------------
void testApp::gotFocus(){
	
}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){
	
}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){
	
	
}
//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs& args){
	
}
//--------------------------------------------------------------
void testApp::loadMain(){
	
	myGuiViewController.viewMain.hidden = NO;
	myGuiViewController.viewSettings.hidden = YES;
	
}
//--------------------------------------------------------------

void testApp::loadSettings(){
	
	myGuiViewController.viewMain.hidden = YES;
	myGuiViewController.viewSettings.hidden = NO;
	
}
//--------------------------------------------------------------

void testApp::randomSettings(){


		line.pos.x = ofRandom(30, 290);
		tline.pos.x = ofRandom(30, 290);
		scale.pos.x = ofRandom(30, 290);
		n = ofRandom(1, 5);
		t = ofRandom(0, 200);
		scl = ofRandom(1, 5);			
		colourr.pos.x = ofRandom(30, 290);
		colourg.pos.x = ofRandom(30, 290);
		colourb.pos.x = ofRandom(30, 290);

}

//--------------------------------------------------------------

void testApp::loadPresets(){
	
	myGuiViewController.viewMain.hidden = YES;
	myGuiViewController.viewSettings.hidden = YES;
	
}
//--------------------------------------------------------------

void testApp::saveFile(){
	
	XML.setValue("BACKGROUND:COLOR:RED", r);
	XML.setValue("BACKGROUND:COLOR:GREEN", g);
	XML.setValue("BACKGROUND:COLOR:BLUE", b);
	
	XML.setValue("SETTINGS:PARAMETER:LINE", line.pos.x);
	XML.setValue("SETTINGS:PARAMETER:TRANSPARENCY", tline.pos.x);
	XML.setValue("SETTINGS:PARAMETER:SCALE", scale.pos.x);
	
	XML.setValue("SETTINGS:PARAMETER:XMOD", xman.pos.x);
	XML.setValue("SETTINGS:PARAMETER:YMOD", yman.pos.x);
	XML.setValue("SETTINGS:PARAMETER:ZMOD", zman.pos.x);
	
	XML.setValue("SETTINGS:PARAMETER:FIRST", 0);
    
    XML.saveFile( ofxiPhoneGetDocumentsDirectory() + "SKTCHSave.gml" );
	
}
//--------------------------------------------------------------
void testApp::loadFile(){
    
    XML.loadFile(ofxiPhoneGetDocumentsDirectory() + "SKTCHSave.gml");
    
	colourr.pos.x = XML.getValue("BACKGROUND:COLOR:RED", 20);
	colourg.pos.x = XML.getValue("BACKGROUND:COLOR:GREEN", 20);
	colourb.pos.x = XML.getValue("BACKGROUND:COLOR:BLUE", 20);
	
	line.pos.x = XML.getValue("SETTINGS:PARAMETER:LINE", 100);
	tline.pos.x = XML.getValue("SETTINGS:PARAMETER:TRANSPARENCY", 250);
	scale.pos.x = XML.getValue("SETTINGS:PARAMETER:SCALE", 250);	
	
	xman.pos.x = XML.getValue("SETTINGS:PARAMETER:XMOD", 0);
	yman.pos.x = XML.getValue("SETTINGS:PARAMETER:YMOD", 0);
	zman.pos.x = XML.getValue("SETTINGS:PARAMETER:ZMOD", 0);	
	
	u = XML.getValue("SETTINGS:PARAMETER:FIRST", 1);
	
	
}
