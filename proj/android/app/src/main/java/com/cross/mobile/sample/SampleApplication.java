package com.cross.mobile.sample;

import android.app.Application;

import com.cross.mobile.CrossMobileApplication;

/**
 * Created by Dawid Drozd aka Gelldur on 8/8/16.
 */
public class SampleApplication extends Application {

	static {
		System.loadLibrary("CrossMobiled");
		System.loadLibrary("sampleAppd");
	}

	@Override
	public void onCreate() {
		super.onCreate();
		_crossApp.onCreate();
	}

	private CrossMobileApplication _crossApp = new CrossMobileApplication();
}
