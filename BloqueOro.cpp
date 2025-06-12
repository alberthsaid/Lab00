// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueOro.h"

ABloqueOro::ABloqueOro()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
		if (Material.Succeeded())
		{
			MallaBloque->SetMaterial(0, Material.Object);
		}
	}
	FloatSpeed = 3.0f;
	RotationSpeed = 3.0f;
	bPuedeMoverse = FMath::RandBool();

}
void ABloqueOro::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
}

void ABloqueOro::Tick(float DeltaTime)
{
	/*if (bPuedeMoverse)
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		NewLocation.Y = PosicionInicial.Y + FMath::Cos(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 0.0f;
		SetActorLocation(NewLocation);
	}*/
	if (bPuedeMoverse)
	{
		FVector NewLocation = PosicionInicial;
		NewLocation.Z = FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 100.0f + 120.0f;
		SetActorLocation(NewLocation);
	}
	else {
		FVector NewLocation = PosicionInicial;
		NewLocation.X = PosicionInicial.X + FMath::Sin(GetGameTimeSinceCreation() * FloatSpeed) * 50.0f;
		SetActorLocation(NewLocation);
	}
}