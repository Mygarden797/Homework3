#pragma once
#include <string>

class Item {
public:
	Item(const std::string& name, int price)
	{
		Item::name_ = name;
		Item::price_ = price;
	}
	void PrintInfo() const
	{
		std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << '\n';
	}
private:
	std::string name_;
	int price_;

};
