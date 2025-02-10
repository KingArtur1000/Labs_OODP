#pragma once

#include <algorithm>
#include <vector>

#include "GiftItem.h"


using std::vector;
using std::cerr;
using std::sort;
using std::find_if;


class GiftStorage {
private:
	vector<GiftItem*> gifts;


protected:
	


public:
	void addGift(GiftItem* gift) {
		gifts.push_back(gift); // Добавление нового подарка в список
	}


	void removeGiftByIndex(unsigned int pos) {
		if (pos >= gifts.size()) {
			cerr << "Ошибка: некорректный индекс удаления!" << '\n';
			return;
		}

		delete gifts[pos]; // Освобождаем память, так как храним указатели
		gifts.erase(gifts.begin() + pos); // Удаляем указатель из вектора
	}


	void updateGiftInfo(unsigned int pos, string name, unsigned int quantity, double price, string extraContent) {
		gifts.at(pos)->updateInfo(name, quantity, price, extraContent);
	}


	void updateGiftQuantityByIndex(unsigned int pos, int quantity) {
		gifts.at(pos)->updateQuantity(quantity);
	}



	void showAllGiftItems() const {
		for (const auto& GiftItem : gifts) {
			GiftItem->getInformation(); // Вывод информации о каждом подарке
			cout << "-----------------\n";
		}
	}


	int getGiftsQuantity() {
		unsigned int temp = 0;

		for (auto gift : gifts) {
			temp += gift->getQuantity();
		}

		return temp;
	}


	void findGiftByName(const string& name) const {
		// Поиск подарка по имени
		auto it = find_if(gifts.begin(), gifts.end(), [&name](GiftItem* gift) {
			return gift->getName() == name;
		});

		if (it != gifts.end()) {
			cout << "\tПодарок найден:\n";
			(*it)->getInformation(); // Вывод найденного подарка
		}
		else {
			cout << "Подарок по названию: " << name << " не найден.\n\n";
		}
	}


	// Да-да впервые используем Лямбда-функцию (анонимную функцию), правда в С# объявление куда проще :) ()=> b и всё!
	void sortGiftsByName() {
		sort(begin(gifts), end(gifts), [](GiftItem* gift_1, GiftItem* gift_2) {
			return gift_1->getName() < gift_2->getName();
		});
	}


	~GiftStorage() {
		for (auto* giftItem : gifts) {
			delete giftItem;
		}
	}
};