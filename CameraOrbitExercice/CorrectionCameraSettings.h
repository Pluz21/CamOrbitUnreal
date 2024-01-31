
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "CorrectionCameraSettings.generated.h"

USTRUCT()
struct FOffset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) float xOffset = 0;
	UPROPERTY(EditAnywhere) float yOffset = 0;
	UPROPERTY(EditAnywhere) float zOffset = 0;
	UPROPERTY(EditAnywhere) bool isLocal = false;
	FVector GetOffset(AActor* _target) 
	{
		if (!_target)return FVector(0);
		return isLocal ? LocalOffset(_target):WorldOffset(_target);
	}
	FVector LocalOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		FVector _x = _target->GetActorForwardVector() * xOffset;
		FVector _y = _target->GetActorRightVector() * yOffset;
		FVector _z = _target->GetActorUpVector() * zOffset;
		return _target->GetActorLocation() +  _x + _y + _z;
	}

	FVector WorldOffset(AActor* _target)
	{
		if (!_target)return FVector(0);
		return _target->GetActorLocation() + FVector(xOffset,yOffset,zOffset);
		
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CAMERAORBITEXERCICE_API UCorrectionCameraSettings : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<AActor> target = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> camera;
	UPROPERTY(EditAnywhere)	float moveSpeed = 50;
	UPROPERTY(EditAnywhere) float rotateSpeed = 50;
	UPROPERTY(EditAnywhere) bool canMove = true;
	UPROPERTY(EditAnywhere) bool canRotate = true;
	UPROPERTY(EditAnywhere) FOffset offset = FOffset();



public:
	// Sets default values for this component's properties
	UCorrectionCameraSettings();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetTarget() { return target; }
	UCameraComponent* GetCamera() { return camera; }
	FVector GetTargetLocation() { return target ? target->GetActorLocation() : FVector(0);}
	FVector GetCurrentPosition() { return GetOwner()->GetActorLocation();}
	FRotator GetTargetRotation() { return target ? target->GetActorRotation() : FRotator(0);}
	FRotator GetCurrentRotation() { return GetOwner()->GetActorRotation(); }
	float GetMoveSpeed() { return moveSpeed; }
	float GetRotateSpeed() { return rotateSpeed; }
	bool GetCanMove() { return canMove; }
	bool GetCanRotate() { return canRotate; }
	FOffset& GetOffset() { return offset; }


	void SetCanMove(bool _value);
	void SetCanRotate(bool _value);
	void SetCameraStatus(bool _status);
	void InitCam(UCameraComponent* _cam);
};
