// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CM_CameraBehaviour.h"
#include "CM_CameraTPS.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCM_CameraTPS : public UCM_CameraBehaviour
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCM_CameraTPS();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CameraMoveTo() override;
	void CameraRotateTo() override;

	FVector GetPosition() override;
	FRotator GetRotation() override;
	
	void Debug() override;
		
};
