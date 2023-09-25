// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023


#include "CameraManager.h"

// Sets default values
ACameraManager::ACameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	



	
}

// Called when the game starts or when spawned
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();

	controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	controller->SetViewTarget(camera1);
}

// Called every frame
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

