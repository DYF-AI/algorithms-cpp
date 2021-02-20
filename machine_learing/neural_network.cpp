
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

// activations
namespace activations{

    double sigmoid(const double &x) { return 1.0 / (1.0 + std::exp(-x)); }

    /**
     * Derivative of sigmoid function
     * @param X Value
     * @return Returns derivative of sigmoid(x)
    */
    // 导数
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
// neural_network::layers::DenseLayers
class DenseLayer{
public:
    double (*activation_function)(const double &);   // 激活函数
    double (*dactivation_function)(const double &);  // 激活函数的导数
    int neurons;            // 神经元数量
    std::string activation; // 激活函数
    std::vector<std::valarray<double>> kernel; // 权重 二维数组

    // 构造函数
    DenseLayer(const int &neurons, const std::string &activation,
               const std::pair<size_t, size_t> &kernel_shape, 
               const bool &rand_kernel) {
        if (activation == "sigmoid"){
            activation_function = neural_network::activations::sigmoid;
            dactivation_function = neural_network::activations::dsigmoid;
        } else if (activation == "relu") {
            activation_function = neural_network::activations::relu;
            dactivation_function = neural_network::activations::drelu;
        } else if (activation == "tanh") {
            activation_function = neural_network::activations::tanh;
            dactivation_function = neural_network::activations::dtanh;
        } else if (activation == "none") {
            activation_function = neural_network::util_function::identity_function;
            dactivation_function = neural_network::util_function::identity_function;
        }
        
                  

    }
    
};
}

}

}
