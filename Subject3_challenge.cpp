#include <iostream>
#include <algorithm>        // sort�Լ��� ����ϱ����� ���

using namespace std;

// ���ø��� ����Ͽ� Ÿ�Ժ��� �����ε��� �ʿ���� �ϳ��� ����Ͽ� �ٸ�Ÿ�Ե� ��� �Է¹��� �� ����
template <typename T>
class SimpleVector {
private:
    T* data;                //  ���� �迭
    int currentSize;        // �迭�� ����ũ��
    int currentCapacity;    // �迭�� �ִ�ũ��
public:
    //  ������
    SimpleVector(int capacity = 10) : currentCapacity(capacity), currentSize(0) {
        data = new T[currentCapacity];
    }
    SimpleVector(const SimpleVector& other) {
        // ��ü ������ �뷮�� ũ�⸦ �������� �� �迭 �Ҵ�
        currentCapacity = other.currentCapacity;
        currentSize = other.currentSize;
        data = new T[currentCapacity];  // ���ο� �迭 �Ҵ�
        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i];
        }

    }


    // �Ҹ���
    ~SimpleVector() {
        delete[] data;
    }
    void resize(int newCapacity) {
        if (newCapacity > currentCapacity) {        // ���� ���뷮���� ���ο� ���뷮�� ��Ŀ�� �۵�
            T* temp = new T[newCapacity];

            for (int i = 0; i < currentSize; i++) {
                temp[i] = data[i];  // ���� �����͸� ���ο� �迭�� ����
            }

            // ���� �迭 ����
            delete[] data;

            data = temp;    // ������ �����͸� ���ο� �迭�� ����

            currentCapacity = newCapacity;      // ���� ���뷮�� �Է¹��� ���뷮���� ����
        }
        
    }

    void push_back(const T& value) {
        if (currentSize < currentCapacity) {
            data[currentSize] = value;
            currentSize++;
        }
        else {
            resize(currentCapacity + 5);        // �迭 �뷮�� 5��ŭ ���ø�
            push_back(value);                   // ���� ���ο� ���ұ��� �߰���Ŵ
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

    SimpleVector <int>arr1;       // �⺻�����ڷ� �ִ�ũ�� 10 �迭����
    cout << "�⺻ ������ arr1�迭�� �ִ� ũ��: " << arr1.capacity() << endl;
    for (int i = 0; i < arr1.capacity(); i++)       // arr1�迭�� 1�� 5���������
        arr1.push_back(i);
    cout << "arr1�迭 : ";
    arr1.display();
    SimpleVector<int>arr2 = arr1;                   // ���� ������ ȣ��
    cout << "arr1�迭�� ������ arr2�迭 : ";
    arr2.display();
    arr1.resize(20);                                //  arr1�迭�� �ִ� ���뷮�� 20���� resize()�Լ��� ����Ͽ� ����
    cout << "arr1�迭�� resize(20)�� ������ �ִ� ���뷮: " << arr1.capacity() << endl;
    cout << "arr1�迭�� resize(20)�� ������ arr1�迭 ���: ";
    arr1.display();
    arr2.push_back(2);                              // �����ִ� arr2�迭�� 2�� push_back()
    arr2.display();
    cout << "�����ִ� arr2�迭�� 2�� push_back()���Ŀ� arr2�� ���뷮: " << arr2.capacity() << endl;
    arr2.sortData();                                // arr2�迭�� sortData()�� ����
    cout << "���� �� arr2�迭: ";
    arr2.display();
    
    return 0;
}