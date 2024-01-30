// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"

#include "CM_CameraSettings.generated.h"

USTRUCT(BlueprintType)
struct FOffsetCamera
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "X offset", meta = (ClampMin = "-1000", ClampMax = "1000"))
	float xOffset = 0;
	UPROPERTY(EditAnywhere, Category = "Y offset", meta = (ClampMin = "-1000", ClampMax = "1000"))
	float yOffset = 0;
	UPROPERTY(EditAnywhere, Category = "Z offset", meta = (ClampMin = "-1000", ClampMax = "1000"))
	float zOffset = 0;
	UPROPERTY(EditAnywhere)
	bool isLocalOffset;

	FVector GetOffSet(AActor* _target)
	{
		if (!_target) return FVector(0);
		if (isLocalOffset) return GetWorldOffset(_target);return FVector(0); // might need double check
	}
	FVector GetLookAtOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		return isLocalOffset ? GetLocalLookAtOffset(_target) : GetWorldLookAtOffset(_target);
	}

	FVector GetLocalLookAtOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		FVector _x = _target->GetActorForwardVector();
		FVector _y = _target->GetActorRightVector();
		FVector _z = _target->GetActorUpVector();
		return _x + _y + _z;
	}
	FVector GetWorldLookAtOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		FVector _worldLookAtOffset = FVector(xOffset, yOffset, zOffset);
		return _worldLookAtOffset;
	}

	FVector GetWorldOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		FVector _worldOffset = _target->GetActorLocation() +
			FVector(xOffset, yOffset, zOffset);
		return _worldOffset;
	}

	bool GetIsLocalOffset() { return isLocalOffset; }

};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCM_CameraSettings : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCM_CameraSettings();
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> cameraRenderer = nullptr;
	UPROPERTY(EditAnywhere, Category = "Offset Camera")
	FOffsetCamera offsetCamera = FOffsetCamera();
	UPROPERTY(EditAnywhere, Category = "Offset Camera")
	FOffsetCamera lookAtOffset = FOffsetCamera();


	UPROPERTY(EditAnywhere, Category = "Camera Speed", meta = (ClampMin = "-4", ClampMax = "4"))
	float cameraMoveSpeed = 1; // Might need adjustment
	UPROPERTY(EditAnywhere, Category = "Camera Speed", meta = (ClampMin = "-4", ClampMax = "4"))
	float cameraRotateSpeed = 1;
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> target = nullptr;

	UPROPERTY(EditAnywhere)
	bool isValidCamera = false;
	
	UPROPERTY(EditAnywhere)
	bool canMoveCamera = true; 
	UPROPERTY(EditAnywhere)
	bool canRotateCamera = true; 

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetTarget() { return target; }
	FOffsetCamera& GetOffsetCamera() { return offsetCamera; }
	FOffsetCamera& GetLookAtOffset() {return lookAtOffset; }
	FVector GetCurrentPosition() { if (!CheckIsValidCamera()) return FVector(0); return GetOwner()->GetActorLocation(); }
	FRotator GetCurrentRotation() { if (!CheckIsValidCamera())return FRotator(0); return GetOwner()->GetActorRotation(); }
	FVector GetTargetPosition() { if (!CheckIsValidCamera())return FVector(0); return target->GetActorLocation();}
	// Might need to change to GetOwner()->GetActorLocation() for the camera location

	bool CheckIsValidCamera() { if (cameraRenderer == nullptr||target == nullptr)return false; return true; }  // Issue here bool is not true when checking
	bool GetCanMoveCamera() { return canMoveCamera; }
	bool GetCanRotateCamera() { return canRotateCamera; }
	
	float GetCameraMoveSpeed() { return cameraMoveSpeed; }
	float GetCameraRotateSpeed() { return cameraRotateSpeed; }

	void SetCanMoveCamera(bool _value) { canMoveCamera = _value; }
	void SetCanRotateCamera(bool _value) { canRotateCamera = _value; }
	void InitCameraRenderer(UCameraComponent* _camera) { cameraRenderer = _camera; }
	void SetCameraRenderer(bool _status) { if (!isValidCamera)return; cameraRenderer->SetActive(_status);}
	//Missing the setCameraRender, might not be needed;
};
