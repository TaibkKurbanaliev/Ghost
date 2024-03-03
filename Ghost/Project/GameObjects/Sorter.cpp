#include "Sorter.h"
#include <thread>
#include <chrono>

std::vector<std::shared_ptr<SortedObject>> Sorter::s_TemporaryArray;

void Sorter::Update()
{
	BubbleSort2();
}

void Sorter::Start()
{
	/*std::thread th([&](){this->BubbleSort(); });
	th.detach();*/
}

void Sorter::BubbleSort2()
{
	static int numberOfIteration = 0;
	static int sortIteration = 0;

	if (numberOfIteration < m_Objects.size() - 1)
	{
		if (sortIteration < m_Objects.size() - 1)
		{
			if (m_Objects[sortIteration]->m_Value > m_Objects[sortIteration + 1]->m_Value)
			{
				auto temp = m_Objects[sortIteration+1];
				SDL_FPoint tempPos = m_Objects[sortIteration]->GetPosition();
				m_Objects[sortIteration]->SetPosition({ m_Objects[sortIteration + 1]->GetPosition().x ,m_Objects[sortIteration]->GetPosition().y});
				m_Objects[sortIteration + 1] = m_Objects[sortIteration];
				m_Objects[sortIteration] = temp;
				m_Objects[sortIteration]->SetPosition({ tempPos.x, m_Objects[sortIteration]->GetPosition().y });
			}

			sortIteration++;
		}
		else if (numberOfIteration < m_Objects.size() - 1)
		{
			sortIteration = 0;
			numberOfIteration++;
		}
	}	
}

void Sorter::BubbleSort()
{
	for (int i = 0; i < m_Objects.size() - 1; i++)
	{
		for (int j = 0; j < m_Objects.size() - 1; j++)
		{
			if (m_Objects[j]->m_Value > m_Objects[j + 1]->m_Value)
			{
				auto temp = m_Objects[j + 1];
				SDL_FPoint tempPos = m_Objects[j]->GetPosition();
				m_Objects[j]->SetPosition({ m_Objects[j + 1]->GetPosition().x ,m_Objects[j]->GetPosition().y });
				m_Objects[j + 1] = m_Objects[j];
				m_Objects[j] = temp;
				m_Objects[j]->SetPosition({ tempPos.x, m_Objects[j]->GetPosition().y });
			}

			std::this_thread::sleep_for(std::chrono::nanoseconds(201));
		}
	}
}

void Sorter::AddObject(std::shared_ptr<SortedObject>& sortObject)
{
	m_Objects.emplace_back(sortObject);
}
