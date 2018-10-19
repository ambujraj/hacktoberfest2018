#include<iostream>
#include<random>

using namespace std;

int main() {
    random_device rd;
    mt19937 engine(rd());
    uniform_int_distribution<> dist(0, 100); // specify your custom range here
    cout << "Random Numbers generated using Mersenne Twister:\n";
    cout << dist(engine) << endl;
    cout << dist(engine) << endl;
    cout << dist(engine) << endl;
    cout << dist(engine) << endl;
    cout << dist(engine) << endl;
    return 0;
}