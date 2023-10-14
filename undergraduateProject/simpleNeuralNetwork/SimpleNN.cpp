#include <stdlib.h>  
#include <math.h>  
#include <iostream>
using namespace std;

double sigmoid_function(double x) {
    return 1 / (1 + exp(-1 * x));
}

int main()
{
    int expected_output;
    //weights for a&b, and the bias
    double w_a = rand() % 10;
    double w_b = rand() % 10;
    double bias = rand() % 10;


    for (int i = 0; i < 50000; i++) {

        int A = rand() % 2; //Assign 0, or 1, to A&B
        int B = rand() % 2;


        if (A == 0 && B == 0) {
            expected_output = 0;
        }
        else {
            expected_output = 1;
        }

        cout << "Iteration: " << i + 1 << endl;
        cout << "A = " << A << endl;
        cout << "B = " << B << endl;

        cout << "w_a = " << w_a << endl;
        cout << "w_b = " << w_b << endl;
        cout << "b = " << bias << endl;

        z_L = w_a * A + w_b * B + bias;
        a_L = sigmoid_function(z_L);

        cout << "Expected output: " << expected_output << endl;
        cout << "----VS----" << endl;
        cout << "Network output: " << a_L << endl;
        cout << " " << endl;

        //changes to be made
        delta_w_a = 2 * A * a_L * (1 - a_L) * (a_L - expected_output);
        delta_w_b = 2 * B * a_L * (1 - a_L) * (a_L - expected_output);
        delta_b = 2 * a_L * (1 - a_L) * (a_L - expected_output);

        w_a -= delta_w_a;
        w_b -= delta_w_b;
        bias -= delta_b;


    }
}
