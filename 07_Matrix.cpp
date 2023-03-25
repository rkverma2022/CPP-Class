#include <bits/stdc++.h>
using namespace std;

class Matrix
{
private:
    int n, m, r, s;
    vector<vector<int>> A;
    vector<vector<int>> B;

public:
    Matrix()
    {
        cout << "Enter order of matrix: " << endl;
        cin >> this->n >> this->m;

        for (int i = 0; i < n; i++)
        {
            vector<int> v;
            for (int j = 0; j < m; j++)
            {
                cout << "A[" << i << "][" << j << "] = ";
                int ele;
                cin >> ele;
                v.push_back(ele);
            }
            A.push_back(v);
        }

        cout << "Enter order of matrix B: " << endl;
        cin >> r >> s;
        for (int i = 0; i < r; i++)
        {
            vector<int> v;
            for (int j = 0; j < s; j++)
            {
                cout << "B[" << i << "][" << j << "] = ";
                int ele;
                cin >> ele;
                v.push_back(ele);
            }
            B.push_back(v);
        }
    }

    void Addition()
    {
        if (!((n == r) && (m == s)))
        {
            cout << "       --CAN'T ADD, ORDER OF MATRICES ARE NOT SAME --" << endl;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << A[i][j] + B[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void Multiplication()
    {
        if(!(m==r))
        {
            cout<<"      --- CAN'T DO MATRIX MULTIPLICATION, ORDER ruleS ARE NOT FOLLOWING --"<<endl;
            return;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s;j++)
            {
                int sum =0;
                for(int k=0;k<m;k++)
                {
                    sum += A[i][k] + B[k][j];
                }
                cout<<sum<<"  ";
            }
            cout<<endl;
        }
    }

    void Is_Equal()
    {
        if(!((n==r)&&(m==s)))
        {
            cout<<"          --- MATRICES ARE NOT EQUAL, AS THEIRS ORDER IS NOT SAME  ---"<<endl;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(!(A[i][j]==B[i][j]))
                {
                    cout<<"          --- MATRICES ARE NOT EQUAL, As their Elements are NOT equal  ---"<<endl;
                    return;
                }
            }
        }
        cout<<"          --- EQUAL MATRICES  ---"<<endl;
    }

    void Transpose()
    {
        cout<<"         --- A-transpose ---"<<endl;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cout<<A[i][j]<<"  ";
            }
            cout << endl;
        }
    }

    void cut_submatrix()
    {
        int x1 = 1, y1 = 1, x4 = 1, y4 = 1;
        cout << "           --- Enter the coordiantes of all vertex of Matrix size of Matrix to Cut from matrix-A" << endl;
        cout << "x1, y1: ";
        cin >> x1 >> y1;
        cout << "x4, y4: ";
        cin >> x4 >> y4;
        if (!((x1 <= n) && (x4 <= n) && (y1 <= m) && (y4 <= m)))
        {
            cout << "   -- Can't make Submatrix --" << endl;
            return;
        }

        for (int i = x1 - 1; i < x4; i++)
        {
            for (int j = y1 - 1; j < y4; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    
};

int main()
{
    // int n,m;
    // cout<<"Enter order of matrix: "<<endl;
    // cin>>n>>m;
    // int A[n][m];
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<"A["<<i<<"]["<<j<<"] = ";
    //         cin>>A[i][j];
    //     }
    // }

    // int r,s;
    // cout<<"Enter order of matrix B: "<<endl;
    // cin>>r>>s;
    // int B[r][s];
    // for(int i=0;i<r;i++)
    // {
    //     for(int j=0;j<s;j++)
    //     {
    //         cout<<"B["<<i<<"]["<<j<<"] = ";
    //         cin>>B[i][j];
    //     }
    // }

    Matrix M;
    M.Addition();
    M.Multiplication();
    M.Is_Equal();
    M.Transpose();
    M.cut_submatrix();

    return 0;
}