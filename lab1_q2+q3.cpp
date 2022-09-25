
// 21L-5777 M.Usman Amjad

#include <iostream>
using namespace std;
// Swap Function(used in sorting(insertion Sort))
template <typename T>
void swap_ele(T &a, T &b)
{
    T temp = a;
    a = b;
    b = a;
}
template <typename T>
class vector_T
{
    // Private Data Members
    T *T_ptr;
    int capacity;
    int size;

public:
    // Default Constructor..
    vector_T()
    {
        this->T_ptr = new T[2]{0};
        this->size = 0;
        this->capacity = 2;
    }
    // Overloaded Constructor
    vector_T(T cap)
    {
        if (size != 0)
            delete[] T_ptr;
        T_ptr = new T[cap]{0};
        this->capacity = cap;
        this->size = 0;
    }
    // Copy Constructor
    vector_T(const vector_T &obj)
    {
        T *temp = new T[obj.size];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.T_ptr[i];
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->T_ptr = new T[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->T_ptr[i] = temp[i];
        }
    }
    // Assignment Operator
    vector_T &operator=(const vector_T &obj)
    {
        T *temp = new T[obj.size];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.T_ptr[i];
        if (this->size != 0)
            delete[] this->T_ptr;
        this->size = obj.size;
        this->capacity = obj.capacity;
        this->T_ptr = new T[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->T_ptr[i] = temp[i];
        }

        return *this;
    }
    vector_T &operator--()
    {
        if (this->size != 0)
            this->size--;
        return *this;
    }
    // Overloaded +opeartor for adding a value
    vector_T &operator+(T val)
    {
        cout << size << "  " << capacity << endl;
        T *temp = new T[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = this->T_ptr[i];
        }
        temp[size] = val;
        size++;
        capacity *= 2;
        if (size != 0)
            delete[] T_ptr;
        T_ptr = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            T_ptr[i] = temp[i];
        }
        return *this;
    }
    // For capacity of Array..
    T get_capacity()
    {
        return this->capacity;
    }
    // Gives no of indices filled..
    T get_size()
    {
        return this->size;
    }
    // Sub-script Operator and also inputs value if idx is not out of bound..
    bool operator[](T idx)
    {
        if (idx < capacity)
        {
            cout << "Enter a Value to Insert:\n";
            cin >> T_ptr[size++];
            return true;
        }
        return false;
    }
    // Insertion Sort(sort in ascending Order)
    void sort_elements()
    {
        for (int i = 1; i < this->size; i++)
        {
            T key = T_ptr[i];
            int j = i - 1;
            for (; j >= 0 && T_ptr[j] > key; j--)
                swap_ele(T_ptr[j + 1], T_ptr[j]);
            T_ptr[j + 1] = key;
        }
    }
    // stream exertion operator
    friend istream &operator>>(istream &in, vector_T &obj)
    {
        if (obj.size == 0)
            in >> obj.T_ptr[obj.size++];
        else
        {
            if (obj.size < (obj.capacity - 1))
            {
                in >> obj.T_ptr[obj.size++];
            }
            else
            {
                T *temp = new T[obj.capacity * 2];
                for (int i = 0; i < obj.size; i++)
                {
                    temp[i] = obj.T_ptr[i];
                }
                in >> temp[obj.size];
                obj.size++;
                obj.capacity *= 2;
                if (obj.T_ptr)
                    delete[] obj.T_ptr;
                obj.T_ptr = temp;
            }
        }
        return in;
    }
    // stream insertion operator..
    friend ostream &operator<<(ostream &out, const vector_T &obj)
    {
        cout << "output is:\n";
        for (int i = 0; i < obj.size; i++)
        {
            out << obj.T_ptr[i] << "  ";
        }
        cout << "\n_________________________________\n";
        return out;
    }
    // Search an Element (Binary Search)
    bool search(T value)
    {
        this->sort_elements();
        T start = 0;
        T mid = 0;
        T last = size - 1;
        while (start <= last)
        {
            mid = (start + last) / 2;
            if (value == T_ptr[mid])
                return true;
            else if (value < T_ptr[mid])
                last = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
    // Overloaded friend +operator(adds two objects of same class)..
    vector_T &operator+(const vector_T &obj)
    {

        T *temp = new T[capacity + obj.capacity];
        int i = 0;
        for (; i < size; i++)
        {
            temp[i] = T_ptr[i];
        }
        for (int j = 0; j < obj.size; j++, i++)
        {
            temp[i] = obj.T_ptr[j];
        }
        if (T_ptr)
            delete[] T_ptr;

        capacity += obj.capacity;
        T_ptr = new T[capacity];
        size += obj.size;
        for (int j = 0; j < size; j++)
        {
            T_ptr[j] = temp[j];
            cout << T_ptr[j] << "  ";
        }
        cout << endl;
        return *this;
    }
};
template <>

class vector_T<char *>
{
    char *ptr;
    int size;
    int capacity;

public:
    vector_T()
    {
        ptr = NULL;
        this->capacity = 2;
        this->size = 0;
    }
    vector_T(int cap)
    {
        if (ptr)
            delete[] ptr;
        ptr = new char[cap];
        this->capacity = cap;
        this->size = 0;
    }

    friend istream &operator>>(istream &in, vector_T &obj)
    {
        cout << "Enter input:-";
        char *temp = new char[1000];
        cin.ignore();
        cin.getline(temp, 1000);
        int i = 0;
        while (temp[i] != 0)
        {
            i++;
        }
        if (obj.size != 0)
            delete[] obj.ptr;
        obj.capacity = 2 * i;
        obj.size = i + 1;
        i = 0;

        obj.ptr = new char[obj.capacity];
        while (temp[i] != 0)
        {
            obj.ptr[i] = temp[i];
            i++;
        }
        obj.ptr[i] = '\0';
        return in;
    }
    friend ostream &operator<<(ostream &out, const vector_T &obj)
    {
        out << obj.ptr;
        return out;
    }
    int get_capacity()
    {
        return this->capacity;
    }
    int get_size()
    {
        return this->size;
    }
    bool search(const char str[])
    {
        bool flag = true;
        for (int i = 0; this->ptr[i] != 0; i++)
        {
            int j = 0;

            if ((i == 0 || ptr[i - 1] == ' ') && this->ptr[i] == str[j])
            {
                for (; str[j] != 0 && (ptr[i] != ' ' || ptr[i] != 0); j++, i++)
                {
                    if (ptr[i] != str[j])
                        flag = false;
                }
            }
        }
        return flag;
    }
    ~vector_T()
    {
        if (this->ptr)
            delete[] this->ptr;
    }
    bool operator[](int idx)
    {
        if (idx < this->capacity)
        {
            cin >> this->ptr[idx];
            this->size = idx;
            return true;
        }
        return false;
    }
    vector_T &operator+(const char *arr)
    {
        int i = 0;
        while (arr[i] != 0)
            i++;
        this->capacity = 2 * size * i;
        cout << "Capacity is:" << capacity << endl;
        char *temp = new char[capacity];
        int k = 0;
        while (this->ptr[k] != 0)
        {
            temp[k] = this->ptr[k];
            k++;
        }
        temp[k++] = ' ';
        for (int j = 0; arr[j] != 0; j++, k++)
        {
            temp[k] = arr[j];
        }
        temp[k++] = 0;
        if (size != 0)
            delete[] ptr;
        this->ptr = new char[this->capacity];
        for (int j = 0; temp[j] != 0; j++)
            ptr[j] = temp[j];
        this->size = k;
        return *this;
    }
    vector_T &operator+(const vector_T &obj1)
    {
        capacity = capacity + obj1.capacity;
        size = size + obj1.size;
        int i = 0;
        while (obj1.ptr[i] != 0)
        {

            i++;
        }
        ptr[i++] = ' ';
        for (int j = 0; obj1.ptr[j] != 0; j++, i++)
            ptr[i] = obj1.ptr[j];
        return *this;
    }
    vector_T(const vector_T &obj)
    {
        char *temp = new char[obj.capacity];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.ptr[i];
        temp[obj.size] = '\0';
        if (this->ptr)
            delete[] ptr;
        this->capacity = obj.capacity;
        this->size = obj.size;
        this->ptr = new char[this->capacity];
        int i = 0;
        for (; temp[i] != 0; i++)
            this->ptr[i] = temp[i];
        this->ptr[i] = '\0';
    }
    vector_T &operator=(const vector_T &obj)
    {
        char *temp = new char[obj.capacity];
        for (int i = 0; i < obj.size; i++)
            temp[i] = obj.ptr[i];
        temp[obj.size] = '\0';
        if (size != 0)
            delete[] ptr;
        this->capacity = obj.capacity;
        this->size = obj.size;
        this->ptr = new char[this->capacity];
        int i = 0;
        for (; temp[i] != 0; i++)
            this->ptr[i] = temp[i];
        this->ptr[i] = '\0';
        return *this;
    }
};
int main()

{

    vector_T<double> v1;
    cout << "Input Values in Vector:-\n";
    for (int i = 0; i < 5; i++)
        cin >> v1;
    cout << v1 << endl;
    --v1;
    vector_T<double> v2;
    v2 = v1;
    cout << v2 << endl;
    v1.sort_elements();
    cout << "v1 after sorting:-\n";
    cout << v1 << endl;
    vector_T<double> v3 = v1;
    cout << "v3 is:\n"
         << v3 << endl;
    v3 = v1 + v2;
    cout << "v3=v1+v2:-\n";
    cout << v3 << endl;
    v3 = v3 + 9.9;
    cout << "v3 after adding 9.9:\n";
    cout << v3 << endl;
    vector_T<char *> char_vect;
    cin >> char_vect;
    cout << "Char* is:\n";
    cout << char_vect << endl;
    vector_T<char *> char_vect2;
    char_vect2 = char_vect;
    cout << "vect1=vect is:\n";
    cout << char_vect2 << endl;
    char arr[20];
    cout << "Enter a word to find in the sentence:-";
    cin >> arr;
    cout << "Boolean value of Search:\n";
    cout << char_vect2.search(arr) << endl;
    cout << "After Adding add in vect2:\n";
    char_vect2 = char_vect2 + "Add";

    cout << char_vect2 << endl;
    vector_T<char *> char_vect3;
    char_vect3 = char_vect + char_vect2;
    cout << "char_vect3=char_vect+char_vect2 is :-\n";
    cout << char_vect3 << endl;
    system("PAUSE");
    return 0;
}