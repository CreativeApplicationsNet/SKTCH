#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"
#include "ofMain.h"
#include "ofxXmlSettings.h"

#include "trackball.h"
#include "ofxVectorMath.h"

#include "about.h"
#include "slider.h"
#include "tooltip.h"
#include "menu.h"
#include "rectangle.h"
#include "mesh.h"
#include "circle.h"
#include "andreas.h"
#include "confirm.h"
#include "network.h"
#include "triangle.h"
#include "asendorf.h"
#include "sixpoints.h"
#include "intro.h"
#include "jocabola.h"
#include "jocabola2.h"
#include "cross.h"
#include "kiebitz.h"
#include "phase.h"
#include "orbit.h"
#include "planes.h"
#include "spline.h"
#include "save.h"
#include "button.h"

#define NUM_PTS 1200

typedef struct {
	
	float 	x;
	float 	y;
	bool 	bBeingDragged;
	bool 	bOver;
	float 	radius;
	
}	draggableVertex;



class testApp : public ofxiPhoneApp {
	
public:
	void setup();
	void update();
	void draw();
	void exit();
	
	void touchDown(ofTouchEventArgs &touch);
	void touchMoved(ofTouchEventArgs &touch);
	void touchUp(ofTouchEventArgs &touch);
	void touchDoubleTap(ofTouchEventArgs &touch);
	void touchCancelled(ofTouchEventArgs &touch);
	
	void initTrackball();
	void mouseTrackballDown( int x, int y );
	void mouseTrackballUp( int x, int y );
	void mouseTrackballMove( int x, int y );
	
	
	void lostFocus();
	void gotFocus();
	void gotMemoryWarning();
	void deviceOrientationChanged(int newOrientation);
	
	
	void drawNormalMode();
	void draw3DMode();
	void touchDownNormal(ofTouchEventArgs &touch);
	void touchDown3DMode(ofTouchEventArgs &touch);
	void touchMovedNormal(ofTouchEventArgs &touch);
	void touchMoved3DMode(ofTouchEventArgs &touch);
	void touchUpNormal(ofTouchEventArgs &touch);
	void touchUp3DMode(ofTouchEventArgs &touch);
	
	void loadSettings();
	void loadMain();
	void randomSettings();
	void loadPresets();
    
    void saveFile();
	void loadFile();
		
	
	vector < ofPoint > pts;
	
	//	ofPoint followPt;
	
//	ofTrueTypeFont  someFont;
	
	// trackball.
	GLfloat gTrackBallRotation[ 4 ];
	GLfloat gWorldRotation[ 4 ];
	bool	gTrackBall;
	
	About hello;
	Slider line;
	Slider tline;
	Slider scale;
	Save save;
	
	Slider colourr;
	Slider colourg;
	Slider colourb;
	
	Slider xman;
	Slider yman;
	Slider zman;
	
	Tooltip tooltip;
	Button button;
	Confirm confirm;
	Menu menu;
	Intro intro;

	
	
	////BUTTONS
	
	
	
	unsigned char * cameraPixels;	// the camera image needs to be flipped, so we'll use this memory for that. 
	ofxiPhoneImagePicker * camera;
	ofImage	photo;
	ofPoint imgPos;
	
	
	//3D MANIPULATORS
	
	float xmanval;
	float ymanval;
	float zmanval;
	
	float t;
	float n;
	
	float counter;
	
	float r;
	float g;
	float b;
	
	float vx;
	float vy;
	float l;
	
	float var;
	
	float scl;
	
	float squareAlpha;	
	
	float m; //mode
	
	bool 	bBeingDragged;
	bool 	bOver;
	
	float width;
	float height;
	
	float transform;
	float translx;
	float transly;
	
	float zoomy;
	
	float translate;
	
	ofxiPhoneKeyboard * keyboard;
	
	// EFFECTS
	
	Rectangle rectangle;
	Mesh mesh;
	Circle circle;
	Andreas andreas;
	Network network;
	Triangle triangle;
	Asendorf asendorf;
	SixPoints sixpoints;
	Jocabola jocabola;
	Jocabola2 jocabola2;
	Cross cross;
	Kiebitz kiebitz;
	Phase phase;
	Orbit orbit;
	Planes planes;
	Spline spline;
	
	int lastTagNumber;
	int pointCount;
	int lineCount;
    
    float u; // first time user or not
    ofxXmlSettings XML;
	string xmlStructure;
	string message;
	
	
	//preset settings
	float pp1;
	
	ofPoint followPt[NUM_PTS];
	
	bool shouldITakeScreenshot;
	bool canDelete;
	
	
	bool showGrid;
	bool tdmenu;
	
	// Display Mode
	int	displayMode;
	
		
	float screenW;
	float screenH;
	
	float lengthRatio;
	int numPoints;
	bool bFill;
	
	
	int menuType;

};


