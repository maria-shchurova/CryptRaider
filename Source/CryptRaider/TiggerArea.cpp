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

    AActor* Actor = GetAcceptableActor();
    if(Actor == nullptr)
    {
        if(Mover)
        {
            Mover->SetShouldMove(false);
        }
    }
    else
    {
        if(Mover != nullptr)
        {
            UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent()); 
            if(Component)
            {
                Component->SetSimulatePhysics(false);
            }
            Component->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
            Mover->SetShouldMove(true);            
        }
    }
}

void UTiggerArea::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

AActor* UTiggerArea::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    for(AActor* Actor : Actors) //like: foreach AActor Actir in Actors
    {
        if(Actor->ActorHasTag(ActorTag) && !Actor->ActorHasTag("Grabbed"))
        {
            return Actor;
        }
    }

    return nullptr;
}

