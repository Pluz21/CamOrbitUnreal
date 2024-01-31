// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CorrectionCameraBehaviour.h"
#include "CorrectionCameraOrbit.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCorrectionCameraOrbit : public UCorrectionCameraBehaviour
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) float radius = 100;
	UPROPERTY(EditAnywhere) float angle = 1;



public:	
	UCorrectionCameraOrbit();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveTo() override;
	virtual void RotateTo() override;
	
	float SetAngle(float _angle, const float& _speed);

	void Debug();
};
