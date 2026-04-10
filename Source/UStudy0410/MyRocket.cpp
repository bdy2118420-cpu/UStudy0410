// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AMyRocket::AMyRocket()
{


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RocketBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = RocketBox;
	RocketBox->SetBoxExtent(FVector(12.214396f, 4.717534f, 4.172323f));

	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));
	Rocket->SetupAttachment(RocketBox);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Rocket(TEXT("/Script/Engine.StaticMesh'/Game/Rocket/Meshes/SM_Rocket.SM_Rocket'"));
	Rocket->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
	Rocket->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));


	if (SM_Rocket.Succeeded())
	{
		Rocket->SetStaticMesh(SM_Rocket.Object);
	}

	Move = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Move"));
	Move->InitialSpeed = 1000.f;
	Move->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void AMyRocket::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AMyRocket::ProcessActorBeginOverlap);

	SetLifeSpan(2.f);
}

// Called every frame
void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyRocket::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	Destroy();

}



