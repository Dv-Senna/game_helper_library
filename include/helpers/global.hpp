#pragma once

#include <vector>

#include "helpers/instance.hpp"
#include "helpers/window.hpp"



namespace gm {
	class Global {
		friend class gm::Instance;
		friend class gm::Window;

		public:
			static gm::Instance &getInstance();
			static gm::Window &getWindow();
			static const std::vector<gm::Window*> &getAllWindows();

		protected:
			static void setInstance(gm::Instance *instance);
			static void addWindow(gm::Window *window);

		private:
			static gm::Instance *s_instance;
			static std::vector<gm::Window*> s_windows;
	};

} // namespace gm
