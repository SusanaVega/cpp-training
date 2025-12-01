#include <iostream>
using namespace std;

constexpr int perfectSquare[4] {0,1,4,9};
int main ()
{
    int x{};
    while (x != -1)
    {
        cout << "Enter a single digit integer, or -1 to quit: ";
        cin >> x;
        cout << endl;
        if (x == -1)
        {
            cout << "Bye\n";
        }
        else
        {
            for(auto &&i: perfectSquare)
            {
                if(i == x)
                {
                    cout << x << " is a perfect square\n";
                    break;
                }
                else
                {
                    cout << x << " is not a perfect square\n";
                    break;
                }
            }
        }
    }
    
    

    return 0;
    
}