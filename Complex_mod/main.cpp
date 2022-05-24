   #include "Complex.h"

int main() {

    srand(time(0));

    ofstream file_in_1("complex.txt", ios::out);

    int n; cout << "Enter n:\t"; cin >> n;

    file_in_1 << n;

    for (int i = 1; i <= n * 2; i++) {
        file_in_1 << " " << rand() % 100 * pow(-1, rand() % 2);
    }

    file_in_1.close();

    Complex number; vector <Complex> p;

    ifstream file_out_1("complex.txt");

    if (file_out_1)
    {
        file_out_1 >> n;

        while (!file_out_1.eof())
        {
            file_out_1 >> number;
            p.push_back(number);
        }
    }

    file_out_1.close();

    for (int i = 0; i < n; i++) {
        cout << "\n" << p[i];
    }

    double max_mod = 0; int key = 0;

    for (int i = 0; i < n; i++) {
        if (p[i].mod() > max_mod) {
            max_mod = p[i].mod();
            key = i;
        }
    }

    cout << "\n\nNumber with max mod: " << p[key] << endl;

    return 0;

}