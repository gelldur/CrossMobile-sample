package com.cross.mobile.sample;

import android.app.Activity;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.cross.mobile.NativeObject;
import com.cross.mobile.help.NativeList;

/**
 * Created by Dawid Drozd aka Gelldur on 8/10/16.
 */

public class Adapter extends RecyclerView.Adapter<ListItemHolder> {

	public Adapter(Activity activity, NativeObject nativeObject) {
		_nativeList = new NativeList(nativeObject);
		_layoutInflater = activity.getLayoutInflater();
	}

	@Override
	public ListItemHolder onCreateViewHolder(final ViewGroup parent, final int viewType) {
		final View view = _layoutInflater.inflate(R.layout.row, parent, false);
		return new ListItemHolder(view);
	}

	@Override
	public void onBindViewHolder(final ListItemHolder holder, final int position) {
		_nativeList.setRow(position, holder.getNodect());
	}

	@Override
	public int getItemCount() {
		return _nativeList.getSize();
	}

	private NativeList _nativeList;
	private LayoutInflater _layoutInflater;
}
