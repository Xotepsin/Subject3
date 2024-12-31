#include <iostream>

using namespace std;

// 템플릿을 사용하여 타입별로 오버로드할 필요없이 하나만 사용하여 다른타입도 모두 입력받을 수 있음
template <typename T>
class SimpleVector {
private:
    T* data;                //  동적 배열
    int currentSize;        // 배열의 현재크기
    int currentCapacity;    // 배열의 최대크기
public:
    //  생성자
    SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
        data = new T[currentCapacity];
    }

    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }
    void push_back(const T& value) {
        if (currentSize < currentCapacity) {
            data[currentSize] = value;
            currentSize++;
        }
    }
    void display() {
        cout << "[";
        for (int i = 0; i < currentSize; i++) {
            cout << data[i];
            if (i == currentSize - 1)
                cout << "]" << endl;
            else
                cout << ", ";
        }

    }
    void pop_back() {
        if (currentSize > 0) {
            currentSize--;
        }
    }
    int size() {
        return currentSize;
    }
    int capacity() {
        return currentCapacity;
    }
};




int main() {

    SimpleVector <int>arr1(5);     // 최대크기 5 배열선언
    SimpleVector <int>arr2;       // 기본생성자로 최대크기 10 배열선언
    cout << "숫자를 하나 받는 생성자 arr1배열의 최대 크기: " << arr1.capacity() << endl;
    cout << "기본 생성자 arr2배열의 최대 크기: " << arr2.capacity() << endl;
    for (int i = 0; i < arr1.capacity(); i++)       // arr1배열에 1을 5번집어넣음
        arr1.push_back(1);
    arr1.display();
    arr1.push_back(2);                                      // arr1 꽉찬 배열에 2를 한번더 집어넣음
    arr1.display();                                         // 아무일도 일어나지않음
    arr1.pop_back();                                        // 배열 맨뒤에 값을 뺌
    arr1.display();
    cout << "현재 배열의 크기: " << arr1.size() << endl;;   // 현재 배열의 크기:4

    return 0;
}