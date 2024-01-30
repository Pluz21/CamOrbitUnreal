// Fill out your copyright notice in the Description page of Project Settings.


#include "CM_CameraTPS.h"

// Sets default values for this component's properties
UCM_CameraTPS::UCM_CameraTPS()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCM_CameraTPS::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("target is : %s"), *cameraSettings->GetTarget()->GetName());

	
	//Init();
	// ...
	
}


// Called every frame
void UCM_CameraTPS::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCM_CameraTPS::CameraMoveTo()
{
	if (!cameraSettings->CheckIsValidCamera() || !cameraSettings->GetCanMoveCamera())
	{
		UE_LOG(LogTemp, Warning, TEXT("early return inside cameramoveto!"));

	return;
	}
	GetOwner()->SetActorLocation(GetPosition());

}

void UCM_CameraTPS::CameraRotateTo()
{
	if (!cameraSettings->CheckIsValidCamera() || !cameraSettings->GetCanRotateCamera())return;
	GetOwner()->SetActorRotation(GetRotation());

}

FVector UCM_CameraTPS::GetPosition()
{
	
	FVector _moveDirection = FMath::VInterpTo(cameraSettings->GetCurrentPosition(),
		cameraSettings->offsetCamera.GetOffSet(cameraSettings->GetTarget()) + (cameraSettings->GetTargetPosition()),
		GetWorld()->DeltaTimeSeconds ,cameraSettings->GetCameraMoveSpeed() * 1); // interpspeed might need tweaking
	return _moveDirection;

	
		

}

FRotator UCM_CameraTPS::GetRotation()
{
	FRotator _newRotation = FMath::RInterpTo(cameraSettings->GetCurrentRotation(),
		cameraSettings->offsetCamera.GetLookAtOffset(cameraSettings->GetTarget()).Rotation(),
		GetWorld()->DeltaTimeSeconds, cameraSettings->GetCameraRotateSpeed() * 1);
	return _newRotation;
}

void UCM_CameraTPS::Debug()
{
	Super::Debug();
	FVector _final = cameraSettings->offsetCamera.GetOffSet(cameraSettings->GetTarget());
	UE_LOG(LogTemp, Warning, TEXT("Final pos vector is %s"), *_final.ToString());

	DrawDebugLine(GetWorld(), cameraSettings->GetCurrentPosition(), _final,FColor::Cyan);
	DrawDebugBox(GetWorld(), _final,FVector::OneVector * 60, FColor::Cyan, 0,0,0,3);
}

