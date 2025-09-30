#include <iostream>//	전처리(포함) <iostream> 헤더파일을 포함
#include <string> //	문자열 처리를 도와주는 라이브러리
#include <list>	  //	연결리스트 : 더블링크 리스트
#include <vector> //	동적배열 : 벡터
using namespace std;

template <typename T>
class mtVector
{
private:
	T* arr;
	int capacity;
	int size;


public:
	myVector()
	{
		capacity = 2;
		size = 0;
		arr = new T[capacity];
	}

	~myVector()
	{
		delete[] arr;
	}

	class iterator
	{
		T* pos;
	public:
		iterator(T* newPos = 0)
		{
			this->pos = newPos;
		}

		int operator - (T* pos)
		{
			return this->pos - pos;
		}

		bool operator != (const iterator& it)
		{
			return pos != itr.pos;
		}
		bool operator == (const iterator& it)
		{
			return pos == itr.pos;
		}

		iterator& operator++()	//전위
		{
			pos++;
			return(*this)
		}

		const iterator operator++(int)
		{
			iterator result(*this);
			pos++;
			return result;
		}

		T operator*()
		{
			return *(pos);
		}
	};

	int Capacity() const
	{
		return capacity;
	}

	int Size() const
	{
		return size;
	}

	iterator Begin()
	{
		iterator itr(arr);
		return itr;
	}

	iterator End()
	{
		iterator itr(arr + size);
		return itr;
	}

	T& operator[](int index)
	{
		if (index >= 0 && index < size)
		{
			return arr[index];
		}
	}

	//	원소 추가 push_back 구현하기 위해 필요한 것
	
	//	사이즈 체크
	//	Y : capacity 증가 -> 메모리 할당
	//	N : size 위치에 데이터 추가 size 증가
	//	
	//	데이터 오른쪽으로 미루기
	//  데이터 왼쪽으로 당기기

	void Reserve(int newCapacity)
	{
		if (capacity >= newCapacity)
			return;
		T* tempArr = new[newCapacity];
		for (int i = 0; i < size; i++)
		{
			tempArr[i] = arr[i];
		}
		delete[] arr;

		arr = tempArr;
		capacity = newCapacity;
	}

	private:
		void ShiftRight(int index)
		{
			for (int i = size; i > index; i--) //	덮어쓰면 안되기 때문에 i=size로 뒤쪽부터 오른쪽으로 옮김
			{
				arr[i] = arr[i - 1];
			}
		}

		void ShiftLeft(int index)
		{
			for (; index < size; index++)
			{
				arr[index] = arr[index + 1];
			}
		}
	public:
		void Insert(iterator itr, T data)
		{
			int index = itr - arr;

			if (size == capacity)
			{
				Reserve(capacity * 2);
			}

			ShiftRight(index);
			arr[index] = data;
			size++;
		}

		void Push_Back(T data)
		{
			Insert(End(), data);
		}

		void Erase(iterator itr)
		{
			int index = itr - arr;
			ShiftLeft(index);
			size--;
		}

		void PopBack()
		{
			if (size > 0)
				size--;		// 단순히 사이즈를 줄이는 것 만으로도 기존 end 값은 가비지 데이터가 됌
		}
};

int main()
{}