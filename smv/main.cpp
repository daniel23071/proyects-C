#include <iostream>
#include <vector>
#include <cmath>

// Estructura para representar un ejemplo de entrenamiento
struct TrainingExample {
    std::vector<double> features; // Características
    int label; // Etiqueta de clase (1 o -1)
};

// Función para entrenar un modelo SVM simple
void trainSVM(std::vector<TrainingExample>& trainingData, double C, double learningRate, int numEpochs) {
    // Inicializar pesos y sesgo
    std::vector<double> weights(trainingData[0].features.size(), 0.0);
    double bias = 0.0;

    // Entrenamiento del modelo
    for (int epoch = 0; epoch < numEpochs; epoch++) {
        for (const TrainingExample& example : trainingData) {
            double prediction = bias;
            for (size_t i = 0; i < example.features.size(); i++) {
                prediction += weights[i] * example.features[i];
            }

            double loss = 1.0 - example.label * prediction;
            if (loss > 0) {
                for (size_t i = 0; i < example.features.size(); i++) {
                    weights[i] += learningRate * (example.label * example.features[i] - 2 * C * weights[i]);
                }
                bias += learningRate * example.label;
            }
        }
    }

    // Imprimir pesos y sesgo
    std::cout << "Pesos: ";
    for (double weight : weights) {
        std::cout << weight << " ";
    }
    std::cout << "\nSesgo: " << bias << std::endl;
}

int main() {
    // Crear datos de entrenamiento de ejemplo
    std::vector<TrainingExample> trainingData = {
        {{2.5, 1.5}, 1},
        {{1.2, 3.0}, -1},
        {{4.0, 0.5}, 1},
        {{3.5, 2.0}, -1}
    };

    // Configurar parámetros (ajusta según tus necesidades)
    double C = 1.0; // Parámetro de penalización
    double learningRate = 0.01; // Tasa de aprendizaje
    int numEpochs = 1000; // Número de épocas de entrenamiento

    // Entrenar el modelo SVM
    trainSVM(trainingData, C, learningRate, numEpochs);

    return 0;
}
