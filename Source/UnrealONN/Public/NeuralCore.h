// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NeuralStructs.h"

#include "Windows/WindowsSystemIncludes.h"
#include "../../ThirdParty/opennn/opennn/opennn.h"
#include "NeuralCore.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogNeuralCore, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventStartTraining);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FEventStopTraining);

UENUM(BlueprintType)
enum class EGeneratedType : uint8
{
	None,
	Simple,
	Custom
};

UENUM(BlueprintType)
enum class ECalculationType : uint8
{
	Int32,
	Int64,
	Float
};

/**
*	Neural Network Object
*	This a configured neural network. When trained, this object will be initiated and
*	perform calculations on the inputs.
*/
UCLASS(Abstract, Blueprintable, BlueprintType)
class UNREALONN_API UNeuralNetwork : public UObject
{
	GENERATED_BODY()

/* Generation */
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAutoGenerate = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FSimpleNeuralNetwork SimpleArchitecture;
	UFUNCTION(BlueprintCallable)
	void GenerateSimpleNetwork(bool bForceRegenerate);

	EGeneratedType NetworkStatus = EGeneratedType::None;

protected:
	shared_ptr<OpenNN::NeuralNetwork> NeuralNetwork;

/* Input */
public:
	template <class I, class O>
	bool CalculateOutputs(TArray<I> InputValues, TArray<O>& OutputValues);


	
	/* Data Set */
public:
protected:



public:
	UFUNCTION(BlueprintPure)
	bool HasValidNetwork() { return false; }


	/* Training Strategy */
	public:
	UPROPERTY(BlueprintAssignable)
	FEventStartTraining OnStartTraining;
	UPROPERTY(BlueprintAssignable)
	FEventStopTraining OnStopTraining;

	UFUNCTION(BlueprintCallable)
	void PerformTraining() {};
	
	protected:
	unique_ptr<OpenNN::TrainingStrategy> TrainingStrategy;
};



