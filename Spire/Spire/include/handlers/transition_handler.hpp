#ifndef TRANSITION_HANDLER_HPP
#define TRANSITION_HANDLER_HPP
#include "../globals/globals.hpp"
#include "../transitions/transition.hpp"
#include "../transitions/fade_in.hpp"
#include "../transitions/fade_out.hpp"
class TransitionHandler
{
public:

	bool active = false;

	void fadeIn(const Vector2ui& size, const Vector2ui& pos, const float& duration);
	void fadeOut(const Vector2ui& size, const Vector2ui& pos, const float& duration);
	void updateTransitions(const float& dt);
	void drawTransitions();
private:

	std::unique_ptr<Transition> activeTransition{ nullptr };
};
#endif