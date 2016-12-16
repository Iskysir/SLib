package slib.platform.android.device;

import slib.platform.android.Logger;
import android.app.Activity;
import android.content.Context;
import android.graphics.Point;
import android.os.Build;
import android.provider.Settings.Secure;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;

public class DeviceInformation {
	/*
		this class need permission "android.permission.VIBRATE"
	 */
	public static String getDeviceId(Activity context) {
		try {
			TelephonyManager telephonyManager = (TelephonyManager) context.getSystemService(Context.TELEPHONY_SERVICE);
			return telephonyManager.getDeviceId();
		} catch (Throwable e) {
			Logger.exception(e);
		}
		return null;
	}

	public static String getDeviceOSVersion() {
		return Build.VERSION.RELEASE;
	}

	public static String getDeviceName() {
		String manufacturer = Build.MANUFACTURER;
		String model = Build.MODEL;
		if (model.startsWith(manufacturer)) {
			return model;
		} else {
			return manufacturer + " " + model;
		}
	}

	public static Point getScreenSize(Activity context) {
		DisplayMetrics dm = new DisplayMetrics();
		context.getWindowManager().getDefaultDisplay().getMetrics(dm);
		Point ret = new Point(dm.widthPixels, dm.heightPixels);
		return ret;
	}

	public static int getDevicePPI(Activity context) {
		DisplayMetrics dm = new DisplayMetrics();
		context.getWindowManager().getDefaultDisplay().getMetrics(dm);
		return dm.densityDpi;
	}
}
