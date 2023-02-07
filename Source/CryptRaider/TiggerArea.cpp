// Fill out your copyright notice in the Description page of Project Settings.


#include "TiggerArea.h"

void UTiggerArea::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp, Display, TEXT("Trigger Component reports duty"));
}


