#include <iostream>
#include <algorithm>        // sort함수를 사용하기위한 헤더

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
    SimpleVector(const SimpleVector& other) {
        // 객체 기존의 용량과 크기를 기준으로 새 배열 할당
        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        data = new T[currentCapacity];  // 새로운 배열 할당
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }

    }


    // 소멸자
    ~SimpleVector() {
        delete[] data;
    }
    void resize(int newCapacity) {
        if (newCapacity > currentCapacity) {        // 현재 수용량보다 새로운 수용량이 더커야 작동
            T* temp = new T[newCapacity];

            for (int i = 0; i < currentSize; i++) {
                temp[i] = data[i];  // 기존 데이터를 새로운 배열에 복사
            }

            // 기존 배열 삭제
            delete[] data;

            data = temp;    // 데이터 포인터를 새로운 배열로 변경

            currentCapacity = newCapacity;      // 현재 수용량을 입력받은 수용량으로 변경
        }
        
    }

    void push_back(const T& value) {
        if (currentSize < currentCapacity) {
            data[currentSize] = value;
            currentSize++;
        }
        else {
            resize(currentCapacity + 5);        // 배열 용량을 5만큼 더늘림
            push_back(value);                   // 그후 새로운 원소까지 추가시킴
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

    void sortData() {
        sort(data, data+currentSize);
    }
    int size() {
        return currentSize;
    }

    int capacity() {
        return currentCapacity;
    }
};




int main() {

    SimpleVector <int>arr1;       // 기본생성자로 최대크기 10 배열선언
    cout << "기본 생성자 arr1배열의 최대 크기: " << arr1.capacity() << endl;
    for (int i = 0; i < arr1.capacity(); i++)       // arr1배열에 1을 5번집어넣음
        arr1.push_back(i);
    cout << "arr1배열 : ";
    arr1.display();
    SimpleVector<int>arr2 = arr1;                   // 복사 생성자 호출
    cout << "arr1배열을 복사한 arr2배열 : ";
    arr2.display();
    arr1.resize(20);                                //  arr1배열의 최대 수용량을 20으로 resize()함수를 사용하여 변경
    cout << "arr1배열을 resize(20)을 한이후 최대 수용량: " << arr1.capacity() << endl;
    cout << "arr1배열을 resize(20)을 한이후 arr1배열 출력: ";
    arr1.display();
    arr2.push_back(2);                              // 꽉차있는 arr2배열에 2를 push_back()
    arr2.display();
    cout << "꽉차있는 arr2배열에 2를 push_back()한후에 arr2의 수용량: " << arr2.capacity() << endl;
    arr2.sortData();                                // arr2배열을 sortData()로 정렬
    cout << "정렬 후 arr2배열: ";
    arr2.display();
    
    return 0;
}