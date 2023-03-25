#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Mystack
{
private:
public:
    int n;

    Mystack(int stack_size = 100)
    {
        this->n = stack_size;
    }
    int top = -1;
    T data[100];

    // copy constructor

    Mystack(Mystack &stack1)
    {
        this->n = stack1.n;
        this->top = stack1.top;
        int t = this->top;
        while (t >= 0)
        {
            this->data[t] = stack1.data[t];
            t--;
        }
    }

    void Push(T d);
    void Pop();
    void MaxSize();
    void CurrentSize();
    bool IsEmpty();
    void Display();
    bool IsFull();
};

template <typename T>
void Mystack<T>::Push(T d)
{
    if (IsFull())
    {
        cout << "::::: STACK IS FULL :::" << endl;
        return;
    }

    this->top += 1;
    this->data[this->top] = d;
}

template <typename T>
void Mystack<T>::Pop()
{
    if (IsEmpty())
    {
        cout << ":::::: STACK IS EMPTY ::::::" << endl;
        return;
    }

    cout << this->data[this->top] << endl;
    this->top -= 1;
}

template <typename T>
bool Mystack<T>::IsEmpty()
{
    if (this->top == -1)
        return true;
    return false;
}

template <typename T>
bool Mystack<T>::IsFull()
{
    if (this->top == this->n)
        return true;
    return false;
}

template <typename T>
void Mystack<T>::MaxSize()
{
    cout << ":::: MAX SIZE  = " << this->n << "   ::::::::" << endl;
}
template <typename T>
void Mystack<T>::CurrentSize()
{
    cout << ":::: CURRENT SIZE  = " << this->top + 1 << "   ::::::::" << endl;
}

template <typename T>
void Mystack<T>::Display()
{
    int Top = this->top;

    cout << "::::::: Display :::::::" << endl;
    while (Top >= 0)
    {
        cout << this->data[Top] << "\t";
        Top--;
    }
    cout << endl;
}

// operations on stacks

template <typename T>
void operations(Mystack<T> stack1)
{
    int F = 0;

    while (true)
    {
        cout << "                 INSTRUCTIONS \n 0 = STOP, 1 = push, 2 = pop, 3 = MaxSize, 4 = Current Size, 5 = IsEmpty, 6 = Display, 7 = IsFull" << endl;
        cin >> F;
        bool stop = false;
        switch (F)
        {
        case 1:
            T d;
            cout << "Enter the Element = ";
            cin >> d;
            stack1.Push(d);
            break;

        case 2:
            stack1.Pop();
            break;

        case 3:
            stack1.MaxSize();
            break;

        case 4:
            stack1.CurrentSize();
            break;

        case 5:
            if (stack1.IsEmpty())
                cout << ":::: EMPTY STACK :::::" << endl;
            cout << "::: Not EMPTY :::::" << endl;
            break;

        case 6:
            stack1.Display();
            break;

        case 7:
            if (stack1.IsFull())
                cout << ":::: STACK IS FULL :::::" << endl;
            cout << "::: NOT FULL :::::" << endl;
            break;
        case 0:
            stop = true;
            break;
        default:
            cout << "Please Enter the right Key !" << endl;
            break;
        }
        if (stop)
            break;
    }
}

int main()
{

    

    cout<<"      ---- int datatype ---"<<endl;
    Mystack<int> stack1;
    operations(stack1);

    cout<<"     --- float datatype ---"<<endl;
    Mystack<float> stack2;
    operations(stack2);

    cout<<"     --- char datatype ---"<<endl;
    Mystack<char> stack3;
    operations(stack3);

    cout<<"     --- copy char stack --- "<<endl;
    Mystack<char> stack = stack3;
    operations(stack);


    // int t;
    // while (true)
    // {
    //     t == -1;
    //     cout << " ---- select datatype ----\n -1: stop, 0: int, 1: float, 2: char" << endl;
    //     cin >> t;
    //     switch (t)
    //     {
    //     case 0:
    //         Mystack<int> stack1;
    //         operations(stack1);
    //         break;
    //     case 1:
    //         Mystack<float> stack2;
    //         operations(stack2);
    //         break;
    //     case 2:
    //         Mystack<char> stack3;
    //         operations(stack3);
    //     default:
    //         cout<<"     --- please choose correct key --- "<<endl;
    //         break;
    //     }
    //     if(t == -1)
    //     {
    //         cout<<" ******** Thank You *********"<<endl;
    //         break;
    //     }
    // }
    return 0;
}