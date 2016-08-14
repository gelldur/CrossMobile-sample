//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#pragma once

#include <screen/ScreenCreator.h>

class AppScreenCreator : public ScreenCreator
{
public:
	virtual Screen* create(const std::string& name, Nodect&& nodeScreen) override;
};


