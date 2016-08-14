//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#include "Adapter.h"

#include <component/NodectHelper.h>
#include <component/view/Text.h>
#include <component/view/Image.h>

Adapter::Adapter()
{
	std::vector<std::string> icons = {"cat", "dog", "tiger"};
	std::vector<unsigned> colors = {0xff0000ff, 0xff00ff00, 0xffff0000, 0xff0C96C4, 0xffC43A0C, 0xffE9F502};
	for (int i = 0; i < 128; ++i)
	{
		_elements.emplace_back(colors[i % colors.size()]
							   , icons[i % icons.size()]
							   , std::string("Element at postion:") + std::to_string(i));
	}
}

int Adapter::getSize()
{
	return static_cast<int>(_elements.size());
}

const std::string& Adapter::getIdentifier(int index)
{
	static std::string id = "element";//In this sample we only support 1 type of row
	return id;
}

void Adapter::setElement(int position, const Nodect& row)
{
	auto& element = _elements.at(position);//using at for safety

	auto& text = NodectHelper::find(row, "text");
	text.getComponent<Text>().setText(element.text);
	text.getComponent<Text>().setTextColor(element.color);

	auto& image = NodectHelper::find(row, "image");
	image.getComponent<Image>().image(element.image);
}
