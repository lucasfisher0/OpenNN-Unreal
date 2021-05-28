// Fill out your copyright notice in the Description page of Project Settings.


#include "NeuralBlueprintLibrary.h"

UNeuralNetwork* UNeuralBlueprintLibrary::NewNeuralNetworkObject(UObject* Outer = (UObject*)GetTransientPackage())
{
	UNeuralNetwork* NewNeuralNetworkObject = NewObject<UNeuralNetwork>(Outer);
	return NewNeuralNetworkObject;
}
