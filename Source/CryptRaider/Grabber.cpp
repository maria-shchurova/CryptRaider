// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	float Damage; //memory for the variable is created
	if(HasDamage(Damage))
	{
		PrintDamage(Damage);
	}	
}

void UGrabber::PrintDamage(const float& Damage) //no copying but referencing the address in the memory
{
	//Damage = newNumber - will change the original vlaue too, because it is the same adress
	//when const, it woun't compile the line above
	//const prevents from accidental reassigning values to the variable
	UE_LOG(LogTemp, Display, TEXT("Damage: %f"), Damage);
}

bool UGrabber::HasDamage(float& OutDamage) //no copying but referencing the address in the memory
{
	OutDamage = 5;
	return true;
}

