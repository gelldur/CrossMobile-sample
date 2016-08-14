//
// Created by Dawid Drozd aka Gelldur on 7/1/16.
//

#ifndef SAMPLE_APP_MAIN_H
#define SAMPLE_APP_MAIN_H

#ifdef __cplusplus

#include <vector>
#include <string>

namespace CrossMobile
{
namespace Platform
{
class Bridge;
}
}

int startApplication(CrossMobile::Platform::Bridge* bridge, const std::vector<std::string>& flags = {});

void waitForBackgroundThreads(int count = 30);

extern "C" {
#endif

int startApplication(int argc, char** argv);

#ifdef __cplusplus
}
#endif

#endif //SAMPLE_APP_MAIN_H
