#include <iostream>

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

    // �Ҹ���
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

    SimpleVector <int>arr1(5);     // �ִ�ũ�� 5 �迭����
    SimpleVector <int>arr2;       // �⺻�����ڷ� �ִ�ũ�� 10 �迭����
    cout << "���ڸ� �ϳ� �޴� ������ arr1�迭�� �ִ� ũ��: " << arr1.capacity() << endl;
    cout << "�⺻ ������ arr2�迭�� �ִ� ũ��: " << arr2.capacity() << endl;
    for (int i = 0; i < arr1.capacity(); i++)       // arr1�迭�� 1�� 5���������
        arr1.push_back(1);
    arr1.display();
    arr1.push_back(2);                                      // arr1 ���� �迭�� 2�� �ѹ��� �������
    arr1.display();                                         // �ƹ��ϵ� �Ͼ������
    arr1.pop_back();                                        // �迭 �ǵڿ� ���� ��
    arr1.display();
    cout << "���� �迭�� ũ��: " << arr1.size() << endl;;   // ���� �迭�� ũ��:4

    return 0;
}