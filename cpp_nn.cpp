#include <iostream>
#include <vector>
#include <Eigen/Dense>

template <typename X>
X maxElement(X x1, X x2) {
    return ((x1 > x2) ? x1 : x2);
}

template <typename X>
void bubbleSort(X a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[j - 1]) 
                std::swap(a[j], a[j - 1]);
}

int main()
{
    std::vector<Eigen::MatrixXf*> testWeightMatrix;
    testWeightMatrix.push_back(new Eigen::MatrixXf(5 + 1, 6 + 1));
    testWeightMatrix.back()->setRandom();

    std::cout << testWeightMatrix[0];
}
