#include <iostream>

#include <log.h>
#include <Director.h>
#include <Application.h>
#include <AppMain.h>

using namespace std;

void mainLoop()
{
	auto app = Director::getInstance().getApp();

	int i = 10;
	while (--i > 0)
	{
		if (i < 1 && app->getUILoop().uiTick.empty() == false)
		{
			++i;
			DLOG("Waiting! for late ones");
			Poco::Thread::sleep(1000);
		}

		app->getUILoop().onTick();
		Poco::Thread::sleep(100);
	}
}

int main(int argc, char** argv)
{
	std::cout << "Hello, World!\n\n" << std::endl;

	int testsResult = startApplication(argc, argv);
	if (testsResult != 0)
	{
		assert(false);
		return testsResult;
	}

	mainLoop();

	Director::destroy();

	return testsResult;
}
