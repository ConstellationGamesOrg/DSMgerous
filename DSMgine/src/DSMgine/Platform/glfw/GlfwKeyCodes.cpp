#include <DSMginePCH.h>

#include "GlfwKeyCodes.h"

#include <GLFW/glfw3.h>

#include <array>
#include <utility>

namespace DSMgine
{
	// TODO: This feels stupid, so it probably is.
	// Perhaps instead of this, `KeyCode` and `MouseButton` are declared in
	// `KeyCodes.h` while it is defined in `Platform/glfw/GlfwKeyCodes.cpp`?

	std::array<std::pair<KeyCode, int>, 120> KeyCodeTable = {
		/* Keyboard */
		std::pair(Key::Space, 32),
		std::pair(Key::Apostrophe, 39), /* ' */
		std::pair(Key::Comma, 44), /* , */
		std::pair(Key::Minus, 45), /* - */
		std::pair(Key::Period, 46), /* . */
		std::pair(Key::Slash, 47), /* / */

		std::pair(Key::D0, 48), /* 0 */
		std::pair(Key::D1, 49), /* 1 */
		std::pair(Key::D2, 50), /* 2 */
		std::pair(Key::D3, 51), /* 3 */
		std::pair(Key::D4, 52), /* 4 */
		std::pair(Key::D5, 53), /* 5 */
		std::pair(Key::D6, 54), /* 6 */
		std::pair(Key::D7, 55), /* 7 */
		std::pair(Key::D8, 56), /* 8 */
		std::pair(Key::D9, 57), /* 9 */

		std::pair(Key::Semicolon, 59), /* ; */
		std::pair(Key::Equal, 61), /* = */

		std::pair(Key::A, 65), /* A */
		std::pair(Key::B, 66), /* B */
		std::pair(Key::C, 67), /* C */
		std::pair(Key::D, 68), /* D */
		std::pair(Key::E, 69), /* E */
		std::pair(Key::F, 70), /* F */
		std::pair(Key::G, 71), /* G */
		std::pair(Key::H, 72), /* H */
		std::pair(Key::I, 73), /* I */
		std::pair(Key::J, 74), /* J */
		std::pair(Key::K, 75), /* K */
		std::pair(Key::L, 76), /* L */
		std::pair(Key::M, 77), /* M */
		std::pair(Key::N, 78), /* N */
		std::pair(Key::O, 79), /* O */
		std::pair(Key::P, 80), /* P */
		std::pair(Key::Q, 81), /* Q */
		std::pair(Key::R, 82), /* R */
		std::pair(Key::S, 83), /* S */
		std::pair(Key::T, 84), /* T */
		std::pair(Key::U, 85), /* U */
		std::pair(Key::V, 86), /* V */
		std::pair(Key::W, 87), /* W */
		std::pair(Key::X, 88), /* X */
		std::pair(Key::Y, 89), /* Y */
		std::pair(Key::Z, 90), /* Z */

		std::pair(Key::LeftBracket, 91),  /* [ */
		std::pair(Key::Backslash, 92),  /* \ */
		std::pair(Key::RightBracket, 93),  /* ] */
		std::pair(Key::GraveAccent, 96),  /* ` */

		std::pair(Key::World1, 161), /* non-US #1 */
		std::pair(Key::World2, 162), /* non-US #2 */

		/* Function keys */
		std::pair(Key::Escape, 256),
		std::pair(Key::Enter, 257),
		std::pair(Key::Tab, 258),
		std::pair(Key::Backspace, 259),
		std::pair(Key::Insert, 260),
		std::pair(Key::Delete, 261),
		std::pair(Key::Right, 262),
		std::pair(Key::Left, 263),
		std::pair(Key::Down, 264),
		std::pair(Key::Up, 265),
		std::pair(Key::PageUp, 266),
		std::pair(Key::PageDown, 267),
		std::pair(Key::Home, 268),
		std::pair(Key::End, 269),
		std::pair(Key::CapsLock, 280),
		std::pair(Key::ScrollLock, 281),
		std::pair(Key::NumLock, 282),
		std::pair(Key::PrintScreen, 283),
		std::pair(Key::Pause, 284),
		std::pair(Key::F1, 290),
		std::pair(Key::F2, 291),
		std::pair(Key::F3, 292),
		std::pair(Key::F4, 293),
		std::pair(Key::F5, 294),
		std::pair(Key::F6, 295),
		std::pair(Key::F7, 296),
		std::pair(Key::F8, 297),
		std::pair(Key::F9, 298),
		std::pair(Key::F10, 299),
		std::pair(Key::F11, 300),
		std::pair(Key::F12, 301),
		std::pair(Key::F13, 302),
		std::pair(Key::F14, 303),
		std::pair(Key::F15, 304),
		std::pair(Key::F16, 305),
		std::pair(Key::F17, 306),
		std::pair(Key::F18, 307),
		std::pair(Key::F19, 308),
		std::pair(Key::F20, 309),
		std::pair(Key::F21, 310),
		std::pair(Key::F22, 311),
		std::pair(Key::F23, 312),
		std::pair(Key::F24, 313),
		std::pair(Key::F25, 314),

		/* Keypad */
		std::pair(Key::KP0, 320), /* 0 */
		std::pair(Key::KP1, 321), /* 1 */
		std::pair(Key::KP2, 322), /* 2 */
		std::pair(Key::KP3, 323), /* 3 */
		std::pair(Key::KP4, 324), /* 4 */
		std::pair(Key::KP5, 325), /* 5 */
		std::pair(Key::KP6, 326), /* 6 */
		std::pair(Key::KP7, 327), /* 7 */
		std::pair(Key::KP8, 328), /* 8 */
		std::pair(Key::KP9, 329), /* 9 */
		std::pair(Key::KPDecimal, 330), /* . */
		std::pair(Key::KPDivide, 331), /* / */
		std::pair(Key::KPMultiply, 332), /* * */
		std::pair(Key::KPSubtract, 333), /* - */
		std::pair(Key::KPAdd, 334), /* + */
		std::pair(Key::KPEnter, 335),
		std::pair(Key::KPEqual, 336), /* = */

		std::pair(Key::LeftShift, 340),
		std::pair(Key::LeftControl, 341),
		std::pair(Key::LeftAlt, 342),
		std::pair(Key::LeftSuper, 343),
		std::pair(Key::RightShift, 344),
		std::pair(Key::RightControl, 345),
		std::pair(Key::RightAlt, 346),
		std::pair(Key::RightSuper, 347),
		std::pair(Key::Menu, 348)
	};

	std::array<std::pair<MouseButton, int>, 9> MouseButtonTable = {
		std::pair(MouseButton::Button0, 0),
		std::pair(MouseButton::Button1, 1),
		std::pair(MouseButton::Button2, 2),
		std::pair(MouseButton::Button3, 3),
		std::pair(MouseButton::Button4, 4),
		std::pair(MouseButton::Button5, 5),
		std::pair(MouseButton::Left, 0),
		std::pair(MouseButton::Right, 1),
		std::pair(MouseButton::Middle, 2)
	};

	int ToGlfwKeyCode(KeyCode keyCode)
	{
		for (auto x : KeyCodeTable)
		{
			if (x.first == keyCode)
				return x.second;
			// TODO: Error key?
		}
	}

	int ToGlfwMouseButton(MouseButton mouseButton)
	{
		for (auto x : MouseButtonTable)
		{
			if (x.first == mouseButton)
				return x.second;
			// TODO: Error key?
		}
	}

	KeyCode ToDSMgineKeyCode(int keyCode)
	{
		for (auto x : KeyCodeTable)
		{
			if (x.second == keyCode)
				return x.first;
			// TODO: Error key?
		}
	}

	MouseButton ToDSMgineMouseButton(int mouseButton)
	{
		for (auto x : MouseButtonTable)
		{
			if (x.second == mouseButton)
				return x.first;
			// TODO: Error key?
		}
	}
}