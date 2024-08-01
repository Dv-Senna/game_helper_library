#pragma once

#include <functional>



namespace gm {
	class Instance {
		public:
			Instance(const std::function<void()> &construct = nullptr, const std::function<void()> destruct = nullptr);
			~Instance();

		private:
			std::function<void()> m_destruct;
	};

} // namespace gm
