//
// Created by Dawid Drozd aka Gelldur on 8/9/16.
//

#pragma once

#include <Application.h>

class SampleApplication : public Application
{
	using inherited = Application;
public:
	SampleApplication(CrossMobile::Platform::Bridge* bridge);
	virtual void onCreate() override;

};


