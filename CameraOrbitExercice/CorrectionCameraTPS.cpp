// Fill out your copyright notice in the Description page of Project Settings.

#include "CorrectionCameraTPS.h"
#include "CorrectionCameraSettings.h"
#include <Kismet/KismetMathLibrary.h>

UCorrectionCameraTPS::UCorrectionCameraTPS()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UCorrectionCameraTPS::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Init TPS"));

	// ...
	
}


void UCorrectionCameraTPS::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveTo();
	RotateTo();
	Debug();

	// ...
}

void UCorrectionCameraTPS::MoveTo()
{
	if (!settings->GetCanMove())return;
	FVector _location = UKismetMathLibrary::VInterpTo_Constant(GetOwner()->
											GetActorLocation(),settings->
											GetOffset().GetOffset(settings->
											GetTarget()),GetWorld()->
											DeltaTimeSeconds,settings->
											GetMoveSpeed());
	GetOwner()->SetActorLocation(_location);
}

void UCorrectionCameraTPS::RotateTo()
{
	if (!settings->GetCanRotate())return;
	FRotator _rotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->
												GetActorLocation(),
												settings->GetTargetLocation());
												FRotator _newRot = UKismetMathLibrary::RInterpTo_Constant(GetOwner()->
												GetActorRotation(),
												_rotation,GetWorld()->DeltaTimeSeconds,
												settings->	GetRotateSpeed());
												GetOwner()->SetActorRotation(_newRot);
}

void UCorrectionCameraTPS::Debug()
{
	if (!settings->GetTarget())return;
	DrawDebugBox(GetWorld(), settings->GetOffset().GetOffset(settings->GetTarget()), FVector::OneVector * 60, FColor::Cyan, 0, 0, 3);

	DrawDebugSphere(GetWorld(), settings->GetOffset().GetOffset(settings->GetTarget()), 70, 25, FColor::Green, 0, 0, 0, 2);
	DrawDebugLine(GetWorld(), settings->GetCurrentPosition(), settings->GetOffset().GetOffset(settings->GetTarget()), FColor::Magenta, 0, 0, 0, 2);
}

