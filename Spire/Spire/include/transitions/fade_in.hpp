#ifndef FADE_IN_HPP
#define FADE_IN_HPP
#include "../globals/globals.hpp"
#include "./transition.hpp"
class FadeIn : public Transition
{
public:
	FadeIn(const Vector2ui& size, const Vector2ui& pos, const float& duration) :
		SIZE(size), POS(pos), DURATION(duration), SPEED(255.0f / duration) {
	}
private:

	const Vector2ui SIZE;
	const Vector2ui POS;
	const float DURATION;
	const float SPEED;
	Color color{ 0 ,0 ,0 , 255 }; // Black
	bool active = true;

	void play(const float& dt) override;
	void draw() override;
	bool isActive() const override;
};
#endif