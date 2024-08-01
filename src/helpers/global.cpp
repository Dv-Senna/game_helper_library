#include "helpers/global.hpp"



namespace gm {
	gm::Instance &Global::getInstance() {
		return *s_instance;
	}


	gm::Window &Global::getWindow() {
		return s_instance->getCurrentWindow();
	}


	const std::vector<gm::Window*> &Global::getAllWindows() {
		return s_windows;
	}


	void Global::setInstance(gm::Instance *instance) {
		s_instance = instance;
	}


	void Global::addWindow(gm::Window *window) {
		s_windows.push_back(window);
	}


	gm::Instance *Global::s_instance {};
	std::vector<gm::Window*> Global::s_windows {};

} // namespace gm
