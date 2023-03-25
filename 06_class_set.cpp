#include <bits/stdc++.h>
#include<math.h>
using namespace std;

class SET
{
private:
int m = 0;
int var;
int sd;

public:
    set<int> s;
    void add(int ele)
    {
        this->s.insert(ele);
    }
    SET() {}

    void display()
    {
        for (auto i : this->s)
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    void POWER_SET()
    {
        int set_size = s.size();
        int a[set_size];
        int count = 0;
        for (auto i : s)
        {
            a[count] = i;
            count++;
        }

        int pow_set_size = pow(2, set_size);

        for (int i = 0; i < pow_set_size; i++)
        {
            for (int j = 0; j < set_size; j++)
            {
                if (i & (1 << j))
                    cout << a[j];
            }
            cout << ", ";
        }
        cout << endl;
    }

    void mean()
    {
        this->m = 0;
        for(auto a : s)
        {
            this->m+=a;
        }
        this->m = this->m/(s.size());
        cout<<"     --Mean: = "<<this->m<<endl;
    }
    void variance()
    {
        this->var = 0;
        for(auto a : s)
        {
            this->var += pow(a-this->m, 2);
        }
        this->var = var/s.size();
        cout<<"           -- Var(): = "<<this->var<<endl;
    }
    void SD()
    {
        cout<<"           --- SD(): = "<<sqrt(this->var)<<endl;
    }
    void median()
    {
        int count =0;
        int n = s.size();
        for(auto a: s)
        {   
            count++;
            if(count == n/2)
            {
                cout<<"             --Median(set) = "<<a<<endl;
                break;
            }
        }
    }
};

class UNION
{
public:
    SET s3;
    UNION(SET &s1, SET &s2)
    {
        for (auto i : s1.s)
        {
            this->s3.s.insert(i);
        }
        for (auto i : s2.s)
        {
            this->s3.s.insert(i);
        }
    }
};

class INTERSECTION
{
public:
    SET s3;
    INTERSECTION(SET &s1, SET &s2)
    {
        for (auto a : s1.s)
        {
            for (auto b : s2.s)
            {
                if (a == b)
                {
                    this->s3.s.insert(a);
                }
            }
        }
    }
};

class DIFFERENCE
{
public:
    SET s3;
    DIFFERENCE(SET &s1, SET &s2)
    {
        for (auto a : s1.s)
        {
            for (auto b : s2.s)
            {
                if (a != b)
                {
                    this->s3.s.insert(a);
                }
            }
        }
    }
};

class EQUAL_SETS
{
private:
    set<int> s1, s2;

public:
    EQUAL_SETS(SET &s1, SET &s2)
    {
        this->s1 = s1.s;
        this->s2 = s2.s;
    }
    bool Is_equal()
    {
        if (this->s1 == this->s2)
        {
            return true;
        }
        return false;
    }
};

class carte_product
{
private:
    set<tuple<int, int>> s3;

public:
    carte_product(SET &s1, SET &s2)
    {
        for (auto a : s1.s)
        {
            for (auto b : s2.s)
            {
                tuple<int, int> tp = make_tuple(a, b);
                this->s3.insert(tp);
            }
        }
    }

    void display()
    {

        for (auto x : this->s3)
        {
            tuple<int, int> tp = x;
            cout << "("<<get<0>(tp) <<", " << get<1>(tp)<<"), ";
        }
        cout << endl;
    }
};


int main()
{
    SET s1;
    // bool flag1 = true;
    // while(flag1)
    // {
    //     flag1 = false;
    //     int ele;
    //     cout<<" enter the elem of set1"<<endl;
    //     cin>>ele;
    //     s1.add(ele);
    //     cout<<"press 0: stop, 1: enter"<<endl;
    //     cin>>flag1;

    // }
    s1.s.insert({1, 2, 3});

    cout << "           -----    set-2           ---" << endl;
    SET s2;
    // bool flag2 = true;
    // while(flag2)
    // {
    //     flag2 = false;
    //     int ele;
    //     cout<<" enter the elem of set2"<<endl;
    //     cin>>ele;
    //     s2.add(ele);
    //     cout<<"press 0: stop, 1: enter"<<endl;
    //     cin>>flag2;

    // }

    s2.s.insert({1, 2, 3, 5});
    cout << "           --set-1 --" << endl;
    s1.display();
    cout << "           --set-2 --" << endl;
    s2.display();

    // UNION
    cout << " -  --- UNION -- " << endl;
    UNION res_union(s1, s2);
    res_union.s3.display();

    // INTERSECTION
    cout << " -  --- INTERSECTION-- " << endl;
    INTERSECTION res_inter(s1, s2);
    res_inter.s3.display();

    // DIFFERENCE
    // let, s1 - s2
    cout << " -  --- DIFFERENCE-- " << endl;
    DIFFERENCE res_def(s1, s2);
    res_def.s3.display();

    // COMPLEMENT
    // let, s2 is whole space and s1 is subset of s2
    cout << " -  --- COMPLEMENT-- " << endl;
    DIFFERENCE res_com(s1, s2);
    res_com.s3.display();

    // EQUAL_SETS
    // let, s1 - s2
    cout << " -  --- EQUAL_SETS-- " << endl;
    EQUAL_SETS res_eq_set(s1, s2);
    if (res_eq_set.Is_equal())
    {
        cout << " s1 and s2 are equal sets" << endl;
    }
    else
    {
        cout << " s1 and s2 are not equal sets" << endl;
    }

    // carte_product
    // let s1 * s2
    cout << " -  --- carte_product-- " << endl;
    carte_product res_prod(s1, s2);
    res_prod.display();

    // POWER_SET
    cout << "  ----     POWER SET  ---" << endl;
    s1.POWER_SET();

    //DISTINCT
    //let, s1 - s2
    cout<<" -  --- DISTINCT-- "<<endl;
    INTERSECTION res_dis_set(s1, s2);
    if(res_dis_set.s3.s.size()==0)
    {
        cout<<"s1 and s2 are distinict"<<endl;
    }
    else{
        cout<<"s1 and s2 are not distinict"<<endl;
    }

    s1.mean();
    s1.variance();
    s1.SD();
    s1.median();
    return 0;
}