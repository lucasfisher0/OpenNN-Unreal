#pragma once

#include "CoreMinimal.h"
#include "NeuralCore.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BTTaskNode.h"

#include "NeuralClasses.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogOpenNN, Log, All);

/*
UCLASS()
class UNREALONN_API UNeuralTask : public UBTTaskNode
{
	GENERATED_BODY();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnMessage(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, FName Message, int32 RequestID, bool bSuccess) override;
	
};

class UNeuralService : public UBTService
{
	protected:
		virtual void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
		virtual void OnCeaseRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
		virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
		virtual void OnSearchStart(FBehaviorTreeSearchData& SearchData) override;
};
*/