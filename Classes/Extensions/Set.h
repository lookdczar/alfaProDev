
#ifndef _SETL_H_
#define _SETL_H_

#include "cocos2d.h"
#include "Config.h"


namespace wgEx
{

	template <class T>
	class Set
	{
	private:

		cocos2d::Map<T, bool> _map;
	public:

		typedef typename cocos2d::Map<T, bool>::iterator iterator;
			
		iterator begin() { return _map.begin(); }
		iterator end() { return _map.end(); }

		Set<T>() : _map()
		{
		}

		~Set<T>()
		{
			clear();
		}

		void addElement(T element)
		{
			if (_map.at(element) == nullptr)
			{
				_map.insert(element, true);
			}
			else _map.at(element) = true;
		}

		void removeElement(T element)
		{
			_map.at(element) = nullptr;
		}

		bool containsElement(T element)
		{
			return _map.at(element) != nullptr;
		}

		cocos2d::Vector& allElements()
		{
			return cocos2d::Vector();
		}

		int count()
		{
			return 0;
		}

		Set<T>& unionSet(Set<T> otherSet);

		void clear()
		{
			for (auto iter = _map.cbegin(); iter != _map.cend(); ++iter)
			{
				iter->first->release();
			}

			_map.clear();
		}

	};
}
#endif