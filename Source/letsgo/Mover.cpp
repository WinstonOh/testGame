// Fill out your copyright notice in the Description page of Project Settings.


#include "Mover.h"
#include "Math/UnrealMathUtility.h"



// Sets default values for this component's properties
UMover::UMover()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMover::BeginPlay()
{
	Super::BeginPlay();

	
	StartLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Get location at inni of begin tick function
	FVector CurrentLocation = GetOwner()->GetActorLocation();

	//update location with values of the product of speed and fps
	CurrentLocation = CurrentLocation + (MoveSpeed * DeltaTime);
	GetOwner()->SetActorLocation(CurrentLocation);

	//check if platform has moved too far
	float MovedDifference = FVector::Dist(StartLocation, CurrentLocation);

	 //if yes return with the direction value of speed negated
	if (MovedDifference > MovedDistance) {
		FVector MoveDirection = MoveSpeed.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection* MovedDistance);
		GetOwner()->SetActorLocation(StartLocation);
		MoveSpeed =-MoveSpeed;
	}


}

	
	
	
	


