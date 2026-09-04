#include "../handlers/transition_handler.hpp"

void TransitionHandler::fadeIn(const Vector2ui& size, const Vector2ui& pos, const float& duration)
{
	if (!activeTransition) {
		activeTransition = std::make_unique<FadeIn>(size, pos, duration);
		active = true;
	}
}

void TransitionHandler::fadeOut(const Vector2ui& size, const Vector2ui& pos, const float& duration)
{
	if (!activeTransition) {
		activeTransition = std::make_unique<FadeOut>(size, pos, duration);
		active = true;
	}
}

void TransitionHandler::updateTransitions(const float& dt)
{
	if (activeTransition) {
		activeTransition->play(dt);
		if (!activeTransition->isActive()) {
			activeTransition.reset();
			active = false;
		}
	}
}

void TransitionHandler::drawTransitions()
{
	if (activeTransition) {
		activeTransition->draw();
	}
}
