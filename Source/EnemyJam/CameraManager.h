// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "CameraManager.generated.h"

UCLASS()
class ENEMYJAM_API ACameraManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACameraActor* camera1;

	APlayerController* controller;


};
