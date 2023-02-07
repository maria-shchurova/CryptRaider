// Fill out your copyright notice in the Description page of Project Settings.


#include "TiggerArea.h"

UTiggerArea::UTiggerArea()
{
    PrimaryComponentTick.bCanEverTick = true;    
}

void UTiggerArea::BeginPlay()
{
	Super::BeginPlay();
}

void UTiggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    if(Actors.Num() > 0)
    {
        UE_LOG(LogTemp, Display, TEXT("Fisr Overlapped Actor is %s"), *Actors[0]->GetActorNameOrLabel());
    }
}

