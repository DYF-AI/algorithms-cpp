
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <valarray>
#include <cmath>
#include <cassert>
#include <string>

namespace machine_learning{

namespace neural_network{

namespace activations{

    double sigmoid(const double &x) { return 1.0 / (1.0 + std::exp(-x)); }

    /**
     * Derivative of sigmoid function
     * @param X Value
     * @return Returns derivative of sigmoid(x)
    */
    double dsigmoid(const double &x) { return x * (1 - x); }

    double relu(const double &x) { return std::max(0.0, x); }

    double drelu(const double &x) { return x >= 0.0 ? 1.0 : 0.0; }

    double tanh(const double &x) { return 2 / (1 + std::exp(-2 * x)) - 1; }

    double dtanh(const double &x) { return 1 - x * x; }
}

namespace util_function{
    double square(const double &x) { return x * x; }
    double identity_function(const double &x) { return x; }  
}

namespace layers{
class DenseLayes{
public:
    double (*activation_function)(const double &);
    double (*dactivation_function)(const double &);
    int neurons;            // 神经元数量
    std::string activation; // 激活函数
    std::vector<std::valarray<double>> kernel; // 权重

    // 构造函数
    
};
}

}

}
