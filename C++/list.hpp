#pragma once
namespace sr
{
	template <typename _Ty>
	struct List
	{
		_Ty value;
		List* next;
		List(List<_Ty>* next = nullptr) noexcept : next(next) {}
		List(_Ty&& value, List<_Ty>* next = nullptr) noexcept : value(value), next(next) {}
		List<_Ty>* push(List<_Ty>* cell) noexcept
		{
			if (this->next)
			{
				return insert(this, cell);
			}
			else
			{
				this->next = cell;
				return cell;
			}
		}

		List<_Ty>* push(_Ty&& value) noexcept
		{
			return push(new List<_Ty>(std::move(value)));
		}
	};

	template <typename _Ty>
	List<_Ty>* find(List<_Ty>* top, _Ty value) noexcept
	{
		if (top == nullptr) { return nullptr; }
		while (top->next)
		{
			if (top->next->value == value) { return top->next; }
			top = top->next;
		}
		return nullptr;
	}

	template <typename _Ty>
	List<_Ty>* find_before(List<_Ty>* top, _Ty value) noexcept
	{
		if (top == nullptr) { return nullptr; }
		while (top->next)
		{
			if (top->next->value == value) { return top; }
			top = top->next;
		}
		return nullptr;
	}

	//will set the top as nullptr
	template <typename _Ty>
	void dispose(List<_Ty>*& top) noexcept
	{
		if (!top) { return; }
		List<_Ty>* temp;
		while (top->next)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
		if (top) { delete top; }
		top = nullptr;
	}

	template <typename _Ty>
	List<_Ty>* push_before(List<_Ty>* top, List<_Ty>* cell) noexcept
	{
		if (!top || !cell) { return cell; }
		dispose(cell->next);
		cell->next = top->next;
		top->next = cell;
		return cell;
	}

	template <typename _Ty>
	List<_Ty>* push_back(List<_Ty>* top, List<_Ty>* cell) noexcept
	{
		if (!top || !cell) { return cell; }
		while (top->next) { top = top->next; }
		top->next = cell;
		return cell;
	}

	template <typename _Ty>
	List<_Ty>* push(List<_Ty>* after_me, List<_Ty>* cell) noexcept
	{
		if (!after_me || !cell) { return cell; }
		return after_me->push(cell);
	}

	template <typename _Ty>
	List<_Ty>* insert(List<_Ty>* after_me, List<_Ty>* cell) noexcept
	{
		if (!after_me || !cell) { return cell; }
		dispose(cell->next);
		cell->next = after_me->next;
		after_me->next = cell;
		return cell;
	}
#define _MAKEFUNC(fn) \
	template <typename _Ty>\
	List<_Ty>* fn(List<_Ty>* top, _Ty&& value) noexcept\
	{\
		return fn(top, new List<_Ty>(std::move(value)));\
	}

	_MAKEFUNC(push_before);
	_MAKEFUNC(push);
	_MAKEFUNC(push_back);
	_MAKEFUNC(insert);
#undef _MAKEFUNC

	template <typename _Ty>
	void remove(List<_Ty>* after_me) noexcept
	{
		if (!after_me || !after_me->next) { return; }
		List<_Ty>* target = after_me->next;
		after_me->next = target->next;
		delete target;
	}
}