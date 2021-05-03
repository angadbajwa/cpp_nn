#include "nn.h"

// constructor of neural network class
NeuralNetwork::NeuralNetwork(std::vector<uint> topology, Scalar learningRate)
{
    this->topology = topology;
    this->learningRate = learningRate;
    for (uint i = 0; i < topology.size(); i++) {
        // initialze neuron layers
        if (i == topology.size() - 1)
            neuronLayers.push_back(new RowVector(topology[i])); //output layer does not have bias neuron
        else
            neuronLayers.push_back(new RowVector(topology[i] + 1)); //extra bias neuron added to all layers except for the output layer

        // initialize cache and delta vectors
        cacheLayers.push_back(new RowVector(neuronLayers.size()));
        deltas.push_back(new RowVector(neuronLayers.size()));

        // vector.back() gives the handle to recently added element
        // coeffRef gives the reference of value at that place 
        // (using this as we are using pointers here)
        if (i != topology.size() - 1) {
            neuronLayers.back()->coeffRef(topology[i]) = 1.0;
            cacheLayers.back()->coeffRef(topology[i]) = 1.0;
        }

        // initialze weights matrix
        if (i > 0) {
            if (i != topology.size() - 1) {
                weights.push_back(new Matrix(topology[i - 1] + 1, topology[i] + 1)); //X in weight matrix is previous topology + 1 (for bias vector), Y is next layer
                weights.back()->setRandom();
                weights.back()->col(topology[i]).setZero();
                weights.back()->coeffRef(topology[i - 1], topology[i]) = 1.0; //set bias neuron
            }
            else {
                weights.push_back(new Matrix(topology[i - 1] + 1, topology[i]));
                weights.back()->setRandom();
            }
        }
    }
};