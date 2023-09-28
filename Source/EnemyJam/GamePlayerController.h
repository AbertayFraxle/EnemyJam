// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ENEMYJAM_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	UPROPERTY()
	class UInputMappingContext* mappingContext;

	UPROPERTY()
	class UInputAction* changeAction;
	class UInputAction* moveAction;


};
