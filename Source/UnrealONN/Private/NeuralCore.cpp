// Fill out your copyright notice in the Description page of Project Settings.


#include "NeuralCore.h"

DEFINE_LOG_CATEGORY(LogNeuralCore);

using Eigen::Index;
using std::string;

void UNeuralNetwork::GenerateSimpleNetwork(bool bForceRegenerate = false)
{
	if (HasValidNetwork())
	{
		if (bForceRegenerate)
			NeuralNetwork = nullptr;
		else
			return;
	}

		const OpenNN::NeuralNetwork::ProjectType NetworkType = static_cast<OpenNN::NeuralNetwork::ProjectType>(SimpleArchitecture.Type);

		const Index InputCount = static_cast<Index>(SimpleArchitecture.Inputs.Num());
		const Index NeuronCount = static_cast<Index>(SimpleArchitecture.NeuronCount);
		const Index OutputCount = static_cast<Index>(SimpleArchitecture.Outputs.Num());
	
		Tensor<string, 1> InputNames(InputCount);
		for (Index i = 0; i < InputCount; i++)
		{
			const string CurrentName = TCHAR_TO_UTF8(*SimpleArchitecture.Inputs[i]);
			InputNames[i] = CurrentName;
		}
	
		Tensor<string, 1> OutputNames(OutputCount);
		for (Index i = 0; i < OutputCount; i++)
		{
			const string CurrentName = TCHAR_TO_UTF8(*SimpleArchitecture.Outputs[i]);
			OutputNames[i] = CurrentName;
		}

		Tensor<Index, 1> SimpleTensor(3);
		SimpleTensor.setValues({InputCount, NeuronCount, OutputCount});
	
		NeuralNetwork = make_shared<OpenNN::NeuralNetwork>(NetworkType, SimpleTensor);
		dynamic_cast<OpenNN::PerceptronLayer*>(NeuralNetwork->get_trainable_layers_pointers()(0))->set_synaptic_weights_glorot(); //TODO WTF?

	/*
        const Tensor<Descriptives, 1> inputs_descriptives = data_set.scale_input_variables_minimum_maximum();
        const Tensor<Descriptives, 1> targets_descriptives = data_set.scale_target_variables_minimum_maximum();

        // Neural network
        const Index inputs_number = data_set.get_input_variables_number();
        const Index hidden_neurons_number = variables;
        const Index outputs_number = data_set.get_target_variables_number();

        Tensor<Index, 1> architecture(3);

        architecture.setValues({inputs_number, hidden_neurons_number, outputs_number});
        NeuralNetwork neural_network(NeuralNetwork::Approximation, architecture);
        ScalingLayer* scaling_layer_pointer = neural_network.get_scaling_layer_pointer();
        scaling_layer_pointer->set_descriptives(inputs_descriptives);
*/
	
}

template <class I, class O>
bool UNeuralNetwork::CalculateOutputs(TArray<I> InputValues, TArray<O>& OutputValues)
{
	if (NeuralNetwork == nullptr)
		return false;

	if (NetworkStatus == EGeneratedType::Simple)
	{
		const Index InputCount = static_cast<Index>(SimpleArchitecture.Inputs.Num());
		const Index OutputCount = static_cast<Index>(SimpleArchitecture.Outputs.Num());
	
		// TODO: Store the input/output tensors and then update as necessary
		Tensor<I, 2> Inputs(1, InputCount);
		Tensor<O, 2> Outputs(1, OutputCount);

		InputValues.Empty();
		for (Index i = 0; i < InputCount; i++)
		{
			Inputs(0, i) = InputValues[i];
		}
		
		Outputs = NeuralNetwork->calculate_outputs(Inputs);
		
		OutputValues.Empty();
		for (Index i = 0; i < OutputCount; i++)
		{
			OutputValues.Add(dynamic_cast<O>(Outputs(0, i)));
		}

		return true;
	}

	return false;
}

// UE_LOG(LogNeuralCore, Log, TEXT(""));
