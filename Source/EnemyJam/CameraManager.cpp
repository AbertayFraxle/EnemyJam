// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023


#include "CameraManager.h"

// Sets default values
ACameraManager::ACameraManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//initialise the timer
	timer = 0;
	
}

// Called when the game starts or when spawned
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();

	controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), camera, FoundActors);

	selection = 0;

	controller->SetViewTarget(FoundActors[selection]);


}

// Called every frame
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//get input in the tick event as EnhancedInput system scares me currently
	if (timer <= 0) {
		if (controller->IsInputKeyDown("E")) {
			selection++;
			timer = 0.2f;
		}
		else if (controller->IsInputKeyDown("Q")) {
			selection--;
			timer = 0.2f;
		}
		
	}
	else {
		timer -= DeltaTime;
	}

	//clamp the selection of the camera between 0 and the last camera in the scene
	if (selection < 0) {
		selection = 0;
	}
	else if (selection > FoundActors.Num()-1) {
		selection = FoundActors.Num()-1;
	}
	
	//set the game target camera to the camera selected
	controller->SetViewTarget(FoundActors[selection]);
}

