#include "../Ghost/Core/Ghost.h"
#include "GameObjects/SortedObject.h"
#include "GameObjects/Sorter.h"
#include "GameObjects/Platform.h"
#include "GameObjects/Player.h"

using namespace Ghost;

void Sort();
void FlappyBird();

int main(int argc, char* argv[])
{
	Sort();
	return 0;
}

void FlappyBird()
{
	Applictation* app = new Ghost::Applictation();
	std::shared_ptr<Texture> texture = std::make_shared<Texture>(*app->LoadTexture("../Assets/Background.jpg", { 0,0 }));
	std::shared_ptr<GameObject> background = std::make_shared<GameObject>();
	background->SetTexture(*texture);
	app->AddGameObject(background);

	Platform::m_EndPosition = { -1302, 982};
	Platform::m_StartPosition = { 2610, 982 };

	std::shared_ptr<Texture> platformTexture1 = std::make_shared<Texture>(*app->LoadTexture("../Assets/Ground.png", { 0,0 }));
	std::shared_ptr<GameObject> platform = std::make_shared<Platform>("Platform");
	platform->SetTexture(*platformTexture1);
	platform->SetPosition({ 0, 982 });
	platform->SetScale({ 2,1 });
	app->AddGameObject(platform);

	std::shared_ptr<Texture> platformTexture2 = std::make_shared<Texture>(*app->LoadTexture("../Assets/Ground.png", { 0,0 }));
	std::shared_ptr<GameObject> platform2 = std::make_shared<Platform>("Platform");
	platform2->SetTexture(*platformTexture2);
	platform2->SetScale({ 2,1 });
	platform2->SetPosition({ 1302, 982 });
	app->AddGameObject(platform2);

	std::shared_ptr<Texture> platformTexture3 = std::make_shared<Texture>(*app->LoadTexture("../Assets/Ground.png", { 0,0 }));
	std::shared_ptr<GameObject> platform3 = std::make_shared<Platform>("Platform");
	platform3->SetTexture(*platformTexture3);
	platform3->SetScale({ 2,1 });
	platform3->SetPosition({ 2604, 982 });
	app->AddGameObject(platform3);

	std::shared_ptr<Texture> playerTexture = std::make_shared<Texture>(*app->LoadTexture("../Assets/Bird.png", { 0,0 }));
	std::shared_ptr<GameObject> player = std::make_shared<Player>();
	std::shared_ptr<BoxCollider> playerCollider = std::make_shared<BoxCollider>(*playerTexture->GetDestinationRect());
	player->SetCollider(*playerCollider);
	player->SetTexture(*playerTexture);
	player->SetScale({ 0.2,0.2 });
	app->AddGameObject(player);

	std::shared_ptr<GameObject> ground = std::make_shared<GameObject>();
	SDL_Rect destRect = { 0, 982, 1920, 98 };
	std::shared_ptr<BoxCollider> groundCollider = std::make_shared<BoxCollider>(destRect);
	ground->SetPosition({(float)destRect.x,(float)destRect.y});
	ground->SetCollider(*groundCollider);

	app->ChangeFPS(60);
	app->Run();
}

void Sort() 
{
	Applictation* app = new Ghost::Applictation();
	std::shared_ptr<Texture> texture = std::make_shared<Texture>(*app->LoadTexture("../Assets/Test.png", { 0,0 }));

	std::shared_ptr<GameObject> background = std::make_shared<GameObject>();
	background->SetTexture(*texture);
	app->AddGameObject(background);
	std::shared_ptr<Sorter> sorter = std::make_shared<Sorter>();
	srand(time(0));
	int count = 240;
	for (int i = 0; i < count; i++)
	{
		int value = float(rand() % 1080);
		std::shared_ptr<SortedObject> sortedObject = std::make_shared<SortedObject>(value);
		std::shared_ptr<GameObject> pixelLine = sortedObject;
		Texture* line = app->LoadTexture("../Assets/Pixel.png", { 0,0 });
		sortedObject->SetTexture(*line);
		sortedObject->SetPosition({ (float)i * (1920 / count), 1080 - (float)value });
		sortedObject->SetScale({ float(1920 / count),(float)value });
		sorter->AddObject(sortedObject);
		app->AddGameObject(pixelLine);
	}
	app->ChangeFPS(0);
	std::shared_ptr<GameObject> sort = sorter;
	app->AddGameObject(sort);

	app->Run();
}