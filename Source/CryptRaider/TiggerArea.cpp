// Fill out your copyright notice in the Description page of Project Settings.


#include "TiggerArea.h"

UTiggerArea::UTiggerArea()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTiggerArea::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp, Display, TEXT("Trigger Component reports duty"));
}

void UTiggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    UE_LOG(LogTemp, Display, TEXT("Tick Component reports duty"));

}

