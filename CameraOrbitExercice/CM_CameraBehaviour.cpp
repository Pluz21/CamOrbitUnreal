// Fill out your copyright notice in the Description page of Project Settings.


#include "CM_CameraBehaviour.h"
#include "CM_CameraSettings.h"
// Sets default values for this component's properties
UCM_CameraBehaviour::UCM_CameraBehaviour()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCM_CameraBehaviour::BeginPlay()
{
	Super::BeginPlay();
	Init();
	// ...
	
}


// Called every frame
void UCM_CameraBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	onUpdateCamera.Broadcast();
	Debug();
	//onUpdateCamera.AddDynamic(this, &UCM_CameraBehaviour())
	// ...
}

void UCM_CameraBehaviour::Init()
{
	onUpdateCamera.AddDynamic(this, &UCM_CameraBehaviour::CameraMoveTo);
	onUpdateCamera.AddDynamic(this, &UCM_CameraBehaviour::CameraRotateTo);
	cameraSettings = GetOwner()->GetComponentByClass<UCM_CameraSettings>();;
	if (!CheckIsValidItem())
	{

		UE_LOG(LogTemp, Warning, TEXT("Not a Valid ID!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cam behaviour has a valid ID!"));

	}

}

void UCM_CameraBehaviour::CameraMoveTo()
{
		UE_LOG(LogTemp, Warning, TEXT("CameraMoveTo called from event"));
}

void UCM_CameraBehaviour::CameraRotateTo()
{
}

FVector UCM_CameraBehaviour::GetPosition()
{
	return FVector();
}

FRotator UCM_CameraBehaviour::GetRotation()
{
	return FRotator();
}

void UCM_CameraBehaviour::Enable()
{
	cameraSettings->SetCanMoveCamera(true);
	cameraSettings->SetCanRotateCamera(true);
	cameraSettings->SetCameraRenderer(true);
}

void UCM_CameraBehaviour::Disable()
{
	cameraSettings->SetCanMoveCamera(false);
	cameraSettings->SetCanRotateCamera(false);
	cameraSettings->SetCameraRenderer(false);
}

void UCM_CameraBehaviour::Debug()
{
	DrawDebugLine(GetWorld(), cameraSettings->GetTargetPosition(), cameraSettings->GetCurrentPosition(),FColor::Yellow,false,0,0,3);
	DrawDebugSphere(GetWorld(), cameraSettings->GetTargetPosition(), 70, 12, FColor::Green, false, 0, 0, 1.5f);
	DrawDebugSphere(GetWorld(), cameraSettings->GetCurrentPosition(), 60, 12, FColor::Red, false, 0, 0, 1.5f);
}

