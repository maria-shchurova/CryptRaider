// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Mover.h"
#include "TiggerArea.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDER_API UTiggerArea : public UBoxComponent
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
public:	
	UTiggerArea();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMover* Mover);

private:
	UPROPERTY(EditAnywhere)
	FName ActorTag;

	AActor* GetAcceptableActor() const;

	UMover* Mover;
};
