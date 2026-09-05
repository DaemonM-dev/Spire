#include "../transitions/fade_in.hpp"

void FadeIn::play(const float& dt) {
	if (active) {
		alpha -= SPEED * dt;
		if (alpha <= 0.0f) {
			alpha = 0.0f;
			active = false;
		}
		else {
			color.a = static_cast<unsigned char>(alpha);
		}
	}
}

void FadeIn::draw() {
	DrawRectangle(POS.x, POS.y, SIZE.x, SIZE.y, color);
}
bool FadeIn::isActive() const {
	return active;
}