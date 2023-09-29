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
	moveAction = NewObject<UInputAction>(this);

	//set changeAction to return a float
	changeAction->ValueType = EInputActionValueType::Axis1D;

	//map changeAction to E for value of 1 and Q for value of -1
	mappingContext->MapKey(changeAction, EKeys::E);

	FEnhancedActionKeyMapping& mapping = mappingContext->MapKey(changeAction, EKeys::Q);
	UInputModifierNegate* negate = NewObject<UInputModifierNegate>(this);

	mapping.Modifiers.Add(negate);
	


	moveAction->ValueType = EInputActionValueType::Axis3D;

	//map changeAction to E for value of 1 and Q for value of -1

	FEnhancedActionKeyMapping& mapping1 = mappingContext->MapKey(moveAction, EKeys::W);
	UInputModifierSwizzleAxis* swizzle = NewObject<UInputModifierSwizzleAxis>(this);
	swizzle->Order = EInputAxisSwizzle::YXZ;

	mapping1.Modifiers.Add(swizzle);

	FEnhancedActionKeyMapping& mapping2 = mappingContext->MapKey(moveAction, EKeys::S);
	mapping2.Modifiers.Add(swizzle);
	mapping2.Modifiers.Add(negate);

	FEnhancedActionKeyMapping& mapping3 = mappingContext->MapKey(moveAction, EKeys::A);

	UInputModifierSwizzleAxis* swizzle2 = NewObject<UInputModifierSwizzleAxis>(this);
	swizzle2->Order = EInputAxisSwizzle::XZY;


	mapping3.Modifiers.Add(swizzle2);
	mapping3.Modifiers.Add(negate);

	mappingContext->MapKey(moveAction, EKeys::D);

	


}