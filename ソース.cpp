#include <iostream>
#include <vector>

template<class T>
class ConfigBox {
public:

	typedef T DataT;
//	typedef ConfigBox<T> CB;

	bool PushData(const T& In) {
		Data.push_back(In);
		return true;
	}
	bool PushBox(const ConfigBox<T>& In) {//シェアードポインタにしてもいいね。
		Boxs.push_back(In);
		return true;
	}
	std::size_t BoxSize() {
		return Boxs.size();
	}

	std::size_t DataSize() {
		return Data.size();
	}

	T& IndexData(std::size_t Idx) {
		return Data[Idx];
	}
	/** /
	ConfigBox<T>& IndexBox(std::size_t Idx) {
		return Boxs[Idx];
	}
	/**/
	ConfigBox<T> operator [](std::size_t In) {
		return Boxs[In];
	}
	const ConfigBox<T>& operator [](std::size_t In) const {
		return Boxs[In];
	}

	typename std::vector<ConfigBox<T>>::iterator begin() {
		return Boxs.begin();
	}
	typename std::vector<ConfigBox<T>>::const_iterator begin() const  {
		return Boxs.begin();
	}
	typename std::vector<ConfigBox<T>>::iterator end() {
		return Boxs.end();
	}
	typename std::vector<ConfigBox<T>>::const_iterator end() const {
		return Boxs.end();
	}
protected:
	std::vector<T> Data;
	std::vector<ConfigBox<T>> Boxs;
};

int main() {
	ConfigBox<int> B;

	B.PushData(1);
	ConfigBox<int> BB;

	B.PushBox(BB);

	B[0].PushData(10);
	B.PushData(20);

	for (auto& o : B) {
		o.IndexData(0);
	}

	return 0;

}