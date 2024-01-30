// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CorrectionCameraBehaviour.generated.h"

class UCorrectionCameraSettings;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCorrectionCameraBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
protected:
	UCorrectionCameraBehaviour();
	UPROPERTY(EditAnywhere)
	FString id = "camera";
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCorrectionCameraSettings> settings = nullptr;

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Debug();

public:	
	void InitItem();
	virtual void Enable();
	virtual void Disable();
	UFUNCTION()
	virtual void MoveTo();        // = 0   virtual pure
	UFUNCTION()
	virtual void RotateTo();
		
};
