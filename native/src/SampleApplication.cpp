//
// Created by Dawid Drozd aka Gelldur on 8/9/16.
//

#include "SampleApplication.h"

#include <Director.h>
#include <api/Server.h>
#include <screen/AppScreenCreator.h>

SampleApplication::SampleApplication(CrossMobile::Platform::Bridge* bridge)
		: inherited(bridge, new AppScreenCreator())
{
}

void SampleApplication::onCreate()
{
	inherited::onCreate();

	Server::setDefaultDebugable(true);
	Server::setDefaultHost("api.sample.com");
}

