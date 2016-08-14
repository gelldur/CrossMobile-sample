//
// Created by Dawid Drozd aka Gelldur on 8/10/16.
//

#pragma once

#include <string>
#include <vector>
#include <component/Nodect.h>
#include <component/adapter/AdapterList.h>

class Adapter : public AdapterList
{
public:
	Adapter();

	virtual int getSize() override;
	virtual const std::string& getIdentifier(int index) override;
	virtual void setElement(int position, const Nodect& row) override;

private:
	struct Element
	{
		Element(int color, const std::string& image, const std::string& text)
				: color(color)
				, image(image)
				, text(text)
		{
		}

		int color;
		std::string image;
		std::string text;
	};

	std::vector<Element> _elements;
};


