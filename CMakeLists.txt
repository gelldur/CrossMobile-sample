CMAKE_MINIMUM_REQUIRED(VERSION 3.4.1)
PROJECT(sampleApp)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/native/libraries/CrossMobile/cmake/")

ADD_COMPILE_OPTIONS(-Wall -pedantic)#add -Werror
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-long-long -Wno-unused-private-field -Wnon-virtual-dtor")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_VERBOSE_MAKEFILE on)

INCLUDE(FixClion)
INCLUDE(CrossMobileBuildHelpers)

IF(IOS)
	SET(SDKVER "9.3")
	INCLUDE(iOSBuildHelpers)
ENDIF()

EXECUTE_PROCESS(COMMAND git rev-list --first-parent --count HEAD
		OUTPUT_VARIABLE E_BUILD_VERSION_CODE
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		OUTPUT_STRIP_TRAILING_WHITESPACE)

SET(E_BUILD_VERSION_NAME "\"sample-debug\"")
IF(LINUX)
	EXECUTE_PROCESS(COMMAND uname -nom
			OUTPUT_VARIABLE E_PLATFORM_NAME
			OUTPUT_STRIP_TRAILING_WHITESPACE)
	SET(E_BUILD_PLATFORM_NAME "\"${E_PLATFORM_NAME}\"")
ELSEIF(ANDROID)
	SET(E_BUILD_PLATFORM_NAME "\"Android\"")
ELSEIF(MAC_IOS)
	SET(E_BUILD_PLATFORM_NAME "\"iOS\"")
ELSE()
	SET(E_BUILD_PLATFORM_NAME "\"Unknown\"")
ENDIF(LINUX)


CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/native/BuildConfig.h.in ${CMAKE_CURRENT_SOURCE_DIR}/native/src/BuildConfig.h)

IF(LINUX)
	SET(SOURCE_FILES_PLATFORM
			proj/linux/main.cpp
			)
ELSEIF(ANDROID)
	INCLUDE(${PROJECT_SOURCE_DIR}/native/libraries/CrossMobile/proj/android/library/src/main/JniSources.cmake)
	SET(SOURCE_FILES_PLATFORM
			${SOURCE_FILES_PLATFORM_JNI}
			)
ELSEIF(MAC_IOS)
	SET(SOURCE_FILES_PLATFORM
			proj/ios/src/main.m
			proj/ios/src/AppDelegate.mm proj/ios/src/AppDelegate.h
			proj/ios/src/MainScreenController.mm proj/ios/src/MainScreenController.h
			proj/ios/src/Adapter.mm proj/ios/src/Adapter.h
			)

	SET(CMAKE_OSX_SYSROOT iphoneos2.2.1)
	SET(CMAKE_OSX_ARCHITECTURES $(ARCHS_STANDARD_32_BIT))
	SET(CMAKE_CXX_FLAGS "-x objective-c++")
	SET(CMAKE_EXE_LINKER_FLAGS
			"-framework UIKit"
			)
	LINK_DIRECTORIES(\${HOME}/\${SDKROOT}/lib)

	SET(MACOSX_BUNDLE_GUI_IDENTIFIER "com.mycompany.\${PRODUCT_NAME:identifier}")
ELSE()
	MESSAGE(FATAL_ERROR "Set build platform, CMake will exit!  \"" ${CMAKE_SYSTEM_NAME} "\"")
ENDIF(LINUX)

SET(CROSS_MOBILE_DIR native/libraries/CrossMobile)
SET(NATIVE_DIR native/src)
SET(NATIVE_TEST_DIR native/test)

# Set core files
SET(SOURCE_FILES_CORE
		${NATIVE_DIR}/Adapter.cpp ${NATIVE_DIR}/Adapter.h
		${NATIVE_DIR}/AppMain.cpp ${NATIVE_DIR}/AppMain.h
		${NATIVE_DIR}/BuildConfig.h
		${NATIVE_DIR}/SampleApplication.cpp ${NATIVE_DIR}/SampleApplication.h
		${NATIVE_DIR}/screen/AppScreenCreator.cpp ${NATIVE_DIR}/screen/AppScreenCreator.h
		${NATIVE_DIR}/screen/MainScreen.cpp ${NATIVE_DIR}/screen/MainScreen.h
		)

SET(TEST_SOURCE_FILES
		${CROSS_MOBILE_DIR}/test/ComponentTest.cpp
		${CROSS_MOBILE_DIR}/test/PreferencesTest.cpp
		${CROSS_MOBILE_DIR}/test/ProviderTest.cpp
		${CROSS_MOBILE_DIR}/test/ScreenStateTest.cpp
		${CROSS_MOBILE_DIR}/test/TestExtractingTags.cpp
		${NATIVE_TEST_DIR}/TestRunner.cpp ${NATIVE_TEST_DIR}/TestRunner.h
		)

INCLUDE_DIRECTORIES(
		${NATIVE_DIR}/
		${NATIVE_TEST_DIR}/
		${CROSS_MOBILE_DIR}/libs/googletest/include
)

ADD_SUBDIRECTORY(${CROSS_MOBILE_DIR})
ADD_SUBDIRECTORY(${CROSS_MOBILE_DIR}/libs/googletest/)

IF(LINUX)
	ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_FILES_CORE} ${SOURCE_FILES_PLATFORM} ${TEST_SOURCE_FILES})
ELSEIF(ANDROID)
	ADD_LIBRARY(${PROJECT_NAME} SHARED ${SOURCE_FILES_CORE} ${SOURCE_FILES_PLATFORM} ${TEST_SOURCE_FILES})
ELSEIF(MAC_IOS)
	ADD_EXECUTABLE(sampleApp
			MACOSX_BUNDLE
			${SOURCE_FILES_CORE} ${SOURCE_FILES_PLATFORM} ${TEST_SOURCE_FILES}
			)
ENDIF(LINUX)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} CrossMobile)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} gtest)

IF(ANDROID)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} log android)
ELSEIF(MAC_IOS)
	# code signing
	SET_TARGET_PROPERTIES(${NAME} PROPERTIES XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY "iPhone Developer: My Name")
ENDIF(ANDROID)
