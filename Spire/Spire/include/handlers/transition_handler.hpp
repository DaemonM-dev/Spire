#ifndef TRANSITION_HANDLER_HPP
#define TRANSITION_HANDLER_HPP

#include "../transitions/transition.hpp"
#include "../transitions/fade_in.hpp"
#include "../transitions/fade_out.hpp"

class TransitionHandler
{
public:
	bool skip = false;
	bool transitionComplete = false;

	bool isActive() const;

	std::unique_ptr<Transition> activeTransition{ nullptr };
	void start(const TransitionType& type, const Vector2ui& size, const Vector2ui& pos, const float& duration);
	void handle(const float& dt);
	void draw() const;
	bool isComplete();

};
#endif