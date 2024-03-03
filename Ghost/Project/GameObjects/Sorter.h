#pragma once
#include "SortedObject.h"

class Sorter : public Ghost::GameObject
{
private:
	static std::vector<std::shared_ptr<SortedObject>> s_TemporaryArray;
public:
	std::vector<std::shared_ptr<SortedObject>> m_Objects;
public:
	void Update() override;
	void Start() override;
	void BubbleSort();
	void BubbleSort2();
	void AddObject(std::shared_ptr<SortedObject>& sortObject);
};

