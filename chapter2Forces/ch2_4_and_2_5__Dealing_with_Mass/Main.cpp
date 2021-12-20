#include <Siv3D.hpp> 
#include "Mover.hpp"

void Main()
{

	Scene::SetBackground(ColorF{ 0.0, 0.0, 0.0 });

	const int32 particleMAX = 10;
	const int32 width = Scene::Width();
	const int32 height = Scene::Height();
	const Point windowSize = Point(width, height);
	const Vec2 wind = Vec2(0.05, 0.0);
	const Vec2 gravity = Vec2(0.0, 0.1);
	

	std::vector<Mover> movers(particleMAX);
	for (int32 count = 0; count < particleMAX; count++) {
		const Vec2 position = Vec2(0, 0);
		const double mass = Random<double>(5.0, 20.0);
		Mover mover = Mover(position, mass);
		movers.push_back(mover);
	}

	std::cout << movers.size() << std::endl;

	while (System::Update())
	{
		for (int32 count = 0; count < movers.size(); count++) {
			movers[count].applyForce(wind);
			movers[count].applyForce(gravity);
			movers[count].update();
			movers[count].render();
			movers[count].checkEdge(windowSize);
		}
	}
}

