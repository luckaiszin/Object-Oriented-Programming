#include "iostream"
#include <fstream>

using namespace std;

int main()
{
    ifstream input;
    ofstream output;
    int x;
    int total;
    output.open("number.txt");
    output << "1" << endl;
    output << "2" << endl;
    output.close();
    input.open("number.txt");
    input >> x;
    while (input)
    {
        total += x;
        cout << "x: " << x << endl;
        input >> x;
    }
    if (!input.eof())
    {
        cout << "Erro de leitura" << endl;
        input.close();
        return 1;
    }
    input.close();
    cout << total << endl;
    return 0;
}