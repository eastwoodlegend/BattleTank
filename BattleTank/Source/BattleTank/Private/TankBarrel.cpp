// Fill out your copyright notice in the Description page of Project Settings.


#include "public/TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevating at: %f degrees per second"), DegreesPerSecond);
}