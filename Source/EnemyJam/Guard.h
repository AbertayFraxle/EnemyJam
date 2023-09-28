// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Guard.generated.h"

UCLASS()
class ENEMYJAM_API AGuard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGuard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<AActor*> nodes;
	
	unsigned int currentNode;
};
