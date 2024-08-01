#pragma once



namespace gm {
	template <typename T>
	struct Vec2 {
		union {
			T x;
			T u;
			T w;
		};

		union {
			T y;
			T v;
			T h;
		};
	};

	using Vec2i = Vec2<int>;
	using Vec2f = Vec2<float>;

} // namespace gm
