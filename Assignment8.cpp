/*
Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search probability pi for each key ki .
Build the Binary search tree that has the least search cost given the access probability for each key?


ALGORITHMS
We have the following procedure for determining R(i, j) and C(i, j) with 0 <= i <= j <= n: PROCEDURE
COMPUTE_ROOT(n, p, q; R, C)
begin
for i = 0 to n do
C (i, i) ←0
W (i, i) ←q(i)
for m = 0 to n do
for i = 0 to (n – m) do
j ←i + m
W (i, j) ←W (i, j – 1) + p (j) + q (j)
*find C (i, j) and R (i, j) which minimize the
tree cost
end
The following function builds an optimal binary sea
rch tree
FUNCTION CONSTRUCT(R, i, j)
begin
*build a new internal node N labeled (i, j)
k ←R (i, j)
f i = k then
*build a new leaf node N‟ labeled (i, i)
else
*N‟ ←CONSTRUCT(R, i, k)
*N‟ is the left child of node
N if k = (j – 1) then
*build a new leaf node N‟‟ labeled (j, j)
else
*N‟‟ ←CONSTRUCT(R, k + 1, j)
*N‟‟ is the right child of node N
return N end

COMPLEXITY ANALYSIS:
The algorithm requires O (n2) time and O (n2) storage. Therefore, as „n‟ increases it will run out of
storage even before it runs out of time. The storage needed can be reduced by almost half by
implementing the twodimensional
arrays as onedimensional
arrays.
*/
#include <iostream>
using namespace std;
#define SIZE 10
class OBST
{
    int p[SIZE];
    int q[SIZE];
    int a[SIZE];
    int w[SIZE][SIZE];
    int c[SIZE][SIZE];
    int r[SIZE][SIZE];
    int n;

public:
    void get_data()
    {
        int i;
        cout << "\n Optimal Binary Search Tree \n";
        cout << "\nEnter the number of nodes";
        cin >> n;
        cout << "\nEnter the data as\n";
        for (i = 1; i <= n; i++)
        {
            cout << "\na[" << i << "] : ";
            cin >> a[i];
        }
        for (i = 1; i <= n; i++)
        {
            cout << "\np[" << i << "] : ";
            cin >> p[i];
        }
        for (i = 0; i <= n; i++)
        {
            cout << "\nq[" << i << "] : ";
            cin >> q[i];
        }
    }
    int Min_Value(int i, int j)
    {
        int m, k;
        int minimum = 32000;
        for (m = r[i][j - 1]; m <= r[i + 1][j]; m++)
        {
            if ((c[i][m - 1] + c[m][j]) < minimum)
            {
                minimum = c[i][m - 1] + c[m][j];
                k = m;
            }
        }
        return k;
    }
    void build_OBST()
    {
        int i, j, k, l, m;
        for (i = 0; i < n; i++)
        {
            w[i][i] = q[i];
            r[i][i] = c[i][i] = 0;
            w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
            r[i][i + 1] = i + 1;
            c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n] = 0;
        for (m = 2; m <= n; m++)
        {
            for (i = 0; i <= n - m; i++)
            {
                j = i + m;
                w[i][j] = w[i][j - 1] + p[j] + q[j];
                k = Min_Value(i, j);
                c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
                r[i][j] = k;
            }
        }
    }
    void build_tree()
    {
        int i, j, k;
        int queue[20], front = -1, rear = -1;
        cout << "The Optimal Binary Search Tree For the Given Node Is :\n";
        cout << "\nThe Root of this OBST is ::" << r[0][n];
        cout << "\nThe Cost of this OBST is::" << c[0][n];
        cout << "\n\n\tNODE \tLEFT CHILD \tRIGHT CHILD ";
        cout << "\n";
        queue[++rear] = 0;
        queue[++rear] = n;
        while (front != rear)
        {
            i = queue[++front];
            j = queue[++front];
            k = r[i][j];
            cout << "\n\t" << k;
            if (r[i][k - 1] != 0)
            {
                cout << "\t\t" << r[i][k - 1];
                queue[++rear] = i;
                queue[++rear] = k - 1;
            }
            else
                cout << "\t\t";
            if (r[k][j] != 0)
            {
                cout << "\t" << r[k][j];
                queue[++rear] = k;
                queue[++rear] = j;
            }
            else
                cout << "\t";
        }
        cout << "\n";
    }
};
int main()
{
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}