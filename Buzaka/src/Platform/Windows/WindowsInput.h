#pragma once

#include "pch/bzpch.h"
#include "Buzaka/Core/Input.h"

namespace Buzaka {

	class WindowsInput : public Input
	{
	protected:
		[[nodiscard]] virtual bool IsKeyPressedImpl(int keycode) const override;
		[[nodiscard]] virtual bool IsMouseButtonPressedImpl(int button) const override;
		[[nodiscard]] virtual std::pair<float, float> GetMousePositionImpl() const override;
		[[nodiscard]] virtual float GetMouseXImpl() const override;
		[[nodiscard]] virtual float GetMouseYImpl() const override;
	};

}
