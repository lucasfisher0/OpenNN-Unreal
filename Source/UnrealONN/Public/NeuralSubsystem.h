// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "NeuralClasses.h"

#include "NeuralSubsystem.generated.h"

/**
 *	SUBSYSTEM - Maintains all current Neural Network objects
 */
UCLASS()
class UNREALONN_API UNeuralSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly)
	TArray<UNeuralNetwork*> NetworkObjects;
};
