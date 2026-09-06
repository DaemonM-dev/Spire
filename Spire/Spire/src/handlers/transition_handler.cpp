#include "../../include/handlers/transition_handler.hpp"

void TransitionHandler::start(const TransitionType& type, const Vector2ui& size, const Vector2ui& pos, const float& duration)
{
	if (!activeTransition && type != NONE) {
		switch (type) {
		case FADE_IN:
			activeTransition = std::make_unique<FadeIn>(size, pos, duration);
			break;
		case FADE_OUT:
			activeTransition = std::make_unique<FadeOut>(size, pos, duration);
			break;
		}
	}
}

void TransitionHandler::handle(const float& dt) {
	if (activeTransition) {
		activeTransition->play(dt);
		if (!activeTransition->isActive()) {
			activeTransition.reset();
			transitionComplete = true;
		}
	}
}

void TransitionHandler::draw() const
{
	if (activeTransition) {
		activeTransition->draw();
	}
}

bool TransitionHandler::isComplete()
{
	if (!activeTransition && transitionComplete) { transitionComplete = false; return true; }
	return false;
}

bool TransitionHandler::isActive() const {
	return activeTransition != nullptr;
}
