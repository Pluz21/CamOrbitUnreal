// Fill out your copyright notice in the Description page of Project Settings.


#include "CorrectionCameraOrbit.h"
#include "CorrectionCameraSettings.h"
#include <Kismet/KismetMathLibrary.h>

// Sets default values for this component's properties
UCorrectionCameraOrbit::UCorrectionCameraOrbit()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCorrectionCameraOrbit::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCorrectionCameraOrbit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveTo();
	RotateTo();
	// ...
}

void UCorrectionCameraOrbit::MoveTo()
{
	if (!settings->GetCanMove())return;
	angle = SetAngle(angle, settings->GetMoveSpeed());
	float _x = FMath::Sin(FMath::DegreesToRadians(angle)) * radius;
	float _y = FMath::Cos(FMath::DegreesToRadians(angle)) * radius;
	float _z = 0;  // No vertical orbiting only on a 2D circle
	FVector _newLocation = FVector(_x, _y, _z);
	GetOwner()->SetActorLocation(_newLocation + settings->GetTargetLocation());
	
}

void UCorrectionCameraOrbit::RotateTo()
{
	if (!settings->GetCanRotate())return;
	if (!settings->GetCanRotate())return;
	FRotator _rotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->
		GetActorLocation(),
		settings->GetTargetLocation());
	FRotator _newRot = UKismetMathLibrary::RInterpTo_Constant(GetOwner()->
		GetActorRotation(),
		_rotation, GetWorld()->DeltaTimeSeconds,
		settings->GetRotateSpeed());
	GetOwner()->SetActorRotation(_newRot);
}

float UCorrectionCameraOrbit::SetAngle(float _angle, const float& _speed)
{
	_angle += GetWorld()->DeltaTimeSeconds * _speed;
	_angle = _angle > 359 ? 1 : _angle;
	return _angle;
}

void UCorrectionCameraOrbit::Debug()
{
	if (!settings)return;
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), 150, 25, FColor::Emerald, false, 0, 0, 2);
	DrawDebugSphere(GetWorld(), settings->GetTargetLocation(), 150, 25, FColor::Red, false, 0, 0, 2);
}

