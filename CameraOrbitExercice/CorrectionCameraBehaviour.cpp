         // Fill out your copyright notice in the Description page of Project Settings.


#include "CorrectionCameraBehaviour.h"
#include "CorrectionCameraSettings.h"

// Sets default values for this component's properties
UCorrectionCameraBehaviour::UCorrectionCameraBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Constructor Behaviour "));

	// ...
}


void UCorrectionCameraBehaviour::BeginPlay()
{
	Super::BeginPlay();
	InitItem();
	
}


void UCorrectionCameraBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Debug();
}

void UCorrectionCameraBehaviour::Debug()
{
	DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), 10, 25, FColor::Red, false, 0, 0, 2);
}

void UCorrectionCameraBehaviour::InitItem()
{
	settings = GetOwner()->GetComponentByClass<UCorrectionCameraSettings>();
	if (!settings)return;
	GetWorld()->GetFirstPlayerController()->SetViewTarget(GetOwner()); // Which camera are we going to look from 
	settings.Get()->InitCam(GetOwner()->GetComponentByClass<UCameraComponent>());
}

void UCorrectionCameraBehaviour::Enable()
{
}

void UCorrectionCameraBehaviour::Disable()
{
}

void UCorrectionCameraBehaviour::MoveTo()
{
}

void UCorrectionCameraBehaviour::RotateTo()
{
}

