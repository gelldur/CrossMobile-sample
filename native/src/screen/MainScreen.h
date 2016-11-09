//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#pragma once

#include <screen/Screen.h>
#include <Adapter.h>

class MainScreen : public Screen
{
public:
	MainScreen(const std::string& screenName);
	MainScreen(const std::string& screenName, Nodect&& node);

	virtual void onCreate() override;
	virtual void onResume() override;
	virtual void onPause() override;
	virtual void onDestroy() override;

	std::shared_ptr<AdapterList> getAdapter();

private:
	std::shared_ptr<AdapterList> _adapter;
};
