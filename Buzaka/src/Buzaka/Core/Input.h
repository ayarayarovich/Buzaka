#pragma once

namespace Buzaka {

	class Input
	{
	public:
		[[nodiscard]] static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }
		[[nodiscard]] static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		[[nodiscard]] static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		[[nodiscard]] static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		[[nodiscard]] static float GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		[[nodiscard]] virtual bool IsKeyPressedImpl(int keycode) const = 0;
		[[nodiscard]] virtual bool IsMouseButtonPressedImpl(int button) const = 0;
		[[nodiscard]] virtual std::pair<float, float> GetMousePositionImpl() const = 0;
		[[nodiscard]] virtual float GetMouseXImpl() const = 0;
		[[nodiscard]] virtual float GetMouseYImpl() const = 0;
	private:
		static Input* s_Instance;
	};

}
