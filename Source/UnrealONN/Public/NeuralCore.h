﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "../../ThirdParty/opennn/opennn/opennn.h"
#include "NeuralCore.generated.h"

/**
 * 
 */
UCLASS()
class UNREALONN_API UNeuralSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY();

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
};