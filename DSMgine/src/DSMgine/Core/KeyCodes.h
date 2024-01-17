#pragma once

#include <cstdint>

namespace DSMgine
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		/* Keyboard */
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65, /* A */
		B = 66, /* B */
		C = 67, /* C */
		D = 68, /* D */
		E = 69, /* E */
		F = 70, /* F */
		G = 71, /* G */
		H = 72, /* H */
		I = 73, /* I */
		J = 74, /* J */
		K = 75, /* K */
		L = 76, /* L */
		M = 77, /* M */
		N = 78, /* N */
		O = 79, /* O */
		P = 80, /* P */
		Q = 81, /* Q */
		R = 82, /* R */
		S = 83, /* S */
		T = 84, /* T */
		U = 85, /* U */
		V = 86, /* V */
		W = 87, /* W */
		X = 88, /* X */
		Y = 89, /* Y */
		Z = 90, /* Z */

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320, /* 0 */
		KP1 = 321, /* 1 */
		KP2 = 322, /* 2 */
		KP3 = 323, /* 3 */
		KP4 = 324, /* 4 */
		KP5 = 325, /* 5 */
		KP6 = 326, /* 6 */
		KP7 = 327, /* 7 */
		KP8 = 328, /* 8 */
		KP9 = 329, /* 9 */
		KPDecimal = 330, /* . */
		KPDivide = 331, /* / */
		KPMultiply = 332, /* * */
		KPSubtract = 333, /* - */
		KPAdd = 334, /* + */
		KPEnter = 335,
		KPEqual = 336, /* = */

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	typedef enum class MouseButton : uint16_t
	{
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Left = Button0,
		Right = Button1,
		Middle = Button2
	} Button;
}

/* Keyboard */
#define DSMGINE_KEY_SPACE           ::DSMgine::Key::Space
#define DSMGINE_KEY_APOSTROPHE      ::DSMgine::Key::Apostrophe    /* ' */
#define DSMGINE_KEY_COMMA           ::DSMgine::Key::Comma         /* , */
#define DSMGINE_KEY_MINUS           ::DSMgine::Key::Minus         /* - */
#define DSMGINE_KEY_PERIOD          ::DSMgine::Key::Period        /* . */
#define DSMGINE_KEY_SLASH           ::DSMgine::Key::Slash         /* / */
#define DSMGINE_KEY_0               ::DSMgine::Key::D0
#define DSMGINE_KEY_1               ::DSMgine::Key::D1
#define DSMGINE_KEY_2               ::DSMgine::Key::D2
#define DSMGINE_KEY_3               ::DSMgine::Key::D3
#define DSMGINE_KEY_4               ::DSMgine::Key::D4
#define DSMGINE_KEY_5               ::DSMgine::Key::D5
#define DSMGINE_KEY_6               ::DSMgine::Key::D6
#define DSMGINE_KEY_7               ::DSMgine::Key::D7
#define DSMGINE_KEY_8               ::DSMgine::Key::D8
#define DSMGINE_KEY_9               ::DSMgine::Key::D9
#define DSMGINE_KEY_SEMICOLON       ::DSMgine::Key::Semicolon     /* ; */
#define DSMGINE_KEY_EQUAL           ::DSMgine::Key::Equal         /* = */
#define DSMGINE_KEY_A               ::DSMgine::Key::A
#define DSMGINE_KEY_B               ::DSMgine::Key::B
#define DSMGINE_KEY_C               ::DSMgine::Key::C
#define DSMGINE_KEY_D               ::DSMgine::Key::D
#define DSMGINE_KEY_E               ::DSMgine::Key::E
#define DSMGINE_KEY_F               ::DSMgine::Key::F
#define DSMGINE_KEY_G               ::DSMgine::Key::G
#define DSMGINE_KEY_H               ::DSMgine::Key::H
#define DSMGINE_KEY_I               ::DSMgine::Key::I
#define DSMGINE_KEY_J               ::DSMgine::Key::J
#define DSMGINE_KEY_K               ::DSMgine::Key::K
#define DSMGINE_KEY_L               ::DSMgine::Key::L
#define DSMGINE_KEY_M               ::DSMgine::Key::M
#define DSMGINE_KEY_N               ::DSMgine::Key::N
#define DSMGINE_KEY_O               ::DSMgine::Key::O
#define DSMGINE_KEY_P               ::DSMgine::Key::P
#define DSMGINE_KEY_Q               ::DSMgine::Key::Q
#define DSMGINE_KEY_R               ::DSMgine::Key::R
#define DSMGINE_KEY_S               ::DSMgine::Key::S
#define DSMGINE_KEY_T               ::DSMgine::Key::T
#define DSMGINE_KEY_U               ::DSMgine::Key::U
#define DSMGINE_KEY_V               ::DSMgine::Key::V
#define DSMGINE_KEY_W               ::DSMgine::Key::W
#define DSMGINE_KEY_X               ::DSMgine::Key::X
#define DSMGINE_KEY_Y               ::DSMgine::Key::Y
#define DSMGINE_KEY_Z               ::DSMgine::Key::Z
#define DSMGINE_KEY_LEFT_BRACKET    ::DSMgine::Key::LeftBracket   /* [ */
#define DSMGINE_KEY_BACKSLASH       ::DSMgine::Key::Backslash     /* \ */
#define DSMGINE_KEY_RIGHT_BRACKET   ::DSMgine::Key::RightBracket  /* ] */
#define DSMGINE_KEY_GRAVE_ACCENT    ::DSMgine::Key::GraveAccent   /* ` */
#define DSMGINE_KEY_WORLD_1         ::DSMgine::Key::World1        /* non-US #1 */
#define DSMGINE_KEY_WORLD_2         ::DSMgine::Key::World2        /* non-US #2 */

/* Function keys */
#define DSMGINE_KEY_ESCAPE          ::DSMgine::Key::Escape
#define DSMGINE_KEY_ENTER           ::DSMgine::Key::Enter
#define DSMGINE_KEY_TAB             ::DSMgine::Key::Tab
#define DSMGINE_KEY_BACKSPACE       ::DSMgine::Key::Backspace
#define DSMGINE_KEY_INSERT          ::DSMgine::Key::Insert
#define DSMGINE_KEY_DELETE          ::DSMgine::Key::Delete
#define DSMGINE_KEY_RIGHT           ::DSMgine::Key::Right
#define DSMGINE_KEY_LEFT            ::DSMgine::Key::Left
#define DSMGINE_KEY_DOWN            ::DSMgine::Key::Down
#define DSMGINE_KEY_UP              ::DSMgine::Key::Up
#define DSMGINE_KEY_PAGE_UP         ::DSMgine::Key::PageUp
#define DSMGINE_KEY_PAGE_DOWN       ::DSMgine::Key::PageDown
#define DSMGINE_KEY_HOME            ::DSMgine::Key::Home
#define DSMGINE_KEY_END             ::DSMgine::Key::End
#define DSMGINE_KEY_CAPS_LOCK       ::DSMgine::Key::CapsLock
#define DSMGINE_KEY_SCROLL_LOCK     ::DSMgine::Key::ScrollLock
#define DSMGINE_KEY_NUM_LOCK        ::DSMgine::Key::NumLock
#define DSMGINE_KEY_PRINT_SCREEN    ::DSMgine::Key::PrintScreen
#define DSMGINE_KEY_PAUSE           ::DSMgine::Key::Pause
#define DSMGINE_KEY_F1              ::DSMgine::Key::F1
#define DSMGINE_KEY_F2              ::DSMgine::Key::F2
#define DSMGINE_KEY_F3              ::DSMgine::Key::F3
#define DSMGINE_KEY_F4              ::DSMgine::Key::F4
#define DSMGINE_KEY_F5              ::DSMgine::Key::F5
#define DSMGINE_KEY_F6              ::DSMgine::Key::F6
#define DSMGINE_KEY_F7              ::DSMgine::Key::F7
#define DSMGINE_KEY_F8              ::DSMgine::Key::F8
#define DSMGINE_KEY_F9              ::DSMgine::Key::F9
#define DSMGINE_KEY_F10             ::DSMgine::Key::F10
#define DSMGINE_KEY_F11             ::DSMgine::Key::F11
#define DSMGINE_KEY_F12             ::DSMgine::Key::F12
#define DSMGINE_KEY_F13             ::DSMgine::Key::F13
#define DSMGINE_KEY_F14             ::DSMgine::Key::F14
#define DSMGINE_KEY_F15             ::DSMgine::Key::F15
#define DSMGINE_KEY_F16             ::DSMgine::Key::F16
#define DSMGINE_KEY_F17             ::DSMgine::Key::F17
#define DSMGINE_KEY_F18             ::DSMgine::Key::F18
#define DSMGINE_KEY_F19             ::DSMgine::Key::F19
#define DSMGINE_KEY_F20             ::DSMgine::Key::F20
#define DSMGINE_KEY_F21             ::DSMgine::Key::F21
#define DSMGINE_KEY_F22             ::DSMgine::Key::F22
#define DSMGINE_KEY_F23             ::DSMgine::Key::F23
#define DSMGINE_KEY_F24             ::DSMgine::Key::F24
#define DSMGINE_KEY_F25             ::DSMgine::Key::F25

/* Keypad */
#define DSMGINE_KEY_KP_0            ::DSMgine::Key::KP0
#define DSMGINE_KEY_KP_1            ::DSMgine::Key::KP1
#define DSMGINE_KEY_KP_2            ::DSMgine::Key::KP2
#define DSMGINE_KEY_KP_3            ::DSMgine::Key::KP3
#define DSMGINE_KEY_KP_4            ::DSMgine::Key::KP4
#define DSMGINE_KEY_KP_5            ::DSMgine::Key::KP5
#define DSMGINE_KEY_KP_6            ::DSMgine::Key::KP6
#define DSMGINE_KEY_KP_7            ::DSMgine::Key::KP7
#define DSMGINE_KEY_KP_8            ::DSMgine::Key::KP8
#define DSMGINE_KEY_KP_9            ::DSMgine::Key::KP9
#define DSMGINE_KEY_KP_DECIMAL      ::DSMgine::Key::KPDecimal
#define DSMGINE_KEY_KP_DIVIDE       ::DSMgine::Key::KPDivide
#define DSMGINE_KEY_KP_MULTIPLY     ::DSMgine::Key::KPMultiply
#define DSMGINE_KEY_KP_SUBTRACT     ::DSMgine::Key::KPSubtract
#define DSMGINE_KEY_KP_ADD          ::DSMgine::Key::KPAdd
#define DSMGINE_KEY_KP_ENTER        ::DSMgine::Key::KPEnter
#define DSMGINE_KEY_KP_EQUAL        ::DSMgine::Key::KPEqual

#define DSMGINE_KEY_LEFT_SHIFT      ::DSMgine::Key::LeftShift
#define DSMGINE_KEY_LEFT_CONTROL    ::DSMgine::Key::LeftControl
#define DSMGINE_KEY_LEFT_ALT        ::DSMgine::Key::LeftAlt
#define DSMGINE_KEY_LEFT_SUPER      ::DSMgine::Key::LeftSuper
#define DSMGINE_KEY_RIGHT_SHIFT     ::DSMgine::Key::RightShift
#define DSMGINE_KEY_RIGHT_CONTROL   ::DSMgine::Key::RightControl
#define DSMGINE_KEY_RIGHT_ALT       ::DSMgine::Key::RightAlt
#define DSMGINE_KEY_RIGHT_SUPER     ::DSMgine::Key::RightSuper
#define DSMGINE_KEY_MENU            ::DSMgine::Key::Menu

/* Mouse */
#define DSMGINE_MOUSE_BUTTON_LEFT    ::DSMgine::Button::Left
#define DSMGINE_MOUSE_BUTTON_RIGHT   ::DSMgine::Button::Right
#define DSMGINE_MOUSE_BUTTON_MIDDLE  ::DSMgine::Button::Middle