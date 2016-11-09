//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#include "MainScreen.h"

#include <component/NodectHelper.h>
#include <component/view/Text.h>
#include <component/common/Pool.h>
#include <component/adapter/AdapterList.h>

MainScreen::MainScreen(const std::string& screenName)
		: Screen(screenName)
		, _adapter(new Adapter())
{
	getNativeScreen().getComponent<Pool>().add("adapter", {_adapter});//TODO join
}

MainScreen::MainScreen(const std::string& screenName, Nodect&& node)
		: Screen(screenName, std::move(node))
		, _adapter(new Adapter())
{
	getNativeScreen().getComponent<Pool>().add("adapter", {_adapter});
}

void MainScreen::onCreate()
{
}

void MainScreen::onResume()
{
	auto& textView = NodectHelper::find(getNativeScreen(), "textView");
	textView.getComponent<Text>().setText("Hello from CrossMobile++ sample\ncode");
}

void MainScreen::onPause()
{

}

void MainScreen::onDestroy()
{

}

std::shared_ptr<AdapterList> MainScreen::getAdapter()
{
	return _adapter;
}
