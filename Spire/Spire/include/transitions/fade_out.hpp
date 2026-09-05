#ifndef FADE_OUT_HPP
#define FADE_OUT_HPP
#include "../globals/globals.hpp"
#include "./transition.hpp"
class FadeOut : public Transition
{
public:
	FadeOut(const Vector2ui& size, const Vector2ui& pos, const float& duration) :
		SIZE(size), POS(pos), DURATION(duration), SPEED(255.0f / duration) {
	}
private:

	const Vector2ui SIZE;
	const Vector2ui POS;
	const float DURATION;
	const float SPEED;
	float alpha{ 0.0f };
	Color color{ 0 ,0 ,0 ,0  }; // Transparent
	bool active = true;

	void play(const float& dt) override;
	void draw() override;
	bool isActive() const override;
};
#endif