package com.cross.mobile.sample;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.cross.mobile.component.Component;
import com.cross.mobile.component.NodectBuilder;

/**
 * Created by Dawid Drozd aka Gelldur on 8/10/16.
 */

public class ListItemHolder extends RecyclerView.ViewHolder {
	public ListItemHolder(final View itemView) {
		super(itemView);

		TextView textView = (TextView) itemView.findViewById(R.id.textView);
		ImageView imageView = (ImageView) itemView.findViewById(R.id.imageView);

		NodectBuilder textViewNodect = new NodectBuilder("text", textView).addComponent(Component.View.Text);
		NodectBuilder imageViewNodect = new NodectBuilder("image", imageView).addComponent(Component.View.Image);

		_nodect = new NodectBuilder("itemRow", itemView).nest(textViewNodect).nest(imageViewNodect);
	}

	public NodectBuilder getNodect() {
		return _nodect;
	}

	private NodectBuilder _nodect;
}
