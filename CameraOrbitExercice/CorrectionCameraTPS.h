// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CorrectionCameraBehaviour.h"
#include "CorrectionCameraTPS.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCorrectionCameraTPS : public UCorrectionCameraBehaviour
{
	GENERATED_BODY()

public:	
	UCorrectionCameraTPS();

protected:
	virtual void BeginPlay() override;

protected:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveTo() override;
	virtual void RotateTo() override;
		
	void Debug();
};
