#pragma once
# include <Siv3D.hpp>
class Mover {
private:
	Vec2 position;
	Vec2 velocity;
	Vec2 acceleration;
	double mass;
public:
	Mover() = default;
	Mover(const Vec2& position, const double& mass) : position(position), velocity(Vec2(0.0, 0.0)), acceleration(Vec2(0.0, 0.0)), mass(mass) {}


	void applyForce(const Vec2& force) {
		Vec2 calcForce = force / mass;
		acceleration += calcForce;
	}

	void update() {
		velocity += acceleration;
		position += velocity;
		acceleration *= 0.0;
	}

	void render() {
		double scale = 2.0;
		double size = mass * scale;
		const ColorF color = ColorF{ 1.0, 1.0, 1.0, 1.0 };
		Circle{ position, size }.draw(color);
	}

	void checkEdge(const Point& windowSize) {
		if (position.x < 0) {
			position.x = 0;
			velocity.x *= -1;
		}
		else if (position.x > windowSize.x) {
			position.x = windowSize.x;
			velocity.x *= -1;
		}

		if (position.y < 0) {
			position.y = 0;
			velocity.y *= -1;
		}
		else if (position.y > windowSize.y) {
			position.y = windowSize.y;
			velocity.y *= -1;
		}
	}
};
