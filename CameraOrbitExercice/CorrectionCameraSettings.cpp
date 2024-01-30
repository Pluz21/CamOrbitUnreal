// Fill out your copyright notice in the Description page of Project Settings.


#include "CorrectionCameraSettings.h"

// Sets default values for this component's properties
UCorrectionCameraSettings::UCorrectionCameraSettings()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCorrectionCameraSettings::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCorrectionCameraSettings::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCorrectionCameraSettings::SetCanMove(bool _value)
{
	canMove = _value;
}

void UCorrectionCameraSettings::SetCanRotate(bool _value)
{
	canRotate = _value;
}

void UCorrectionCameraSettings::SetCameraStatus(bool _status)
{
	camera->SetActive(_status);
}

void UCorrectionCameraSettings::InitCam(UCameraComponent* _cam)
{
	if (!_cam)return;
	camera = _cam;
}

