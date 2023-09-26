// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023


#include "CameraDirector.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GamePlayerController.h"
#include "InputMappingContext.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();

	controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), camera, FoundActors);

	selection = 0;

	controller->SetViewTarget(FoundActors[selection]);
	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraDirector::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//cast the input component to enhanced input
	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	//store the player controller to be used
	AGamePlayerController* GPC = Cast<AGamePlayerController>(Controller);

	check(EIC && GPC);

	EIC->BindAction(GPC->changeAction, ETriggerEvent::Started, this, &ACameraDirector::ChangeCam);

	ULocalPlayer* localPlayer = GPC->GetLocalPlayer();
	check(localPlayer);
	UEnhancedInputLocalPlayerSubsystem* subsystem =
		localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	check(subsystem);
	subsystem->ClearAllMappings();
	subsystem->AddMappingContext(GPC->mappingContext, 0);

}

void ACameraDirector::ChangeCam(const struct FInputActionValue& ActionValue) {

	selection+= ActionValue.Get<FInputActionValue::Axis1D>();

	//clamp the selection of the camera between 0 and the last camera in the scene
	if (selection < 0) {
		selection = 0;
	}
	else if (selection > FoundActors.Num() - 1) {
		selection = FoundActors.Num() - 1;
	}

	controller->SetViewTarget(FoundActors[selection]);
}