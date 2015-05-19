
#ifndef _ARRAY2D_H_
#define _ARRAY2D_H_

#include "cocos2d.h"
#include "Config.h"


namespace wgEx
{

	template <class T>
	class Array2D
	{
	private:
		int _columns;
		int _rows;
		//cocos2d::Vector<T> _data;
		T* _data;
	public:
		Array2D<T>(int rows, int columns) : _columns(columns), _rows(rows)
		{
			int arraySize = sizeof(T )* _columns * _rows;
			_data = (T *)malloc(arraySize);
			memset((void*)_data, 0, arraySize);
		}

		~Array2D<T>()
		{
			if (_data) {
				free(_data);
			}
		}

		void clear()
		{
			int arraySize = sizeof(T *)* _columns * _rows;
			memset((void*)_data, 0, arraySize);
		}

		T at(int row, int column) const
		{
			if (row > _rows - 1 || column > _columns - 1) return nullptr;
			int index = column*row + column;
			
			return _data[index];
		}

		bool insert(int row, int column, T obj)
		{
			if (row > _rows - 1 || column > _columns - 1) return false;
			int index = column*row + column;
			_data[index] = obj;
		}
	
		bool swap(int rowA, int colA, int rowB, int colB)
		{
			if (rowA > _rows - 1 || colA > _columns - 1) return false;
			if (rowB > _rows - 1 || colB > _columns - 1) return false;
			int indexA = colA*rowA + colA;
			int indexB = colB*rowB + colB;
			T* temp= _data[indexA];
			_data[indexA] = _data[indexB];
			_data[indexB] = temp;
		}
		/*void swap(T* objA, T* objB)
		{
			_data.swap(objA, objB);
		}*/

		void erase(int col, int row)
		{
			int index = col*row + col;
			_data[index] = NULL;
		}

		T *const  operator[](int k)
		{
			//T t = _data.at(k * _columns);
			return &_data[k * _columns];
		}

	};
}
#endif