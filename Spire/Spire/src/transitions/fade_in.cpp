#include "../transitions/fade_in.hpp"

void FadeIn::play(const float& dt) {
	if (active && color.a > 0) {
		color.a -= SPEED * dt;
		if (color.a < 0) { color.a = 0; }
		std::cout << "Transparency: " << color.a << "\n";
	}
	else {
		active = false;
	}
}
void FadeIn::draw() {
	DrawRectangle(POS.x, POS.y, SIZE.x, SIZE.y, color);
}
bool FadeIn::isActive() const {
	return active;
}