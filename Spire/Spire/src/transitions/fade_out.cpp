#include "../transitions/fade_out.hpp"

void FadeOut::play(const float& dt) {
	if (active) {
		alpha += SPEED * dt;
		if (alpha >= 255) {
			alpha = 255;
			active = false;
		}
		else {
			color.a = static_cast<unsigned char>(alpha);
		}
		std::cout << "Transparency: " << static_cast<int>(color.a) << "\n";
	}
}
void FadeOut::draw() {
	DrawRectangle(POS.x, POS.y, SIZE.x, SIZE.y, color);
}
bool FadeOut::isActive() const {
	return active;
}