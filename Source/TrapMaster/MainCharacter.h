// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class TRAPMASTER_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void MoveForward(float Axis);
	void MoveRight(float Axis);
	void SetCrouch();
	void SetCrawl();
	void StandUp();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crawl")
	float CrawlSpeed = 200;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Crawl")
	float CrawlHeight = 20;
};
