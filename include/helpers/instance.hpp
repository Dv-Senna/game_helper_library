#pragma once

#include <functional>
#include <stack>

#include "helpers/window.hpp"



namespace gm {
	class Instance {
		public:
			Instance(const std::function<void()> &construct = nullptr, const std::function<void()> destruct = nullptr);
			~Instance();

			void pushCurrentWindow(gm::Window &window);
			void popCurrentWindow();
			gm::Window &getCurrentWindow() const noexcept;

		private:
			std::function<void()> m_destruct;
			std::stack<gm::Window*> m_windowStack;
	};

} // namespace gm
