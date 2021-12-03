// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMainCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed , this, &AMainCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed , this, &AMainCharacter::SetCrouch);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released , this, &AMainCharacter::StandUp);
	PlayerInputComponent->BindAction(TEXT("Crawl"), IE_Pressed , this, &AMainCharacter::SetCrawl);
	PlayerInputComponent->BindAction(TEXT("Crawl"), IE_Released , this, &AMainCharacter::StandUp);
}

void AMainCharacter::MoveForward(float Axis){
	AddMovementInput(GetActorForwardVector() * Axis);
}
void AMainCharacter::MoveRight(float Axis){
	AddMovementInput(GetActorRightVector() * Axis);
}
void AMainCharacter::SetCrouch(){
	AMainCharacter::GetCharacterMovement()->MaxWalkSpeedCrouched = 0;
	AMainCharacter::CrouchedEyeHeight = 32;
	AMainCharacter::Crouch();	
}
void AMainCharacter::SetCrawl(){
	AMainCharacter::GetCharacterMovement()->MaxWalkSpeedCrouched = CrawlSpeed;
	AMainCharacter::CrouchedEyeHeight = CrawlHeight;
	AMainCharacter::Crouch();	
}
void AMainCharacter::StandUp(){
	AMainCharacter::UnCrouch();	
}

