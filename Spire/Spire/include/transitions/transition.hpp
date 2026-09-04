#ifndef TRANSITION_HPP
#define TRANSITION_HPP
class Transition
{
public:
	virtual ~Transition() = default;
	virtual void play(const float& dt) = 0;
	virtual void draw() = 0;
	virtual bool isActive() const = 0;
};
#endif