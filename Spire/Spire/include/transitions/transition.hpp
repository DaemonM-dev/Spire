#ifndef TRANSITION_HPP
#define TRANSITION_HPP

enum TransitionType {
	NONE,
	FADE_IN,
	FADE_OUT
};

class Transition
{
public:
	virtual ~Transition() = default;
	virtual void play(const float& dt) = 0;
	virtual void draw() = 0;
	virtual bool isActive() const = 0;
};
#endif