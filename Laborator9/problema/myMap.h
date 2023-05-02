#include <iostream>
template <typename K, typename V>

class Map
{
	struct Element{
		K key;
		V value;
		int index;
	}*arr;

	int index;
	int dim;

	void Resize()
	{
		if (dim!=0)
		{
			Element* v=new Element[dim*2];
			memcpy(v, arr, sizeof(Element)*dim);
			arr=v;
			dim=dim*2;
			return;
		}
		arr=new Element[1];
		dim=1;
		index=0;
	}
public:
	Map()
	{
		arr=new Element[1];
		dim=1;
		index=0;
	}

	Element* begin() const { return &arr[0]; }
	Element* end() const { return &arr[this->index]; }

	V& operator[] (K key)
	{
		for(int i=0; i<index; i++)
		{
			if(key==arr[i].key)
				return arr[i].value;
		}
		arr[this->index].index=this->index;
		arr[this->index].key=key;
		this->index++;
		if(this->index==dim)
			Resize();
		return arr[this->index-1].value;
	}

	void Set(K k, V v)
	{
		for(int i=0; i<index; i++)
		{
			if(arr[i].key==k)
			{
				arr[i].value=v;
				dim++;
				return;
			}
		}
		printf("Cheia nu exista\n");
		return;
	}

	bool Get(const K& k, V& v)
	{
		for(int i=0; i<index; i++)
		{
			if(arr[i].key==k)
			{
				v=arr[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() const
	{
		return index;
	}

	void Clear()
	{
		dim=0;
		index=0;
		delete[] arr;
	}

	bool Delete(const K& k)
	{
		for(int i=0; i<index; i++)
		{
			if (arr[i].key==k)
			{
				for(int j=i; j<index-1; j++)
					arr[j] = arr[j+1];
				index--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map)
	{
		if(index<map.index) return false;

		bool x;
		for(int i=0; i<map.index; i++)
		{
			x=false;
			for(int j=0; j<index; j++)
				if (arr[j].key==map.arr[i].key)
				{
					x=true;
					break;
				}
			if(x==false)
				return false;
		}
		return true;
	}
};


