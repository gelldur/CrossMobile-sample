//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#include "AppScreenCreator.h"

#include "MainScreen.h"

Screen* AppScreenCreator::create(const std::string& name, Nodect&& nodeScreen)
{
	if (name == "MainScreen")
	{
		return new MainScreen(name, std::move(nodeScreen));
	}

	return ScreenCreator::create(name, std::move(nodeScreen));
}
