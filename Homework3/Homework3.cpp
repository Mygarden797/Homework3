// Homework3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include "Inventory.h"

int main()
{
	Inventory<Item> *MyInventory = new Inventory<Item>();

	for (int i = 0; i < 12; i++)
	{
		MyInventory->AddItem(Item("Item" + std::to_string(i), (12-i) * 100));
	}

	MyInventory->PrintAllItems();
	MyInventory->RemoveLastItem();
	MyInventory->PrintAllItems();
	  
	MyInventory->SortItems();
	MyInventory->PrintAllItems();
	delete MyInventory;


}
