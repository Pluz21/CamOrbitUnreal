// Fill out your copyright notice in the Description page of Project Settings.


#include "CM_CameraSettings.h"

// Sets default values for this component's properties
UCM_CameraSettings::UCM_CameraSettings()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCM_CameraSettings::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("VALID CAMERA : %b"), CheckIsValidCamera());
	InitCameraRenderer(GetOwner()->GetComponentByClass<UCameraComponent>());
	FVector _testLocation = GetCurrentPosition();
	UE_LOG(LogTemp, Warning, TEXT("_testLocation is : %s"), *_testLocation.ToString());
	// ...
	
}


// Called every frame
void UCM_CameraSettings::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

