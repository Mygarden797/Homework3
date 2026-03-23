#pragma once
#include <algorithm>

class Item {
public:
	Item() : name_(""), price_(0) {} //Inventory에서 new T를 통해서 생성될 때 필요한 함수
	//만약 메모리만 필요한 방식으로 설계할 경우 필요 없을 것이다.
	Item(const std::string& name, int price);
	void PrintInfo() const;
	int getPrice() const;
private:
	std::string name_;
	int price_;

};

template <typename T>
class Inventory {
public:
	Inventory(int capacity = 10);
	Inventory(const Inventory<T>& other);
	~Inventory();
	void AddItem(const T& item);
	int GetSize() const;
	int GetCapacity() const;
	void PrintAllItems() const;
	void RemoveLastItem();
	void Assign(const Inventory<T>& other);
	void Resize();
	void SortItems();

	
	protected:
	private:
		T* pItem_;
		int capacity_;
		int size_;
		void Allocate(int newCapacity);
};


//비교함수
bool compareItemsByPrice(const Item& a, const Item& b)
{
	return a.getPrice() < b.getPrice();
}


//Item 정의
Item::Item(const std::string& name, int price)
{
	Item::name_ = name;
	Item::price_ = price;
}

void Item::PrintInfo() const
{
	std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << '\n';
}

int Item::getPrice() const
{
	return price_;
}


//인벤토리 정의
template <typename T>
Inventory<T>::Inventory(int capacity)
{
	if (capacity <= 0)
	{
		capacity_ = 1;
	}
	else
	{
		capacity_ = capacity;
	}
	pItem_ = new T[capacity_];
	size_ = 0;



}

template<typename T>
inline Inventory<T>::Inventory(const Inventory<T>& other)
{
	capacity_ = other.GetCapacity();
	size_ = other.GetSize();
	pItem_ = new T[capacity_];

	for (int i = 0; i < size_; i++)
	{
		pItem_[i] = other.pItem_[i];
	}
	


}

template <typename T>
Inventory<T>::~Inventory()
{
	delete[] pItem_;
	pItem_ = nullptr;
}

template<typename T>
void Inventory<T>::AddItem(const T& item)
{
	if (size_ < capacity_)
	{
		pItem_[size_] = item;
		size_++;

	}
	else
	{
		Resize();
		pItem_[size_] = item;
		size_++;
		//std::cout << "인벤토리가 꽉 찼습니다.\n";
	}
}

template <typename T>
void Inventory<T>::RemoveLastItem()
{
	if (size_ <= 0)
	{
		std::cout << "인벤토리가 비었습니다.\n";
	}
	else
	{
		size_--;
	}
}

template<typename T>
inline void Inventory<T>::Assign(const Inventory<T>& other)
{


	Allocate(other.GetCapacity());
	size_ = other.GetSize();

	for (int i = 0; i < size_; i++)
	{
		pItem_[i] = other.pItem_[i];
	}
}

template<typename T>
inline void Inventory<T>::Resize()
{
	
	T* temp = new T[size_];
	for (int i = 0; i < size_; i++)
	{
		temp[i] = pItem_[i];
	}

	Allocate(2 * capacity_);

	for (int i = 0; i < size_; i++)
	{
		pItem_[i] = temp[i];
	}

	delete[] temp;
	temp = nullptr;


}

template<typename T>
inline void Inventory<T>::SortItems()
{
	std::sort(pItem_, pItem_ + size_, compareItemsByPrice);

}



template<typename T>
inline void Inventory<T>::Allocate(int newCapacity)
{
	delete[] pItem_;

	capacity_ = newCapacity;
	pItem_ = new T[capacity_];
}

template <typename T>
int Inventory<T>::GetSize() const
{
	return size_;
}

template <typename T>
int Inventory<T>::GetCapacity() const
{
	return capacity_;
}

template <typename T>
void Inventory<T>::PrintAllItems() const
{
	for (int i = 0; i < size_; i++)
	{
		pItem_[i].PrintInfo();
	}
}