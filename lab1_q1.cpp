
// 21L-5777 M.Usman Amjad

#include <iostream>
using namespace std;
// Swap Function(used in sorting(insertion Sort))
void swap_ele(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
}
class vector_int
{
    // Private Data Members
    int *int_ptr;
    int capacity;
    int size;

public:
    // Default Constructor..
    vector_int()
    {
        this->int_ptr = new int[2]{0};
        this->size = 0;
        this->capacity = 2;
    }
    // Overloaded Constructor
    vector_int(int cap)
    {
        if (size != 0)
            delete[] int_ptr;
        int_ptr = new int[cap]{0};
        this->capacity = cap;
        this->size = 0;
    }
    // Copy Constructor
    vector_int(const vector_int &obj)
    {
        int *temp = new int[obj.size];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.int_ptr[i];
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->int_ptr = new int[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->int_ptr[i] = temp[i];
        }
    }
    // Assignment Operator
    vector_int &operator=(const vector_int &obj)
    {
        int *temp = new int[obj.size];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.int_ptr[i];
        if (this->size != 0)
            delete[] this->int_ptr;
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->int_ptr = new int[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->int_ptr[i] = temp[i];
        }

        return *this;
    }
    vector_int &operator--()
    {
        if (this->size != 0)
            this->size--;
        return *this;
    }
    // Overloaded +opeartor for adding a value
    vector_int &operator+(int val)
    {
        cout << size << "  " << capacity << endl;
        int *temp = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = this->int_ptr[i];
        }
        temp[size] = val;
        size++;
        capacity *= 2;
        if (size != 0)
            delete[] int_ptr;
        int_ptr = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            int_ptr[i] = temp[i];
        }
        return *this;
    }
    // For capacity of Array..
    int get_capacity()
    {
        return this->capacity;
    }
    // Gives no of indices filled..
    int get_size()
    {
        return this->size;
    }
    // Sub-script Operator and also inputs value if idx is not out of bound..
    bool operator[](int idx)
    {
        if (idx < capacity)
        {
            cout << "Enter a Value to Insert:\n";
            cin >> int_ptr[size++];
            return true;
        }
        return false;
    }
    // Insertion Sort(sort in ascending Order)
    void sort_elements()
    {
        for (int i = 1; i < this->size; i++)
        {
            int key = int_ptr[i];
            int j = i - 1;
            for (; j >= 0 && int_ptr[j] > key; j--)
                swap_ele(int_ptr[j + 1], int_ptr[j]);
            int_ptr[j + 1] = key;
        }
    }
    // stream exertion operator
    friend istream &operator>>(istream &in, vector_int &obj)
    {
        if (obj.size == 0)
            in >> obj.int_ptr[obj.size++];
        else
        {
            if (obj.size < (obj.capacity - 1))
            {
                in >> obj.int_ptr[obj.size++];
            }
            else
            {
                int *temp = new int[obj.capacity * 2];
                for (int i = 0; i < obj.size; i++)
                {
                    temp[i] = obj.int_ptr[i];
                }
                in >> temp[obj.size];
                obj.size++;
                obj.capacity *= 2;
                if (obj.int_ptr)
                    delete[] obj.int_ptr;
                obj.int_ptr = temp;
            }
        }
        return in;
    }
    // stream insertion operator..
    friend ostream &operator<<(ostream &out, const vector_int &obj)
    {
        cout << "output is:\n";
        for (int i = 0; i < obj.size; i++)
        {
            out << obj.int_ptr[i] << "  ";
        }
        cout << "\n_________________________________\n";
        return out;
    }
    // Search an Element (Binary Search)
    bool search(int value)
    {
        this->sort_elements();
        int start = 0;
        int mid = 0;
        int last = size - 1;
        while (start <= last)
        {
            mid = (start + last) / 2;
            if (value == int_ptr[mid])
                return true;
            else if (value < int_ptr[mid])
                last = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
    // Overloaded friend +operator(adds two objects of same class)..
    vector_int &operator+(const vector_int &obj)
    {

        int *temp = new int[capacity + obj.capacity];
        int i = 0;
        for (; i < size; i++)
        {
            temp[i] = int_ptr[i];
        }
        for (int j = 0; j < obj.size; j++, i++)
        {
            temp[i] = obj.int_ptr[j];
        }
        if (int_ptr)
            delete[] int_ptr;

        capacity += obj.capacity;
        int_ptr = new int[capacity];
        size += obj.size;
        for (int j = 0; j < size; j++)
        {
            int_ptr[j] = temp[j];
            cout << int_ptr[j] << "  ";
        }
        cout << endl;
        return *this;
    }
};

int main()
{

    vector_int v1;
    cout << "Input Values in Vector:-";
    for (int i = 0; i < 5; i++)
        cin >> v1;
    cout << v1 << endl;
    --v1;
    vector_int v2;
    v2 = v1;
    cout << v2 << endl;
    v1.sort_elements();
    cout << "v1 after sorting:-\n";
    cout << v1 << endl;
    vector_int v3 = v1;
    cout << "v3 is:\n"
         << v3 << endl;
    v3 = v1 + v2;
    cout << "v3=v1+v2:-\n";
    cout << v3 << endl;
    v3 = v3 + 10;
    cout << "v3 after adding 10:\n";
    cout << v3 << endl;
    system("PAUSE");
    return 0;
}