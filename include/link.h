#pragma once
template <typename T>
class link
{
public:
	T Key = 0;
	link* pNext = nullptr;

	link(T value) : Key(value) {
	}
	link() = default;
};
