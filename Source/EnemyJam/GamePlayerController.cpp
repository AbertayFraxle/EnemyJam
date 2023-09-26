// Fraser McCann + Callum Shepherd AGDS FRESHERS JAM 2023


#include "GamePlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"

void AGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//create mapping context to store keybinds with the corresponding actions
	mappingContext = NewObject<UInputMappingContext>(this);

	//create actions
	changeAction = NewObject<UInputAction>(this);

	//set changeAction to return a float
	changeAction->ValueType = EInputActionValueType::Axis1D;

	//map changeAction to E for value of 1 and Q for value of -1
	mappingContext->MapKey(changeAction, EKeys::E);

	FEnhancedActionKeyMapping& mapping = mappingContext->MapKey(changeAction, EKeys::Q);
	UInputModifierNegate* negate = NewObject<UInputModifierNegate>(this);

	mapping.Modifiers.Add(negate);
	
}