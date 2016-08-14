//
// Created by Dawid Drozd aka Gelldur on 6/30/16.
//

#include "TestRunner.h"

#include <cstring>
#include <gtest/gtest.h>

int TestRunner::run(const std::vector<std::string>& flags)
{
	char** argv = new char* [flags.size()];
	for (unsigned i = 0; i < flags.size(); ++i)
	{
		argv[i] = new char[flags[i].size() + 1];
		strcpy(argv[i], flags[i].c_str());
	}

	int argc = (int) flags.size();
	::testing::InitGoogleTest(&argc, argv);
	int testsResult = RUN_ALL_TESTS();
	if (testsResult != 0)
	{
		assert(false);
	}

	for (unsigned i = 0; i < argc; ++i)
	{
		delete[] argv[i];
	}
	delete[] argv;

	return testsResult;
}
