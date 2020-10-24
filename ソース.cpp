#include <iostream>
#include <vector>

template<class T>
class ConfigBox {
public:

	typedef T DataT;

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
	const ConfigBox<T>& operator [](std::size_t In) const{
		return Boxs[In];
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

	return 0;

}