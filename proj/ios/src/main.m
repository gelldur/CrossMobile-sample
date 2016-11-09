//
//  main.m
//  eSportLiveScore
//
//  Created by Vagrant on 4/12/16.
//  Copyright © 2016 ESportSolutions. All rights reserved.
//
#import "AppDelegate.h"
#import <UIKit/UIKit.h>

#include <AppMain.h>

int main(int argc, char* argv[]) // This comment prevent from line brak clang-formatter :D
{
	int result = startApplication(argc, argv);
	if (result != 0)
	{
		return result;
	}

	@autoreleasepool
	{
		@try
		{
			return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
		}
		@catch (NSException* exception)
		{ /* Catch any uncaught exceptions and print out a friendly call stack. Instead of an ugly memory addresses. */
			NSString* message = [NSString stringWithFormat:@"Uncaught exception %@ : %@\n %@", exception.name,
										  exception.reason, [exception callStackSymbols]];
			NSLog(@"%@", message);
			@throw;
		}
		@catch (...)
		{
			// Attempt to get the correct stacktrace for C++ exceptions.
			dispatch_sync(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
				@throw;
			});
		}
	}
}
