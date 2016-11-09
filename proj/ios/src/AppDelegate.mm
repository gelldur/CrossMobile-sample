#import "AppDelegate.h"

#import <ColorUtils.h>
#import "MainScreenController.h"

#include <Director.h>
#include <log.h>

// clang-format off
@interface AppDelegate ()
// clang-format on
@property (atomic, strong) NSTimer* _timer;
@end

@implementation AppDelegate

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions
{
#ifdef NDEBUG

#else
	DLOG("DEBUG MODE ON!!!");
#endif
	// Hide 1 px space between toolbar and app content
	[[UINavigationBar appearance] setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
	[[UINavigationBar appearance] setShadowImage:[UIImage new]];

	DLOG("didFinishLaunchingWithOptions!");

	self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
	self.window.backgroundColor = UIColorFromRGB(0xedebef);

	MainScreenController* mainScreen = [MainScreenController new];

	self.window.rootViewController = mainScreen;
	[self.window makeKeyAndVisible];

	[self onResume];

	return YES;
}

- (void)onResume
{
	DLOG("App onResume");
	if (self._timer != nil)
	{
		[self._timer invalidate];
	}
	self._timer = [NSTimer timerWithTimeInterval:0.1f target:self selector:@selector(onTick) userInfo:nil repeats:YES];
	[[NSRunLoop mainRunLoop] addTimer:self._timer forMode:NSRunLoopCommonModes];
}

- (void)onPause
{
	DLOG("App onPause");
	[self._timer invalidate];
}

- (void)onTick
{
	Director::getInstance().onTickUI();
}

- (void)applicationWillResignActive:(UIApplication*)application
{
	// Sent when the application is about to move from active to inactive state. This can occur for certain types of
	// temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application
	// and it begins the transition to the background state.
	// Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use
	// this method to pause the game.
	DLOG("applicationWillResignActive!");
	[self onPause];
}

- (void)applicationDidEnterBackground:(UIApplication*)application
{
	// Use this method to release shared resources, save user data, invalidate timers, and store enough application
	// state information to restore your application to its current state in case it is terminated later.
	// If your application supports background execution, this method is called instead of applicationWillTerminate:
	// when the user quits.
	DLOG("applicationDidEnterBackground!");
}

- (void)applicationWillEnterForeground:(UIApplication*)application
{
	// Called as part of the transition from the background to the inactive state; here you can undo many of the changes
	// made on entering the background.
	DLOG("applicationWillEnterForeground!");
}

- (void)applicationDidBecomeActive:(UIApplication*)application
{
	DLOG("applicationDidBecomeActive!");
	[self onResume];
	// Restart any tasks that were paused (or not yet started) while the application was inactive. If the application
	// was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication*)application
{
	DLOG("applicationWillTerminate!");
	// Called when the application is about to terminate. Save data if appropriate. See also
	// applicationDidEnterBackground:.
	// Saves changes in the application's managed object context before the application terminates.
	Director::getInstance().destroy();
}

@end
