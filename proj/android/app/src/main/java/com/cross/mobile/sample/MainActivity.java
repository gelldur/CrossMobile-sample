package com.cross.mobile.sample;

import android.os.Bundle;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.widget.TextView;

import com.cross.mobile.component.Component;
import com.cross.mobile.component.NodectBuilder;
import com.cross.mobile.help.NativeScreen;

import static com.cross.mobile.sample.R.id.listView;

public class MainActivity extends NativeScreen {

	public MainActivity() {
		super("MainScreen");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		_textView = (TextView) findViewById(R.id.textView);
		_recyclerView = (RecyclerView) findViewById(listView);
		_recyclerView.setItemAnimator(new DefaultItemAnimator());
		_recyclerView.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL, false));

		NodectBuilder textViewNodect = new NodectBuilder("textView", _textView).addComponent(Component.View.Text);
		nestNodect(textViewNodect);

		NodectBuilder listViewNodect = new NodectBuilder("listView", _recyclerView).addComponent(Component.View.List);
		nestNodect(listViewNodect);

		_adapter = new Adapter(this, findNative("adapter"));
		_recyclerView.setAdapter(_adapter);
	}

	private TextView _textView;
	private Adapter _adapter;
	private RecyclerView _recyclerView;
}
