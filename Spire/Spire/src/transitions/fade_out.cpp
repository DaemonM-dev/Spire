#include "../transitions/fade_out.hpp"

void FadeOut::play(const float& dt) {
	if (active && color.a < 255) {
		color.a += SPEED * dt;
		if (color.a > 255) { color.a = 255; }
		std::cout << "Transparency: " << color.a << "\n";
	}
	else {
		active = false;
	}
}
void FadeOut::draw() {
	DrawRectangle(POS.x, POS.y, SIZE.x, SIZE.y, color);
}
bool FadeOut::isActive() const {
	return active;
}