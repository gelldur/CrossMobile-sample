//
// Created by Dawid Drozd aka Gelldur on 7/1/16.
//

#include "AppMain.h"

#include <log.h>
#include <Director.h>
#include <SampleApplication.h>

#include <TestRunner.h>

int startApplication(CrossMobile::Platform::Bridge* bridge, const std::vector<std::string>& flags)
{
	DLOG("######################################################################################################");
	DLOG("######################################################################################################");
	DLOG("######################################################################################################");
	DLOG("main runTests\n");

	std::vector<std::string> args = {"./app", "--gtest_break_on_failure", "--gtest_filter=*", "--gtest_color=no"};
	if (flags.empty() == false)
	{
		args[0] = flags[0];
		args.insert(args.end(), flags.begin() + 1, flags.end());
	}

	TestRunner testRunner;
	int testsResult = testRunner.run(args);
	if (testsResult != 0)
	{
		assert(false);
		return testsResult;
	}

	DLOG("######################################################################################################");
	DLOG("######################################################################################################");
	DLOG("######################################################################################################");
	DLOG("main startApplication");
	auto app = new SampleApplication(bridge);
	Director::create(std::unique_ptr<Application>(app));
	return 0;
}

int startApplication(int argc, char** argv)
{
	std::vector<std::string> args;
	for (int i = 0; i < argc; ++i)
	{
		args.emplace_back(argv[i]);
	}

	return startApplication(CrossMobile::Platform::Bridge::create(), args);
}

void waitForBackgroundThreads(int count)
{
	auto app = Director::getInstance().getApp();
	int i = count;
	DLOG("Waiting! for late ones");
	while (--i > 0)
	{
		if (i < 1 && app->getUILoop().uiTick.empty() == false)
		{
			++i;
			Poco::Thread::sleep(100);
		}

		app->getUILoop().onTick();
		Poco::Thread::sleep(100);
	}
	DLOG("Done waiting for late ones");
}
