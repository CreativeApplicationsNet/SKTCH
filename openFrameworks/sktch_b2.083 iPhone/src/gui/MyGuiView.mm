//
//  MyGuiView.m
//  iPhone Empty Example
//
//  Created by theo on 26/01/2010.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "MyGuiView.h"
#include "ofxiPhoneExtras.h"



@implementation MyGuiView

@synthesize viewMain, viewSettings, viewPresets;

// called automatically after the view is loaded, can be treated like the constructor or setup() of this class
-(void)viewDidLoad {
	myApp = (testApp*)ofGetAppPtr();

}

-(void)loadViewMain
{
	[viewMain removeFromSuperview];
	[self.view addSubview:viewSettings];
    [self.view addSubview:viewPresets];

    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
	
	
}

//----------------------------------------------------------------
-(void)setStatusString:(NSString *)trackStr{
	displayText.text = trackStr;
}

//----------------------------------------------------------------
-(IBAction)more:(id)sender{
	myApp->vx += 1.0;
	myApp->vy += 1.0;			
}

//----------------------------------------------------------------
-(IBAction)less:(id)sender{
	myApp->vx -= 1.0;
	myApp->vy -= 1.0;
	
}
//----------------------------------------------------------------
-(IBAction)threed:(id)sender{
	
	if(myApp->displayMode == 0){
		myApp->displayMode = 2;
		
	}
	else {
		myApp->displayMode = 0;
	}
	
	
	
}
//----------------------------------------------------------------
-(IBAction)settings:(id)sender{
	if (myApp->hello.bVisible == true) {
		myApp->hello.bVisible = false;
	}
	else {
		myApp->hello.bVisible = true;
	}
	
}
//----------------------------------------------------------------

-(IBAction)acc:(id)sender{
	
//	myApp->vx = 1.0;
//	myApp->vy = 1.0;
//	myApp->l = 60.0;
		
}
//----------------------------------------------------------------
-(IBAction)clear:(id)sender{
	
    myApp->pts.clear();
    myApp->triangle.touchDown(0, 0, 0);
    myApp->spline.touchDown(0, 0, 0);
    
    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
	

	
	
}
//----------------------------------------------------------------
-(IBAction)info:(id)sender{

	if (myApp->hello.bVisible == true) {
		myApp->hello.bVisible = false;
	}
	else {
		myApp->hello.bVisible = true;
	}
    
    myApp->intro.bVisible = false;
    
    viewPresets.hidden = YES;
    viewSettings.hidden = YES;
    viewMain.hidden = NO;
}

//----------------------------------------------------------------
-(IBAction)help:(id)sender{
    
	if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
	else {
		myApp->intro.bVisible = true;
	}
    
    myApp->hello.bVisible = false;
    
    viewPresets.hidden = YES;
    viewSettings.hidden = YES;
    viewMain.hidden = NO;
}


//----------------------------------------------------------------
-(IBAction)hide:(id)sender{
		
    self.view.hidden = YES;
    self.viewMain.hidden = YES;
    //self.viewSettings.hidden = YES;
    
    if (myApp->hello.bVisible == true) {
		myApp->hello.bVisible = false;
	}
    
    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
	

}

//----------------------------------------------------------------
-(IBAction)hideonly:(id)sender{
	
	self.view.hidden = YES;
    self.viewMain.hidden = YES;
    self.viewSettings.hidden = YES;
    self.viewPresets.hidden = YES;
    
    
    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
	
	
}

//----------------------------------------------------------------
-(IBAction)loadMain:(id)sender{
		
    viewPresets.hidden = YES;
	viewSettings.hidden = YES;
	viewMain.hidden = NO;
    
    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
    
    
	
}

//----------------------------------------------------------------
-(IBAction)openSettings:(id)sender{
		
	//myApp->loadSettings();
    if (viewSettings.hidden == YES){
        viewSettings.hidden = NO;
    }
    else {
        viewSettings.hidden = YES;
    }
    
    viewPresets.hidden = YES;
    
    myApp->saveFile();
}

//----------------------------------------------------------------
-(IBAction)openPresets:(id)sender{
    
    //viewPresets.hidden = NO;
    if (viewPresets.hidden == YES){
        viewPresets.hidden = NO;
    }
    else {
        viewPresets.hidden = YES;
    }
    
    if (myApp->intro.bVisible == true) {
		myApp->intro.bVisible = false;
	}
    
    viewSettings.hidden = YES;
    
    myApp->saveFile();
}

//----------------------------------------------------------------
-(IBAction)randomSettings:(id)sender{
		
	myApp->randomSettings();
}

//----------------------------------------------------------------
-(IBAction)openEdit:(id)sender{
	
	if(myApp->displayMode == 0){
		myApp->displayMode = 1;
	}
}

//----------------------------------------------------------------
-(IBAction)settingsR:(id)sender{
	
	UISlider * slider = sender;
	
	if(myApp->displayMode == 0){
		myApp->colourr.pos.x = [slider value];
	}
	
	if(myApp->displayMode == 2){
		myApp->xman.pos.x = [slider value];
	}
	
	

}

//----------------------------------------------------------------
-(IBAction)settingsG:(id)sender{
	
	UISlider * slider = sender;
	
	if(myApp->displayMode == 0){
		myApp->colourg.pos.x = [slider value];
	}
	
	if(myApp->displayMode == 2){
		myApp->yman.pos.x = [slider value];
	}
	
	
	
}

//----------------------------------------------------------------
-(IBAction)settingsB:(id)sender{
	
	UISlider * slider = sender;
	
	if(myApp->displayMode == 0){
		myApp->colourb.pos.x = [slider value];
	}
	
	if(myApp->displayMode == 2){
		myApp->zman.pos.x = [slider value];
	}
	
		
}

//----------------------------------------------------------------
-(IBAction)settingsN:(id)sender{
	
	UISlider * slider = sender;
	myApp->line.pos.x = [slider value];
}

//----------------------------------------------------------------
-(IBAction)settingsT:(id)sender{
	
	UISlider * slider = sender;
	myApp->tline.pos.x = [slider value];
    
    //slider.Value = myApp->tline.pos.x;
	
}

//----------------------------------------------------------------
-(IBAction)settingsSCL:(id)sender{
	
	UISlider * slider = sender;
	myApp->scale.pos.x = [slider value];	
}

//----------------------------------------------------------------
-(IBAction)imageLibrary:(id)sender{
	
	myApp->camera->openLibrary();
	

}

//----------------------------------------------------------------
-(IBAction)imageCamera:(id)sender{
	
	//myApp->camera->openCamera(2); //front
    myApp->camera->openCamera(1); //back
	
	
}

//----------------------------------------------------------------
-(IBAction)imageClear:(id)sender{
	
	myApp->photo.clear(); 
}

//----------------------------------------------------------------
-(IBAction)takescreenshot:(id)sender{
	
    myApp->shouldITakeScreenshot=true;
	
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Screenshot Saved" message:@"See your Photo Gallery"
												   delegate:self cancelButtonTitle:@"OK" otherButtonTitles: nil];
	[alert show];	
	[alert release];
}

//----------------------------------------------------------------
-(IBAction)grid:(id)sender{
	
    if (myApp->showGrid == true) {
		myApp->showGrid = false;
	}
	else {
		myApp->showGrid = true;
	} 
}

//----------------------------------------------------------------


//// PRESETS
//----------------------------------------------------------------
-(IBAction)presetRectangle:(id)sender{
	UISwitch * toggle = sender;	
    myApp->rectangle.bVisible = [toggle isOn];
}
-(IBAction)presetCircle:(id)sender{
	UISwitch * toggle = sender;	
    myApp->circle.bVisible = [toggle isOn];
}
-(IBAction)presetMesh:(id)sender{
	UISwitch * toggle = sender;	
    myApp->mesh.bVisible = [toggle isOn];
}
-(IBAction)presetAndreas:(id)sender{
	UISwitch * toggle = sender;	
    myApp->andreas.bVisible = [toggle isOn];
}
-(IBAction)presetNetwork:(id)sender{
	UISwitch * toggle = sender;	
    myApp->network.bVisible = [toggle isOn];
}
-(IBAction)presetTriangle:(id)sender{
    UISwitch * toggle = sender;	
    myApp->triangle.bVisible = [toggle isOn];
}
-(IBAction)presetAsendorf:(id)sender{
    UISwitch * toggle = sender;	
    myApp->asendorf.bVisible = [toggle isOn];
}
-(IBAction)presetSixpoints:(id)sender{
    UISwitch * toggle = sender;	
    myApp->sixpoints.bVisible = [toggle isOn];
}
-(IBAction)presetJocabola:(id)sender{
    UISwitch * toggle = sender;	
    myApp->jocabola.bVisible = [toggle isOn];
}
-(IBAction)presetJocabola2:(id)sender{
    UISwitch * toggle = sender;	
    myApp->jocabola2.bVisible = [toggle isOn];
}
-(IBAction)presetCross:(id)sender{
    UISwitch * toggle = sender;	
    myApp->cross.bVisible = [toggle isOn];
}
-(IBAction)presetKiebitz:(id)sender{
    UISwitch * toggle = sender;	
    myApp->kiebitz.bVisible = [toggle isOn];
}
-(IBAction)presetPhase:(id)sender{
    UISwitch * toggle = sender;	
    myApp->phase.bVisible = [toggle isOn];
}
-(IBAction)presetOrbit:(id)sender{
    UISwitch * toggle = sender;	
    myApp->orbit.bVisible = [toggle isOn];
}
-(IBAction)presetPlanes:(id)sender{
    UISwitch * toggle = sender;	
    myApp->planes.bVisible = [toggle isOn];
}
-(IBAction)presetSpline:(id)sender{
    UISwitch * toggle = sender;	
    myApp->spline.bVisible = [toggle isOn];
}

//----------------------------------------------------------------
-(IBAction)link:(id)sender{
	
	if (myApp->hello.bVisible == true) {
        string sktchlink="http://apps.creativeapplications.net";
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString: [[[[NSString alloc] initWithCString: sktchlink.c_str()]stringByAddingPercentEscapesUsingEncoding: NSASCIIStringEncoding] autorelease]   ]];
	}	
	
}

//----------------------------------------------------------------
-(IBAction)linkrate:(id)sender{
	
	if (myApp->hello.bVisible == true) {
        string sktchlink="http://itunes.apple.com/us/app/sktch/id369434236?mt=8";
        [[UIApplication sharedApplication] openURL:[NSURL URLWithString: [[[[NSString alloc] initWithCString: sktchlink.c_str()]stringByAddingPercentEscapesUsingEncoding: NSASCIIStringEncoding] autorelease]   ]];
	}	
	
}


@end

