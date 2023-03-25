#include <bits/stdc++.h>
using namespace std;
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
    int data[100];

    //copy constructor
    Mystack(Mystack &stack1)
    {
        this->n = stack1.n;
        this->top = stack1.top;
        int t = this->top;
        while(t >= 0)
        {
            this->data[t] = stack1.data[t];
            t--;
        }
        
    }

    void Push(int d);
    void Pop();
    void MaxSize();
    void CurrentSize();
    bool IsEmpty();
    void Display();
    bool IsFull();
};

void Mystack::Push(int d)
{
    if (IsFull())
    {
        cout << "::::: STACK IS FULL :::" << endl;
        return;
    }

    this->top += 1;
    this->data[this->top] = d;
}
void Mystack::Pop()
{
    if (IsEmpty())
    {
        cout << ":::::: STACK IS EMPTY ::::::" << endl;
        return;
    }

    cout << this->data[this->top] << endl;
    this->top -= 1;
}

bool Mystack::IsEmpty()
{
    if (this->top == -1)
        return true;
    return false;
}
bool Mystack::IsFull()
{
    if (this->top == this->n)
        return true;
    return false;
}
void Mystack::MaxSize()
{
    cout << ":::: MAX SIZE  = " << this->n << "   ::::::::" << endl;
}
void Mystack::CurrentSize()
{
    cout << ":::: CURRENT SIZE  = " << this->top + 1 << "   ::::::::" << endl;
}
void Mystack::Display()
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


//operations on stacks

template<class T>
void operations(T & stack1)
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
            int d;
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
    Mystack stack1;

    operations(stack1);

   
    // //stack 2
    Mystack stack2;
    cout<<"::::::::::::::::    STACK2    :::::::::::"<<endl;
    operations(stack2);


    //copy stack
    cout<<"::::::::::::   COPY STACK  ::::::::::::"<<endl;
    Mystack stack(stack1);
    operations(stack);

    return 0;
}