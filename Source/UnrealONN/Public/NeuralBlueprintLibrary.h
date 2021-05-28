﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "NeuralClasses.h"
#include "NeuralBlueprintLibrary.generated.h"

/**
 * Implements miscellaneous functions into Blueprint.
 */
UCLASS(meta=(ScriptName="OpenNN Library"))
class UNREALONN_API UNeuralBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/* Blueprint Functions here */

	UFUNCTION(BlueprintCallable)
	UNeuralNetwork* NewNeuralNetworkObject(UObject* Outer);
};
