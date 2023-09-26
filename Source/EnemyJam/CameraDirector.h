// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "CameraDirector.generated.h"

UCLASS()
class ENEMYJAM_API ACameraDirector : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraDirector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ACameraActor> camera;

	TArray<AActor*> FoundActors;

	APlayerController* controller;

	int selection;

	void ChangeCam(const struct FInputActionValue& ActionValue);
};
