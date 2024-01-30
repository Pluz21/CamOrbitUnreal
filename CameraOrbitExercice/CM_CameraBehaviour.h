// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CM_CameraSettings.h"
#include "CM_CameraBehaviour.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCM_CameraBehaviour : public UActorComponent
{
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateCameraEvent);

	UPROPERTY()
	FUpdateCameraEvent onUpdateCamera;

	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCM_CameraSettings> cameraSettings;
public:
	UPROPERTY(EditAnywhere)
	FString ID;
	UPROPERTY(EditAnywhere)
	bool isValidItem = false;
	//UPROPERTY(EditAnywhere)
	//FOffsetCamera offsetCamera;

public:	
	// Sets default values for this component's properties
	UCM_CameraBehaviour();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Init();

	virtual FString GetID() { return ID; }
	virtual bool CheckIsValidItem() { if (!ID.IsEmpty()) return true; return false; }
	
	UFUNCTION()
	virtual void CameraMoveTo();
	UFUNCTION()
	virtual void CameraRotateTo();

	virtual FVector GetPosition();
	virtual FRotator GetRotation();

	void Enable();
	void Disable();
	virtual void Debug();
	
};
