//
//  MyGuiView.h
//  iPhone Empty Example
//
//  Created by theo on 26/01/2010.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

#include "testApp.h"



@interface MyGuiView : UIViewController {
	IBOutlet UILabel *displayText;
	
	testApp *myApp;		// points to our instance of testApp
	
	IBOutlet UIView *viewMain;
	IBOutlet UIView *viewSettings;
    IBOutlet UIView *viewPresets;
}

@property (nonatomic, retain) IBOutlet UIView *viewMain;
@property (nonatomic, retain) IBOutlet UIView *viewSettings;
@property (nonatomic, retain) IBOutlet UIView *viewPresets;

-(void)loadViewMain;

-(void)setStatusString:(NSString *)trackStr;

-(IBAction)adjustPoints:(id)sender;
//-(IBAction)fillSwitch:(id)sender;

-(IBAction)more:(id)sender;
-(IBAction)less:(id)sender;
-(IBAction)acc:(id)sender;


-(IBAction)threed:(id)sender;
-(IBAction)settings:(id)sender;
-(IBAction)clear:(id)sender;
-(IBAction)info:(id)sender;
-(IBAction)help:(id)sender;

-(IBAction)hide:(id)sender;
-(IBAction)hideonly:(id)sender;
-(IBAction)loadMain:(id)sender;
-(IBAction)openSettings:(id)sender;
-(IBAction)openPresets:(id)sender;
-(IBAction)randomSettings:(id)sender;
-(IBAction)openEdit:(id)sender;
-(IBAction)openAbout:(id)sender;

//settings
-(IBAction)settingsR:(id)sender;
-(IBAction)settingsG:(id)sender;
-(IBAction)settingsB:(id)sender;
-(IBAction)settingsN:(id)sender;
-(IBAction)settingsT:(id)sender;
-(IBAction)settingsSCL:(id)sender;

-(IBAction)imageLibrary:(id)sender;
-(IBAction)imageCamera:(id)sender;
-(IBAction)imageClear:(id)sender;
-(IBAction)takescreenshot:(id)sender;
-(IBAction)grid:(id)sender;

//presets
-(IBAction)presetRectangle:(id)sender;
-(IBAction)presetCircle:(id)sender;
-(IBAction)presetMesh:(id)sender;
-(IBAction)presetAndreas:(id)sender;
-(IBAction)presetNetwork:(id)sender;
-(IBAction)presetTriangle:(id)sender;
-(IBAction)presetAsendorf:(id)sender;
-(IBAction)presetSixpoints:(id)sender;
-(IBAction)presetJocabola:(id)sender;
-(IBAction)presetJocabola2:(id)sender;
-(IBAction)presetCross:(id)sender;
-(IBAction)presetKiebitz:(id)sender;
-(IBAction)presetPhase:(id)sender;
-(IBAction)presetOrbit:(id)sender;
-(IBAction)presetPlanes:(id)sender;
-(IBAction)presetSpline:(id)sender;

//about
-(IBAction)link:(id)sender;
-(IBAction)linkrate:(id)sender;

@end


