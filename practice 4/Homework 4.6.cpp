#include "Source.h"

int main()
{
    cout << "\t\tBox in Box\n\n";

    int a, b, c, m, n, k;
    cout << "Enter a,b,c: "; cin >> a >> b >> c;
    cout << "Enter m,n,k: "; cin >> m >> n >> k;

    //  Sorting the first box by size 
    if (a > b)
        std::swap(a, b);
    if (a > c)
        std::swap(a, c);
    if (b > c)
        std::swap(b, c);

    // Sorting the second box by size 
    if (m > n)
        std::swap(m, n);
    if (m > k)
        std::swap(m, k);
    if (n > k)
        std::swap(n, k);


    if (a == m && b == n && c == k)
        cout << "Boxes is equal\n";
    else if (a <= m && b <= n && c <= k)
        cout << "First box is smaller\n";
    else if (a >= m && b >= n && c >= k)
        cout << "Second box is smaller\n";
    else
        cout << "Boxes are incompatible\n";


    return 0;
}