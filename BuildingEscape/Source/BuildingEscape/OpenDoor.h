// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	float InitialYaw;
	float CurrentYaw;
	bool OpenDoorSound = false;
	bool CloseDoorSound = true;
	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;

	float DoorLastOpen;
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.5f;
	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 0.8f;
	UPROPERTY(EditAnywhere)
	float DoorShuttingSpeed = 2.0f;
	UPROPERTY(EditAnywhere)
	float MassToOpen = 50.0f;

	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudioComponent();
};
