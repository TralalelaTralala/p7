#include <iostream>

using namespace std;

class Chislo
{
private:
    long n;

public:
    Chislo(long value = 0)
    {
        n = value;
    }

    virtual ~Chislo()
    {
    }

    long getN()
    {
        return n;
    }

    virtual long long factorial(long x)
    {
        long long f = 1;

        for (long i = 1; i <= x; i++)
            f *= i;

        return f;
    }
};

class Matrix : public Chislo
{
public:
    int arr[100];

    Matrix(long size = 0) : Chislo(size)
    {
    }

    void input()
    {
        for (int i = 0; i < getN(); i++)
        {
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
    }

    void showFactorials(Chislo* p)
    {
        cout << "\nFactorials:\n";

        for (int i = 0; i < getN(); i++)
        {
            cout << arr[i]
                 << "! = "
                 << p->factorial(arr[i])
                 << endl;
        }
    }
};

int main()
{
    long size;

    cout << "Enter size: ";
    cin >> size;

    Matrix obj(size);

    obj.input();

    Chislo* p = &obj;

    obj.showFactorials(p);

    return 0;
}
