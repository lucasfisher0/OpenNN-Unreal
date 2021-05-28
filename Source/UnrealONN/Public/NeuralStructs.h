#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Misc/Guid.h"

#include "NeuralStructs.generated.h"


/* Data Input 
USTRUCT(BlueprintType)
struct UNREALONN_API FNeuralInputOutputSet
{
	GENERATED_BODY()
	
	FGuid GUID = FGuid::NewGuid();
	const TArray<FBlackboardKeySelector> InputKeys;

	int GetCount() const
	{
		return InputKeys.Num();
	}

	FName GetName(int Index)
	{
		return InputKeys[Index].SelectedKeyName;
	}
};


/* Neural Network - Neurons */
USTRUCT()
struct UNREALONN_API FNeuralNetworkNeuron
{
	GENERATED_BODY()
};

/* Neural Network - Layers */
UENUM(BlueprintType)
enum class ENeuralNetworkLayerTypes : uint8
{	
	Scaling,
	Convolutional,
	Perceptron,
	Pooling,
	Probabilistic,
	LongShortTermMemory UMETA(DisplayName="Long Short Term Memory"),
	Recurrent,
	Unscaling,
	Bounding,
	PrincipalComponents UMETA(DisplayName="Principal Components")
};

USTRUCT(BlueprintType)
struct UNREALONN_API FNeuralNetworkLayer
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	ENeuralNetworkLayerTypes LayerType;

	UPROPERTY(EditAnywhere)
	TArray<FNeuralNetworkNeuron> LayerNeurons;

	uint8 GetNeuronCount() { return LayerNeurons.Num(); }
};

/* Simple Network Generation */
UENUM(BlueprintType)
enum class ENeuralNetworkTypes : uint8
{
	Approximation,
	Classification,
	Forecasting,
	ImageApproximation UMETA(DisplayName="Image Approximation"),
	ImageClassification UMETA(DisplayName="Image Classification"),
};

USTRUCT(BlueprintType)
struct UNREALONN_API FSimpleNeuralNetwork
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ENeuralNetworkTypes Type;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FString> Inputs;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	uint8 NeuronCount = 6;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FString> Outputs;
};

/* Training Strategy */
UENUM()
enum class ELossMethod : uint8
{
	SUM_SQUARED_ERROR,
	MEAN_SQUARED_ERROR,
	NORMALIZED_SQUARED_ERROR,
	MINKOWSKI_ERROR,
	WEIGHTED_SQUARED_ERROR,
	CROSS_ENTROPY_ERROR
};

UENUM()
enum class EOptimizationMethod : uint8
{
	GRADIENT_DESCENT,
	CONJUGATE_GRADIENT,
	QUASI_NEWTON_METHOD,
	LEVENBERG_MARQUARDT_ALGORITHM,
	STOCHASTIC_GRADIENT_DESCENT,
	ADAPTIVE_MOMENT_ESTIMATION
};
